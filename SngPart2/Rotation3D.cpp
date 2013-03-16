/*
 *  Rotation3D
 *  SNG
 *
 *  Copyright 2009 by Erno Pakarinen. All rights reserved.
 */

#include "Rotation3D.h"

Rotation3D::Rotation3D(void) : rX(0), rY(0), rZ(0)
{
}

Rotation3D::Rotation3D( const Rotation3D& other )
{
	rX = other.rX;
	rY = other.rY;
	rZ = other.rZ;
}

Rotation3D::Rotation3D( float angleX, float angleY, float angleZ )
	: rX(angleX), rY(angleY), rZ(angleZ)
{
}

Rotation3D::~Rotation3D(void)
{
}

void Rotation3D::SetRotation( float angleX, float angleY, float angleZ )
{
	rX = angleX;
	rY = angleY;
	rZ = angleZ;
}

void Rotation3D::SetRotX( float angleX )
{
	rX = angleX;
}

void Rotation3D::SetRotY( float angleY )
{
	rY = angleY;
}

void Rotation3D::SetRotZ( float angleZ )
{
	rZ = angleZ;
}

float Rotation3D::RotX() const
{
	return rX;
}

float Rotation3D::RotY() const
{
	return rY;
}

float Rotation3D::RotZ() const
{
	return rZ;
}

Rotation3D& Rotation3D::operator=( const Rotation3D &rhs )
{
	rX = rhs.rX;
	rY = rhs.rY;
	rZ = rhs.rZ;
	return *this;
}

Rotation3D& Rotation3D::operator+=( const Rotation3D &rhs )
{
	rX += rhs.rX;
	rY += rhs.rY;
	rZ += rhs.rZ;
	return *this;
}

Rotation3D& Rotation3D::operator-=( const Rotation3D &rhs )
{
	rX -= rhs.rX;
	rY -= rhs.rY;
	rZ -= rhs.rZ;
	return *this;
}

const Rotation3D& Rotation3D::operator+( const Rotation3D &rhs ) const
{
	return ( Rotation3D(*this) += rhs );
}

const Rotation3D& Rotation3D::operator-( const Rotation3D &rhs ) const
{
	return ( Rotation3D(*this) -= rhs );
}
