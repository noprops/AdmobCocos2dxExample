#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "PlatformUtil.h"

namespace {
    const char* kHelvetica = "Helvetica";
    const int FontSize = 20;
    const int MenuItemMargin = 10;
}

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    Label* label1 = Label::createWithSystemFont("Show Interstitial Ad", kHelvetica, FontSize);
    label1->setTextColor(Color4B::WHITE);
    MenuItemLabel* showInterstitialAd = MenuItemLabel::create(label1,
                                                              [](Ref* sender){
        PlatformUtil::showInterstitialAd();
    });
    showInterstitialAd->setPosition(origin + Vec2(visibleSize.width / 2, visibleSize.height - FontSize / 2 - MenuItemMargin));
    
    Label* label2 = Label::createWithSystemFont("Show Reward Based Video Ad", kHelvetica, FontSize);
    label2->setTextColor(Color4B::WHITE);
    MenuItemLabel* showRewardBasedVideoAd = MenuItemLabel::create(label2,
                                                                  [](Ref* sender){
        PlatformUtil::showRewardBasedVideoAd();
    });
    showRewardBasedVideoAd->setPosition(showInterstitialAd->getPosition() - Vec2(0, FontSize + MenuItemMargin));

    // create menu, it's an autorelease object
    auto menu = Menu::create(showInterstitialAd, showRewardBasedVideoAd, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    return true;
}
