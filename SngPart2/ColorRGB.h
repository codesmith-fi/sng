/*
 *  ColorRGB.h
 *  SNG
 *
 *  Copyright 2009 by Erno Pakarinen. All rights reserved.
 */
#pragma once

// DEFINITIONS
#define COLOR_MAX_INT_VALUE 255
#define COLOR_MIN_INT_VALUE 0
#define COLOR_MAX_FLOAT_VALUE 1.0f
#define COLOR_MIN_FLOAT_VALUE 0.0f

/**
 * Color value with Red, Blue and Green properties
 * 
 * Color is internally held as a float.
 */
class ColorRGB
{
public: // Constructor(s) and destructor
	/**
	 * Default constructor, initializes color to (0,0,0)
	 */
	ColorRGB();

	/**
	 * Copy constructor
	 * @param other ColorRGB which will be copied
	 */
	ColorRGB( const ColorRGB& other );

	/**
	 * Constructor with integer color components
	 * @param r red value, range 0..255
	 * @param g red value, range 0..255
	 * @param b red value, range 0..255
	 */
	ColorRGB( int r, int g, int b );

	/**
	 * Constructor with float color components
	 * @param r red value, range 0..1.0f
	 * @param g red value, range 0..1.0f
	 * @param b red value, range 0..1.0f
	 */
	ColorRGB( float r, float g, float b );

	/// Destructor
	virtual ~ColorRGB();

public: // Operators
	/**
	 * Assignment operator. Set properties from another ColorRGB
	 * @param rhs Color which will be copied to this color
	 * @return the modified color
	 */
    ColorRGB& operator=( const ColorRGB& rhs );	

	/**
	 * Unary addition operator (color2 += color1)
	 * @param rhs Color which will be added to this
	 * @return the modified color
	 */
	ColorRGB& operator+=( const ColorRGB& rhs );

	/**
	 * Unary substraction operator. (color2 -= color1)
	 * @param rhs Color which will be substracted from this
	 * @return the modified color
	 */
	ColorRGB& operator-=( const ColorRGB& rhs );

	/**
	 * Binary addition operator ( color3 = color1 + color 2)
	 * @param rhs Color which will be added to this
	 * @return the modified color
	 */
	const ColorRGB& operator+( const ColorRGB& rhs ) const;

	/**
	 * Binary substraction operator ( color3 = color1 - color 2)
	 * @param rhs Color which will be substracted from this
	 * @return the modified color
	 */
	const ColorRGB& operator-( const ColorRGB& rhs ) const;
	
public: // Getters
	/// @return (float)Red component value
	float Red() const;
	/// @return (float)Green component value
	float Green() const;
	/// @return (float)Blue component value
	float Blue() const;	
	/// @return (int)Red component value. Range 0-255
	int Red_i() const;
	/// @return (int)Green component value. Range 0-255
	int Green_i() const;
	/// @return (int)Blue component value. Range 0-255
	int Blue_i() const;
	
private: // Data
	/// Red component value
	float red;
	/// Green component value
	float green;
	/// Blue component value
	float blue;
};