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

    addEventListener(TouchEvent::OVER, [&](Event*)
    {
        addTween(Actor::TweenScale(1.4f), 40);
    });

    addEventListener(TouchEvent::OUTX, [&](Event*)
    {
        addTween(Actor::TweenScale(1.f), 40);
    });

    setAnchor(0.5f, 0.5f);
}


Avatar::Avatar(const Avatar& o)
{}


Avatar::~Avatar()
{}


void Avatar::anim_win()
{
    addTween(Actor::TweenRotation(MATH_PI*4), 2000)
            ->setDoneCallback([&](Event*)
            {
                setRotation(0.f);
            });
}
