/*
 *  Object3DBase
 *  SNG
 *
 *  Copyright 2009 by Erno Pakarinen. All rights reserved.
 */

#include "Object3DBase.h"
#include "Polygon3D.h"

Object3DBase::Object3DBase(void)
{
}

Object3DBase::Object3DBase( const Vertex3D& newPos, const Rotation3D& newRot )
	: pos( newPos ), rot( newRot )
{
}

Object3DBase::~Object3DBase(void)
{
}

void Object3DBase::SetPosition( const Vertex3D& newPos )
{
	pos = newPos;
}

void Object3DBase::SetRotation( const Rotation3D& newRot )
{
	rot = newRot;
}

Vertex3D& Object3DBase::Position()
{
	return pos;
}

Rotation3D& Object3DBase::Rotation() 
{
	return rot;
}

void Object3DBase::Move( const Vertex3D& posDelta )
{
	pos += posDelta;
}

void Object3DBase::Rotate( const Rotation3D& rotDelta )
{
	rot += rotDelta;
}

int Object3DBase::PolygonCount() const
{
	return 0;
}
