#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

    void onTextClicked(Ref *sender);

//    void pageViewEvent(Ref *pSender, cocos2d::ui::PageView::EventType type);
    void pageViewEvent(Ref *pSender, cocos2d::ui::PageView::EventType type);
    void onButtonClicked(Ref *sender, cocos2d::ui::Widget::TouchEventType type);
private:
    void initPageView();
//    void pageViewEvent();
    void fillLayout(cocos2d::ui::Layout* layout, const int &i);
    std::string convertInt(const int &i);
    bool _isClicked;
    int _currentIndex;
    std::string convertJson(int i, bool flag);
};

#endif // __HELLOWORLD_SCENE_H__
