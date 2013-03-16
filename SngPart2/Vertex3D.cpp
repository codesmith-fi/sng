/*
 *  Vertex3D.h
 *  SNG
 *
 *  Copyright 2009 by Erno Pakarinen. All rights reserved.
 */
#include "Vertex3D.h"

Vertex3D::Vertex3D(void) : pX(0.0f), pY(0.0f), pZ(0.0f)
{
}

Vertex3D::Vertex3D( const Vertex3D& other )
{
	pX = other.pX;
	pY = other.pY;
	pZ = other.pZ;
}

Vertex3D::Vertex3D( float x, float y, float z ) : pX(x), pY(y), pZ(z)
{
}

Vertex3D::~Vertex3D(void)
{
}

void Vertex3D::Set( float x, float y, float z )
{
	pX = x;
	pY = y;
	pZ = z;
}

void Vertex3D::SetX( float x )
{
	pX = x;
}

void Vertex3D::SetY( float y )
{
	pY = y;
}

void Vertex3D::SetZ( float z )
{
	pZ = z;
}

float Vertex3D::X() const
{
	return pX;
}

float Vertex3D::Y() const
{
	return pY;
}

float Vertex3D::Z() const
{
	return pZ;
}

Vertex3D& Vertex3D::operator=( const Vertex3D &rhs )
{
	pX = rhs.pX;
	pY = rhs.pY;
	pZ = rhs.pZ;
	return *this;
}

Vertex3D& Vertex3D::operator+=( const Vertex3D &rhs )
{
	pX += rhs.pX;
	pY += rhs.pY;
	pZ += rhs.pZ;
	return *this;
}

Vertex3D& Vertex3D::operator-=( const Vertex3D &rhs )
{
	pX -= rhs.pX;
	pY -= rhs.pY;
	pZ -= rhs.pZ;
	return *this;
}

const Vertex3D& Vertex3D::operator+( const Vertex3D &rhs ) const
{
	return ( Vertex3D(*this) += rhs );
}

const Vertex3D& Vertex3D::operator-( const Vertex3D &rhs ) const
{
	return ( Vertex3D(*this) -= rhs );
}

