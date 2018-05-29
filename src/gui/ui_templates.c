/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by lubas_ben,
*/

#include "ui.h"
#include "game.h"

image_t *from_template_to_image(list_t *textures, image_template_t *template)
{
	image_t *image = malloc(sizeof(image_t));

	if (!image)
		return (NULL);
	memset(image, 0, sizeof(image_t));
	image->template = my_memdup(template, sizeof(image_template_t));
	image->rectangle = sfRectangleShape_create();
	image->texture = get_texture(template->image_name, textures);
	if (image->rectangle == NULL)
		return (NULL);
	sfRectangleShape_setSize(image->rectangle, template->size);
	if (image->texture != NULL)
		sfRectangleShape_setTexture(image->rectangle, image->texture,
			sfTrue);
	return (image);
}

panel_t *from_template_to_panel(list_t *textures, panel_template_t *template)
{
	panel_t *panel = malloc(sizeof(panel_t));

	if (!panel)
		return (NULL);
	memset(panel, 0, sizeof(panel_t));
	panel->template = my_memdup(template, sizeof(panel_template_t));
	panel->rectangle = sfRectangleShape_create();
	panel->texture = get_texture(template->texture_path, textures);
	if (panel->rectangle == NULL ||
		(panel->texture == NULL && template->texture_path != NULL))
		return (NULL);
	sfRectangleShape_setSize(panel->rectangle, panel->template->size);
	if (panel->texture != NULL)
		sfRectangleShape_setTexture(panel->rectangle, panel->texture,
			sfTrue);
	return (panel);
}

button_t *from_template_to_button(list_t *textures, button_template_t *template)
{
	button_t *button = malloc(sizeof(button_t));

	if (button == NULL)
		return (NULL);
	memset(button, 0, sizeof(button_t));
	button->template = my_memdup(template, sizeof(button_template_t));
	button->state = FREE;
	button->rectangle = sfRectangleShape_create();
	button->texture = get_texture(template->texture_path, textures);
	if (button->rectangle == NULL || button->texture == NULL)
		return (NULL);
	sfRectangleShape_setSize(button->rectangle, button->template->size);
	sfRectangleShape_setTexture(button->rectangle, button->texture, sfTrue);
	button->text = create_ui_text(button->template->text_value,
		button->template->text_size);
	return (button);
}

void parse_templates(game_t *game, list_t *textures, ui_template_t template,
	ui_t *ui)
{
	image_t *img = NULL;
	button_t *buttn = NULL;
	text_t *txt = NULL;

	if (template.buttons_generation_func != NULL)
		template.buttons_generation_func(game, &template);
	if (template.images_generation_func != NULL)
		template.images_generation_func(game, &template);
	for (int i = 0 ; template.buttons[i].text_value ; i++) {
		buttn = from_template_to_button(textures, &template.buttons[i]);
		buttn == NULL ? NULL : list_append(&ui->buttons, buttn);
	}
	for (int i = 0 ; template.images[i].image_name ; i++) {
		img = from_template_to_image(textures, &template.images[i]);
		img == NULL ? NULL : list_append(&ui->images, img);
	}
	for (int i = 0; template.texts[i].size != -1; i++) {
		txt = from_template_to_text(&template.texts[i]);
		txt == NULL ? NULL : list_append(&ui->texts, txt);
	}
}

ui_t *from_template_to_ui(game_t *game, list_t *textures,
	ui_template_t template)
{
	ui_t *ui = malloc(sizeof(ui_t));

	if (ui == NULL)
		return (NULL);
	memset(ui, 0, sizeof(ui_t));
	ui->name = template.name;
	ui->panel = from_template_to_panel(textures, &template.panel);
	ui->life_time = template.life_time;
	ui->unmodified_life_time = template.life_time;
	if (ui->panel == NULL)
		return (NULL);
	parse_templates(game, textures, template, ui);
	ui->draw = 0;
	return (ui);
}
