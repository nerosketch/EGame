/* 
 * File:   Dialog.cpp
 * Author: ns
 * 
 * Created on January 15, 2019, 12:08 AM
 */

#include "resources.h"
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
        ->setDoneCallback(CLOSURE(this, &Dialog::_on_die));
}

void Dialog::_on_die(Event*)
{
    detach();
}
