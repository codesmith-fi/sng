/*
 *  TextureColorFlat
 *  SNG
 *
 *  Copyright 2009 by Erno Pakarinen. All rights reserved.
 */
#include "TextureColorFlat.h"

TextureColorFlat::TextureColorFlat() : color( 0.0f, 0.0f, 0.0f )
{
	renderer = NULL;
}

TextureColorFlat::TextureColorFlat( const ColorRGB& c ) : color( c) 
{
	renderer = NULL;
}

TextureColorFlat::~TextureColorFlat()
{
}

const ColorRGB& TextureColorFlat::Color() const
{
	return color;
}

void TextureColorFlat::SetColor( const ColorRGB& c )
{
	color = c;
}

void TextureColorFlat::Render()
{
	if( renderer ) 
	{
		renderer->RenderTexture( *this );
	}
}

void TextureColorFlat::SetRenderer( TextureColorFlatRenderer* r )
{
	renderer = r;
}
