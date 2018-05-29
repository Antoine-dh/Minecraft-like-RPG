/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** npc
*/

#ifndef NPC_H_
#define NPC_H_

#include <SFML/Graphics.h>
#include "model.h"

typedef struct npc {
	sfVector3f pos;
	sfVector3f scale;
	sfVector3f rotation;
	animodel_t *model;
	sfTexture *texture;
	char *name;
	char **dialog;
	int quest_id;
} npc_t;

void draw_npc(game_t *game, list_t *npc);

void update_npc(game_t *game, list_t *npc);
void *load_npc(const char *path);
void free_npc(npc_t *npc);


#endif /* !NPC_H_ */
