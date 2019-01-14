/* 
 * File:   AddPlayerScene.cpp
 * Author: ns
 * 
 * Created on January 13, 2019, 3:21 AM
 */

#include "AddPlayerScene.h"
#include "resources.h"
#include "Player.h"
#include "TextButton.h"


const char* ava_names[] = {"niga", "girl1", "girl2", "boy1", "mem1"};


AddPlayerScene::AddPlayerScene() : _ava_im(new Sprite),
_current_ava(0), text_inp_name(new TextInput)
{
    setResAnim(res::resources.getResAnim("panel_b"));
    setSize(744.f, 370.f);

    // кнопка закрытия
    spButton close_btn = new Button;
    close_btn->setResAnim(res::resources.getResAnim("close_button"));
    close_btn->setPosition(getWidth() - close_btn->getWidth(), 0.f);
    close_btn->addEventListener(TouchEvent::CLICK, CLOSURE(this, &AddPlayerScene::_on_die));
    addChild(close_btn);

    // Текст заголовок
    spTextField title = new TextField;
    title->setText("Добавить игрока");
    title->setPosition(getWidth() / 2.f - 80.f, 15.f);
    title->setFontSize(24);
    title->setColor(Color::Crimson);
    addChild(title);

    // Ввод имени
    spTextField text_input_name = new TextField;
    text_input_name->setText("Впиши своё имя");
    text_input_name->setPosition(25.f, 70.f);
    text_input_name->setFontSize(21);
    text_input_name->setColor(Color::BlanchedAlmond);
    addChild(text_input_name);
    // Тут хранится текст
    text_inp_name->setPosition(175.f, 67.f);
    addChild(text_inp_name);

    // Спрайт для выбора авки
    _ava_im->setResAnim(res::resources.getResAnim(ava_names[_current_ava]));
    const float y_pos = getHeight() / 2;
    _ava_im->setAnchor(0.5f, 0.5f);
    _ava_im->setPosition(getWidth() / 2, y_pos);
    addChild(_ava_im);
    // кнопка выбора левого спрайта
    spButton select_left_ava = new Button;
    select_left_ava->setAnchor(0.5f, 0.5f);
    select_left_ava->setResAnim(res::resources.getResAnim("play_btn"));
    select_left_ava->setFlippedX(true);
    select_left_ava->setPosition(getWidth() / 2.f - 90, y_pos);
    select_left_ava->addEventListener(TouchEvent::CLICK, CLOSURE(this, &AddPlayerScene::_on_select_left));
    addChild(select_left_ava);
    // кнопка выбора правого спрайта
    spButton select_right_ava = new Button;
    select_right_ava->setAnchor(0.5f, 0.5f);
    select_right_ava->setResAnim(res::resources.getResAnim("play_btn"));
    select_right_ava->setPosition(getWidth() / 2.f + 90.f, y_pos);
    select_right_ava->addEventListener(TouchEvent::CLICK, CLOSURE(this, &AddPlayerScene::_on_select_right));
    addChild(select_right_ava);
    
    // Кнопка ОК
    spTextButton ok_btn = new TextButton("ОК");
    ok_btn->addEventListener(TouchEvent::CLICK, CLOSURE(this, &AddPlayerScene::_on_ok_click));
    ok_btn->setAnchor(0.5f, 0.5f);
    ok_btn->setPosition(getWidth() / 2.f, getHeight() - ok_btn->getHeight());
    addChild(ok_btn);
}


AddPlayerScene::AddPlayerScene(const AddPlayerScene& o)
{}


AddPlayerScene::~AddPlayerScene()
{}


void AddPlayerScene::_on_die(Event*)
{
    detach();
}


void AddPlayerScene::_on_select_left(Event*)
{
    logs::messageln("AddPlayerScene::_on_select_left");
    _current_ava--;
    _round_current_ava();
    _ava_im->setResAnim(res::resources.getResAnim(ava_names[_current_ava]));
}


void AddPlayerScene::_on_select_right(Event*)
{
    logs::messageln("AddPlayerScene::_on_select_right");
    _current_ava++;
    _round_current_ava();
    _ava_im->setResAnim(res::resources.getResAnim(ava_names[_current_ava]));
}


void AddPlayerScene::_round_current_ava()
{
    if(_current_ava > 4)
        _current_ava = 0;
    else if(_current_ava < 0)
        _current_ava = 4;
}


void AddPlayerScene::_on_ok_click(Event*)
{
    logs::messageln("AddPlayerScene::_on_ok_click");

    spPlayer player = new Player(ava_names[_current_ava]);
    player->setName(text_inp_name->getText());

    Player::addPlayerGlobal(player);
    detach();
}
