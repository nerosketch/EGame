/* 
 * File:   MainScene.cpp
 * Author: ns
 * 
 * Created on January 12, 2019, 11:03 PM
 */
#include "resources.h"
#include "AddPlayerScene.h"
#include "MainScene.h"
#include "SceneTasks.h"
#include "Player.h"


MainScene::MainScene() :
arrow(new Sprite), rulet(new Sprite),
_angle(0.f)
{}


MainScene::MainScene(const MainScene& o)
{}


MainScene::~MainScene()
{}


void MainScene::init()
{
    //setResAnim(res::resources.getResAnim("rulet"));

    // Фон слева
    spSprite li = new Sprite;
    li->setResAnim(res::resources.getResAnim("ftop.ru_587dd65125936"));
    li->setScale(getHeight() / li->getHeight() * 0.8f);
    li->setPosition(0.f, getHeight()/2 - li->getScaledHeight()/2);
    addChild(li);
    // Фон справа
    spSprite ri = new Sprite;
    ri->setResAnim(res::resources.getResAnim("89795"));
    //ri->setAnchor(0.5f, 0.5f);
    ri->setScale(getHeight() / ri->getHeight() * 0.7f);
    ri->setPosition(getWidth() - ri->getScaledWidth(), getHeight()/2 - ri->getScaledHeight()/2);
    addChild(ri);

    // Фон в центре под стрелкой
    rulet->setAnchor(0.5f, 0.5f);
    rulet->setResAnim(res::resources.getResAnim("rulet"));
    rulet->setPosition(getSize() / 2);
    addChild(rulet);

    // Стрелка
    arrow->setResAnim(res::resources.getResAnim("arrow"));
    arrow->setAnchor(0.5f, 0.5f);
    arrow->setPosition(rulet->getSize() / 2.f);
    rulet->addChild(arrow);

    // Кнопка кручения
    spTextButton run_btn = new TextButton("Крути!");
    run_btn->setPosition(20.f, 85.f);
    run_btn->addEventListener(TouchEvent::CLICK, CLOSURE(this, &MainScene::on_click_run));
    addChild(run_btn);

    // Кнопка диалога добавления игрока
    spTextButton add_player_btn = new TextButton("Игроки");
    add_player_btn->setPosition(20.f, 140.f);
    add_player_btn->addEventListener(TouchEvent::CLICK, CLOSURE(this, &MainScene::on_add_player));
    addChild(add_player_btn);

    // Кнопка диалога добавления вопроса
    spTextButton add_question_btn = new TextButton("Вопросы");
    add_question_btn->setPosition(20.f, 195.f);
    add_question_btn->addEventListener(TouchEvent::CLICK, CLOSURE(this, &MainScene::on_add_question));
    addChild(add_question_btn);

}


void MainScene::on_click_run(Event*)
{
#ifdef DBG
    logs::messageln("MainScene::click_run");
#endif

    _angle = scalar::randFloat(0.f, (MATH_PI*2.f)*8);

    arrow->addTween(Sprite::TweenRotation(_angle), 5000, 1, false, 0, Tween::ease_inOutBounce)
        ->setDoneCallback(CLOSURE(this, &MainScene::on_speen_done));

    rulet->addTween(Sprite::TweenRotation(-MATH_PI*4.f), 5000, 1, false, 0, Tween::ease_outQuad)
        ->setDoneCallback([&](Event*)
        {
            rulet->setRotation(0.f);
        });
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
    }
    else
    {
        arrow_angle = _angle;
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
            player->win();
            break;
        }
    }

}


void MainScene::on_add_player(Event*)
{
    spAddPlayerScene ap = new AddPlayerScene;
    ap->init();
    //ap->setAnchor(0.5f, 0.5f);
    //ap->setPosition(getPosition()/2);
    //ap->setPosition(90.f, 70.f);
    //ap->setSize(getSize() * 0.7f);
    ap->setDoneCallback(CLOSURE(this, &MainScene::on_add_player_done));
    addChild(ap);
}


void MainScene::on_add_player_done(spObject& ob)
{
    logs::messageln("::Player done");

    spPlayer new_player = safeSpCast<Player>(ob);

    _players.push_back(new_player);

    const uint avs_count = _players.size();
    const float round = MATH_PI * 2;
    const float part = round / avs_count;
    float angle = 0.f;
    const Vector2& center_pos = rulet->getPosition();
    Vector2 r;
    
    for(spPlayer& player : _players)
    {
        // задаём радиус круга 240
        player->setPosition(
            center_pos.x + 320.f,
            center_pos.y
        );

        // Распологаем авки вокруг центра
        r.x = center_pos.x + (player->getPosition().x - center_pos.x) * cos(angle) - (player->getPosition().y - center_pos.y) * sin(angle);
        r.y = center_pos.y + (player->getPosition().y - center_pos.y) * cos(angle) + (player->getPosition().x - center_pos.x) * sin(angle);
        player->setPosition(r);
        player->setAnglePos(angle);
        addChild(player);

        angle += part;
    }
}


void MainScene::on_add_question(Event*)
{
    spSceneTasks st = new SceneTasks;
    st->init();
    //at->setPosition(90.f, 70.f);
    st->setDoneCallback(CLOSURE(this, &MainScene::on_add_question_done));
    addChild(st);
}


void MainScene::on_add_question_done(spObject&)
{
    logs::messageln("::Question done");
}
