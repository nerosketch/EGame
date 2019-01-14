/* 
 * File:   MainScene.h
 * Author: ns
 *
 * Created on January 12, 2019, 11:03 PM
 */

#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <list>
#include <oxygine-framework.h>
#include "flags.h"
#include "TextButton.h"
#include "Player.h"


using namespace oxygine;


DECLARE_SMART(MainScene, spMainScene);


class MainScene : public Stage
{
private:
    INHERITED(Stage);
    spSprite arrow;
    float _angle;
    std::list<spPlayer> _players;

    void on_click_run(Event*);
    void on_speen_done(Event*);
    void on_add_player(Event*);
    void on_add_question(Event*);

public:
    MainScene();
    MainScene(const MainScene&);
    virtual ~MainScene();

    void init();
};

#endif /* MAINSCENE_H */
