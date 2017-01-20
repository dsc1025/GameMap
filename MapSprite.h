#ifndef __MAPSPRITE_H__
#define __MAPSPRITE_H__

#include "cocos2d.h"

class MapSprite : public cocos2d::Label
{
public:
	MapSprite(cocos2d::Rect* SpriteRect);
	~MapSprite();
private:
	cocos2d::DrawNode *draw = cocos2d::DrawNode::create();
	cocos2d::LabelTTF *_GText = cocos2d::LabelTTF::create();
	cocos2d::LabelTTF *_HText = cocos2d::LabelTTF::create();
	cocos2d::LabelTTF *_FText = cocos2d::LabelTTF::create();

	
public:
	struct NodeRect
	{
		int x = 0;
		int y = 0;
		int width = 0;
		int height = 0;
	};

	NodeRect nodeRect;

	// ��ǰ����ʼ
	int G = 0;
	void setG(int g);
	int getG(void);

	// ��ǰ���յ�
	int H = 0;
	void setH(int h);
	int getH(void);

	// F = G + H
	int F = 0;
	void setF(int f);
	int getF(void);

};

#endif //__MAPSPRITE_H__