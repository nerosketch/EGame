/* 
 * File:   TextPanel.h
 * Author: ns
 *
 * Created on October 21, 2018, 8:44 AM
 */

#ifndef BASEINTERFACE_H
#define BASEINTERFACE_H

#include <string>
#include <oxygine-framework.h>
#include "flags.h"


using namespace std;
using namespace oxygine;


DECLARE_SMART(TextPanel, spTextPanel);


class TextPanel : public Box9Sprite
{
private:
    INHERITED(Box9Sprite);

protected:
    spTextField text_field;

    void _kill_me(Event*);
    EventCallback _die_event;

public:
    TextPanel();
    TextPanel(const TextPanel& orig);
    virtual ~TextPanel();

    void init(const string& text);

    void setText(const string& text);

    void sizeChanged(const Vector2& size) override;

    void setTimeToLive(const uint ttl = 1000);
    void setOnDieEvent(const EventCallback&);
    static void showMessage(const string&, Actor*);

    spButton ok_btn;
};

#endif /* BASEINTERFACE_H */
