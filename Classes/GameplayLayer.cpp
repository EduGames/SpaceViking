/* 
 * File:   GameplayLayer.cpp
 * Author: thedreamer
 * 
 * Created on October 25, 2014, 4:21 PM
 */

#include "GameplayLayer.h"
USING_NS_CC;
bool GameplayLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    vikingSprite = Sprite::create("sv_anim_1.png");
    vikingSprite->setPosition(Vec2(visibleSize.width/2,visibleSize.height*0.17f));
    this->addChild(vikingSprite);
    
    return true;
}


