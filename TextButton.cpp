/* 
 * File:   TextButton.cpp
 * Author: ns
 * 
 * Created on January 1, 2019, 11:21 PM
 */

#include "resources.h"
#include "TextButton.h"


TextButton::TextButton() :
_text(new TextField)
{
    _text->setFont(res::resources.getResFont("SanasoftHermes"));
    _text->setFontSize(21);
    //_text->setAnchor(0.5f, 0.5f);
    _text->setPosition(10.f, 7.f);
    _text->setColor(Color::Azure);

    setResAnim(res::resources.getResAnim("btn_i"));
    addChild(_text);
}


TextButton::TextButton(const string str) : TextButton()
{
    setText(str);
}


TextButton::TextButton(const TextButton& o) :
_text(o._text)
{}


TextButton::~TextButton()
{}


void TextButton::setText(const string str)
{
    _text->setText(str);
}
