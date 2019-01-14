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


class Dialog : public Box9Sprite
{
private:
    void _on_close_click(Event*);
    void _on_die(Event*);

public:
    Dialog();
    Dialog(const Dialog& orig);
    virtual ~Dialog();
private:

};

#endif /* DIALOG_H */

