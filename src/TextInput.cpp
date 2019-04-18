/* 
 * File:   TextInput.cpp
 * Author: ns
 * 
 * Created on January 13, 2019, 11:12 AM
 */

#include "TextInput.h"
#include "resources.h"


TextInput::TextInput() :
_text(new TextField), _input(new InputText)
{
    TextField::setDefaultFont(res::resources.getResFont("SanasoftHermes"));
    _text->setFont(res::resources.getResFont("SanasoftHermes"));
    setResAnim(res::resources.getResAnim("panel"));
    setGuides(16.f, 16.f, 16.f, 16.f);
    setHeight(35.f);
}


TextInput::TextInput(const TextInput& o)
{}


TextInput::~TextInput()
{}


void TextInput::init()
{
    _text->setFontSize(16);
    _text->setPosition(10.f, 8.f);
    _text->setText("Кликни для ввода");
    _text->setColor(Color::Black);
    setWidth(_text->getTextRect().size.x + 32.f);
    _text->setWidth(getWidth());

    _input->addEventListener(Event::COMPLETE, [&](Event*)
    {
#ifdef DBG
        logs::messageln("stopAnyInput");
#endif
        _input->stopAnyInput();
    });

    _input->addEventListener(InputText::EVENT_TEXT_CHANGED, CLOSURE(this, &TextInput::_on_text_changed));

    addEventListener(TouchEvent::CLICK, [&](Event*)
    {
#ifdef DBG
        logs::messageln("Start input");
#endif
        _input->start(_text);
    });

    addChild(_text);
}


void TextInput::_on_text_changed(Event*)
{
    //p_kev->data->keysym.scancode
    const Rect& r = _text->getTextRect();
    
    if(r.size.x > 0)
        setWidth(r.size.x + 32.f);
    else
        setWidth(48.f);
    
    if(r.size.y > 0)
        setHeight(r.size.y + 22.f);
    else
        setHeight(16.f);
}
