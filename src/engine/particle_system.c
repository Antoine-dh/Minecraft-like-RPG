/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#include "particles.h"
#include "list.h"
#include "physics.h"
#include "my.h"

particle_sys_t *particle_sys_create(const particle_sys_t *template,
	const sfVector3f *pos)
{
	particle_sys_t *sys = malloc(sizeof(particle_sys_t));

	if (sys == NULL)
		return (NULL);
	my_memcpy(sys, template, sizeof(particle_sys_t));
	sys->pos = *pos;
	return (sys);
}

particle_sys_t *particle_sys_instantiate(list_t **particle_sys_list,
	const particle_sys_t *template, const sfVector3f *pos)
{
	particle_sys_t *sys = particle_sys_create(template, pos);

	if (sys == NULL)
		return (NULL);
	list_push(particle_sys_list, sys);
	return (sys);
}

void particle_sys_update(particle_sys_t *sys, list_t **particles, float dt)
{
	particle_t *particle = NULL;

	sys->sys_lifetime -= dt;
	if (dt == 0 || (int)(sys->spawn_per_second * dt) < 2) {
		particle = particle_create_from_system(sys);
		if (particle != NULL)
			list_push(particles, particle);
		return;
	}
	while (rand() % (int)(sys->spawn_per_second * dt) == 0) {
		particle = particle_create_from_system(sys);
		if (particle != NULL)
			list_push(particles, particle);
	}
}

int particle_sys_life_cmp(UNUSED particle_sys_t *a, particle_sys_t *b)
{
	return (b->sys_lifetime > 0 ? 1 : 0);
}
