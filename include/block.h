/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#ifndef MY_RPG_BLOCK_H
#define MY_RPG_BLOCK_H

#include "vector.h"
#include "physics.h"

#define MAX_TILES	(256)

enum {
	BLOCK_NULL = 0,
	BLOCK_SOLID = 1,
	BLOCK_SLOW = 2,
	BLOCK_DAMAGE = 4,
	BLOCK_ICE = 8,
	BLOCK_ALPHA = 16,
	BLOCK_LIQUID = 32,
	BLOCK_LIGHT = 64
};

/* up down front back left right */
typedef int block_faces_t[6];

typedef struct block {
	int id;
	vector3i_t pos;
	int attribute;
	block_faces_t faces;
} block_t;

static const block_t BLOCKS[] = {
	{0, {}, BLOCK_NULL, {}},
	{1, {}, BLOCK_SOLID, {1, 1, 1, 1, 1, 1}},
	{2, {}, BLOCK_SOLID, {0, 2, 3, 3, 3, 3}},
	{3, {}, BLOCK_SOLID, {2, 2, 2, 2, 2, 2}},
	{4, {}, BLOCK_SOLID, {16, 16, 16, 16, 16, 16}},
	{5, {}, BLOCK_SOLID, {4, 4, 4, 4, 4, 4}},
	{6, {}, BLOCK_SOLID, {17, 17, 17, 17, 17, 17}},
	{7, {}, BLOCK_SOLID, {18, 18, 18, 18, 18, 18}},
	{8, {}, BLOCK_SOLID, {19, 19, 19, 19, 19, 19}},
	{9, {}, BLOCK_SOLID, {32, 32, 32, 32, 32, 32}},
	{10, {}, BLOCK_SOLID, {33, 33, 33, 33, 33, 33}},
	{11, {}, BLOCK_SOLID, {34, 34, 34, 34, 34, 34}},
	{12, {}, BLOCK_SOLID, {36, 36, 36, 36, 36, 36}},
	{13, {}, BLOCK_SOLID, {21, 21, 20, 20, 20, 20}},
	{14, {}, BLOCK_SOLID, {21, 21, 116, 116, 116, 116}},
	{15, {}, BLOCK_SOLID, {21, 21, 117, 117, 117, 117}},
	{16, {}, BLOCK_SOLID | BLOCK_ALPHA, {52, 52, 52, 52, 52, 52}},
	{17, {}, BLOCK_SOLID | BLOCK_ALPHA, {132, 132, 132, 132, 132, 132}},
	{18, {}, BLOCK_SOLID, {48, 48, 48, 48, 48, 48}},
	{19, {}, BLOCK_SOLID | BLOCK_ALPHA, {49, 49, 49, 49, 49, 49}},
	{20, {}, BLOCK_SOLID, {160, 160, 160, 160, 160, 160}},
	{21, {}, BLOCK_SOLID, {144, 144, 144, 144, 144, 144}},
	{22, {}, BLOCK_SOLID, {176, 208, 192, 192, 192, 192}},
	{23, {}, BLOCK_SOLID, {74, 74, 74, 74, 74, 74}},
	{24, {}, BLOCK_SLOW | BLOCK_ALPHA, {11, 11, 11, 11, 11, 11}},
	{25, {}, BLOCK_SOLID, {64, 64, 64, 64, 64, 64}}, /* wool */
	{26, {}, BLOCK_SOLID, {113, 113, 113, 113, 113, 113}},
	{27, {}, BLOCK_SOLID, {114, 114, 114, 114, 114, 114}},
	{28, {}, BLOCK_SOLID, {129, 129, 129, 129, 129, 129}},
	{29, {}, BLOCK_SOLID, {130, 130, 130, 130, 130, 130}},
	{30, {}, BLOCK_SOLID, {145, 145, 145, 145, 145, 145}},
	{31, {}, BLOCK_SOLID, {146, 146, 146, 146, 146, 146}},
	{32, {}, BLOCK_SOLID, {161, 161, 161, 161, 161, 161}},
	{33, {}, BLOCK_SOLID, {162, 162, 162, 162, 162, 162}},
	{34, {}, BLOCK_SOLID, {177, 177, 177, 177, 177, 177}},
	{35, {}, BLOCK_SOLID, {178, 178, 178, 178, 178, 178}},
	{36, {}, BLOCK_SOLID, {193, 193, 193, 193, 193, 193}},
	{37, {}, BLOCK_SOLID, {194, 194, 194, 194, 194, 194}},
	{38, {}, BLOCK_SOLID, {209, 209, 209, 209, 209, 209}},
	{39, {}, BLOCK_SOLID, {210, 210, 210, 210, 210, 210}},
	{40, {}, BLOCK_SOLID, {225, 225, 225, 225, 225, 225}},
	{41, {}, BLOCK_SOLID, {22, 22, 22, 22, 22, 22}},
	{42, {}, BLOCK_SOLID, {23, 23, 23, 23, 23, 23}},
	{43, {}, BLOCK_SOLID, {24, 24, 24, 24, 24, 24}},
	{44, {}, BLOCK_SOLID, {6, 6, 5, 5, 5, 5}},
	{45, {}, BLOCK_SOLID, {7, 7, 7, 7, 7, 7}},
	{46, {}, BLOCK_SOLID, {4, 4, 35, 35, 35, 35}},
	{47, {}, BLOCK_SOLID, {54, 54, 54, 54, 54, 54}},
	{48, {}, BLOCK_LIQUID | BLOCK_DAMAGE | BLOCK_SLOW,
		{230, 230, 230, 230, 230, 230}},
	{49, {}, BLOCK_SOLID, {103, 103, 103, 103, 103, 103}},
	{50, {}, BLOCK_SOLID | BLOCK_SLOW, {104, 104, 104, 104, 104, 104}},
	{51, {}, BLOCK_SOLID | BLOCK_LIGHT, {105, 105, 105, 105, 105, 105}},
	{52, {}, BLOCK_SOLID, {224, 224, 224, 224, 224, 224}},
	{53, {}, BLOCK_SOLID, {37, 37, 37, 37, 37, 37}},
	{53, {}, BLOCK_SOLID | BLOCK_DAMAGE, {69, 70, 70, 70, 70, 70}},
	{54, {}, BLOCK_LIQUID | BLOCK_SLOW,
		{214, 214, 214, 214, 214, 214}},
};

