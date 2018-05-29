/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by lubas_ben,
*/

#include "game.h"
#include "ui.h"

void draw_panel_text(game_t *game,  ui_t *ui, text_t *text)
{
	sfText_setString(text->text, text->template->value);
	sfText_setColor(text->text, text->template->color);
	sfText_setPosition(text->text, (sfVector2f){
		.x =ui->panel->draw_position.x + text->template->position.x,
		.y = ui->panel->draw_position.y + text->template->position.y
	});
	sfRenderWindow_drawText(game->window, text->text, NULL);
}

void draw_button_text(game_t *game, button_t *button)
{
	sfText_setPosition(button->text, (sfVector2f){
		.x = sfRectangleShape_getPosition(button->rectangle).x +
			sfRectangleShape_getGlobalBounds(
				button->rectangle).width / 2 -
			sfText_getLocalBounds(button->text).width / 2,
		.y = sfRectangleShape_getPosition(button->rectangle).y +
			sfRectangleShape_getGlobalBounds(
				button->rectangle).height / 2});
	sfRenderWindow_drawText(game->window, button->text, NULL);
}

sfText *create_ui_text(char *value, int size)
{
	sfFont *font = NULL;
	sfText *text = sfText_create();

	if (text == NULL)
		return (NULL);
	sfText_setString(text, value);
	font = sfFont_createFromFile(FONT_DIR FONT_NAME);
	if (font == NULL)
		return (NULL);
	sfText_setFont(text, font);
	sfText_setCharacterSize(text, (unsigned int)size);
	return (text);
}