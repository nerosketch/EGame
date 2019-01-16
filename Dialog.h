/* 
 * File:   Dialog.h
 * Author: ns
 *
 * Created on January 15, 2019, 12:08 AM
 */

#ifndef DIALOG_H
#define DIALOG_H


#include <oxygine-framework.h>
#include "flags.h"
#include "TextInput.h"


using namespace oxygine;


DECLARE_SMART(Dialog, spDialog);


typedef Closure<void(spObject&)> DialogDoneCallback;


class Dialog : public Box9Sprite
{
private:
    void _on_close_click(Event*);

protected:
    DialogDoneCallback _dc;

    // Нужно переопределить и добавить событием для кнопки сохранения
    virtual void on_ok_click(Event*);

public:
    Dialog();
    Dialog(const Dialog& orig);
    virtual ~Dialog();

    inline void setDoneCallback(const DialogDoneCallback& dc)
    {
        _dc = dc;
    }

};

#endif /* DIALOG_H */

