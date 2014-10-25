/* 
 * File:   BackgroundLayer.cpp
 * Author: thedreamer
 * 
 * Created on October 25, 2014, 4:07 PM
 */

#include "BackgroundLayer.h"
USING_NS_CC;
bool BackgroundLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    Sprite * backgroundImage = Sprite::create("background.png");
    backgroundImage->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));
    this->addChild(backgroundImage);
    
    return true;
}


