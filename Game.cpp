/* 
 * File:   Game.cpp
 * Author: ns
 * 
 * Created on January 12, 2019, 10:23 PM
 */

#include <oxygine-framework.h>
#include <ResFontFT.h>
#include "resources.h"
#include "Game.h"


Game::Game() :
    _viewport(Point(0, 0), core::getDisplaySize()),
    //_clearColor(32, 32, 32, 255)
    _clearColor(0, 0, 0, 0)
{}

Game::Game(const Game& o) :
    _viewport(o._viewport),
    _clearColor(o._clearColor)
{}

Game::~Game()
{}


void Game::preinit(){}

bool Game::init()
{
#ifdef DBG
    logs::messageln("Game:: init");
#endif

#ifdef SOUND_ENABLE
    SoundSystem::create()->init(16);
    SoundPlayer::initialize();
#endif

    ResFontFT::initLibrary();

    res::load();

    const spStage& p_stage = getStage();

    spMainScene main_scene = new MainScene();
    main_scene->setSize(p_stage->getSize());
    main_scene->init();
    p_stage->addChild(main_scene);

    return true;
}
void Game::destroy()
{
#ifdef DBG
    logs::messageln("Game:: destroy");
#endif

    ResFontFT::freeLibrary();

#ifdef SOUND_ENABLE
    stage_manager->p_sound->stop();

    SoundPlayer::free();
    SoundSystem::free();
#endif

    res::free();
}
bool Game::update()
{
    return false;
}
void Game::flush(){}
