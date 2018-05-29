/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#include <SFML/OpenGL.h>
#include <math.h>
#include "lightning.h"
#include "my.h"

void update_lightning(float dt)
{
	static float elapsed;
	static float sun[] = {0.8f, 1.0f, 0.7f, 0.0f};

	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0, GL_AMBIENT, AMBIENT_LIGHT);
	glLightfv(GL_LIGHT0, GL_EMISSION, EMISSION_LIGHT);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, DIFFUSE_LIGHT);
	glLightfv(GL_LIGHT0, GL_POSITION, sun);
	sun[0] = cosf(elapsed * SUN_SPEED);
	sun[1] = ABS(cosf((elapsed * SUN_SPEED) / 2.0f));
	sun[2] = sinf(elapsed * SUN_SPEED);
	elapsed += dt;
}
