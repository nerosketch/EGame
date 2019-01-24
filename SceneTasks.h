/* 
 * File:   SceneTasks.h
 * Author: ns
 *
 * Created on January 18, 2019, 6:24 PM
 */

#ifndef SCENETASKS_H
#define SCENETASKS_H

#include <vector>
#include <oxygine-framework.h>
#include "TextInput.h"
#include "Dialog.h"
#include "flags.h"


using namespace oxygine;


DECLARE_SMART(SceneTasks, spSceneTasks);


class SceneTasks : public Dialog
{
public:
    SceneTasks();
    SceneTasks(const SceneTasks&);
    virtual ~SceneTasks();

    void init() override;
    void on_ok_click(Event *ev) override
    {
        Dialog::closeSendClick();
        addTween(TweenDummy(), 1500)
        ->setDoneCallback([&](Event*){
            detach();
        });
    }

};

#endif /* SCENETASKS_H */

