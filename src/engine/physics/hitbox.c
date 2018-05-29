/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#include "vector.h"
#include "game.h"

sfBool hitbox3_collide(const hitbox_t *a, const hitbox_t *b)
{
	if ((b->origin.x >= a->origin.x + a->size.x) ||
		(b->origin.x + b->size.x <= a->origin.x) ||
		(b->origin.y >= a->origin.y + a->size.y) ||
		(b->origin.y + b->size.y <= a->origin.y) ||
		(b->origin.z >= a->origin.z + a->size.z) ||
		(b->origin.z + b->size.z <= a->origin.z)) {
		return (sfFalse);
	}
	return (sfTrue);
}

hitbox_t hitbox_transform(entity_t *entity)
{
	hitbox_t hitbox = entity->hitbox;

	hitbox.size = vector3_mul(&entity->hitbox.size,
		&entity->scale);
	hitbox.origin = vector3_mul(&entity->hitbox.origin,
		&entity->scale);
	hitbox.origin = vector3_add(&entity->position, &hitbox.origin);
	return (hitbox);
}
