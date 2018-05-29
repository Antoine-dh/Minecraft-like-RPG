/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by lubas_ben,
*/

#include "game.h"

int get_toolbar_scroll_index(int index)
{
	static int _index = 0;

	if (index != -1)
		_index = index;
	return (_index);
}

void scroll_mouse_toolbar(game_t *game, int up_or_down)
{
	int index = get_toolbar_scroll_index(-1);
	set_under_slot_image(game, index, 1);

	index -= up_or_down;
	if (index == -1)
		index = 9;
	index = index % 10;
	get_toolbar_scroll_index(index);
	set_under_slot_image(game, index, 2);
}
