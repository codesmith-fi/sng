/*
 *  Scene3D.h
 *  SNG
 *
 *  Copyright 2009 by Erno Pakarinen. All rights reserved.
 */
#pragma once

#include <windows.h>
#include <gl\gl.h>								// Header File For The OpenGL32 Library
#include <gl\glu.h>								// Header File For The GLu32 Library

#include "SingleList.h"
#include "Object3D.h"

#include "TextureColorFlat.h"

// Type definitions
/// Defines a concrete type for list of Object3D objects
typedef SingleList< Object3D > ObjectList;

/// Defines a iterator type for ObjectList
typedef SingleListIterator< Object3D > ObjectListIterator;

/**
 * Simple 3D scene having multiple objects and a simple animation
 */
class Scene3D 
	: public TextureColorFlatRenderer
{
public: // Default constructor and destructor
	/// Constructor
	Scene3D();
	/// Destructor
	~Scene3D();

public: // Public methods
	/// Renders a single frame, call in main loop
	void RenderScene();

	/** 
	 * Resizes the scene according to the new dimensions
	 * @param width new width of the render window
	 * @param height new height of the render window
	 */
	void ResizeScene( GLsizei width, GLsizei height );

	/// Initialize OpenGL renderer
	void InitGL();

	/// Set up the 3D scene (objects and materials etc.)
	void SetupScene();

private: // From Base Classes
	void RenderTexture( const TextureColorFlat& texture ) const;
	
private: // New methods

private: // Data
	/// Owned: Objects in the scene
	ObjectList* objects;
	/// Value which will be used to fake the lighting in this version
	float deColor;
};
