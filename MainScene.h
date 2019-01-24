/* 
 * File:   MainScene.h
 * Author: ns
 *
 * Created on January 12, 2019, 11:03 PM
 */

#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <vector>
#include <oxygine-framework.h>
#include "flags.h"
#include "TextButton.h"
#include "Player.h"
#include "TextPanel.h"


using namespace oxygine;


DECLARE_SMART(MainScene, spMainScene);


class MainScene : public Actor
{
private:
    INHERITED(Stage);
    spSprite arrow;
    spSprite rulet;
    uint _win_user_index;
    uint _spin_round_count;
    std::vector<spPlayer> _players;
    TextPanel *p_question_panel;

    void on_click_run(Event*);
    void on_speen_done(Event*);
    void on_add_player(Event*);
    void on_add_player_done(spObject&);
    void on_add_question(Event*);

public:
    MainScene();
    MainScene(const MainScene&);
    virtual ~MainScene();

    void init();
};

#endif /* MAINSCENE_H */

