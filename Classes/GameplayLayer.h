/* 
 * File:   GameplayLayer.h
 * Author: thedreamer
 *
 * Created on October 25, 2014, 4:21 PM
 */

#pragma once
#include "cocos2d.h"

class GameplayLayer : public cocos2d::Layer {
public:
    CREATE_FUNC(GameplayLayer);
    virtual bool init();
private:
    cocos2d::Sprite *vikingSprite;
};