/*
 *  NodeArtist.h
 *  Bloom
 *
 *  Created by Robert Hodgin on 1/21/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once

#include "CinderIPod.h"
#include "Node.h"
#include "cinder/Vector.h"

class NodeArtist : public Node
{
  public:
	NodeArtist( int index, const ci::Font &font, const ci::Font &smallFont, const ci::Surface &hiResSurfaces, const ci::Surface &loResSurfaces, const ci::Surface &noAlbumArt );
	
	void update( float param1, float param2 );
	void drawEclipseGlow();
	void drawExtraGlow( const ci::gl::Texture &tex );
	void drawPlanet( const ci::gl::Texture &tex );
//	void drawAtmosphere( const ci::Vec2f &center, const ci::gl::Texture &tex, const ci::gl::Texture &directionalTex, float pinchAlphaPer );
	void drawAtmosphere( const ci::Vec3f &camEye, const ci::Vec2f &center, const ci::gl::Texture &tex, const ci::gl::Texture &directionalTex, float pinchAlphaPer );
	
	void select();
	void setChildOrbitRadii();
    std::string getName();
    uint64_t getId();
	void setData( ci::ipod::PlaylistRef playlist );
	int getNumAlbums(){ return mNumAlbums; }
    ci::ipod::PlaylistRef getPlaylist() { return mPlaylist; }
	
  private:
	void setColors();
	ci::ipod::PlaylistRef mPlaylist;
	int mNumAlbums;
};

bool yearSortFunc(Node* a, Node* b);