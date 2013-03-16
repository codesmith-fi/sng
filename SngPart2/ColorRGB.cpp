/*
 *  ColorRGB
 *  SNG
 *
 *  Copyright 2009 by Erno Pakarinen. All rights reserved.
 */

#include "ColorRGB.h"

ColorRGB::ColorRGB() : red( 0.0f ), green( 0.0f ), blue( 0.0f )
{
}

ColorRGB::ColorRGB( const ColorRGB& other )
{
	red = other.red;
	green = other.green;
	blue = other.blue;
}

ColorRGB::ColorRGB( int r, int g, int b )
{
	// Ensure color limits when constructing with int
	r = r % COLOR_MAX_INT_VALUE;
	g = g % COLOR_MAX_INT_VALUE;
	b = b % COLOR_MAX_INT_VALUE;
	
	red = !r ? 0.0f : 1.0f / r;
	green = !g ? 0.0f : 1.0f / r;
	blue = !b ? 0.0f : 1.0f / r;
}

ColorRGB::ColorRGB( float r, float g, float b ) : red( r), green( g ), blue( b )
{
}

ColorRGB::~ColorRGB()
{
}

ColorRGB& ColorRGB::operator=( const ColorRGB& rhs )
{
	red = rhs.red;
	green = rhs.green;
	blue = rhs.blue;
	return *this;
}

ColorRGB& ColorRGB::operator+=( const ColorRGB& rhs )
{
	red += rhs.red;
	green += rhs.green;
	blue += rhs.blue;
	
	// Ensure the value does not go beyond the limits
	red = red < COLOR_MAX_FLOAT_VALUE ? red : COLOR_MAX_FLOAT_VALUE;
	green = green < COLOR_MAX_FLOAT_VALUE ? green : COLOR_MAX_FLOAT_VALUE;
	blue = blue < COLOR_MAX_FLOAT_VALUE ? blue : COLOR_MAX_FLOAT_VALUE;
	return *this;
}

ColorRGB& ColorRGB::operator-=( const ColorRGB& rhs )
{
	red -= rhs.red;
	green -= rhs.green;
	blue -= rhs.blue;
	
	// Ensure the value does not go beyond the limits
	red = red > COLOR_MIN_FLOAT_VALUE ? red : COLOR_MIN_FLOAT_VALUE;
	green = green > COLOR_MIN_FLOAT_VALUE ? green : COLOR_MIN_FLOAT_VALUE;
	blue = blue > COLOR_MIN_FLOAT_VALUE ? blue : COLOR_MIN_FLOAT_VALUE;
	return *this;
}

const ColorRGB& ColorRGB::operator+( const ColorRGB& rhs ) const
{
	return ( ColorRGB(*this) += rhs );
}

const ColorRGB& ColorRGB::operator-( const ColorRGB& rhs ) const
{
	return ( ColorRGB(*this) -= rhs );
}

float ColorRGB::Red() const
{
	return red;
}

float ColorRGB::Green() const
{
	return green;
}

float ColorRGB::Blue() const
{
	return blue;
}

int ColorRGB::Red_i() const
{
	return ( red == 0.0f ) 
		? COLOR_MIN_INT_VALUE 
		: ( int )( COLOR_MAX_INT_VALUE * red ); 
}

int ColorRGB::Green_i() const
{
	return ( green == 0.0f ) 
		? COLOR_MIN_INT_VALUE 
		: ( int )( COLOR_MAX_INT_VALUE * green ); 
}

int ColorRGB::Blue_i() const
{
	return ( blue == 0.0f ) 
		? COLOR_MIN_INT_VALUE 
		: ( int ) (COLOR_MAX_INT_VALUE * blue ); 
}

