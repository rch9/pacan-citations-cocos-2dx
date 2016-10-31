#include "HelloWorldScene.h"
#include "editor-support/cocostudio/LocalizationManager.h"
#include "TouchableLabel.h"
#ifdef SDKBOX_ENABLED
#include "pluginiap/PluginIAP.h"
#endif

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

    if (Application::getInstance()->getCurrentLanguage() == LanguageType::RUSSIAN) {
        cocostudio::JsonLocalizationManager::getInstance()->initLanguageData("text/ru-RU.lang.json");
    } else {
        cocostudio::JsonLocalizationManager::getInstance()->initLanguageData("text/en-US.lang.json");
    }

    initPageView();

    return true;
}

void HelloWorld::onTextClicked(Ref *sender) {
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

    auto localManager = cocostudio::JsonLocalizationManager::getInstance();


    auto l1 = Layout::create();
    l1->setContentSize(size);
    auto hi = Label::createWithTTF(localManager->getLocalizationString("hi"), "fonts/helios.ttf", 65);
    hi->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    hi->setPosition(400, 700);
    hi->setWidth(700);
    hi->setAlignment(TextHAlignment::LEFT);
    l1->addChild(hi);
    pageView->pushBackCustomItem(l1);

    int pageCount = 30;
    for (int i = 0; i < pageCount; ++i) {
        auto layout = TouchableLabel::create(convertInt(i).c_str(), convertJson(i, false).c_str(), convertJson(i, true).c_str());

        pageView->pushBackCustomItem(layout);
    }

    auto l2 = Layout::create();
    l2->setContentSize(size);
    auto bb = Label::createWithTTF(localManager->getLocalizationString("s0"), "fonts/helios.ttf", 65);
    bb->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    bb->setPosition(400, 1100);
    bb->setWidth(700);
    bb->setAlignment(TextHAlignment::LEFT);
    l2->addChild(bb);

    MenuItemFont::setFontName("fonts/helios.ttf");
    MenuItemFont::setFontSize(100);

    //    auto item1 = MenuItemFont::create("СКАЗАТЬ\nСПАСИБО", [&](Ref* ref){
    auto item1 = MenuItemFont::create(localManager->getLocalizationString("s1"), [&](Ref* ref){
        #ifdef SDKBOX_ENABLED
            sdkbox::IAP::purchase("thank_you_1");
        #endif
});
    item1->setPosition(50, 300);
    item1->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);


    auto item2 = MenuItemFont::create(localManager->getLocalizationString("bb"), [&](Ref* ref){
            Director::getInstance()->end();
        #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
            exit(0);
        #endif
});
    item2->setPosition(50, 50);
    item2->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
    auto menu = Menu::create(item1, item2, nullptr);

    menu->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
    menu->setPosition(0, 0);
    l2->addChild(menu);

    pageView->pushBackCustomItem(l2);

    this->addChild(pageView, 1, 0);
}

std::string HelloWorld::convertInt(const int &ind) {
    char buffer[10];
    sprintf(buffer, "img/%d.jpg", ind);

    return std::string(buffer);
}

std::string HelloWorld::convertJson(const int &ind, bool flag) {

    char buffer[3];
    if (flag) {
        sprintf(buffer, "%da", ind);
    } else {
        sprintf(buffer, "%d", ind);
    }

    return std::string(buffer);
}
