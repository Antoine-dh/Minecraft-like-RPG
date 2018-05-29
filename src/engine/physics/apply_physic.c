/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** apply_physic
*/

#include <SFML/System.h>
#include <physics.h>
#include "game.h"

void attribute_check(int attribute, entity_t *entity)
{
	if (attribute & BLOCK_SLOW) {
		entity->force.x /= 2.0f;
		entity->force.z /= 2.0f;
	}
	if (attribute & BLOCK_DAMAGE)
		entity->health_point -= 2.0f;
}

void manage_hitbox(hitbox_t *new, hitbox_t *cube, entity_t *entity,
	int attribute)
{
	hitbox_t tmp = {.size = new->size, .origin = entity->hitbox.origin};

	attribute_check(attribute, entity);
	tmp.origin.x = new->origin.x;
	if (hitbox3_collide(cube, &tmp))
		entity->force.x = 0;
	tmp.origin.x = entity->hitbox.origin.x;
	tmp.origin.y = new->origin.y;
	if (hitbox3_collide(cube, &tmp)) {
		if (entity->force.y < 0)
			entity->grounded = sfTrue;
		entity->force.y = 0;
	}
	tmp.origin.y = entity->hitbox.origin.y;
	tmp.origin.z = new->origin.z;
	if (hitbox3_collide(cube, &tmp))
		entity->force.z = 0;
}

void triple_array(entity_t *entity, game_t *game, block_t *block)
{
	hitbox_t cube_hitbox;
	sfVector3f dt_force = {entity->force.x * game->dt,
		entity->force.y * game->dt, entity->force.z * game->dt};
	hitbox_t new_hitbox = {.origin = vector3_add(&entity->hitbox.origin,
		&dt_force), .size = entity->hitbox.size};

	if (block == NULL)
		return;
	cube_hitbox.origin.x = block->pos.x;
	cube_hitbox.origin.y = block->pos.y;
	cube_hitbox.origin.z = block->pos.z;
	cube_hitbox.size = CUBE_HITBOX.size;
	if (block->id != 0 && hitbox3_collide(&cube_hitbox, &new_hitbox))
		manage_hitbox(&new_hitbox, &cube_hitbox, entity,
			block->attribute);
}

void entity_apply_physic(entity_t *entity, game_t *game)
{
	sfVector3f *p = &entity->position;
	sfVector3f s = entity->hitbox.size;

	entity->hitbox.origin.x = p->x - entity->hitbox.size.x / 2.0f;
	entity->hitbox.origin.y = p->y;
	entity->hitbox.origin.z = p->z - entity->hitbox.size.z / 2.0f;
	for (int z = (int)p->z - 2 ; z < p->z + 2 ; z++)
		for (int y = (int)p->y - 2 ; y < p->y + s.y + 2 ; y++)
			for (int x = (int)p->x - 2 ; x < p->x + 2 ; x++)
				triple_array(entity, game,
					get_map_block(game->map, x, y, z));
}
