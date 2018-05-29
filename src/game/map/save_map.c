/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** save_map
*/

#include "game.h"
#include <fcntl.h>

void my_put_nbr_fd(int number, int fd)
{
	char *str = my_itoa(number, "0123456789");

	write(fd, str, my_strlen(str));
	free(str);
}

static void write_to_map(map_t *map, vector3i_t *p, int fd)
{
	if (map->blocks[p->z][p->y][p->x].id == 0)
		return;
	my_put_nbr_fd(p->x, fd);
	write(fd, ",", 1);
	my_put_nbr_fd(p->y, fd);
	write(fd, ",", 1);
	my_put_nbr_fd(p->z, fd);
	write(fd, ",", 1);
	my_put_nbr_fd(map->blocks[p->z][p->y][p->x].id, fd);
	write(fd, ":", 1);
}

void save_map(map_t *map, const char *filename)
{
	int fd = open(filename, O_RDWR | O_TRUNC | O_CREAT, 0644);
	vector3i_t p;

	write(fd, "map=", 4);
	for (p.x = 0; p.x < map->size.x; p.x++)
		for (p.y = 0; p.y < map->size.y; p.y++)
			for (p.z = 0; p.z < map->size.z; p.z++)
				write_to_map(map, &p, fd);
}