/*
 *  Light
 *  SNG
 *
 *  Copyright 2009 by Erno Pakarinen. All rights reserved.
 */

#include "Light.h"

Light::Light()
{
}

Light::Light( const ColorRGB& c, const Vertex3D& p, const Rotation3D& r ) 
	: Object3DBase( p, r ), color( c )
{
}

Light::~Light()
{
}

