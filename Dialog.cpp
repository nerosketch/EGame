/* 
 * File:   Dialog.cpp
 * Author: ns
 * 
 * Created on January 15, 2019, 12:08 AM
 */

#include "resources.h"
#include "TextButton.h"
#include "Dialog.h"


Dialog::Dialog()
{
    setResAnim(res::resources.getResAnim("panel_b"));
    setSize(744.f, 370.f);

    // кнопка закрытия
    spButton close_btn = new Button;
    close_btn->setResAnim(res::resources.getResAnim("close_button"));
    close_btn->setPosition(getWidth() - close_btn->getWidth(), 0.f);
    close_btn->addEventListener(TouchEvent::CLICK, CLOSURE(this, &Dialog::_on_close_click));
    addChild(close_btn);

    // Анимация открытия
    setScale(0.f);
    addTween(Sprite::TweenScale(1.f), 300, 1, false, 0, Tween::ease_outQuad);

    // Кнопка ОК
    spTextButton ok_btn = new TextButton("ОК");
    ok_btn->addEventListener(TouchEvent::CLICK, CLOSURE(this, &Dialog::on_ok_click));
    ok_btn->setAnchor(0.5f, 0.5f);
    ok_btn->setPosition(getWidth() / 2.f, getHeight() - ok_btn->getHeight());
    addChild(ok_btn);
}


Dialog::Dialog(const Dialog&)
{
}


Dialog::~Dialog()
{
}


void Dialog::_on_close_click(Event*)
{
    addTween(Sprite::TweenScale(0.f), 300, 1, false, 0, Tween::ease_outQuad)
        ->setDoneCallback([&](Event*)
        {
            detach();
        });
}


void Dialog::on_ok_click(Event* ev)
{
    logs::messageln("user ptr %p", ev->userData);

    spObject sob(static_cast<oxygine::Object*>(ev->userData));
    if(_dc)
        _dc(sob);
}
