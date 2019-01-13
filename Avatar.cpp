/* 
 * File:   Avatar.cpp
 * Author: ns
 * 
 * Created on January 13, 2019, 12:53 AM
 */

#include "resources.h"
#include "Avatar.h"


Avatar::Avatar(const string& res_name)
{
    setResAnim(res::resources.getResAnim(res_name));
    addEventListener(TouchEvent::OVER, CLOSURE(this, &Avatar::_on_hover));
    addEventListener(TouchEvent::OUTX, CLOSURE(this, &Avatar::_on_outx));
    setAnchor(0.5f, 0.5f);
}


Avatar::Avatar(const Avatar& o)
{}


Avatar::~Avatar()
{}


void Avatar::_on_hover(Event*)
{
    addTween(Actor::TweenScale(1.4f), 40);
}


void Avatar::_on_outx(Event*)
{
    //removeTweens();
    addTween(Actor::TweenScale(1.f), 40);
}


void Avatar::anim_win()
{
    addTween(Actor::TweenRotation(MATH_PI*4), 2000)
            ->setDoneCallback(CLOSURE(this, &Avatar::_on_anim_win_done));
}

void Avatar::_on_anim_win_done(Event*)
{
    setRotation(0.f);
}
