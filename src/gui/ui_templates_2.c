/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by lubas_ben,
*/

#include "ui.h"
#include "my.h"

text_t *from_template_to_text(text_template_t *template)
{
	text_t *text = malloc(sizeof(text_t));

	if (text == NULL)
		return (NULL);
	text->template = my_memdup(template, sizeof(text_template_t));
	text->text = create_ui_text(template->value, template->size);
	if (text->text == NULL)
		return (NULL);
	sfText_setColor(text->text, text->template->color);
	return (text);
}
