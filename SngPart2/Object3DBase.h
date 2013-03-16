/*
 *  Object3DBase.h
 *  SNG
 *
 *  Copyright 2009 by Erno Pakarinen. All rights reserved.
 */
#pragma once

#include <stdlib.h>
#pragma once

#include "Vertex3D.h"
#include "Rotation3D.h"

// TYPE DEFINITIONS

/**
 * Base class for 3D Object. Not intended for direct use.
 * 
 * Contains the base attributes for a object in 3D space
 *
 */
class Object3DBase
{
public: // Constructors and destructor
	/// Default constructor
	Object3DBase();

	/**
	 * Constructor
	 * @param newPos position of the object
	 * @param newRot rotation of the object
	 */
	Object3DBase( const Vertex3D& newPos, const Rotation3D& newRot );

	/// Destructor
	virtual ~Object3DBase();

public: // New methods, virtual
	/**
	 * Set new position for this object
	 * @param newPos position of the object
	 */
	virtual void SetPosition( const Vertex3D& newPos );
	/**
	 * Set new rotation for this object
	 * @param newRot rotation of the object
	 */
	virtual void SetRotation( const Rotation3D& newRot );

	/**
	 * Move the object, given delta is added to the current position
	 * @param posDelta specifies the amount to move this object
	 */
	virtual void Move( const Vertex3D& posDelta );

	/**
	 * Rotate the object, given delta will be added to the current rotation
	 * @param rotDelta specifies how much the object will be rotated
	 */
	virtual void Rotate( const Rotation3D& rotDelta );

	/// @return the current position of this object
	virtual Vertex3D& Position();

	/// @return the current rotation of this object
	virtual Rotation3D& Rotation();

	/// @return the polygon count of this object. This always returns 0.
	virtual int PolygonCount() const;

private: // Data
	/// Current rotation of this object
	Rotation3D rot;
	/// Current position of this object
	Vertex3D pos;
};
