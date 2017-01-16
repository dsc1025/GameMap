#ifndef __MAPSPRITE_H__
#define __MAPSPRITE_H__

#include "cocos2d.h"

class MapSprite : public cocos2d::Sprite
{
public:
	MapSprite();
	~MapSprite();
private:
	cocos2d::DrawNode *draw = cocos2d::DrawNode::create();
};

#endif //__MAPSPRITE_H__