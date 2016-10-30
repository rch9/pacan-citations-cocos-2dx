#ifndef TOUCHABLELABEL_H
#define TOUCHABLELABEL_H

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class TouchableLabel : public cocos2d::ui::Layout {
public:
    bool init(const char *path, const char *key1, const char *key2);

    static TouchableLabel* create(const char *path, const char *key1, const char *key2);


    const std::string &getKey1() const;
    const std::string &getKey2() const;
    void setKey12(const char *key1, const char *key2);

    void onButtonClicked(Ref *sender, cocos2d::ui::Widget::TouchEventType type);
private:
    std::string _key1;
    std::string _key2;
    bool _isClicked;
};

#endif // TOUCHABLELABEL_H
