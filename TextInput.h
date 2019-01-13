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
    void _on_complete(Event*);
    void _on_click(Event*);

protected:
    spTextField _text;
    spInputText _input;

public:
    TextInput();
    TextInput(const TextInput& orig);
    virtual ~TextInput();

    inline const string& getText()
    {
        return _text->getText();
    }

};

#endif /* TEXTINPUT_H */
