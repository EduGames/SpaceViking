#include "GameScene.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = GameScene::create();
    
    // 'layer' is an autorelease object
    auto gamePlayLayer = GameplayLayer::create();
    auto backgroundLayer = BackgroundLayer::create();

    // add layer as a child to scene
    scene->addChild(backgroundLayer);
    scene->addChild(gamePlayLayer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
//bool GameScene::init()
//{
//    //////////////////////////////
//    // 1. super init first
//    if ( !Layer::init() )
//    {
//        return false;
//    }
//    
//    Size visibleSize = Director::getInstance()->getVisibleSize();
//    Vec2 origin = Director::getInstance()->getVisibleOrigin();
//
//
//    BackgroundLayer *backgroundLayer = BackgroundLayer::create();
//    this->addChild(backgroundLayer,0);
//    GameplayLayer *gameplayLayer = GameplayLayer::create();
//    this->addChild(gameplayLayer,5); 
//
//    return true;
//}
