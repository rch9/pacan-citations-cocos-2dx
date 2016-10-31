#include "HelloWorldScene.h"
#include "editor-support/cocostudio/LocalizationManager.h"
#include "TouchableLabel.h"

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
    _isClicked = false;
    _currentIndex = 0;

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
    pageView->addEventListener(CC_CALLBACK_2(HelloWorld::pageViewEvent, this));
    this->addChild(pageView, 1, 0);
}

void HelloWorld::pageViewEvent(Ref *pSender, PageView::EventType type) {
    _isClicked = false;
}

void HelloWorld::fillLayout(Layout *layout, const int& ind) {

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

