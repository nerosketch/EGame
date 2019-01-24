/* 
 * File:   TextInput.h
 * Author: ns
 *
 * Created on January 13, 2019, 11:12 AM
 */

#ifndef TEXTINPUT_H
#define TEXTINPUT_H

#include <string>
#include <oxygine-framework.h>


using namespace oxygine;
using namespace std;


DECLARE_SMART(TextInput, spTextInput);


class TextInput : public Box9Sprite
{
private:
    INHERITED(Box9Sprite);
    void _on_text_changed(Event*);

protected:
    spTextField _text;
    spInputText _input;

public:
    TextInput();
    TextInput(const TextInput& orig);
    virtual ~TextInput();

    void init();

    inline const string& getText()
    {
        return _text->getText();
    }
    inline spTextField& getTextField(){ return _text; }
    inline spInputText& getInputText(){ return _input; }

};

#endif /* TEXTINPUT_H */
