#include <windows.h>
#include <gl\gl.h>								// Header File For The OpenGL32 Library
#include <gl\glu.h>								// Header File For The GLu32 Library
#include <gl\glaux.h>
#include "glut/glut.h"		// Header File For The GLut Library

#include "Scene3D.h"

#define kWindowWidth	1024
#define kWindowHeight	768

GLvoid draw(GLvoid);
GLvoid resize(int width, int height);
GLvoid idle(GLvoid);

Scene3D* scene = NULL;

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
	glutInitWindowSize( kWindowWidth, kWindowHeight );
	glutInitWindowPosition( 100, 100 );
	glutCreateWindow( argv[0] );
	glutDisplayFunc( draw );
	glutReshapeFunc( resize );
	glutIdleFunc( idle );
		
	scene = new Scene3D();
	scene->InitGL();
	scene->SetupScene();
	
	glutMainLoop();
	
	delete scene;
	return 0;
}

GLvoid idle( GLvoid )
{
	glutPostRedisplay();
}

GLvoid draw( GLvoid) 
{
	scene->RenderScene();
	glutSwapBuffers();
}

GLvoid resize( int width, int height )
{
	scene->ResizeScene(width, height);
}
