/*
 *  Polygon3D
 *  SNG
 *
 *  Copyright 2009 by Erno Pakarinen. All rights reserved.
 */
#include "Polygon3D.h"
#include "TextureBase.h"

Polygon3D::Polygon3D(void)
{
	texture = NULL;
}

Polygon3D::Polygon3D( 
	const Vertex3D& v1, 
	const Vertex3D& v2, 
	const Vertex3D& v3 )
{
	vertices[0] = v1;
	vertices[1] = v2;
	vertices[2] = v3;
	
	texture = NULL;
}

Polygon3D::~Polygon3D(void)
{
	delete texture;
}

void Polygon3D::SetVertices( const Vertex3D& v1, 
	const Vertex3D& v2, 
	const Vertex3D& v3 )
{
	vertices[0] = v1;
	vertices[1] = v2;
	vertices[2] = v3;
}

const Vertex3D& Polygon3D::GetVertice( int num ) const
{
	num = ( num > 2 ) ? 2 : num;
	return vertices[ num ];
}

void Polygon3D::SetTexture( TextureBase* newTexture )
{
	if( texture ) 
	{
		delete texture;
	}
	texture = newTexture;
}

TextureBase* Polygon3D::Texture() 
{
	return texture;
}
