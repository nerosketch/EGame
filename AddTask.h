/* 
 * File:   AddTask.h
 * Author: ns
 *
 * Created on January 13, 2019, 9:37 PM
 */

#ifndef ADDTASK_H
#define ADDTASK_H

#include <oxygine-framework.h>
#include "TextInput.h"


using namespace oxygine;

DECLARE_SMART(AddTask, spAddTask);


class AddTask : public Box9Sprite
{
private:
    INHERITED(Box9Sprite);
    void _on_die(Event*);
    void _on_ok_click(Event*);
    spTextInput _text_question_title;
    spTextInput _text_question_descr;

public:
    AddTask();
    AddTask(const AddTask&);
    virtual ~AddTask();
};

#endif /* ADDTASK_H */

