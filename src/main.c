/*
** EPITECH PROJECT, 2018
** glPrototype
** File description:
** Created by antoine_dh,
*/

#include "ui.h"
#include "game.h"

bool_t check_env(char **env, const char *entry)
{
	for (int i = 0 ; env[i] != NULL ; i++)
		if (my_strncmp(env[i], entry, my_strlen(entry)) == 0)
			return (TRUE);
	return (FALSE);
}

int main(int ac, char **av, char **env)
{
	game_t *game;

	if (!check_env(env, "DISPLAY="))
		return (84);
	srand((unsigned int)(unsigned long)av);
	game = init_game();
	if (game == NULL)
		return (84);
	if (ac == 2) {
		game->map = map_load(av[1]);
		game->player->godmode = sfTrue;
	} else
		game->map = map_load(MAPS_DIR "default.map");
	if (game->map == NULL || !load_resources(game))
		return (84);
	game->player->entity.position.x = (float)game->map->spawn.x;
	game->player->entity.position.y = (float)game->map->spawn.y;
	game->player->entity.position.z = (float)game->map->spawn.z;
	generate_ui(game);
	initialize_loading_screen(game);
	return (run_game(game));
}
