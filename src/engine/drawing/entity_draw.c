/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#include <entity.h>
#include "game.h"

void draw_face(face_t *face, bool_t texture)
{
	glBegin(GL_POLYGON);
	for (int i = 0 ; i < face->points_count ; ++i) {
		if (!texture || face->vt[i].x < 0)
			continue;
		glTexCoord2f(face->vt[i].x, 1 - face->vt[i].y);
		glVertex3f(face->v[i].x, face->v[i].y, face->v[i].z);
	}
	glEnd();
}

int entity_draw(entity_t *entity)
{
	model_t *frame = entity->model->frames[entity->frame_index];

	glPushMatrix();
	glTranslatef(entity->position.x, entity->position.y,
		entity->position.z);
	glRotatef(entity->rotation.x, 1, 0, 0);
	glRotatef(entity->rotation.y, 0, 1, 0);
	glRotatef(entity->rotation.z, 0, 0, 1);
	glScalef(entity->scale.x, entity->scale.y, entity->scale.z);
	if (entity->texture)
		sfTexture_bind(entity->texture);
	for (int i = 0 ; i < frame->faces_count ; ++i)
		draw_face(&frame->faces[i], (bool_t)entity->texture);
	glPopMatrix();
	return (0);
}
