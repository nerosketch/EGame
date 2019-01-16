/* 
 * File:   Player.h
 * Author: ns
 *
 * Created on January 13, 2019, 2:08 AM
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <list>
#include <oxygine-framework.h>
#include "flags.h"
#include "Avatar.h"


using namespace oxygine;
using namespace std;


DECLARE_SMART(Player, spPlayer);

class Player : public Avatar
{
private:
    string _name;
    float _angle;
    spTextField _tx;

public:
    Player(const string& res_name);
    Player(const Player& orig);
    virtual ~Player();

    inline void setAnglePos(const float angle)
    {
        _angle = angle;
    }

    inline const float getAnglePos() const
    {
        return _angle;
    }

    inline void setName(const string& name)
    {
        _name = name;
        _tx->setText(name);
    }

    inline const string getName() const
    {
        return _name;
    }

    // включаем когда выигрываем
    void win();
};

#endif /* PLAYER_H */

