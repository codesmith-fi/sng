/*
 *  Object3D
 *  SNG
 *
 *  Copyright 2009 by Erno Pakarinen. All rights reserved.
 */
#include "Object3D.h"
#include "Polygon3D.h"

Object3D::Object3D()
{
}

Object3D::Object3D( const Vertex3D& newPos, const Rotation3D& newRot )
	: Object3DBase( newPos, newRot )
{
	polygons = new PolygonList();
}

Object3D::~Object3D()
{
	delete polygons;
}

void Object3D::AddPolygon( Polygon3D* newPolygon )
{
	newPolygon->SetPosition( Position() );
	newPolygon->SetRotation( Rotation() );
	polygons->insert( newPolygon );
}

int Object3D::PolygonCount() const
{
	return polygons->size();
}

PolygonList& Object3D::Polygons()
{
	return *polygons;
}
