/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh, lucas_ben
*/

#ifndef MY_RPG_GAME_H
#define MY_RPG_GAME_H

#include <string.h>
#include <stdio.h>
#include <SFML/OpenGL.h>
#include "entity.h"
#include "monster.h"
#include "physics.h"
#include "stats.h"
#include "block.h"
#include "my.h"
#include "model.h"
#include "list.h"
#include "map.h"
#include "file.h"
#include "camera.h"
#include "player.h"
#include "prefabs.h"
#include "textures.h"
#include "teleporter.h"
#include "vector.h"
#include "saving.h"
#include "particles.h"
#include "quest.h"
#include "ui.h"
#include "skybox.h"
#include "projectile.h"
#include "npc.h"
#include "sound.h"

#define RES_DIR		"resources/"
#define MODELS_DIR	RES_DIR "models/"
#define TEXTURES_DIR	RES_DIR "textures/"
#define PREFABS_DIR	RES_DIR "prefabs/"
#define MAPS_DIR	RES_DIR "maps/"
#define SOUNDS_DIR	RES_DIR "sounds/"
#define MUSIC_DIR	RES_DIR "musics/"
#define FONT_DIR	RES_DIR "fonts/"
#define NPC_DIR		RES_DIR "quests/"

#define FONT_NAME	"Minecraftia-Regular.ttf"

#define TO_SEC(x)	((x) / 1000000.0f)

typedef struct game {
	sfRenderWindow *window;
	camera_t *cam;
	map_t *map;
	player_t *player;
	sfVector2i *mouse_pos;
	list_t *entities;
	list_t *textures;
	list_t *models;
	list_t *prefabs;
	list_t *particles;
	list_t *particle_systems;
	list_t *active_quests;
	list_t *ui;
	list_t *active_ui;
	list_t *sounds;
	list_t *projectile;
	list_t *npc;
	float dt;
	float elapsed;
	int pause;
} game_t;

game_t *init_game(void);
int run_game(game_t *game);
void draw_game(game_t *game);
void free_game(game_t *game);
int load_resources(game_t *game);

void handle_events(game_t *game, sfEvent *event);

entity_t *instantiate_entity(game_t *, const prefab_t *, const sfVector3f *);
entity_t *instantiate_prefab(game_t *game, const char *name,
	const sfVector3f *pos);

sfVector2f uv_sheet_split(const sfTexture *texture, const sfVector2f *uv,
	const sfVector2u *tile_size, int id);
sfIntRect sheet_split(const sfTexture *sheet, const sfVector2u *tile_size,
	int id);
void switch_cursor_lock(camera_t *cam);
void initialize_loading_screen(game_t *game);
void destroy_non_used(game_t *game);

#endif //MY_RPG_GAME_H
