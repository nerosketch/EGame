/* 
 * File:   MainScene.cpp
 * Author: ns
 * 
 * Created on January 12, 2019, 11:03 PM
 */
#include "resources.h"
#include "MainScene.h"


MainScene::MainScene() :
arrow(new Sprite), run_btn(new TextButton("Крути!")),
_angle(0.f)
{}


MainScene::MainScene(const MainScene& o)
{}


MainScene::~MainScene()
{}


void MainScene::init()
{
    // Стрелка
    arrow->setResAnim(res::resources.getResAnim("arrow"));
    arrow->setAnchor(0.5f, 0.5f);
    arrow->setPosition(getSize() / 2);
    addChild(arrow);

    // Кнопка кручения
    run_btn->setPosition(20.f, 85.f);
    run_btn->addEventListener(TouchEvent::CLICK, CLOSURE(this, &MainScene::on_click_run));
    addChild(run_btn);
    
    // Добавим авки
    spPlayer niga = new Player("niga");
    _players.push_back(niga);
    spPlayer girl1 = new Player("girl1");
    _players.push_back(girl1);
    spPlayer girl2 = new Player("girl2");
    _players.push_back(girl2);
    spPlayer boy1 = new Player("boy1");
    _players.push_back(boy1);
    spPlayer mem1 = new Player("mem1");
    _players.push_back(mem1);

    const uint avs_count = _players.size();
    const float round = MATH_PI * 2;
    const float part = round / avs_count;
    float angle = 0.f;
    const Vector2& center_pos = arrow->getPosition();
    Vector2 r;
    
    for(spPlayer& player : _players)
    {
        // задаём радиус круга 240
        player->setPosition(
            center_pos.x + 240.f,
            center_pos.y
        );
        
        logs::messageln("player_angle=%.4f, name=%s",
                    angle, player->getName().c_str());

        // Распологаем авки вокруг центра
        r.x = center_pos.x + (player->getPosition().x - center_pos.x) * cos(angle) - (player->getPosition().y - center_pos.y) * sin(angle);
        r.y = center_pos.y + (player->getPosition().y - center_pos.y) * cos(angle) + (player->getPosition().x - center_pos.x) * sin(angle);
        player->setPosition(r);
        player->setAnglePos(angle);
        addChild(player);

        angle += part;
    }

}


void MainScene::on_click_run(Event*)
{
    logs::messageln("MainScene::click_run");

    _angle = scalar::randFloat(0.f, (MATH_PI*2.f)*8);

    arrow->addTween(Sprite::TweenRotation(_angle), 5000, 1, false, 0, Tween::ease_inOutBounce)
        ->setDoneCallback(CLOSURE(this, &MainScene::on_speen_done));
}


void MainScene::on_speen_done(Event*)
{
    // Устанавливаем угол поворота стрелки такой, на котором закончилась анимация
    const float one_round = MATH_PI*2.f;
    float arrow_angle;
    if(_angle > one_round)
    {
        const int loop_count = _angle / one_round;
        arrow_angle = _angle - loop_count * one_round;
        logs::messageln("rAngle: %.3f", arrow_angle);
    }
    else
    {
        arrow_angle = _angle;
        logs::messageln("Angle: %.3f", _angle);
    }
    arrow->setRotation(arrow_angle);

    // Выясняем кто победил
    // Сравниваем угол поворота стрелки с углом положения игрока
    const float part = one_round / _players.size();

    for(spPlayer& player : _players)
    {
        const float player_angle = player->getAnglePos();
        const float a = player_angle - part / 2;
        const float b = player_angle + part / 2;

        if(arrow_angle > a && arrow_angle < b)
        {
            logs::messageln("a=%.4f, b=%.4f, player_angle=%.4f, arrow_angle=%.4f",
                    a, b, player_angle, arrow_angle);
            player->win();
            break;
        }
    }

}
