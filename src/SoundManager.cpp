/* 
 * File:   SoundManager.cpp
 * Author: ns
 * 
 * Created on August 2, 2018, 12:48 AM
 */
#include "flags.h"
#ifdef SOUND_ENABLE

#include "resources.h"
#include "SoundManager.h"

SoundManager::SoundManager()
{
#ifdef DBG
    logs::messageln("SoundManager:: constructor");
#endif

    setVolume(0.7f);
}

SoundManager::SoundManager(const SoundManager& orig)
{}

SoundManager::~SoundManager()
{
#ifdef DBG
    logs::messageln("SoundManager:: destructor");
#endif

    stop();
}



void SoundManager::doUpdate()
{
    SoundSystem::get()->update();
    update();
}


void SoundManager::play_from_name(const string& fname)
{
#ifdef DBG
    logs::messageln("SoundManager:: play_from_name %s", fname.c_str());
#endif

    play(res::resources.get(fname));

    // For example: play looped music with fade in 1.5 seconds:
    //play(resources.get(fname), PlayOptions().loop().fade(1500));
}


#endif
