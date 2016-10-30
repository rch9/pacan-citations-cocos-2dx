#include "HelloWorldScene.h"
#include "editor-support/cocostudio/LocalizationManager.h"


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

    cocostudio::JsonLocalizationManager::getInstance()->initLanguageData("text/ru-RU.lang.json");

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

    int pageCount = 30;
    for (int i = 0; i < pageCount; ++i) {
        Layout* layout = Layout::create();
        layout->setContentSize(size);

        fillLayout(layout, i);

        pageView->pushBackCustomItem(layout);
    }
    pageView->addEventListener(CC_CALLBACK_2(HelloWorld::pageViewEvent, this));
    this->addChild(pageView, 1, 0);
}

void HelloWorld::pageViewEvent(Ref *pSender, PageView::EventType type) {
    _isClicked = false;
}

void HelloWorld::fillLayout(Layout *layout, const int& i) {

    auto imageView = ImageView::create(convertInt(i));
    imageView->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
    imageView->setPosition(Vec2(0, 1400));
    layout->addChild(imageView);

    auto label = Label::createWithTTF("НИКОГДА\nНЕ\nОПАЗДЫВАЙ", "fonts/helios.ttf", 100);
    label->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    label->setPosition(Vec2(layout->getContentSize().width / 2, layout->getContentSize().height / 4));
    label->setWidth(800);
    label->setAlignment(TextHAlignment::CENTER);

    auto btn = Button::create("bg.jpg", "bg.jpg");
    btn->setContentSize(Size(800, 600));
    btn->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
    btn->setPosition(Vec2(0, 0));
    btn->addTouchEventListener(CC_CALLBACK_2(HelloWorld::onButtonClicked, this));
    layout->addChild(label, 1, 0);
    layout->addChild(btn, 0);
}
//LanguageType currentLanguageType = Application::getInstance()->getCurrentLanguage();

void HelloWorld::onButtonClicked(Ref* sender, Widget::TouchEventType type) {
    if (type == Widget::TouchEventType::ENDED) {
        _isClicked = !_isClicked;
        auto layout = static_cast<Layout*>(dynamic_cast<Button*>(sender)->getParent());
        auto label = static_cast<Label*>(layout->getChildByTag(0));
        label->setString(convertJson(1, _isClicked));
    }
}

std::string HelloWorld::convertInt(const int &i) {
    char buffer[10];
    sprintf(buffer, "img/%d.jpg", i + 1);

    return std::string(buffer);
}

std::string HelloWorld::convertJson(int i, bool flag) {

    char buffer[3];
    if (flag) {
        sprintf(buffer, "%da", i + 1);
    } else {
        sprintf(buffer, "%d", i + 1);
    }

    return cocostudio::JsonLocalizationManager::getInstance()->getLocalizationString(buffer);
}

