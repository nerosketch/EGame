/* 
 * File:   Dialog.cpp
 * Author: ns
 * 
 * Created on January 15, 2019, 12:08 AM
 */

#include "resources.h"
#include "TextButton.h"
#include "Dialog.h"


Dialog::Dialog() : tech_panel_bot(new Sprite), tech_panel_top(new Sprite),
tech_panel_top_line(new Sprite), tech_panel_c1(new Sprite), tech_panel_c2(new Sprite),
tech_panel_c3(new Sprite)
{}


Dialog::Dialog(const Dialog&)
{}


Dialog::~Dialog()
{}


void Dialog::init()
{
    //setResAnim(res::resources.getResAnim("panel_b"));
    setSize(getStage()->getSize());
    setColor(Color::Zero);

    // кнопка закрытия
    spButton close_btn = new Button;
    close_btn->setResAnim(res::resources.getResAnim("close_button"));
    close_btn->setPosition(getWidth() - close_btn->getWidth(), 0.f);
    close_btn->addEventListener(TouchEvent::CLICK, CLOSURE(this, &Dialog::_on_close_click));
    addChild(close_btn);

    // Анимация открытия
    //setScale(0.f);
    addTween(Sprite::TweenColor(0x101010de), 900, 1, false, 0, Tween::ease_outQuad);;

    tech_panel_bot->setResAnim(res::resources.getResAnim("tech_panel_bot"));
    tech_panel_bot->setPosition(
        -tech_panel_bot->getWidth(),
        getHeight() - tech_panel_bot->getHeight() - 25.f
    );
    tech_panel_bot->addTween(Sprite::TweenPosition(0.f, getHeight() - tech_panel_bot->getHeight() - 25.f), 1200, 1, false, 0, Tween::ease_outInCubic);
    addChild(tech_panel_bot);

    tech_panel_top->setResAnim(res::resources.getResAnim("tech_panel_top"));
    tech_panel_top->setPosition(
        getWidth(),
        45.f
    );
    tech_panel_top->addTween(Sprite::TweenPosition(10.f, 45.f), 1500, 1, false, 0, Tween::ease_outQuad);
    addChild(tech_panel_top);

    tech_panel_top_line->setResAnim(res::resources.getResAnim("tech_panel_top_line"));
    tech_panel_top_line->setPosition(
        -tech_panel_top_line->getWidth(),
        25.f
    );
    tech_panel_top_line->addTween(Sprite::TweenPosition(10.f, 25.f), 2300, 1, false, 0, Tween::ease_outQuad);
    addChild(tech_panel_top_line);

    const Vector2 c_pos(getWidth() - 155, getHeight() - 205);
    tech_panel_c1->setResAnim(res::resources.getResAnim("tech_panel_c1"));
    tech_panel_c1->setAnchor(0.5f, 0.5f);
    tech_panel_c1->setPosition(c_pos);
    tech_panel_c1->addTween(Sprite::TweenRotation(MATH_PI * 1), 1000, 1, false, 0, Tween::ease_outQuad);
    addChild(tech_panel_c1);

    tech_panel_c2->setResAnim(res::resources.getResAnim("tech_panel_c2"));
    tech_panel_c2->setAnchor(0.5f, 0.5f);
    tech_panel_c2->setPosition(c_pos);
    tech_panel_c2->addTween(Sprite::TweenRotation(-MATH_PI * 2), 1000, 1, false, 0, Tween::ease_outQuad);
    addChild(tech_panel_c2);

    tech_panel_c3->setResAnim(res::resources.getResAnim("tech_panel_c3"));
    tech_panel_c3->setAnchor(0.5f, 0.5f);
    tech_panel_c3->setPosition(c_pos);
    tech_panel_c3->addTween(Sprite::TweenRotation(MATH_PI * 2), 2000, 1, false, 0, Tween::ease_outQuad);
    addChild(tech_panel_c3);


    // Кнопка ОК
    spTextButton ok_btn = new TextButton("ОК");
    ok_btn->addEventListener(TouchEvent::CLICK, CLOSURE(this, &Dialog::on_ok_click));
    ok_btn->setAnchor(0.5f, 0.5f);
    ok_btn->setPosition(getWidth() / 2.f, getHeight() - ok_btn->getHeight());
    addChild(ok_btn);
}


void Dialog::_on_close_click(Event*)
{
    addTween(TweenQueue::create(
        createTween(TweenDummy(), 1000),
        createTween(Sprite::TweenColor(Color::Zero), 400, 1, false, 0, Tween::ease_outQuad))
    )
    ->setDoneCallback([&](Event*)
    {
        detach();
    });

    tech_panel_bot->addTween(Sprite::TweenPosition(
        -tech_panel_bot->getWidth(),
        getHeight() - tech_panel_bot->getHeight() - 25.f
    ), 1200, 1, false, 0, Tween::ease_outInCubic);

    tech_panel_top->addTween(Sprite::TweenPosition(
        getWidth(),
        45.f
    ), 1500, 1, false, 0, Tween::ease_outQuad);

    tech_panel_top_line->addTween(Sprite::TweenPosition(
        -tech_panel_top_line->getWidth(),
        25.f
    ), 2300, 1, false, 0, Tween::ease_outQuad);

    spSprite sprites[] = {
        tech_panel_c1,
        tech_panel_c2,
        tech_panel_c3
    };
    for(const spSprite& spr : sprites)
    {
        spr->addTween(Sprite::TweenRotation(0.f), 1000, 1, false, 0, Tween::ease_outQuad)
            ->setDoneCallback([&, spr](Event*){
                const Vector2 c_pos(getWidth() * 1.5f, getHeight() - 205.f);
                spr->setPriority(1);
                spr->addTween(Sprite::TweenPosition(c_pos), 1000, 1, false, 0, Tween::ease_outQuad);
            });
    }
    

}


void Dialog::on_ok_click(Event* ev)
{
    spObject sob(static_cast<oxygine::Object*>(ev->userData));
    if(_dc)
        _dc(sob);
}
