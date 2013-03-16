/*
 *  Rotation3D.h
 *  SNG
 *
 *  Copyright 2009 by Erno Pakarinen. All rights reserved.
 */
#pragma once

/**
 * Defines the properties and operations for 3D rotation. 
 */
class Rotation3D
{
public:
	/// Default constructor
	Rotation3D();
	/** 
	 * Copy constructor
	 * @param other Rotation which will be copied
	 */
	Rotation3D( const Rotation3D& other );

	/**
	 * Constructor which takes the 3 angles (X, Y, Z )
	 * @param angleX X rotation 
	 * @param angleY Y rotation
	 * @param angleZ Z rotation 
	 */
	Rotation3D( float angleX, float angleY, float angleZ );

	/// Destructor
	~Rotation3D(void);

	/**
	 * Set a new rotation for this object
	 * 
	 * @param angleX X rotation 
	 * @param angleY Y rotation
	 * @param angleZ Z rotation 
	 */
	void SetRotation( float angleX, float angleY, float angleZ );

	/**
	 * Set a new X rotation for this object
	 * 
	 * @param angleX new X rotation 
	 */
	void SetRotX( float angleX );

	/**
	 * Set a new Y rotation for this object
	 * 
	 * @param angleY new Y rotation 
	 */
	void SetRotY( float angleY );

	/**
	 * Set a new Z rotation for this object
	 * 
	 * @param angleZ new Z rotation 
	 */
	void SetRotZ( float angleZ );

	/// @return (float) current X rotation
	float RotX() const;

	/// @return (float) current Y rotation
	float RotY() const;

	/// @return (float) current Z rotation
	float RotZ() const;

public: // Operators
	/**
	 * Assignment operator
	 * Properties from rhs will be copied to this
	 * @param rhs the source Rotation which will be copied to this
	 * @return the modified rotation
	 */
	Rotation3D& operator=( const Rotation3D &rhs );

	/**
	 * Unary addition operation
	 * Properties of rhs will be added to this
	 * @param rhs the source Rotation which will be added to this
	 * @return the modified rotation
	 */
	Rotation3D& operator+=( const Rotation3D &rhs );

	/**
	 * Unary substraction operator
	 * Properties of rhs will be substracted from this
	 * @param rhs the source Rotation which will be substracted from this
	 * @return the modified rotation
	 */
	Rotation3D& operator-=( const Rotation3D &rhs );

	/**
	 * Binary addition operator
	 * Properties of rhs will be added to this
	 * @param rhs the source Rotation which will be added to this
	 * @return modified rotation
	 */
	const Rotation3D& operator+( const Rotation3D &rhs ) const;

	/**
	 * Binary substraction operator
	 * Properties of rhs will be substracted from this
	 * @param rhs the source Rotation which will be substracted from this
	 * @return the modified rotation
	 */
	const Rotation3D& operator-( const Rotation3D &rhs ) const;

private: 
	/// Current X axis rotation
	float rX;
	/// Current Y axis rotation
	float rY;
	/// Current Z axis rotation
	float rZ;
};
