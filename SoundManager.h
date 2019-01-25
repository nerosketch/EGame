/* 
 * File:   SoundManager.h
 * Author: ns
 *
 * Created on August 2, 2018, 12:48 AM
 */
#include "flags.h"
#ifdef SOUND_ENABLE

#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <string>

#include <oxygine-sound.h>
#include "resources.h"

using namespace oxygine;
using namespace std;


//DECLARE_SMART(SoundManager, spSoundManager);


class SoundManager: public SoundPlayer
{
private:
    //INHERITED(SoundPlayer);

    SoundManager();
    SoundManager(const SoundManager& orig);
    virtual ~SoundManager();

public:
    static SoundManager& get_instance()
    {
        static SoundManager somngr;
        return somngr;
    }

    void doUpdate();

    inline void ieshuva()
    {
        play_from_name("ieshuva");
    }
    inline void iripe()
    {
        play_from_name("i");
    }

    void play_from_name(const string&);
};

#endif
#endif /* SOUNDMANAGER_H */

