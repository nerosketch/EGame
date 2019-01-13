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
    setResAnim(res::resources.getResAnim("panel"));
    setGuides(16.f, 16.f, 16.f, 16.f);
    setSize(80.f, 35.f);

    _text->setFontSize(16);
    _text->setPosition(10.f, 8.f);
    _text->setText("Input");
    _text->setColor(Color::Black);

    _input->addEventListener(Event::COMPLETE, CLOSURE(this, &TextInput::_on_complete));
    _input->addEventListener(InputText::EVENT_TEXT_CHANGED, CLOSURE(this, &TextInput::_on_text_changed));
    addEventListener(TouchEvent::CLICK, CLOSURE(this, &TextInput::_on_click));

    addChild(_text);
}


TextInput::TextInput(const TextInput& o)
{}


TextInput::~TextInput()
{}


void TextInput::_on_complete(Event*)
{
    _input->stopAnyInput();
    logs::messageln("stopAnyInput");
}


void TextInput::_on_click(Event*)
{
    _input->start(_text);
    logs::messageln("Start input");
}


void TextInput::_on_text_changed(Event*)
{
    //p_kev->data->keysym.scancode
    const Rect& r = _text->getTextRect();
    logs::messageln("Text W %d", r.size.x);

    if(r.size.x > 0)
        setWidth(r.size.x + 32.f);
    else
        setWidth(48.f);

    //const KeyEvent *p_kev = static_cast<const KeyEvent*>(ev);
    //logs::messageln("TextInput::_on_key_up, scancode=%d", p_kev->data->keysym.scancode);
}
