/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#include <SFML/System.h>
#include <math.h>
#include "game.h"
#include "vector.h"

void camera_update(camera_t *cam)
{
	sfVector2u win_size = sfRenderWindow_getSize(cam->window);
	sfVector3f dir = vector_from_angle(&cam->rot);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(cam->fov, (double)win_size.x / win_size.y, cam->near,
		cam->far);
	cam->look_at = vector3_add(&cam->pos, &dir);
	gluLookAt(cam->pos.x, cam->pos.y, cam->pos.z, cam->look_at.x,
		cam->look_at.y, cam->look_at.z, 0, 1, 0);
}

camera_t *camera_create(sfRenderWindow *window)
{
	camera_t *cam = malloc(sizeof(camera_t));

	memset(cam, 0, sizeof(camera_t));
	cam->window = window;
	cam->fov = FOV;
	cam->near = 0.1f;
	cam->far = 200.0f;
	cam->cursor_locked = sfTrue;
	return (cam);
}
