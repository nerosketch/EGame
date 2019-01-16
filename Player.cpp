/* 
 * File:   Player.cpp
 * Author: ns
 * 
 * Created on January 13, 2019, 2:08 AM
 */
#include "resources.h"
#include "Player.h"


Player::Player(const string& res_name) : Avatar(res_name),
_name(res_name), _angle(0.f), _tx(new TextField)
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
}
