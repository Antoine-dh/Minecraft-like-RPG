/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#ifndef MY_RPG_CAMERA_H
#define MY_RPG_CAMERA_H

#include <SFML/Graphics.h>

static const float FOV = 70.0f;
static const float SENSIVITY = 0.2f;

typedef struct camera {
	sfRenderWindow *window;
	sfVector3f pos;
	sfVector2f rot;
	sfVector3f look_at;
	float fov;
	float near;
	float far;
	sfBool cursor_locked;
	sfVector2f last_mouse_pos;
} camera_t;

camera_t *camera_create(sfRenderWindow *window);
void camera_update(camera_t *cam);
void handle_mouse(game_t *game, camera_t *cam, sfRenderWindow *window);
void entity_lookat(entity_t *entity, sfVector3f *target, sfVector3f *axis);

#endif //MY_RPG_CAMERA_H
