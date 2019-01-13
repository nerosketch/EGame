/* 
 * File:   Player.cpp
 * Author: ns
 * 
 * Created on January 13, 2019, 2:08 AM
 */
#include "resources.h"
#include "Player.h"

Player::Player(const string& res_name) : Avatar(res_name),
_name(res_name)
{
    spTextField tx = new TextField;
    tx->setText(res_name);
    tx->setAnchor(0.5f, 0.5f);
    tx->setFont(res::resources.getResFont("SanasoftHermes"));
    tx->setColor(Color::BurlyWood);
    tx->setFontSize(14);
    tx->setPosition(getWidth() / 2, getHeight());
    addChild(tx);
}


Player::Player(const Player& o) : Avatar(o.getResAnim()->getName()),
_name(o._name), _angle(o._angle)
{}


Player::~Player()
{}


void Player::win()
{
    anim_win();
    logs::messageln("Player::win() name %s", _name.c_str());
}
