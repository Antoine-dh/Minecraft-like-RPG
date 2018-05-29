/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#ifndef MY_RPG_VECTOR_H
#define MY_RPG_VECTOR_H

#include <SFML/Graphics.h>
#include <math.h>

typedef struct vector3i {
	int x;
	int y;
	int z;
} vector3i_t;

sfVector3f vector3_add(const sfVector3f *a, const sfVector3f *b);
sfVector3f vector3_sub(const sfVector3f *a, const sfVector3f *b);
sfVector3f vector3_mul(const sfVector3f *a, const sfVector3f *b);
sfVector3f vector3_div(const sfVector3f *a, const sfVector3f *b);

sfVector3f vector3_normalize(const sfVector3f *vect);
float vector3_distance(const sfVector3f *a, const sfVector3f *b);
float vector3_magnitude(const sfVector3f *v);
sfVector3f vector3_cross_product(const sfVector3f *a, const sfVector3f *b);
sfVector3f vector_from_angle(sfVector2f *angle);

#endif //MY_RPG_VECTOR_H
