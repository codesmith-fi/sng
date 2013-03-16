/*
 *  Vertex3D.h
 *  SNG
 *
 *  Copyright 2009 by Erno Pakarinen. All rights reserved.
 */
#pragma once

/**
 * Defines properties and operations for a position in 3D space
 *
 */
class Vertex3D
{
public: // Constructors and a destructor
	/// Default constructor
	Vertex3D(void);

	/**
	 * Copy constructor
	 * @param other Vertex which will be copied
	 */
	Vertex3D( const Vertex3D& other );

	/**
	 * Constructor which takes the x, y and z coordinates
	 * @param x the x coordinate
	 * @param y the y coordinate
	 * @param z the z coordinate
	 */
	Vertex3D( float x, float y, float z );

	/// Destructor
	~Vertex3D(void);

public: // setters and getters
	/**
	 * Set new coordinates
	 * @param x the x coordinate
	 * @param y the y coordinate
	 * @param z the z coordinate
	 */
	void Set( float x, float y, float z );

	/**
	 * Set the X coordinate
	 * @param x the x coordinate
	 */
	void SetX( float x );

	/**
	 * Set the Y coordinate
	 * @param y the y coordinate
	 */
	void SetY( float y );

	/**
	 * Set the Y coordinate
	 * @param y the y coordinate
	 */
	void SetZ( float z );

	/// @return the X coordinate
	float X() const;

	/// @return the Y coordinate
	float Y() const;

	/// @return the Z coordinate
	float Z() const;

public: // Operators
    Vertex3D& operator=( const Vertex3D& rhs );
	Vertex3D& operator+=( const Vertex3D& rhs );
	Vertex3D& operator-=( const Vertex3D& rhs );
	const Vertex3D& operator+( const Vertex3D& rhs ) const;
	const Vertex3D& operator-( const Vertex3D& rhs ) const;

private: 
	float pX;
	float pY;
	float pZ;
};
