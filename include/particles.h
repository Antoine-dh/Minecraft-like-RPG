/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#ifndef MY_RPG_PARTICLES_H
#define MY_RPG_PARTICLES_H

#include <SFML/Graphics.h>
#include <math.h>
#include "list.h"
#include "my.h"

typedef struct particle_renderer {
	sfVector3f pos;
	float scale;
	sfColor color;
} particle_render_t;

typedef struct particle {
	sfVector3f pos;
	sfVector3f force;
	float scale;
	float gravity;
	sfColor start_color;
	sfColor end_color;
	float elapsed;
	float lifetime;
} particle_t;

typedef struct particle_system {
	sfVector3f pos;
	sfVector2f min_angle;
	sfVector2f max_angle;
	float min_force;
	float max_force;
	float min_scale;
	float max_scale;
	float min_gravity;
	float max_gravity;
	float min_lifetime;
	float max_lifetime;
	float sys_lifetime;
	int spawn_per_second;
	sfColor start_colors[16];
	sfColor end_colors[16];
} particle_sys_t;

static const float ATTENUATION = 0.9f;

static const particle_sys_t PARTICLE_FOUNTAIN = {
	{0, 0, 0},
	{-180, 10}, //angle
	{180, 90},
	1.0f, //force
	10.0f,
	0.05f, //scale
	0.2f,
	45.0f, //gravity
	45.0f,
	1.0f, //lifetime
	5.0f,
	10.0f,
	20, //spawn/seconds
	{{0, 0, 200, 255}, {0, 50, 150, 255}, {0, 0, 0, 0}},
	{{0, 50, 150, 50}, {0, 0, 200, 50}, {0, 0, 0, 0}}
};

static const particle_sys_t PARTICLE_SPAWN = {
	{0, 0, 0},
	{-180, 10}, //angle
	{180, 90},
	4.0f, //force
	8.0f,
	0.03f, //scale
	0.1f,
	0.0f, //gravity
	0.0f,
	0.7f, //lifetime
	1.0f,
	1.0f,
	30, //spawn/seconds
	{{255, 0, 0, 255}, {255, 255, 0, 255}, {255, 0, 255, 255},
		{0, 255, 255, 255}, {0, 255, 0, 255}, {0, 0, 0, 0}},
	{{255, 255, 255, 0}, {255, 255, 255, 0}, {255, 255, 255, 0},
		{255, 255, 255, 0}, {255, 255, 255, 0}, {0, 0, 0, 0}}
};

static const particle_sys_t PARTICLE_FIRE = {
	{0, 0, 0},
	{-180, 10}, //angle
	{180, 90},
	2.0f, //force
	4.0f,
	0.2f, //scale
	0.4f,
	-2.0f, //gravity
	-2.0f,
	0.7f, //lifetime
	1.0f,
	10,
	5, //spawn/seconds
	{{255, 100, 0, 255}, {200, 50, 0, 255}, {235, 75, 0, 255},
		{50, 50, 50, 255}, {0, 0, 0, 0}},
	{{255, 100, 0, 1}, {200, 50, 0, 1}, {235, 75, 0, 1},
		{150, 150, 150, 1}, {0, 0, 0, 0}}
};

static const particle_sys_t PARTICLE_BREAK = {
	{0, 0, 0},
	{-180, 0}, //angle
	{180, 90},
	5.0f, //force
	8.0f,
	0.15f, //scale
	0.2f,
	45.0f, //gravity
	45.0f,
	0.3f, //lifetime
	0.5f,
	0.2,
	5, //spawn/seconds
	{{100, 100, 100, 255}, {125, 125, 125, 255}, {0, 0, 0, 0}},
	{{100, 100, 100, 50}, {125, 125, 125, 50}, {0, 0, 0, 0}}
};

static const particle_sys_t PARTICLE_BLOOD = {
	{0, 0, 0},
	{-180, 10}, //angle
	{180, 90},
	5.0f, //force
	10.0f,
	0.05f, //scale
	0.2f,
	45.0f, //gravity
	45.0f,
	1.0f, //lifetime
	2.0f,
	0.1f,
	10, //spawn/seconds
	{{200, 0, 0, 200}, {225, 0, 0, 200}, {0, 0, 0, 0}},
	{{200, 0, 0, 50}, {225, 0, 0, 50}, {0, 0, 0, 0}}
};

particle_sys_t *particle_sys_instantiate(list_t **particle_sys_list,
	const particle_sys_t *template, const sfVector3f *pos);
void particle_sys_update(particle_sys_t *sys, list_t **particles, float dt);
int particle_sys_life_cmp(UNUSED particle_sys_t *a, particle_sys_t *b);

particle_t *particle_create_from_system(const particle_sys_t *sys);
void particle_draw(const particle_render_t *particle);
void particle_update(particle_t *particle, float dt);
int particle_life_cmp(UNUSED particle_t *a, particle_t *b);

#endif //MY_RPG_PARTICLES_H
