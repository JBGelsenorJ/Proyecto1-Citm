#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer::ModulePlayer()
{
	position.x = 100;
	position.y = 220;

	// idle animation (arcade sprite sheet)
	idle.PushBack({27, 914, 58, 103});
	idle.PushBack({95, 916, 59, 102});
	idle.PushBack({165, 917, 58, 101});
	idle.PushBack({ 95, 916, 59, 102 });

	idle.speed = 0.18f;

	// walk forward animation (arcade sprite sheet)
	//forward.frames.PushBack({9, 136, 53, 83});
	forward.PushBack({78, 131, 60, 88});
	forward.PushBack({162, 128, 64, 92});
	forward.PushBack({259, 128, 63, 90});
	forward.PushBack({352, 128, 54, 91});
	forward.PushBack({432, 131, 50, 89});
	forward.speed = 0.1f;

	// TODO 4: Make ryu walk backwards with the correct animations
	jump.PushBack({ 78, 131, 60, 88 });
	jump.PushBack({ 162, 128, 64, 92 });
	jump.PushBack({ 259, 128, 63, 90 });
	jump.PushBack({ 352, 128, 54, 91 });
	jump.PushBack({ 432, 131, 50, 89 });
	jump.speed = 0.1f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("Source/Sprites/Character_Sprites/Terry_Bogard/terry.png"); // Terry Bogard Sprites
	return ret;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	Animation* current_animation = &idle;

	int speed = 1;

	if(App->input->keyboard[SDL_SCANCODE_D] == 1)
	{
		current_animation = &forward;
		position.x += speed;
	}

	SDL_Rect r = current_animation->GetCurrentFrame();

	App->render->Blit(graphics, position.x, position.y - r.h, &r);
	
	return UPDATE_CONTINUE;
}