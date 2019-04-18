/* 
 * File:   Game.h
 * Author: ns
 *
 * Created on January 12, 2019, 10:23 PM
 */

#ifndef GAME_H
#define GAME_H

#include "flags.h"
#include <oxygine-framework.h>
#include "MainScene.h"


using namespace oxygine;


class Game
{
private:
    Rect _viewport;
    Color _clearColor;

public:
    Game();
    Game(const Game&);
    virtual ~Game();

    void preinit();
    bool init();
    void destroy();
    bool update();
    void flush();

    inline const Rect& getViewport() const
    {
        return _viewport;
    }

    inline void setViewport(const Rect& r)
    {
        _viewport = r;
    }

    inline const Color& getClearColor() const
    {
        return _clearColor;
    }

    inline void setClearColor(const Color& c)
    {
        _clearColor = c;
    }
};

#endif /* GAME_H */

