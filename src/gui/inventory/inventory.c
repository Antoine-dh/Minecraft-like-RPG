/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by lubas_ben,
*/

#include <SFML/System.h>
#include <ui.h>
#include "game.h"

int sub_add_inventory(game_t *game, list_t *images, int slot_id, int item_id)
{
	int index = 0;
	image_t *image = NULL;
	sfTexture *texture = get_texture(ITEMS_SHEET_NAME, game->textures);
	ui_t *ui = get_ui_by_name(game, INVENTORY_NAME);
	sfVector3f split = (sfVector3f){.x = 16, .y = 23, .z = item_id};

	if (my_strcmp(((image_t *)images->data)->template->image_name,
		"NULL") == 0) {
		index = get_slot_image_id(slot_id);
		image = get_ui_image(ui, index);
		if (image != NULL) {
			image->template->split_info = split;
			image->texture = texture;
			image->template->image_name = my_itoa(item_id,
				"0123456789");
			image_set_texture(image);
		}
		return (1);
	}

	return (0);
}

void add_inventory(game_t *game, int item_id)
{
	int slot_id = 0;
	list_t *images = NULL;
	char *item_str = my_itoa(item_id, "0123456789");
	ui_t *ui = get_ui_by_name(game, INVENTORY_NAME);

	images = ui->images;
	while (images != NULL) {
		if (my_strcmp(((image_t *)images->data)->template->image_name,
			"slot") != 0) {
			if (my_strcmp(
				((image_t *)images->data)->template->image_name,
				item_str) == 0)
				break;
			if (sub_add_inventory(game, images, slot_id, item_id))
				break;
		}
		slot_id++;
		images = images->next;
	}
	free(item_str);
}

void create_inventory_slot(ui_template_t *ui, int *index, int x, int y)
{
	ui->images[*index].image_name = "slot";
	ui->images[*index].split_info = (sfVector3f){3, 1, 1};
	ui->images[*index].size = (sfVector2f){64, 64};
	ui->images[*index].position = (sfVector2f){15 + (x * 64), 30 + y * 64};
	(*index)++;
	ui->images[*index].image_name = "NULL";
	ui->images[*index].size = (sfVector2f){50, 50};
	ui->images[*index].position = (sfVector2f){20 + x * 64, 35 + y * 64};
	(*index)++;
}

void generate_inventory_slots(game_t *game, ui_template_t *ui)
{
	int index = 0;

	(void)game;
	for (int y = 0 ; y < 7 ; y++) {
		for (int x = 0 ; x < 3 ; x++)
			create_inventory_slot(ui, &index, x, y);
	}
}
