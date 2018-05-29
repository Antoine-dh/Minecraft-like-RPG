/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#include "game.h"

void center_mouse(sfRenderWindow *window)
{
	sfVector2i pos;

	pos.x = sfRenderWindow_getSize(window).x / 2;
	pos.y = sfRenderWindow_getSize(window).y / 2;
	sfMouse_setPositionRenderWindow(pos, window);
}

void switch_cursor_lock(camera_t *cam)
{
	cam->cursor_locked = !cam->cursor_locked;
	sfRenderWindow_setMouseCursorVisible(cam->window, !cam->cursor_locked);
}

void handle_mouse(game_t *game, camera_t *cam, sfRenderWindow *window)
{
	sfVector2i pos = sfMouse_getPositionRenderWindow(window);
	game->mouse_pos = my_memdup((void *)&pos, sizeof(sfVector2i));
	sfVector2u c = sfRenderWindow_getSize(window);
	sfVector2i relative;

	relative.x = pos.x - c.x / 2;
	relative.y = pos.y - c.y / 2;
	if (cam->cursor_locked) {
		cam->rot.x -= relative.x * SENSIVITY;
		cam->rot.y -= relative.y * SENSIVITY;
		center_mouse(window);
	}
	cam->rot.y = cam->rot.y > 89 ? 89 : cam->rot.y;
	cam->rot.y = cam->rot.y < -89 ? -89 : cam->rot.y;
	cam->last_mouse_pos.x = pos.x;
	cam->last_mouse_pos.y = pos.y;
}

