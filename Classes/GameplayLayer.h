/* 
 * File:   GameplayLayer.h
 * Author: thedreamer
 *
 * Created on October 25, 2014, 4:21 PM
 */

#pragma once
#include "cocos2d.h"
#include "SneakyInput/SneakyJoystick.h"
#include "SneakyInput/SneakyButton.h"
#include "SneakyInput/SneakyJoystickSkinnedBase.h"
#include "SneakyInput/SneakyButtonSkinnedBase.h"

class GameplayLayer : public cocos2d::Layer {
public:
    CREATE_FUNC(GameplayLayer);
    virtual bool init();
    virtual void update(float dt);
private:
    void initJoystickAndButtons();
    void applyJoystick(SneakyJoystick *aJoystick,Node *tempNode, float dt);
    
    cocos2d::Sprite *vikingSprite;
    SneakyJoystick *leftJoystick;
    SneakyButton *jumpButton;
    SneakyButton *attackButton;
    
    cocos2d::Size _visibleSize;
};