/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by lubas_ben,
*/

#include <ui.h>
#include "game.h"

image_t *get_ui_image(ui_t *ui, int id)
{
	list_t *node = NULL;

	if (id > list_size(ui->images) - 1)
		return (NULL);
	node = ui->images;
	for (int i = 0 ; i < id ; i++)
		node = node->next;
	return (node->data);
}

void image_set_texture(image_t *image)
{
	sfIntRect rect = sheet_split(image->texture, &(sfVector2u){
			sfTexture_getSize(image->texture).x /
				(unsigned int)image->template->split_info.x,
			sfTexture_getSize(image->texture).y /
				(unsigned int)image->template->split_info.y},
		(int)image->template->split_info.z);
	sfRectangleShape_setTexture(image->rectangle, image->texture, sfTrue);
	sfRectangleShape_setTextureRect(image->rectangle, rect);
}

void draw_image(game_t *game, image_t *image)
{
	if (image->texture == NULL)
		return;
	image_set_texture(image);
	sfRenderWindow_drawRectangleShape(game->window, image->rectangle, NULL);
}

void update_image(panel_t *panel, image_t *image)
{
	sfRectangleShape_setPosition(image->rectangle, (sfVector2f){
		image->template->position.x + panel->draw_position.x,
		image->template->position.y + panel->draw_position.y});
}
