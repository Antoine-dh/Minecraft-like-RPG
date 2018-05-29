/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by lubas_ben,
*/

#include "game.h"

button_t *get_ui_button(ui_t *ui, int id)
{
	list_t *node = NULL;

	if (id > list_size(ui->buttons) - 1)
		return (NULL);
	node = ui->buttons;
	for (int i = 0 ; i < id ; i++)
		node = node->next;
	return (node->data);
}

void button_set_texture(button_t *button, int texture_id)
{
	sfRectangleShape_setTextureRect(button->rectangle,
		sheet_split(button->texture,
			&(sfVector2u){.x = sfTexture_getSize(
				button->texture).x, .y =
			sfTexture_getSize(button->texture).y / 3}, texture_id));
}

void draw_button(game_t *game, button_t *button)
{
	sfRenderWindow_drawRectangleShape(game->window,
		button->rectangle, NULL);
	draw_button_text(game, button);
}

void update_button(game_t *game, panel_t *panel, button_t *button)
{
	sfFloatRect a = sfRectangleShape_getGlobalBounds(button->rectangle);

	if (sfFloatRect_contains(&a, game->mouse_pos->x, game->mouse_pos->y)) {
		button_set_texture(button, 1);
		if (sfMouse_isButtonPressed(sfMouseLeft) &&
			button->template->on_click != NULL)
			button->template->on_click(game);
	} else
		button_set_texture(button, 0);
	sfRectangleShape_setPosition(button->rectangle, (sfVector2f)
		{ button->template->position.x + panel->draw_position.x,
		button->template->position.y + panel->draw_position.y});
}