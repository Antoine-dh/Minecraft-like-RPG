/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#include "quest.h"
#include "game.h"

quest_t *quest_from_template(const quest_template_t *template)
{
	quest_t *quest = malloc(sizeof(quest_t));

	if (quest == NULL)
		return (NULL);
	quest->id = template->id;
	quest->step = 0;
	return (quest);
}

int quest_add(game_t *game, int id)
{
	const quest_template_t *template = NULL;
	quest_t *new_quest;

	for (size_t i = 0 ; QUESTS[i].id != -1 ; ++i)
		if (QUESTS[i].id == id)
			template = &QUESTS[i];
	if (template == NULL)
		return (0);
	new_quest = quest_from_template(template);
	if (new_quest == NULL)
		return (0);
	list_push(&game->active_quests, new_quest);
	return (1);
}

int quest_new(game_t *game, const int data[10])
{
	return (quest_add(game, data[0]));
}
