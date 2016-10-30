#include "TouchableLabel.h"
#include "editor-support/cocostudio/LocalizationManager.h"

USING_NS_CC;
using namespace ui;


bool TouchableLabel::init() {
    _key1 = "";
    _key2 = "";
    _isClicked = false;

    setContentSize(Size(800, 1400));

    auto imageView = ImageView::create("img/1.jpg");
    imageView->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
    imageView->setPosition(Vec2(0, 1400));
    this->addChild(imageView);

    auto label = Label::createWithTTF("none", "fonts/helios.ttf", 100);
    label->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    label->setPosition(Vec2(_contentSize.width / 2, _contentSize.height / 2));
    label->setWidth(800);
    label->setAlignment(TextHAlignment::CENTER);

    auto btn = Button::create("bg.jpg", "bg.jpg");
    btn->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
    btn->setPosition(Vec2(0, 0));
    btn->addTouchEventListener(CC_CALLBACK_2(TouchableLabel::onButtonClicked, this));
    this->addChild(label, 1, 0);
    this->addChild(btn, 0);

    return true;
}

void TouchableLabel::onButtonClicked(Ref* sender, Widget::TouchEventType type) {
    if (type == Widget::TouchEventType::ENDED) {
        _isClicked = !_isClicked;
        auto label = static_cast<Label*>(this->getChildByTag(0));
        if (_isClicked) {
            label->setString(cocostudio::JsonLocalizationManager::getInstance()->getLocalizationString(_key1));
        } else {
            label->setString(cocostudio::JsonLocalizationManager::getInstance()->getLocalizationString(_key2));
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

