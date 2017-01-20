#ifndef __GAMEMAP_H__
#define __GAMEMAP_H__
#pragma once

#include "cocos2d.h"
#include "MapSprite.h"

class GameMap : public cocos2d::Layer
{
public:
	virtual bool init();
	CREATE_FUNC(GameMap);

	cocos2d::DrawNode *draw = cocos2d::DrawNode::create();

private:
	cocos2d::experimental::TMXTiledMap *TMap = nullptr;
	cocos2d::experimental::TMXLayer* Layer2 = nullptr;
	cocos2d::experimental::TMXLayer* Layer1 = nullptr;

	cocos2d::Size layerSize;
	cocos2d::Size mapTileSize;

	MapSprite* EndSprite = nullptr;
	MapSprite* StartSprite = nullptr;
	MapSprite* NodeSprite = nullptr;

	cocos2d::EventListenerMouse *listenerMouse = cocos2d::EventListenerMouse::create();
	void onMouseClick(cocos2d::EventMouse* event);

	cocos2d::Vec2 tileCoordForPosition(const cocos2d::Vec2& position);

	cocos2d::Vector<cocos2d::Sprite *> setBarrier(std::vector<cocos2d::Vec2> barrier);

	//Âü¹þ¶Ù¹À¼Û·¨
	int manhattan(cocos2d::Vec2 *end, cocos2d::Vec2 *start);

	cocos2d::Label *infotext = cocos2d::Label::createWithSystemFont("", "Arial", 20);
};
#endif //__GAMEMAP_H__

