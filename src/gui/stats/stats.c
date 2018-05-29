/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by lubas_ben,
*/

#include <ui.h>
#include "game.h"

void set_stats_life(game_t *game, int min, int max)
{
	ui_t *ui = get_ui_by_name(game, STATS_SCREEN);
	text_t *text = get_stats_corresponding_text(ui, STATS_LIFE_TEXT_ID);
	char *min_str = my_itoa(min, "0123456789");
	char *max_str = my_itoa(max, "0123456789");
	char *str = NULL;

	if (ui == NULL || text == NULL || min_str == NULL || max_str == NULL)
		return;
	str = my_strcat_dup(str, min_str);
	str = my_strcat_dup(str, "/");
	str = my_strcat_dup(str, max_str);
	free(text->template->value);
	text->template->value = str;
	free(min_str);
	free(max_str);
}

void set_stats_defense(game_t *game, int value)
{
	ui_t *ui = get_ui_by_name(game, STATS_SCREEN);
	text_t *text = get_stats_corresponding_text(ui, STATS_DEFENSE_TEXT_ID);
	char *value_str = my_itoa(value, "0123456789");

	if (ui == NULL || text == NULL || value_str == NULL)
		return;
	free(text->template->value);
	text->template->value = value_str;
}

void set_stats_attack(game_t *game, int value)
{
	ui_t *ui = get_ui_by_name(game, STATS_SCREEN);
	text_t *text = get_stats_corresponding_text(ui, STATS_ATTACK_TEXT_ID);
	char *value_str = my_itoa(value, "0123456789");

	if (ui == NULL || text == NULL || value_str == NULL)
		return;
	free(text->template->value);
	text->template->value = value_str;
}

void set_stats_experience(game_t *game, int min, int max)
{
	ui_t *ui = get_ui_by_name(game, STATS_SCREEN);
	text_t *text = get_stats_corresponding_text(ui,
		STATS_EXPERIENCE_TEXT_ID);
	char *min_str = my_itoa(min, "0123456789");
	char *max_str = my_itoa(max, "0123456789");
	char *str = NULL;

	if (ui == NULL || text == NULL || min_str == NULL || max_str == NULL)
		return;
	str = my_strcat_dup(str, min_str);
	str = my_strcat_dup(str, "/");
	str = my_strcat_dup(str, max_str);
	free(text->template->value);
	text->template->value = str;
	free(min_str);
	free(max_str);
}

void set_stats_level(game_t *game, int value)
{
	char *value_str = NULL;
	char *level_str = NULL;
	ui_t *ui = get_ui_by_name(game, STATS_SCREEN);
	text_t *text = get_stats_corresponding_text(ui, STATS_LEVEL_TEXT_ID);

	if (ui == NULL || text == NULL)
		return;
	level_str = my_itoa(value, "0123456789");
	value_str = my_strcat_dup(value_str, "level : ");
	value_str = my_strcat_dup(value_str, level_str);
	free(text->template->value);
	text->template->value = value_str;
	free(level_str);
}