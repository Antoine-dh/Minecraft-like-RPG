/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#include <model.h>
#include "vector.h"
#include "game.h"

void knockback_update(entity_t *entity)
{
	entity->force.x += entity->knockback_coefficient.x;
	entity->force.y += entity->knockback_coefficient.y;
	entity->force.z += entity->knockback_coefficient.z;
	entity->knockback_coefficient.x /= 1.1f;
	entity->knockback_coefficient.y /= 1.1f;
	entity->knockback_coefficient.z /= 1.1f;
}

void entity_update(game_t *game, entity_t *entity)
{
	sfVector3f dt_force;

	entity->grounded = sfFalse;
	entity->force.y -= GRAVITY * game->dt;
	knockback_update(entity);
	entity_apply_physic(entity, game);
	dt_force = (sfVector3f){entity->force.x * game->dt,
		entity->force.y * game->dt, entity->force.z * game->dt};
	entity->position = vector3_add(&entity->position, &dt_force);
	entity->force.x = 0;
	entity->force.z = 0;
	if (entity->model)
		entity->frame_index =
			(entity->frame_index + 1) % entity->model->frames_count;
}

hitbox_t generate_hitbox_from_model(model_t *model, const sfVector3f *scale)
{
	hitbox_t hitbox = {.origin = {0, 0, 0}, .size = {0, 0, 0}};
	sfVector3f min = model->faces[0].v[0];
	sfVector3f max = model->faces[0].v[0];
	sfVector3f tmp;

	for (int f = 0 ; f < model->faces_count ; f++)
		for (int v = 0 ; v < model->faces[f].points_count ; v++) {
			tmp = model->faces[f].v[v];
			max.x = tmp.x > max.x ? tmp.x : max.x;
			max.y = tmp.y > max.y ? tmp.y : max.y;
			max.z = tmp.z > max.z ? tmp.z : max.z;
			min.x = tmp.x < min.x ? tmp.x : min.x;
			min.y = tmp.y < min.y ? tmp.y : min.y;
			min.z = tmp.z < min.z ? tmp.z : min.z;
		}
	hitbox.size = vector3_sub(&max, &min);
	hitbox.size = vector3_mul(&hitbox.size, scale);
	return (hitbox);
}

entity_t *entity_create(animodel_t *anim, sfTexture *texture,
	const sfVector3f *scale)
{
	entity_t *entity = malloc(sizeof(entity_t));

	if (entity == NULL)
		return (NULL);
	memset(entity, 0, sizeof(entity_t));
	entity->hit_rate = 2.0f;
	entity->cooldown = 0.0f;
	entity->model = anim;
	entity->texture = texture;
	entity->scale = *scale;
	entity->hitbox = generate_hitbox_from_model(anim->frames[0], scale);
	entity->knockback_coefficient = (sfVector3f){0, 0, 0};
	return (entity);
}

void entity_lookat(entity_t *entity, sfVector3f *target,
	UNUSED sfVector3f *axis)
{
	sfVector3f dist_vect = vector3_sub(target, &entity->position);

	entity->rotation.y = TO_DEG(atan2f(dist_vect.x, dist_vect.z));
}
