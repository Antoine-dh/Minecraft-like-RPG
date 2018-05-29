/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#include "game.h"
#include "lightning.h"

static void draw_block_preview(game_t *game)
{
	sfRenderWindow_pushGLStates(game->window);
	sfRectangleShape *shape = sfRectangleShape_create();
	sfRectangleShape_setSize(shape, (sfVector2f){50, 50});
	sfRectangleShape_setTexture(shape, game->map->tileset, sfFalse);
	sfRectangleShape_setTextureRect(shape,
		sheet_split(game->map->tileset, &(sfVector2u){32, 32},
			BLOCKS[game->player->selection].faces[2]));
	sfRenderWindow_drawRectangleShape(game->window, shape, NULL);
	sfRenderWindow_popGLStates(game->window);
}

static void subdraw_game(game_t *game)
{
	glColor4f(1, 1, 1, 1);
	glDisable(GL_LIGHTING);
	list_apply_on_nodes(game->entities, entity_draw);
	draw_npc(game, game->npc);
	sfRenderWindow_pushGLStates(game->window);
	draw_ui(game);
	sfRenderWindow_popGLStates(game->window);
	if (game->player->godmode)
		draw_block_preview(game);
	sfRenderWindow_display(game->window);
}

void draw_game(game_t *game)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	update_lightning(game->dt);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	draw_skybox(game->map->skybox, game->cam);
	map_draw(game->map, &game->player->entity.position, 100, game->elapsed);
	glBegin(GL_QUADS);
	for (list_t *tmp = game->particles ; tmp ; tmp = tmp->next)
		particle_update(tmp->data, game->dt);
	glEnd();
	subdraw_game(game);
}
