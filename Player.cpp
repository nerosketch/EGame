/* 
 * File:   Player.cpp
 * Author: ns
 * 
 * Created on January 13, 2019, 2:08 AM
 */
#include "resources.h"
#include "Player.h"
#include "SoundManager.h"


Player::Player(const string& res_name, const string& voice) : Avatar(res_name),
_name(res_name), _angle(0.f), _tx(new TextField),
#ifdef SOUND_ENABLE
_voice(voice)
#endif
{
    TextField::setDefaultFont(res::resources.getResFont("SanasoftHermes"));
    _tx->setText(res_name);
    _tx->setAnchor(0.5f, 0.5f);
    _tx->setColor(Color::BurlyWood);
    _tx->setFontSize(14);
    _tx->setPosition(getWidth() / 2, getHeight());
    addChild(_tx);
}


Player::Player(const Player& o) : Avatar(o.getResAnim()->getName()),
_name(o._name), _angle(o._angle)
{}


Player::~Player()
{}


void Player::win()
{
#ifdef DBG
    logs::messageln("Player::win() name %s", _name.c_str());
#endif

    anim_win();

#ifdef SOUND_ENABLE
    SoundManager& sm = SoundManager::get_instance();
    sm.play_from_name(_voice);
#endif
}









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
