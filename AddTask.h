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
#include "Dialog.h"


using namespace oxygine;

DECLARE_SMART(AddTask, spAddTask);


class AddTask : public Dialog
{
private:
    void on_ok_click(Event*);
    spTextInput _text_question_title;
    spTextInput _text_question_descr;

public:
    AddTask();
    AddTask(const AddTask&);
    virtual ~AddTask();

    void init() override;

};

#endif /* ADDTASK_H */

