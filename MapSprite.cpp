#include "MapSprite.h"

USING_NS_CC;

MapSprite::MapSprite(cocos2d::Rect* SpriteRect) {
	nodeRect.x = SpriteRect->origin.x;
	nodeRect.y = SpriteRect->origin.y;
	nodeRect.width = SpriteRect->size.width;
	nodeRect.height = SpriteRect->size.height;

	Vec2 point[4] = { Vec2(0, 0) , Vec2(nodeRect.width, 0), Vec2(nodeRect.width, nodeRect.height), Vec2(0,nodeRect.height) };
	this->draw->drawPolygon(point, 4, Color4F(1, 0, 0, 0), 1, Color4F(0, 1, 0, 1));
	this->setName("side");
	this->addChild(draw, 0);

	this->_GText->setAnchorPoint(Vec2(0, 0));
	this->_GText->setFontSize(10);
	this->_GText->setPosition(Vec2(2, 0));
	this->addChild(this->_GText, 1);

	this->_HText->setAnchorPoint(Vec2(0, 0));
	this->_HText->setFontSize(10);
	this->_HText->setPosition(Vec2(2, 10));
	this->addChild(this->_HText, 1);


	this->_FText->setAnchorPoint(Vec2(0, 0));
	this->_FText->setFontSize(10);
	this->_FText->setPosition(Vec2(2, 20));
	this->addChild(this->_FText, 1);
}
MapSprite::~MapSprite() {
	this->removeChild(this->draw, true);
	this->removeChild(this->_GText, true);
	this->removeChild(this->_HText, true);
	this->removeChild(this->_FText, true);
}

int MapSprite::getG() {
	return this->G;
};
void MapSprite::setG(int g) {
	this->G = g;
	char str[10];
	sprintf(str, "g:%d", g);
	this->_GText->setString(str);
};

int MapSprite::getH() {
	return this->H;
};
void MapSprite::setH(int h) {
	this->H = h;
	char str[10];
	sprintf(str, "h:%d", h);
	this->_HText->setString(str);
};

int MapSprite::getF() {
	return this->F;
};
void MapSprite::setF(int f) {
	this->F = f;
	char str[10];
	sprintf(str, "f:%d", f);
	this->_FText->setString(str);
};