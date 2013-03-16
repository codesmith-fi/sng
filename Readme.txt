------------------------------
SNG - Simple Engine for OpenGL
------------------------------
Author: Erno Pakarinen (C) 2009
Date: 23.8.2009
------------------------------

A small practice with OpenGL and C++. 

This program implements a very simple 3D engine with OpenGL. The example scene renders a funky multicolor 'star' field where each 'star' is a 2D square ( having 2 polygons ) in 3D space. Lighting is faked so that a higher Z coordinate makes the objects material color darker. Camera is at (0,0,0).

The animation is done by moving each object towards the observer (Z = 0) and resetting each object back to the the MAX Z when it reaches Z = 0.

GLUT is used to initialize the rendering environment (window). This was implemented as a C++ sample and was also my very first OpenGL exercise.

-------------------------------------------------------------------------------

The engine is designed to have a class for each actor in the 3D engine and the design should be pretty straightforward and easy to understand. In the current version all textures are rendered using a simple observer call to the materials own observer interface.  This might change later when more complex textures are implemented.

What can it do?
- Objects containing any number of polygons (triangles).
  - Objects have rotation and space coordinate (X,Y,Z).
  - Each polygon has a texture
- Basic texture/material support. Currently there exists only one material 
  having a single RGB color value

What it can't do?
- Pretty much everything else.
- No camera, no real lighting, no animation, no bitmap textures, no ...

-------------------------------------------------------------------------------

Class descriptions:

SingleList
	A collection template for Singly Linked List (abstract). 
	It is used in the engine for several collections 
	(e.g. objects have polygons, scene has objects etc.)
ColorRGB
	Operations and data for a RGB color. Each color has 3 components:
	red, green and blue having a value of 0.0f .. 1.0f.
	ColorRGB(1.0f, 1.0f, 1.0f) means white.
Vertex3D
	A coordinate in 3D space. Has X, Y and Z properties. Implements
	operations for adding and substracting vertices.
Object3DBase
	Base for a object in 3D space. Has position and rotation. Intended
	only for extension.
Polygon3D
	A 3D polygon having 3 vertices (Vertex3D) and a texture.
	Extends Object3DBase and thus has position and rotation itself.
Rotation3D
	Defines a 3D rotation having Xrot, Yrot and Zrot. 
Object3D
	Object in 3D space having one texture.
Scene3D
	Contains all the objects and the rendering code. 
TextureBase
	Base class for textures.
TextureColorFlat
	Texture which has only a RGB color property.

main.cpp has only the initialization code and the main loop.

As you see, it is very simple. It is not lightning fast nor it's intended to be so at this phase. This was just my first practise with OpenGL but if time allows, I will work on this more and add new features.

-------------------------------------------------------------------------------

Precompiled windows binaries exist in release folders. VC2005 project included for building.


Thanks for reading!

Contact: erno.pakarinen@codesmith.fi


