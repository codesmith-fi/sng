/*
 *  Object3D.h
 *  SNG
 *
 *  Copyright 2009 by Erno Pakarinen. All rights reserved.
 */
#pragma once

#include "Vertex3D.h"
#include "Rotation3D.h"
#include "Polygon3D.h"
#include "SingleList.h"

// TYPE DEFINITIONS
/// Defines a concrete type for List of Polygon3D objects
typedef SingleList< Polygon3D > PolygonList;

/// Defines a iterator type for PolygonList
typedef SingleListIterator< Polygon3D > PolygonListIterator;

/**
 * Base class for 3D Object. ! 
 * 
 * Contains the base attributes for every object in 3D space
 *
 */
class Object3D : public Object3DBase
{
public: // Constructors and destructor
	/**
	 * Default constructor
	 * Object is initialized at coordinate (0,0,0) having a rotation (0,0,0)
	 */
	Object3D();

	/**
	 * Constructor
	 * @param newPos position of the object
	 * @param newRot rotation of the object
	 */
	Object3D( const Vertex3D& newPos, const Rotation3D& newRot );

	/// Destructor
	~Object3D();

public: // New methods, virtual
	/**
	 * Add a new polygon to the object. 
	 * @notice Takes ownership
	 */
	virtual void AddPolygon( Polygon3D* newPolygon );

	/**
	 * Getter for the polygons
	 ' @return (PolygonList&) reference to the list of polygons
	 */
	virtual PolygonList& Polygons();

public: // From Object3DBase
	/// @return (int)the number of polygons in this object
	int PolygonCount() const;

private: // Data
	/// Owned: Polygons in this object
	PolygonList* polygons;
};
