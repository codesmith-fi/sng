/*
 *  Light.h
 *  SNG
 *
 *  Copyright 2009 by Erno Pakarinen. All rights reserved.
 */
#include "Vertex3D.h"
#include "Rotation3D.h"
#include "ColorRGB.h"
#include "Object3DBase.h"

class Light : public Object3DBase
{
public: // Constructor(s) and destructor
	/// Default constructor
	Light();
	
	/**
	 * Constructor which takes the position and color
	 */
	Light( const ColorRGB& c, const Vertex3D& p, const Rotation3D& r );
	
	/// Destructor
	~Light();
	
private: // Data
	ColorRGB color;
};
