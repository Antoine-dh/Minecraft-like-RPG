/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by lucas_benghida,
*/

#include "quest.h"
#include "game.h"

void apply_rewards(UNUSED game_t *game, const quest_template_t *template)
{
	for (size_t i = 0 ; template->rewards[i].type != QUEST_NULL ; ++i)
		for (size_t j = 0 ; j < LEN(STEPS) ; ++j)
			if (STEPS[j].step == template->rewards[i].type)
				STEPS[j].fptr(game, template->rewards[i].data);
}

void update_quest(game_t *game, quest_t *quest)
{
	const quest_template_t *template = NULL;

	for (size_t i = 0 ; QUESTS[i].id != -1 ; ++i)
		if (QUESTS[i].id == quest->id)
			template = &QUESTS[i];
	if (template == NULL)
		return;
	if (template->steps[quest->step].type != QUEST_NULL)
		for (size_t i = 0 ; i < LEN(STEPS) ; ++i)
			if (STEPS[i].step ==
				template->steps[quest->step].type &&
				STEPS[i].fptr(game,
					template->steps[quest->step].data))
				quest->step++;
	if (template->steps[quest->step].type == QUEST_NULL)
		apply_rewards(game, template);
}
