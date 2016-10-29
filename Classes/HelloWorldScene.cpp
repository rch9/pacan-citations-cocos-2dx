//#include "MainMenuScene.h"
#include "HelloWorldScene.h"
//#include "HelloWorldScene2.h"
//#include "ShopScene.h"
//#include "Managers/DatabaseManager.h"

//#include "cocos2d/external/json/rapidjson.h"

//#include "json/rapidjson.h"
//#include "json/document.h"

USING_NS_CC;
using namespace cocos2d::ui;

Scene* HelloWorld::createScene() {
    auto scene = Scene::create();
    auto layer = HelloWorld::create();
    scene->addChild(layer);

    return scene;
}

bool HelloWorld::init() {
    if (!Layer::init()) {
        return false;
    }

//#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
//    DataBaseManager *sql = DataBaseManager::getInstance();
//    sql->insert("foo", "value1");
//    std::string value = sql->select("foo");
//    auto label = Label::createWithTTF(value,"fonts/Marker Felt.ttf",32);
//    label->setPosition(100, 100);
//    this->addChild(label);
//#endif

    initPageView();
//    initShopButton();

    return true;
}

void HelloWorld::onTextClicked(Ref *sender, Widget::TouchEventType type) {
    auto parent =  this->getChildByTag(0);
//    auto text = RichElementText)
    if (_isClicked) {

    } else {

    }
}

void HelloWorld::initPageView() {
    auto visibleSize = Director::getInstance()->getVisibleSize();

    Size size(800, 1400);
    PageView* pageView = PageView::create();
    pageView->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    pageView->setDirection(PageView::Direction::VERTICAL);
    pageView->setContentSize(size);
    pageView->setPosition(visibleSize / 2.f);
    pageView->removeAllItems();
    pageView->setIndicatorEnabled(false);

    int pageCount = 30;
    for (int i = 0; i < pageCount; ++i) {
        Layout* layout = Layout::create();
        layout->setContentSize(size);

        auto imageView = ImageView::create("26.jpg");
//        auto imageView = RichElementImage::create(0, Color3B::WHITE, 0.5, "26.jpg");

//        auto richText = RichText::createWithXML("<font face=\"fonts/Marker Felt.ttf\" size=\"24\"><glow color=\"#AFEEEE\">Важно никогда не опаздывать.\nЗаранее продумайте план, как добраться до места\nвстречи.\nСтарайтесь быть к назначенному времени</glow></font>");
//        richText->ignoreContentAdaptWithSize(false);
//        richText->setContentSize(Size(100, 100));
//        richText->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
//        richText->setPosition(Vec2(layout->getContentSize().width / 2, layout->getContentSize().height / 4));
//        richText->setLocalZOrder(10);
        auto text = Text::create("Важно никогда не опаздывать.\nЗаранее продумайте план, как добраться до места\nвстречи.\nСтарайтесь быть к назначенному времени", "fonts/arial.ttf", 44);
        text->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
        text->enableGlow(Color4B::GREEN);//  Text::ignoreContentAdaptWithSize(false)

        text->setPosition(Vec2(layout->getContentSize().width / 2, layout->getContentSize().height / 4));
        text->setLocalZOrder(10);

        layout->addChild(text);

        imageView->setContentSize(size);
        imageView->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);
        imageView->setPosition(Vec2(layout->getContentSize().width / 2.0f, 1400));
        layout->addChild(imageView);

        pageView->insertCustomItem(layout, i);
    }

    this->addChild(pageView, 1, 0);
}
