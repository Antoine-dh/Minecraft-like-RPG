/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#ifndef MY_RPG_LIGHTNING_H
#define MY_RPG_LIGHTNING_H

static const float AMBIENT_LIGHT[] = {0.3f, 0.3f, 0.3f, 1.0f};
static const float EMISSION_LIGHT[] = {0.3f, 0.3f, 0.3f, 1.0f};
static const float DIFFUSE_LIGHT[] = {0.8f, 0.8f, 0.8f, 1.0f};
static const float SUN_SPEED = 0.05f;

void update_lightning(float dt);

#endif //MY_RPG_LIGHTNING_H
