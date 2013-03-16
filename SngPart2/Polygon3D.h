/*
 *  Polygon3D.h
 *  SNG
 *
 *  Copyright 2009 by Erno Pakarinen. All rights reserved.
 */
#pragma once

#include "object3dbase.h"
#include "vertex3d.h"

/// Number of polygons in the object. We always have 3 in this version
#define NUM_VERTICES_POLYGON	3

// FORWARD DECLARATIONS
class TextureBase;

/**
 * Polygon is a full object with position and rotation
 */
class Polygon3D :
	public Object3DBase
{
public: // Constructors and destructor
	/// Default constructor
	Polygon3D();

	/**
	 * Constructor which takes the vertices that form the polygon
	 * @param v1 First vertex
	 * @param v2 Second vertex
	 * @param v3 Third vertex
	 */
	Polygon3D( 
		const Vertex3D& v1, 
		const Vertex3D& v2, 
		const Vertex3D& v3 );

	/// Destructor
	~Polygon3D(void);

public: // New methods
	/**
	 * Setter for the vertices for this polygon
	 * @param v1 First vertex
	 * @param v2 Second vertex
	 * @param v3 Third vertex
	 */
	void SetVertices( 
		const Vertex3D& v1, 
		const Vertex3D& v2, 
		const Vertex3D& v3 );

	/**
	 * Get a vertex from this polygon
	 * @param num the vertex number (0..2)
	 * @return the requested vertex
	 */
	const Vertex3D& GetVertice( int num ) const;

	/**
	 * Set a new texture for this object. Old one is deleted
	 * @notice Ownership is transferred to this object!
	 */
	void SetTexture( TextureBase* newTexture );

	/// Get a pointer to the texture
	TextureBase* Texture(); 
	
private: // data
	/// Vertices that form this polygon
	Vertex3D vertices[ NUM_VERTICES_POLYGON ];
	/// Owned: Texture
	TextureBase* texture;
};
