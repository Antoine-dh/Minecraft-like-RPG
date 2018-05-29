/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#include <stdlib.h>
#include <SFML/System.h>
#include "particles.h"
#include "my.h"
#include "vector.h"

static sfVector3f particle_set_force(const sfVector2f *min_angle,
	const sfVector2f *max_angle, float force)
{
	sfVector3f dir_vect;
	sfVector2f angle;
	sfVector3f force_vect = {force, force, force};

	angle.x = RANDF_RANGE(min_angle->x, max_angle->x);
	angle.y = RANDF_RANGE(min_angle->y, max_angle->y);
	dir_vect = vector_from_angle(&angle);
	return (vector3_mul(&dir_vect, &force_vect));
}

particle_t *particle_create_from_system(const particle_sys_t *sys)
{
	particle_t *particle = malloc(sizeof(particle_t));
	float force = RANDF_RANGE(sys->min_force, sys->max_force);
	size_t color;

	if (particle == NULL)
		return (NULL);
	for (color = 0 ; sys->start_colors[color].a != 0 ; color++);
	color = rand() % color;
	particle->pos = sys->pos;
	particle->elapsed = 0;
	particle->scale = RANDF_RANGE(sys->min_scale, sys->max_scale);
	particle->lifetime = RANDF_RANGE(sys->min_lifetime, sys->max_lifetime);
	particle->gravity = RANDF_RANGE(sys->min_gravity, sys->max_gravity);
	particle->start_color = sys->start_colors[color];
	particle->end_color = sys->end_colors[color];
	particle->force = particle_set_force(&sys->min_angle, &sys->max_angle,
		force);
	return (particle);
}

static sfColor particle_color_blend(const particle_t *particle)
{
	sfColor color;
	float factor = (1 / particle->lifetime) / (1 / particle->elapsed);

	color.r = (sfUint8)(RANGE(factor, particle->start_color.r,
		particle->end_color.r));
	color.g = (sfUint8)(RANGE(factor, particle->start_color.g,
		particle->end_color.g));
	color.b = (sfUint8)(RANGE(factor, particle->start_color.b,
		particle->end_color.b));
	color.a = (sfUint8)(RANGE(factor, particle->start_color.a,
		particle->end_color.a));
	return (color);
}

void particle_update(particle_t *particle, float dt)
{
	particle_render_t renderer;
	sfVector3f dt_vector = {particle->force.x * dt, particle->force.y * dt,
		particle->force.z * dt};

	particle->elapsed += dt;
	if (particle->elapsed >= particle->lifetime)
		return;
	particle->pos = vector3_add(&particle->pos, &dt_vector);
	particle->force.x = particle->force.x * powf(ATTENUATION, dt * 60);
	if (particle->gravity != 0)
		particle->force.y -= particle->gravity * dt;
	else
		particle->force.y =
			particle->force.y * powf(ATTENUATION, dt * 60);
	particle->force.z = particle->force.z * powf(ATTENUATION, dt * 60);
	renderer.pos = particle->pos;
	renderer.scale = particle->scale;
	renderer.color = particle_color_blend(particle);
	particle_draw(&renderer);
}

int particle_life_cmp(UNUSED particle_t *a, particle_t *b)
{
	return (b->elapsed >= b->lifetime ? 0 : 1);
}
