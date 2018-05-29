/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#include "my.h"
#include "vector.h"

sfVector3f vector3_cross_product(const sfVector3f *a, const sfVector3f *b)
{
	sfVector3f result;

	result.x = a->y * b->z - a->z * b->y;
	result.y = a->z * b->x - a->x * b->z;
	result.z = a->x * b->y - a->y * b->x;
	return (result);
}

float vector3_magnitude(const sfVector3f *v)
{
	return (sqrtf((v->x * v->x) + (v->y * v->y) + (v->z * v->z)));
}

float vector3_distance(const sfVector3f *a, const sfVector3f *b)
{
	float i;

	i = sqrtf(((b->x - a->x) * (b->x - a->x) +
		(b->y - a->y) * (b->y - a->y) * (b->z - a->z) * (b->z - a->z)));
	return (ABS(i));
}

sfVector3f vector3_normalize(const sfVector3f *vect)
{
	float magnitude = vector3_magnitude(vect);
	sfVector3f result;

	if (magnitude == 0)
		return (*vect);
	result.x = vect->x / magnitude;
	result.y = vect->y / magnitude;
	result.z = vect->z / magnitude;
	return (result);
}

sfVector3f vector_from_angle(sfVector2f *angle)
{
	sfVector3f dir;
	float tmp = cosf(TO_RAD(angle->y));

	dir.x = tmp * sinf(TO_RAD(angle->x));
	dir.y = sinf(TO_RAD(angle->y));
	dir.z = tmp * cosf(TO_RAD(angle->x));
	return (dir);
}
