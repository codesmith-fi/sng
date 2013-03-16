/*
 *  TextureBase.h
 *  SNG
 *
 *  Copyright 2009 by Erno Pakarinen. All rights reserved.
 */
#pragma once

#include <stdlib.h>

/** 
 * Base class for every texture
 */
class TextureBase
{
public: // Constructor and destructor
	/// Default constructor
	TextureBase();

	/// Destructor
	virtual ~TextureBase();

public: // New methods	
	/** 
	 * Renders the texture
	 * This method should be overridden by each derived texture class.
	 */
	virtual void Render();
	
private: // Data
};
