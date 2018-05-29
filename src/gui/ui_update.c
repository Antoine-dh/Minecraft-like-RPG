/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by lubas_ben,
*/

#include "game.h"
#include "ui.h"

void update_stats(game_t *game)
{
	ui_t *ui = get_ui_by_name(game, STATS_SCREEN);

	if (!ui)
		return;
	set_stats_life(game, (int)game->player->entity.health_point,
		game->player->max_life);
	set_stats_attack(game, game->player->attack);
	set_stats_experience(game, game->player->experience_actual,
		game->player->experience_max);
	set_stats_defense(game, game->player->defense);
	set_stats_level(game, game->player->level);
}

void sub_update_ui(game_t *game, ui_t *ui)
{
	list_t *buttons  = ui->buttons;
	list_t *images = ui->images;

	while (buttons != NULL) {
		update_button(game, ui->panel, buttons->data);
		buttons = buttons->next;
	}
	while (images != NULL) {
		update_image(ui->panel, images->data);
		images = images->next;
	}
}

static void update_ui_life(game_t *game, ui_t *ui)
{
	sub_update_ui(game, ui);
	if (ui->life_time != INFINITY) {
		ui->life_time -= game->dt;
		if (ui->life_time <= 0) {
			ui->life_time =
				ui->unmodified_life_time;
			ui->draw = 0;
		}
	}
}

void update_ui(game_t *game)
{
	ui_t *ui = NULL;
	list_t *list = game->ui;

	update_stats(game);
	while (list != NULL) {
		ui = (ui_t *)list->data;
		if (ui != NULL && ui->draw == 1)
			update_ui_life(game, ui);
		list = list->next;
	}

}
