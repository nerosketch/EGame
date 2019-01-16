/* 
 * File:   Avatar.h
 * Author: ns
 *
 * Created on January 13, 2019, 12:53 AM
 */

#ifndef AVATAR_H
#define AVATAR_H

#include <string>
#include <oxygine-framework.h>
#include "flags.h"


using namespace oxygine;
using namespace std;


DECLARE_SMART(Avatar, spAvatar);


class Avatar : public Sprite
{
private:
    INHERITED(Sprite);

public:
    Avatar(const string& res_name);
    Avatar(const Avatar& orig);
    virtual ~Avatar();

    // запускаем когда победил
    void anim_win();
};

#endif /* AVATAR_H */
