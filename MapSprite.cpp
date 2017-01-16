#include "MapSprite.h"

USING_NS_CC;

MapSprite::MapSprite() {
	Vec2 point[4] = { Vec2(0, 0) , Vec2(32, 0), Vec2(32, 32), Vec2(0,32) };
	draw->drawPolygon(point, 4, Color4F(1, 0, 0, 0), 1, Color4F(0, 1, 0, 1));
	this->setName("side");
	this->addChild(draw, 0);
}
MapSprite::~MapSprite() {
	this->removeChild(draw, true);
}