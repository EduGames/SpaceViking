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
    initJoystickAndButtons();
    scheduleUpdate();

    return true;
}

void GameplayLayer::initJoystickAndButtons(){
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    Rect joystickBaseDimensions = Rect(0, 0, 128.0f, 128.0f);
    Rect jumpButtonDimensions = Rect(0, 0, 64.0f, 64.0f);
    Rect attackButtonDimensions = Rect(0, 0, 64.0f, 64.0f);
    
    Vec2 joystickBasePosition = Vec2(visibleSize.width * 0.2,visibleSize.height * 0.2);
    Vec2 jumpButtonPosition = Vec2(visibleSize.width * 0.8,visibleSize.height * 0.4);
    Vec2 attackButtonPosition = Vec2(visibleSize.width * 0.8,visibleSize.height * 0.2);
    
    SneakyJoystickSkinnedBase *joystickBase = SneakyJoystickSkinnedBase::create();
    joystickBase->setPosition(joystickBasePosition);
    joystickBase->setThumbSprite(Sprite::create("joystickDown.png"));
    joystickBase->setBackgroundSprite(Sprite::create("dpadDown.png"));
    
    leftJoystick = new SneakyJoystick();
    leftJoystick->initWithRect(joystickBaseDimensions);
    joystickBase->setJoystick(leftJoystick);
    
    this->addChild(joystickBase);
    
    SneakyButtonSkinnedBase *jumpButtonBase = SneakyButtonSkinnedBase::create();
    jumpButtonBase->setPosition(jumpButtonPosition);
    jumpButtonBase->setDefaultSprite(Sprite::create("jumpUp.png"));
    jumpButtonBase->setPressSprite(Sprite::create("jumpUp.png"));
    jumpButtonBase->setActivatedSprite(Sprite::create("jumpDown.png"));
    
    jumpButton = new SneakyButton();
    jumpButton->initWithRect(jumpButtonDimensions);
    jumpButtonBase->setButton(jumpButton);
    jumpButton->setIsToggleable(false);
    this->addChild(jumpButtonBase);
    
    SneakyButtonSkinnedBase *attackButtonBase = SneakyButtonSkinnedBase::create();
    attackButtonBase->setPosition(attackButtonPosition);
    attackButtonBase->setDefaultSprite(Sprite::create("handUp.png"));
    attackButtonBase->setPressSprite(Sprite::create("handUp.png"));
    attackButtonBase->setActivatedSprite(Sprite::create("handDown.png"));
    
    attackButton = new SneakyButton();
    attackButton->initWithRect(attackButtonDimensions);
    attackButtonBase->setButton(attackButton);
    attackButton->setIsToggleable(false);
    this->addChild(attackButtonBase);
}
void GameplayLayer::applyJoystick(SneakyJoystick *aJoystick,Node *tempNode, float dt){
    
    Vec2 scaledVelocity = aJoystick->getVelocity()* 1024.0f;

    Vec2 newPosition =
        Vec2(tempNode->getPosition().x + scaledVelocity.x * dt,
        tempNode->getPosition().y + scaledVelocity.y * dt);

    tempNode->setPosition(newPosition);

    if (jumpButton->getIsActive()) {
        CCLOG("Jump button is pressed.");
    }
    if (attackButton->getIsActive()) {
        CCLOG("Attack button is pressed.");
    }
}

void GameplayLayer::update(float dt){
    applyJoystick(leftJoystick,vikingSprite,dt);
}
