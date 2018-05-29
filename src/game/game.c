/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#include <fcntl.h>
#include "game.h"

void exit_game(game_t *game)
{
	sfRenderWindow_close(game->window);
}

void free_game(game_t *game)
{
	sfRenderWindow_destroy(game->window);
	free(game->player);
	free(game->cam);
	list_free(&game->entities, NULL);
	list_free(&game->textures, free_texture);
	list_free(&game->models, free_animodel);
	list_free(&game->prefabs, free_prefab);
	list_free(&game->sounds, free_sound);
	list_free(&game->npc, NULL);
	list_free(&game->projectile, free_projectile);
	list_free(&game->particles, NULL);
	list_free(&game->particle_systems, NULL);
	list_free(&game->ui, NULL);
	list_free(&game->active_quests, NULL);
	list_free(&game->active_ui, NULL);
	free_map(game->map);
	free(game);
}

void init_display(sfRenderWindow *window)
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.5);
	sfRenderWindow_setKeyRepeatEnabled(window, sfFalse);
	sfRenderWindow_setFramerateLimit(window, 60);
	sfRenderWindow_setMouseCursorVisible(window, sfFalse);
}

game_t *init_game(void)
{
	sfVideoMode mode = sfVideoMode_getFullscreenModes(NULL)[0];
	sfContextSettings settings = {.majorVersion = 3, .minorVersion = 0,
		.depthBits = 24, .stencilBits = 8};
	sfRenderWindow *window = sfRenderWindow_create(mode, "My Minecraft",
		sfFullscreen, &settings);
	game_t *game = malloc(sizeof(game_t));

	if (window == NULL || game == NULL)
		return (NULL);
	memset(game, 0, sizeof(game_t));
	game->cam = camera_create(window);
	game->player = player_create(game->cam, &(sfVector3f){0, 10, 0});
	game->window = window;
	if (game->cam == NULL || game->player == NULL)
		return (NULL);
	init_display(window);
	return (game);
}
