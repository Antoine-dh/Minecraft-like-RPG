/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by lubas_ben,
*/

#include <ui.h>
#include <SFML/Audio.h>
#include "game.h"

float from_coord_y_to_screen_y(game_t *game, float y)
{
	sfVector2u screen_size = sfRenderWindow_getSize(game->window);

	return (y * screen_size.y / 1080);
}

float from_coord_x_to_screen_x(game_t *game, float x)
{
	sfVector2u screen_size = sfRenderWindow_getSize(game->window);

	return (x * screen_size.x / 1920);
}

void sub_sub_draw_ui(game_t *game, ui_t *ui)
{
	list_t *buttons = ui ? ui->buttons : NULL;
	list_t *images = ui ? ui->images : NULL;
	list_t *texts = ui ? ui->texts : NULL;

	while (buttons != NULL) {
		draw_button(game, buttons->data);
		buttons = buttons->next;
	}
	while (images != NULL) {
		draw_image(game, images->data);
		images = images->next;
	}
	while (texts != NULL) {
		draw_panel_text(game, ui, texts->data);
		texts = texts->next;
	}
}

void sub_draw_ui(game_t *game, ui_t *ui)
{
	if (ui == NULL)
		return;
	sfRectangleShape_setPosition(ui->panel->rectangle,
		ui->panel->draw_position);
	sfRenderWindow_pushGLStates(game->window);
	sfRenderWindow_drawRectangleShape(game->window, ui->panel->rectangle,
		NULL);
	sub_sub_draw_ui(game, ui);
	sfRenderWindow_popGLStates(game->window);
}

void draw_ui(game_t *game)
{
	list_t *ui = game->ui;

	while (ui != NULL) {
		if (ui->data != NULL && ((ui_t *)ui->data)->draw)
			sub_draw_ui(game, (ui_t *)ui->data);
		ui = ui->next;
	}
}
