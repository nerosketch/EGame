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


class Dialog : public ColorRectSprite
{
private:
    void _on_close_click(Event*);
    spSprite tech_panel_bot;
    spSprite tech_panel_top;
    spSprite tech_panel_top_line;
    spSprite tech_panel_c1;
    spSprite tech_panel_c2;
    spSprite tech_panel_c3;

protected:
    DialogDoneCallback _dc;

    // Нужно переопределить и добавить событием для кнопки сохранения
    virtual void on_ok_click(Event*);

public:
    Dialog();
    Dialog(const Dialog& orig);
    virtual ~Dialog();

    virtual void init();

    inline void setDoneCallback(const DialogDoneCallback& dc)
    {
        _dc = dc;
    }

};

#endif /* DIALOG_H */

