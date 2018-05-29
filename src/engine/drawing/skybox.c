/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#include "game.h"
#include "skybox.h"

static void draw_sky_face(size_t i)
{
	for (size_t j = 0 ; j < 4 ; ++j) {
		glTexCoord2f(SKY_UV[i][j].x, 1 - SKY_UV[i][j].y);
		glVertex3f(CUBE_VERTS[CUBE_FACES_V[i][j]].x - 0.5f,
			CUBE_VERTS[CUBE_FACES_V[i][j]].y - 0.5f,
			CUBE_VERTS[CUBE_FACES_V[i][j]].z - 0.5f);
	}
}

void draw_skybox(const sfTexture *texture, const camera_t *cam)
{
	if (texture == NULL)
		return;
	glDisable(GL_LIGHTING);
	glDepthMask(GL_FALSE);
	sfTexture_bind(texture);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(cam->pos.x, cam->pos.y, cam->pos.z);
	glBegin(GL_QUADS);
	for (size_t i = 0 ; i < 6 ; ++i)
		draw_sky_face(i);
	glEnd();
	glPopMatrix();
	glDepthMask(GL_TRUE);
	glEnable(GL_LIGHTING);
}
