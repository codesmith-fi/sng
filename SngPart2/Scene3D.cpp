/*
 *  Scene3D
 *  SNG
 *
 *  Copyright 2009 by Erno Pakarinen. All rights reserved.
 */
#include "Scene3D.h"

#include <time.h>

#include "Polygon3D.h"
#include "TextureColorFlat.h"

#define MAX_DISTANCE 100.0f

Scene3D::Scene3D(void)
{
	objects = new ObjectList();
}

Scene3D::~Scene3D(void)
{
	delete objects;
}

void Scene3D::ResizeScene( GLsizei width, GLsizei height )
{
	height = ( height == 0 ) ? 1 : height;

	glViewport(0, 0, width, height);
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluPerspective( 45.0f, (GLfloat)width/(GLfloat)height, 0.1f, 100.0f );
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();			
}

void Scene3D::InitGL()
{
	glShadeModel( GL_SMOOTH );
	glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
	glClearDepth( 1.0f );
	glEnable( GL_DEPTH_TEST );
	glDepthFunc( GL_LEQUAL );
	glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
}

void Scene3D::SetupScene()
{
	srand( (unsigned)time( NULL ) );

	for( int i = 0; i < 15000; i++ )
	{
		int r1 = ( ( rand() % 3600 ) - 1600 );
		int r2 = ( ( rand() % 3600 ) - 1600 );

		// Get a random position in our "world"
		float f1 = r1 / 100.0f;
		float f2 = r2 / 100.0f;
		float f3 = -1.0f * ( rand() % (int)MAX_DISTANCE ); 
		
		// Set a random color (R,G,B) for each object, we are going to
		// use a flat colored texture
		float c1 = ( ( rand() % 256 ) ) / 256.0f;
		float c2 = ( ( rand() % 256 ) ) / 256.0f;
		float c3 = ( ( rand() % 256 ) ) / 256.0f;
				
		// Create a new 3D object at our specified position and rotation
		Object3D* newObject = new Object3D( 
			Vertex3D( f1, f2, f3 ), 
			Rotation3D( 0.0f, 0.0f, 0.0f ) );

		// Create 2 polygons for each object to make up a flat square.
		Polygon3D* polygon = new Polygon3D(
			Vertex3D( -0.1f, -0.1f, 0.0f ),
			Vertex3D(  0.1f,  0.1f, 0.0f ),
			Vertex3D( -0.1f,  0.1f, 0.0f ) );
		TextureColorFlat* texture = new TextureColorFlat( ColorRGB( c1, c2, c3 ) );
		texture->SetRenderer( this );
		polygon->SetTexture( texture );		
		newObject->AddPolygon( polygon );

		polygon = new Polygon3D(
			Vertex3D( -0.1f, -0.1f, 0.0f ),
			Vertex3D(  0.1f, -0.1f, 0.0f ),
			Vertex3D(  0.1f,  0.1f, 0.0f ) );
		texture = new TextureColorFlat( ColorRGB( c1, c2, c3 ) );
		texture->SetRenderer( this );
		polygon->SetTexture( texture );
		newObject->AddPolygon( polygon );

		// Add to our objects
		objects->insert( newObject );
	}
}

void Scene3D::RenderScene()
{
	// Clear
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	// Iterate through every object in the scene and render them
	ObjectListIterator objIter( objects );
	Object3D* obj;
	while( (obj = objIter.next() ) != NULL )
	{
		Vertex3D newPos( obj->Position() );

		glPushMatrix();
		glTranslatef( newPos.X(), newPos.Y(), newPos.Z() );

		Rotation3D& rot( obj->Rotation() );
		
		if( rot.RotX() != 0.0f ) 
			glRotatef( rot.RotX(), 1.0f, 0.0f, 0.0f );
		if( rot.RotY() != 0.0f ) 
			glRotatef( rot.RotY(), 0.0f, 1.0f, 0.0f );
		if( rot.RotZ() != 0.0f ) 
			glRotatef( rot.RotZ(), 0.0f, 0.0f, 1.0f );
		
		PolygonListIterator polyIter( &obj->Polygons() );
		Polygon3D* t;

		// Render polygons (triangles)
		while( ( t = polyIter.next() ) != NULL )
		{
			// Store a multiplier related to the distance from Z(0.0) coord
			// This is used to fake the lighting now when real lighting is
			// not implemented
			deColor = 1.0f - ( obj->Position().Z() / -MAX_DISTANCE );

			// Set texture/material			
			TextureBase* texture = t->Texture();
			texture->Render();
			
			glBegin( GL_TRIANGLES );
			for( int k = 0; k < 3; k++ ) 
			{
				const Vertex3D& v( t->GetVertice( k ) );
				glVertex3f( v.X(), v.Y(), v.Z() );
			}
			glEnd();
		}
		glPopMatrix();
		
		// In this example, move each objects towards the "camera" by 
		// increasing the Z coordinate. Each object also rotates around Z axis
		obj->Move( Vertex3D( 0.0f, 0.0f, 0.1f ) );
		obj->Rotate( Rotation3D( 0.0f, 0.0f, 5.0f ) );

		// Reset each object back to the max distance when they get too close
		// at Z(0.0)
		if( newPos.Z() >= 0.0f ) 
		{
			obj->Position().SetZ( -MAX_DISTANCE );
		}

	}	
}

void Scene3D::RenderTexture( const TextureColorFlat& texture ) const
{
	// Set properties caused by a flat colored texture
	const ColorRGB& color( texture.Color() );
	
	// Fake the lighting using the distance multiplier, farther from Z(0.0) 
	// we are the darker is the color
	glColor3f( color.Red() * deColor, 
		color.Green() * deColor, 
		color.Blue() * deColor );
}

/*
void Scene3D::RenderTexture( const TextureBitmap& texture ) const
{
}
*/
