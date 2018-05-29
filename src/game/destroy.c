/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** destroy
*/

#include "quest.h"
#include "game.h"

int entity_off_map(UNUSED entity_t *a, entity_t *b)
{
	if (b->position.y < -50)
		return (0);
	return (1);
}

int no_hp(UNUSED void *data, void *current)
{
	entity_t *entity = (entity_t *)current;

	if (entity->health_point <= 0)
		return (0);
	return (1);
}

int quest_done(UNUSED void *data, void *current)
{
	quest_t *quest = current;
	const quest_template_t *template = NULL;

	for (size_t i = 0 ; QUESTS[i].id != -1 ; ++i)
		if (QUESTS[i].id == quest->id)
			template = &QUESTS[i];
	if (template == NULL)
		return (1);
	if (template->steps[quest->step].type == QUEST_NULL)
		return (0);
	return (1);
}

void destroy_non_used(game_t *game)
{
	list_delete_matching_nodes(&game->entities, NULL, no_hp, NULL);
	list_delete_matching_nodes(&game->projectile, NULL, is_projectile_alive,
		free_projectile);
	list_delete_matching_nodes(&game->particle_systems, NULL,
		particle_sys_life_cmp, NULL);
	list_delete_matching_nodes(&game->particles, NULL, particle_life_cmp,
		NULL);
	list_delete_matching_nodes(&game->entities, NULL, entity_off_map, NULL);
	list_delete_matching_nodes(&game->active_quests, NULL, quest_done,
		NULL);
}