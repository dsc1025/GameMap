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
	SpriteSide = new MapSprite();
	Layer1->getTileAt(Vec2(12, 9))->setColor(Color3B(0, 0, 255));
	Layer1->getTileAt(Vec2(12, 9))->addChild(SpriteSide, 1);

	//ÕÏ°­
	/*Layer1->getTileAt(Vec2(7, 7))->setColor(Color3B(0, 255, 0));
	Layer1->getTileAt(Vec2(7, 8))->setColor(Color3B(0, 255, 0));
	Layer1->getTileAt(Vec2(7, 9))->setColor(Color3B(0, 255, 0));
	Layer1->getTileAt(Vec2(7, 10))->setColor(Color3B(0, 255, 0));
	Layer1->getTileAt(Vec2(7, 11))->setColor(Color3B(0, 255, 0));*/

	this->setObstacles({ Vec2(7,7),Vec2(7, 8),Vec2(7, 9),Vec2(7, 10),Vec2(7, 11) });

	listenerMouse->onMouseUp = CC_CALLBACK_1(GameMap::onMouseClick, this);
	Layer1->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listenerMouse, Layer1);

	return true;
}

void GameMap::onMouseClick(EventMouse* event) {
	static Vec2 pointA;

	Vec2 pointB = GameMap::tileCoordForPosition(Layer1->convertToNodeSpace(event->getLocationInView()));

	if (Layer1->getTileAt(pointB) != nullptr && pointA != pointB) {

		Layer1->getTileAt(pointB)->setColor(Color3B(255, 0, 0));

		SpriteSide = new MapSprite();
		Layer1->getTileAt(pointB)->addChild(SpriteSide, 1);

		if (Layer1->getTileAt(pointA) != nullptr && pointA != pointB) {
			Layer1->getTileAt(pointA)->setColor(Color3B(255, 255, 255));
			Layer1->getTileAt(pointA)->removeChildByName("side");
		}
		pointA = pointB;
	}
}

Vec2 GameMap::tileCoordForPosition(const Vec2& position)
{
	int x = position.x / mapTileSize.width;
	int y = (layerSize.height * mapTileSize.height - position.y) / mapTileSize.height;
	return Vec2(x, y);
}


cocos2d::Vector<cocos2d::Sprite *> GameMap::setObstacles(std::vector<cocos2d::Vec2> obs) {
	cocos2d::Vector<cocos2d::Sprite *> vec1;
	for (int i = 0; i != obs.size(); ++i) {
		Layer1->getTileAt(obs[i])->setColor(Color3B(0, 255, 0));
		vec1.insert(i, Layer1->getTileAt(obs[i]));
	}
	return vec1;
}