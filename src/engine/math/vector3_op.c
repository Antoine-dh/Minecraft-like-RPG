/*
** EPITECH PROJECT, 2017
** glPrototype
** File description:
** Created by antoine_dh,
*/

#include <SFML/System.h>
#include "vector.h"

sfVector3f vector3_add(const sfVector3f *a, const sfVector3f *b)
{
	sfVector3f result;

	result.x = a->x + b->x;
	result.y = a->y + b->y;
	result.z = a->z + b->z;
	return (result);
}

sfVector3f vector3_sub(const sfVector3f *a, const sfVector3f *b)
{
	sfVector3f result;

	result.x = a->x - b->x;
	result.y = a->y - b->y;
	result.z = a->z - b->z;
	return (result);
}

sfVector3f vector3_mul(const sfVector3f *a, const sfVector3f *b)
{
	sfVector3f result;

	result.x = a->x * b->x;
	result.y = a->y * b->y;
	result.z = a->z * b->z;
	return (result);
}

sfVector3f vector3_div(const sfVector3f *a, const sfVector3f *b)
{
	sfVector3f result = {0, 0, 0};

	if (b->x == 0 || b->y == 0 || b->z == 0)
		return (result);
	result.x = a->x / b->x;
	result.y = a->y / b->y;
	result.z = a->z / b->z;
	return (result);
}
