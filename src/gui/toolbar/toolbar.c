/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by lubas_ben,
*/

#include <ui.h>
#include <SFML/System.h>
#include "game.h"

int get_slot_id(int slot_num)
{
	if (slot_num < 1)
		return (1);
	if (slot_num > 9)
		return (17);
	return (SLOTS_ID[slot_num - 1]);
}

int get_under_slot_id(int under_slot_num)
{
	if (under_slot_num < 1)
		return (0);
	if (under_slot_num > 9)
		return (16);
	return (UNDER_SLOTS_ID[under_slot_num - 1]);
}

void set_slot_image(game_t *game, int slot_id, sfVector3f split)
{
	sfTexture *texture = get_texture(ITEMS_SHEET_NAME, game->textures);
	ui_t *ui = get_ui_by_name(game, TOOLBAR_NAME);
	image_t *image = NULL;

	if (ui == NULL || texture == NULL)
		return;
	image = get_ui_image(ui, get_slot_id(slot_id));
	if (image != NULL) {
		image->template->split_info = split;
		image->texture = texture;
		image->template->image_name = "SLOT";
		image_set_texture(image);
	}
}

void set_under_slot_image(game_t *game, int slot_id, int sheet_id)
{
	ui_t *ui = get_ui_by_name(game, TOOLBAR_NAME);

	if (ui == NULL)
		return;
	image_t *image = get_ui_image(ui, get_under_slot_id(slot_id));
	if (image != NULL) {
		image->template->split_info.z = sheet_id;
		image_set_texture(image);
	}
}

void generate_toolbar_slots(game_t *game, ui_template_t *ui)
{
	int index = 0;

	for (int i = 0 ; i < 9 ; i++) {
		ui->images[index].image_name = "slot";
		ui->images[index].split_info = (sfVector3f){3, 1, 1};
		ui->images[index].size = (sfVector2f){64, 64};
		ui->images[index].position = (sfVector2f)
			{from_coord_x_to_screen_x(game, i * 64), 0};
		index++;
		ui->images[index].image_name = "NULL";
		ui->images[index].size = (sfVector2f){50, 50};
		ui->images[index].position = (sfVector2f)
			{from_coord_x_to_screen_x(game, i * 64 + 5),
				from_coord_y_to_screen_y(game, 0 + 5)};
		index++;
	}
	ui->images[index].image_name = "";
}