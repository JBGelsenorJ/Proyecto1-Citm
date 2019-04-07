#ifndef __ModuleEnemy_H__
#define __ModuleEnemy_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleParticles.h"

struct SDL_Texture;

class ModuleEnemy : public Module
{
public:
	ModuleEnemy();
	~ModuleEnemy();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	Animation idle;
	Animation forward;
	Animation backward;
	Animation jump;
	Animation kick;
	Animation punch;
	Animation crouch;
	Particle special;
	Animation sm1;
	iPoint position;
	Mix_Chunk* Specialattack;
	Mix_Chunk* Punch;
	Mix_Chunk* Kick;
	bool jumpreset;
	bool TimeAnim = false;
	bool KickAnim = false;
	bool TimePunch = false;
	

};

#endif