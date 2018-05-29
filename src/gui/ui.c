/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by lubas_ben,
*/

#include <ui.h>
#include "game.h"

ui_t *get_ui_by_name(game_t *game, char *name)
{
	list_t *node = game->ui;

	while (node != NULL) {
		if (my_strcmp(((ui_t *)node->data)->name, name) == 0)
			break;
		node = node->next;
	}
	return (node == NULL ? NULL : (ui_t *)node->data);
}

void generate_ui(game_t *game)
{
	ui_t *ui = NULL;

	for (int i = 0 ; UI_TEMPLATES[i].name != NULL ; i++) {
		ui = from_template_to_ui(game, game->textures, UI_TEMPLATES[i]);
		if (ui != NULL)
			list_append(&game->ui, (void *)ui);
	}
}
