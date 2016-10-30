#include "HelloWorldScene.h"

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


    initPageView();

    return true;
}

void HelloWorld::onTextClicked(Ref *sender) {
    //    auto parent =  this->getChildByTag(0);
    //    auto text = RichElementText)
    //    if (_isClicked) {

    //    } else {

    //    }
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

        pageView->insertCustomItem(layout, i);
    }

//    pageView->addEventListener(CC_CALLBACK_2(HelloWorld::pageViewEvent, this));
    this->addChild(pageView, 1, 0);
}

void HelloWorld::pageViewEvent(Ref *pSender) {
//    if (type == PageView::EventType::TURNING) {
////        auto pageView = dynamic_cast<PageView*>(pSender);
////        addPageViewInCurLayoutAndRemoveOldPageView(pageView);
//        CCLOG("aaaa1");
//    } else {
//        CCLOG("aaaa");
//    }
}

void HelloWorld::fillLayout(Layout *layout, const int& i) {
    auto imageView = ImageView::create("26.jpg");
    imageView->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
    imageView->setPosition(Vec2(0, 1400));
    imageView->addClickEventListener(CC_CALLBACK_1(HelloWorld::onTextClicked, this));
    layout->addChild(imageView);


//    layout->setOnEnterCallback(CC_CALLBACK_2(HelloWorld::pageViewEvent, this));

//    layout->addClickEventListener(CC_CALLBACK_2(this, HelloWorld::pageViewEvent));

//    Button::create()->setContentSize();
//    Button.setTEx

//    layout->onTouchBegan()

    Label* label = Label::createWithTTF("НИКОГДА\nНЕ\nОПАЗДЫВАЙ", "fonts/helios.ttf", 100);
    label->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    label->setPosition(Vec2(layout->getContentSize().width / 2, layout->getContentSize().height / 4));
    label->setLocalZOrder(10);
    label->setWidth(800);
    label->setAlignment(TextHAlignment::CENTER);

//    auto listener1 = EventListenerTouchOneByOne::create();

//    // trigger when you push down
//    listener1->onTouchBegan = [=](Touch* touch, Event* event){
//        // your code
//        return true; // if you are consuming it
//    };

//    // trigger when moving touch
//    listener1->onTouchMoved = [=](Touch* touch, Event* event){
//        // your code
//    };

//    // trigger when you let up
//    listener1->onTouchEnded = [=](Touch* touch, Event* event){
//        // your code
//    };

//    label->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener1, this);




    layout->addChild(label);

}

//void HelloWorld::addPageViewInCurLayoutAndRemoveOldPageView(PageView *pageView) {
//    pageView->getItem(pageView->getCurrentPageIndex() - 1)->removeChildByTag(0, true);
//    auto layout = static_cast<Layout*>(pageView->getCurrentFocusedWidget());
//    addPageViewInLayout(layout);
//}

//        auto text = Text::create("Важно никогда не опаздывать.\nЗаранее продумайте план, как добраться до места\nвстречи.\nСтарайтесь быть к назначенному времени", "fonts/arial.ttf", 44);
//        Label* text = Label::createWithTTF("НИКОГДА НЕ ОПАЗДЫВАЙ", "fonts/helios.ttf", 100);
//        text->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
//        text->setPosition(Vec2(layout->getContentSize().width / 2, layout->getContentSize().height / 4));
//        text->setLocalZOrder(10);
//        //        text->setLineBreakWithoutSpace(true);
//        text->setWidth(800);
//        text->setAlignment(TextHAlignment::LEFT);
//        //        text->setAdditionalKerning(2);
//
//        layout->addChild(text);
