#include "SneakyButton.h"

using namespace cocos2d;

void SneakyButton::onEnterTransitionDidFinish()
{
//	Director::getInstance()->getTouchDispatcher()->addTargetedDelegate(this, 1, true);
}

void SneakyButton::onExit()
{
//	Director::getInstance()->getTouchDispatcher()->removeDelegate(this);
}

bool SneakyButton::initWithRect(Rect rect)
{
	bool pRet = false;
	//if(CCSprite::init()){
		
		bounds = Rect(0, 0, rect.size.width, rect.size.height);
		center = Point(rect.size.width/2, rect.size.height/2);
		status = 1; //defaults to enabled
		active = false;
		value = 0;
		isHoldable = 0;
		isToggleable = 0;
		radius = 32.0f;
		rateLimit = 1.0f/120.0f;
                auto listener = EventListenerTouchOneByOne::create();
                listener->onTouchBegan = CC_CALLBACK_2(SneakyButton::onTouchBegan, this);
                listener->onTouchMoved = CC_CALLBACK_2(SneakyButton::onTouchMoved, this);
                listener->onTouchEnded = CC_CALLBACK_2(SneakyButton::onTouchEnded, this);
                this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
                
                setAnchorPoint(Vec2(0.5,0.5));
        	
                setContentSize(rect.size);
		setPosition(rect.origin); //not sure about this
		pRet = true;
	//}
	return pRet;
}

void SneakyButton::limiter(float delta)
{
	value = 0;
	this->unschedule(schedule_selector(SneakyButton::limiter));
	active = false;
}

void SneakyButton::setRadius(float r)
{
	radius = r;
	radiusSq = r*r;
}

bool SneakyButton::onTouchBegan(Touch *touch, Event *event)
{
	if (active) return false;
	
	Point location = Director::getInstance()->convertToGL(touch->getLocationInView());
	location = this->convertToNodeSpace(location);
        location = ccpSub(location, ccp(getContentSize().width/2, getContentSize().height/2));
		//Do a fast rect check before doing a circle hit check:
	if(location.x < -radius || location.x > radius || location.y < -radius || location.y > radius){
		return false;
	}else{
		float dSq = location.x*location.x + location.y*location.y;
		if(radiusSq > dSq){
			active = true;
			if (!isHoldable && !isToggleable){
				value = 1;
				this->schedule(schedule_selector(SneakyButton::limiter), rateLimit);
			}
			if (isHoldable) value = 1;
			if (isToggleable) value = !value;
			return true;
		}
	}
return false;
}

void SneakyButton::onTouchMoved(Touch *touch, Event *event)
{
	if (!active) return;
	
	Point location = Director::getInstance()->convertToGL(touch->getLocationInView());
	location = this->convertToNodeSpace(location);
		//Do a fast rect check before doing a circle hit check:
	if(location.x < -radius || location.x > radius || location.y < -radius || location.y > radius){
		return;
	}else{
		float dSq = location.x*location.x + location.y*location.y;
		if(radiusSq > dSq){
			if (isHoldable) value = 1;
		}
		else {
			if (isHoldable) value = 0; active = false;
		}
	}
}

void SneakyButton::onTouchEnded(Touch *touch, Event *event)
{
	if (!active) return;
	if (isHoldable) value = 0;
	if (isHoldable||isToggleable) active = false;
}

void SneakyButton::onTouchCancelled(Touch *touch, Event *event)
{
	this->onTouchEnded(touch, event);
}

void SneakyButton::touchDelegateRelease()
{
	this->release();
}

void SneakyButton::touchDelegateRetain()
{
	this->retain();
}
