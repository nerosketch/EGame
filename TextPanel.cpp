/* 
 * File:   TextPanel.cpp
 * Author: ns
 * 
 * Created on October 21, 2018, 8:44 AM
 */

#include "resources.h"
#include "TextPanel.h"


#define TILE_WIDTH 16.f
#define TILE_HEIGHT 16.f


TextPanel::TextPanel() : text_field(new TextField),
ok_btn(new Button)
{
    TextField::setDefaultFont(res::resources.getResFont("SanasoftHermes"));
    setResAnim(res::resources.getResAnim("panel"));
    setGuides(TILE_WIDTH, TILE_WIDTH, TILE_HEIGHT, TILE_HEIGHT);

}


TextPanel::TextPanel(const TextPanel& o)
{
}


TextPanel::~TextPanel()
{
}


void TextPanel::init(const string& text)
{
    //text_field->setAlign(TextStyle::VerticalAlign::VALIGN_BASELINE, TextStyle::HorizontalAlign::HALIGN_LEFT);
    text_field->setPosition(10.f, 10.f);
    text_field->setColor(Color::Thistle);
    text_field->setFontSize(14);
    text_field->setMultiline(true);
    text_field->setWidth(180.f);
    addChild(text_field);

    // Ok button
    ok_btn->setResAnim(res::resources.getResAnim("close_button"));
    ok_btn->setPosition(50.f, 20.f);
    ok_btn->addEventListener(TouchEvent::CLICK, CLOSURE(this, &TextPanel::_kill_me));
    addChild(ok_btn);

    setText(text);
}


void TextPanel::sizeChanged(const Vector2& size)
{
    Box9Sprite::sizeChanged(size);

    if(ok_btn)
    {
        ok_btn->setX(size.x - 13.f);
        ok_btn->setY(-4.f);
    }
}


void TextPanel::setText(const string& text)
{
    text_field->setText(text);

    RectF b;
    text_field->getBounds(b);

    //setPosition(b.pos);
    b.size.x += TILE_WIDTH * 2.f;
    b.size.y += TILE_HEIGHT * 2.f;
    setSize(b.size);
}


void TextPanel::setTimeToLive(const uint ttl)
{
#ifdef DBG
    logs::messageln("TextPanel::setTimeToLive");
#endif

    spTween _delay_timeout_tween = addTween(TweenDummy(), ttl);
    _delay_timeout_tween->setDoneCallback(CLOSURE(this, &TextPanel::_kill_me));
}

void TextPanel::_kill_me(Event* ev)
{
#ifdef DBG
    logs::messageln("TextPanel::_on_die_event");
#endif

    detach();

    if(_die_event)
        _die_event(ev);
}


void TextPanel::setOnDieEvent(const EventCallback& ev)
{
    _die_event = ev;
}
