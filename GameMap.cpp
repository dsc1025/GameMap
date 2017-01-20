#include "GameMap.h"

USING_NS_CC;

bool GameMap::init() {

	TMap = experimental::TMXTiledMap::create("map/t2.tmx");
	this->addChild(TMap, 0);

	Layer1 = TMap->getLayer("layer1");
	mapTileSize = Layer1->getMapTileSize();
	layerSize = Layer1->getLayerSize();
	//Layer1->setPosition(Vec2(-100, -100));

	//ÖÕµã
	EndSprite = new MapSprite(&cocos2d::Rect(12, 9, mapTileSize.width, mapTileSize.height));

	Layer1->getTileAt(Vec2(12, 9))->setColor(Color3B(0, 0, 255));
	Layer1->getTileAt(Vec2(12, 9))->addChild(EndSprite, 1);

	//ÕÏ°­
	/*Layer1->getTileAt(Vec2(7, 7))->setColor(Color3B(0, 255, 0));
	Layer1->getTileAt(Vec2(7, 8))->setColor(Color3B(0, 255, 0));
	Layer1->getTileAt(Vec2(7, 9))->setColor(Color3B(0, 255, 0));
	Layer1->getTileAt(Vec2(7, 10))->setColor(Color3B(0, 255, 0));
	Layer1->getTileAt(Vec2(7, 11))->setColor(Color3B(0, 255, 0));*/

	this->setBarrier({ Vec2(7,7),Vec2(7, 8),Vec2(7, 9),Vec2(7, 10),Vec2(7, 11) });

	listenerMouse->onMouseUp = CC_CALLBACK_1(GameMap::onMouseClick, this);
	Layer1->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listenerMouse, Layer1);

	this->infotext->setTextColor(Color4B(255, 0, 0, 255));
	this->infotext->setAnchorPoint(Vec2(0, 1));
	this->infotext->setPosition(Vec2(5, Director::getInstance()->getVisibleSize().height));
	this->addChild(this->infotext, 1);

	return true;
}

void GameMap::onMouseClick(EventMouse* event) {
	static Vec2 pointA;

	Vec2 pointB = GameMap::tileCoordForPosition(Layer1->convertToNodeSpace(event->getLocationInView()));

	if (Layer1->getTileAt(pointB) != nullptr && pointA != pointB) {

		Layer1->getTileAt(pointB)->setColor(Color3B(255, 0, 0));

		StartSprite = new MapSprite(&cocos2d::Rect(pointB.x, pointB.y, mapTileSize.width, mapTileSize.height));
		Layer1->getTileAt(pointB)->addChild(StartSprite, 1);

		if (Layer1->getTileAt(pointA) != nullptr && pointA != pointB) {
			Layer1->getTileAt(pointA)->setColor(Color3B(255, 255, 255));
			if (Layer1->getTileAt(pointA)->getChildByName("side"))
				Layer1->getTileAt(pointA)->removeChildByName("side");
		}
		pointA = pointB;
	}

	GameMap::manhattan(&Vec2(this->EndSprite->nodeRect.x, this->EndSprite->nodeRect.y), &Vec2(this->StartSprite->nodeRect.x, this->StartSprite->nodeRect.y));
}

Vec2 GameMap::tileCoordForPosition(const Vec2& position)
{
	int x = position.x / mapTileSize.width;
	int y = (layerSize.height * mapTileSize.height - position.y) / mapTileSize.height;
	return Vec2(x, y);
}


cocos2d::Vector<cocos2d::Sprite *> GameMap::setBarrier(std::vector<cocos2d::Vec2> barrier) {
	cocos2d::Vector<cocos2d::Sprite *> vec1;
	for (int i = 0; i != barrier.size(); ++i) {
		Layer1->getTileAt(barrier[i])->setColor(Color3B(0, 255, 0));
		vec1.insert(i, Layer1->getTileAt(barrier[i]));
	}
	return vec1;
}

//Âü¹þ¶Ù¹À¼Û·¨
int GameMap::manhattan(cocos2d::Vec2 *end, cocos2d::Vec2 *start) {
	int dx = std::abs(end->x - start->x);
	int dy = std::abs(end->y - start->y);

	char str[20];
	sprintf(str, "manhattan:%d", dx + dy);
	this->infotext->setString(str);
	return dx + dy;
}