static const vector3i_t BLOCK_POS[] = {
	{0, 1, 0},
	{0, -1, 0},
	{0, 0, -1},
	{0, 0, 1},
	{1, 0, 0},
	{-1, 0, 0}
};

static const sfVector3f CUBE_VERTS[] = {
	{1, 1, 0},
	{1, 0, 0},
	{0, 0, 0},
	{0, 1, 0},
	{1, 1, 1},
	{1, 0, 1},
	{0, 0, 1},
	{0, 1, 1}
};

static const sfVector2f CUBE_UV[] = {
	{0, 0},
	{0, 1},
	{1, 1},
	{1, 0}
};

static const sfVector3f CUBE_NORMALS[] = {
	{0.0f, 1.0f, 0.0f},
	{0.0f, -1.0f, 0.0f},
	{0.0f, 0.0f, -1.0f},
	{0.0f, 0.0f, 1.0f},
	{1.0f, 0.0f, 0.0f},
	{-1.0f, 0.0f, 0.0f},
};

typedef int vert_quad_t[4];

static const vert_quad_t CUBE_FACES_V[] = {
	{4, 0, 3, 7},
	{1, 5, 6, 2},
	{0, 1, 2, 3},
	{7, 6, 5, 4},
	{4, 5, 1, 0},
	{3, 2, 6, 7}
};

void block_draw(const map_t *map, vector3i_t *pos, float elapsed);
void block_set_id(block_t *block, int id);
block_t *get_map_block(const map_t *map, int x, int y, int z);
void place_block(game_t *game, map_t *map);
void break_block(game_t *game);

#endif //MY_RPG_BLOCK_H
