/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#include <SFML/OpenGL.h>
#include "block.h"
#include "particles.h"

void particle_draw(const particle_render_t *particle)
{
	glColor4ub(particle->color.r, particle->color.g, particle->color.b,
		particle->color.a);
	for (int i = 0 ; i < 6 ; i++) {
		glNormal3f(CUBE_NORMALS[i].x, CUBE_NORMALS[i].y,
			CUBE_NORMALS[i].z);
		for (int j = 0 ; j < 4 ; j++)
			glVertex3f((CUBE_VERTS[CUBE_FACES_V[i][j]].x - 0.5f) *
					particle->scale + particle->pos.x,
				(CUBE_VERTS[CUBE_FACES_V[i][j]].y - 0.5f) *
					particle->scale + particle->pos.y,
				(CUBE_VERTS[CUBE_FACES_V[i][j]].z - 0.5f) *
					particle->scale + particle->pos.z);
	}
}
