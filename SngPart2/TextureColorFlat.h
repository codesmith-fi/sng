/*
 *  TextureColorFlat.h
 *  SNG
 *
 *  Copyright 2009 by Erno Pakarinen. All rights reserved.
 */
#pragma once

#include "TextureBase.h"
#include "ColorRGB.h"

// FORWARD DECLARATIONS
class TextureColorFlatRenderer;

/**
 * Defines a simple texture having a RGB color property
 */
class TextureColorFlat : public TextureBase
{
public: // Constructor and destructor
	/// Default constructor
	TextureColorFlat();
	/** 
	 * Constructor which takes the color value as argument
	 * @param c color for this texture
	 */
	TextureColorFlat( const ColorRGB& c );

	/// destructor
	~TextureColorFlat();
public: // New methods
	/// @return the Color value of this texture
	const ColorRGB& Color() const;

	/**
	 * Set a new color for this texture
	 * @param color new color
	 */
	void SetColor( const ColorRGB& color );

	/**
	 * Set the renderer which will be used to render this texture
	 */
	void SetRenderer( TextureColorFlatRenderer* r );

protected: // From TextureBase
	void Render();
	
private: // Data
	/// Color value of this texture
	ColorRGB color;
	/// Reference: Renderer
	TextureColorFlatRenderer* renderer;
};

/**
 * Observer interface for ColorFlat renderer.
 */
class TextureColorFlatRenderer
{
protected:
	/// Destruction not allowed through this interface
	~TextureColorFlatRenderer() { };

public:
	/** 
	 * Render this texture. Must be implemented by the renderer.
	 * @param a pointer to the texture
	 */
	virtual void RenderTexture( const TextureColorFlat& texture ) const = 0;
};
