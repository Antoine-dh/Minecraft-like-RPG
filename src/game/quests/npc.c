/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** npc
*/

#include "ui.h"
#include "game.h"

void sub_draw_npc(animodel_t *animodel, npc_t *npc, player_t *player)
{
	model_t *frame = animodel->frames[0];

	sfVector3f dist_vect = vector3_sub(&player->entity.position,
	&npc->pos);
	npc->rotation.y = TO_DEG(atan2f(dist_vect.x, dist_vect.z));
	glPushMatrix();
	glTranslatef(npc->pos.x, npc->pos.y, npc->pos.z);
	glRotatef(npc->rotation.x, 1, 0, 0);
	glRotatef(npc->rotation.y, 0, 1, 0);
	glRotatef(npc->rotation.z, 0, 0, 1);
	glScalef(npc->scale.x, npc->scale.y, npc->scale.z);
	if (npc->texture)
		sfTexture_bind(npc->texture);
	for (int i = 0 ; i < frame->faces_count ; ++i) {
		draw_face(&frame->faces[i], (bool_t)npc->texture);
	}
	glPopMatrix();
}

void draw_npc(game_t *game, list_t *npc)
{
	for (list_t *tmp = npc ; tmp ; tmp = tmp->next) {
		sub_draw_npc(((npc_t *)npc->data)->model, npc->data,
		game->player);
	}
}

int is_quest(void *id, void *data)
{
	int *i = (int *)id;
	quest_t *quest = (quest_t *)data;

	if (*i == quest->id)
		return (0);
	return (1);
}

void set_dialog(ui_t *ui, npc_t *data)
{
	char *str = NULL;

	for (size_t i = 0 ; data->dialog[i] != NULL ; ++i) {
		str = my_strcat_dup(str, data->dialog[i]);
		str = my_strcat_dup(str, "\n");
	}
	((text_t *)ui->texts->data)->template->value = str;
}

void update_npc(game_t *game, list_t *npc)
{
	float distance = 0.0f;
	npc_t *data = NULL;
	ui_t *ui = NULL;

	for (list_t *tmp = npc ; tmp ; tmp = tmp->next) {
		data = (npc_t *)tmp->data;
		distance = vector3_distance(&data->pos,
			&game->player->entity.position);
		if (distance < 2.0f && data->quest_id != -1 &&
			list_find_node(game->active_quests, &data->quest_id,
				is_quest) == NULL) {
			quest_add(game, data->quest_id);
			ui = get_ui_by_name(game, "TextBox");
			ui->panel->draw_position = (sfVector2f){0, 0};
			set_dialog(ui, data);
			ui->draw = 1;
			data->quest_id = -1;
		}
	}
}
