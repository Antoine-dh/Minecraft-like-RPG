/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#ifndef MY_RPG_SKYBOX_H
#define MY_RPG_SKYBOX_H

#include <SFML/Graphics.h>

void draw_skybox(const sfTexture *texture, const camera_t *cam);

static const sfVector2f SKY_UV[][4] = {
	{{0.5, 1}, {0.5, 2 / 3.0f}, {0.25, 2 / 3.0f}, {0.25, 1}},
	{{0.5, 1 / 3.0f}, {0.5, 0.0f}, {0.25, 0.0f}, {0.25, 1 / 3.0f}},
	{{0.5, 2 / 3.0f}, {0.5, 1 / 3.0f}, {0.25, 1 / 3.0f}, {0.25, 2 / 3.0f}},
	{{1, 2 / 3.0f}, {1, 1 / 3.0f}, {0.75, 1 / 3.0f}, {0.75, 2 / 3.0f}},
	{{0.75, 2 / 3.0f}, {0.75, 1 / 3.0f}, {0.5, 1 / 3.0f}, {0.5, 2 / 3.0f}},
	{{0.25, 2 / 3.0f}, {0.25, 1 / 3.0f}, {0.0f, 1 / 3.0f}, {0, 2 / 3.0f}},
};

#endif //MY_RPG_SKYBOX_H
