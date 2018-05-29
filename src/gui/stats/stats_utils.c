/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by lubas_ben,
*/

#include "ui.h"

text_t *get_stats_corresponding_text(ui_t *ui, int id)
{
	if (ui == NULL || ui->texts == NULL)
		return (NULL);
	list_t *list = ui->texts;

	for (int i = 0; i < id && list->next != NULL; i++)
		list = list->next;
	return (list->data);
}
