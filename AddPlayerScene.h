/* 
 * File:   AddPlayerScene.h
 * Author: ns
 *
 * Created on January 13, 2019, 3:21 AM
 */

#ifndef ADDPLAYERSCENE_H
#define ADDPLAYERSCENE_H

#include <oxygine-framework.h>
#include "flags.h"
#include "TextInput.h"
#include "Dialog.h"


using namespace oxygine;


DECLARE_SMART(AddPlayerScene, spAddPlayerScene);


class AddPlayerScene : public Dialog
{
private:
    void _on_select_left(Event*);
    void _on_select_right(Event*);
    void on_ok_click(Event*) override;
    spSprite _ava_im;
    char _current_ava;
    spTextInput text_inp_name;
    void _round_current_ava();

public:
    AddPlayerScene();
    AddPlayerScene(const AddPlayerScene&);
    virtual ~AddPlayerScene();
};

#endif /* ADDPLAYERSCENE_H */

