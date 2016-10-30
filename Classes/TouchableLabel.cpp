#include "TouchableLabel.h"
#include "editor-support/cocostudio/LocalizationManager.h"

USING_NS_CC;
using namespace ui;


bool TouchableLabel::init(const char *path, const char *key1, const char *key2) {
    _key1 = key1;
    _key2 = key2;
    _isClicked = false;

    setContentSize(Size(800, 1400));

    auto imageView = ImageView::create(path);
    imageView->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
    imageView->setPosition(Vec2(0, 1400));
    this->addChild(imageView);

    auto label = Label::createWithTTF(cocostudio::JsonLocalizationManager::getInstance()->getLocalizationString(_key1), "fonts/helios.ttf", 100);
    label->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    label->setPosition(Vec2(_contentSize.width / 2, 300));
    label->setWidth(700);
    label->setAlignment(TextHAlignment::CENTER);

    auto btn = Button::create("bg.jpg", "bg.jpg");
    btn->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
    btn->setPosition(Vec2(0, 0));
    btn->addTouchEventListener(CC_CALLBACK_2(TouchableLabel::onButtonClicked, this));
    this->addChild(label, 1, 0);
    this->addChild(btn, 0);

    return true;
}

TouchableLabel* TouchableLabel::create(const char *path, const char *key1, const char *key2) {
    TouchableLabel* layout = new (std::nothrow) TouchableLabel();
    if (layout && layout->init(path, key1, key2)) {
        layout->autorelease();
        return layout;
    }
    CC_SAFE_DELETE(layout);
    return nullptr;
}

void TouchableLabel::onButtonClicked(Ref* sender, Widget::TouchEventType type) {
    if (type == Widget::TouchEventType::ENDED) {
        _isClicked = !_isClicked;
        auto label = static_cast<Label*>(this->getChildByTag(0));
        if (_isClicked) {
            label->setString(cocostudio::JsonLocalizationManager::getInstance()->getLocalizationString(_key2));
    //            label->set
            label->setTTFConfig(TTFConfig("fonts/helios.ttf", 50));
        } else {
            label->setString(cocostudio::JsonLocalizationManager::getInstance()->getLocalizationString(_key1));
            label->setTTFConfig(TTFConfig("fonts/helios.ttf", 100));
        }
    }
}

const std::string &TouchableLabel::getKey1() const {
    return _key1;
}

const std::string &TouchableLabel::getKey2() const {
    return _key2;
}

void TouchableLabel::setKey12(const char *key1, const char *key2) {
    _key1 = key1;
    _key2 = key2;
}

