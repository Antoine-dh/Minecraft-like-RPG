/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by lucas_ben
*/

#ifndef MY_RPG_UI_H
#define MY_RPG_UI_H

#include <SFML/Graphics.h>
#include <math.h>
#include "list.h"

#define TOOLBAR_NAME "toolbar"
#define ITEMS_SHEET_NAME "items"
#define CROSSBAR_NAME "crossbar"
#define LOADING_SCREEN_NAME "loading_screen"
#define PAUSE_SCREEN_NAME "pause_screen"
#define INVENTORY_NAME "inventory_screen"
#define INVENTORY_BACKGROUND_NAME "inventory_background"
#define LOADING_NEW_MAP_SCREEN "loading_new_map_screen"
#define STATS_SCREEN "stats_screen"
#define DEATH_SCREEN "death_screen"

#define STATS_LIFE_TEXT_ID  0
#define STATS_DEFENSE_TEXT_ID 1
#define STATS_ATTACK_TEXT_ID 2
#define STATS_EXPERIENCE_TEXT_ID 3
#define STATS_LEVEL_TEXT_ID 4

static const int SLOTS_ID[] = {
	1,
	3,
	5,
	7,
	9,
	11,
	13,
	15,
	17,
	-1
};

static const int UNDER_SLOTS_ID[] = {
	0,
	2,
	4,
	6,
	8,
	10,
	12,
	14,
	16,
	-1
};

typedef struct game game_t;

typedef struct ui ui_t;
typedef struct ui_template ui_template_t;

enum button_state {
	FREE,
	MOUSE_OVER,
	CLICKED,
};

typedef struct {
	char *value;
	int size;
	sfColor color;
	sfVector2f position;
} text_template_t;

typedef struct {
	char *image_name;
	sfVector2f position;
	sfVector2f size;
	sfVector3f split_info;
} image_template_t;

typedef struct {
	char *text_value;
	int text_size;
	sfVector2f size;
	sfVector2f position;
	char *texture_path;
	void (*on_click)(game_t *data);
} button_template_t;

typedef struct {
	char *texture_path;
	sfVector2f size;
} panel_template_t;

struct ui_template {
	char *name;
	panel_template_t panel;
	float life_time;
	void (*buttons_generation_func)(game_t *game, ui_template_t *ui);
	button_template_t buttons[51];
	void (*images_generation_func)(game_t *game, ui_template_t *ui);
	image_template_t images[51];
	text_template_t texts[51];
};

typedef struct {
	text_template_t *template;
	sfText *text;
} text_t;

typedef struct {
	image_template_t *template;
	sfRectangleShape *rectangle;
	sfTexture *texture;
} image_t;

typedef struct {
	button_template_t *template;
	sfText *text;
	sfRectangleShape *rectangle;
	sfTexture *texture;
	enum button_state state;
} button_t;

typedef struct {
	panel_template_t *template;
	sfRectangleShape *rectangle;
	sfTexture *texture;
	sfVector2f draw_position;
} panel_t;

struct ui {
	float life_time;
	float unmodified_life_time;
	int draw;
	char *name;
	panel_t *panel;
	list_t *buttons;
	list_t *images;
	list_t *texts;
};

float from_coord_x_to_screen_x(game_t *game, float x);
float from_coord_y_to_screen_y(game_t *game, float y);

void exit_game(game_t *game);
void remove_loading_screen(game_t *game);
void generate_toolbar_slots(game_t *game, ui_template_t *ui);
void generate_inventory_slots(game_t *game, ui_template_t *ui);
void add_inventory(game_t *game, int item_id);
void remove_inventory(game_t *game, int item_id);
void scroll_mouse_toolbar(game_t *game, int up_or_down);
void exit_pause(game_t *game);
void goto_menu(game_t *game);
int get_slot_image_id(int slot_id);
text_t *get_stats_corresponding_text(ui_t *ui, int id);
void set_stats_life(game_t *game, int min, int max);
void set_stats_defense(game_t *game, int value);
void set_stats_attack(game_t *game, int value);
void set_stats_experience(game_t *game, int min, int max);
void set_stats_level(game_t *game, int value);

static const ui_template_t UI_TEMPLATES[] = {
	{ //LOADING_SCREEN
		name : LOADING_SCREEN_NAME,
		panel : {texture_path : "menu", size : {1920, 1080}},
		INFINITY,
		buttons_generation_func : NULL,
		buttons : {
			{
				text_value : "PLAY",
				text_size : 26,
				size : {300, 50},
				position : {810, 390},
				texture_path : "large_button",
				on_click : remove_loading_screen
			},
			{
				text_value : "EXIT",
				text_size : 26,
				size : {300, 50},
				position : {810, 490},
				texture_path : "large_button",
				on_click : exit_game
			}, {NULL}
		},
		images_generation_func : NULL,
		images : {
			{
				image_name : "logo",
				position : {1920 / 2 - 350, 100},
				size : {700, 200},
				split_info : {1, 1, 0}
			}, {NULL}
		},
		texts : {{value : NULL, size : -1}}
	}
	,
	{  //BOTTOM_TOOLBAR
		name : TOOLBAR_NAME,
		panel : {NULL, {0, 0}},
		INFINITY,
		buttons_generation_func : NULL,
		buttons : {{NULL}},
		images_generation_func : &generate_toolbar_slots,
		images : {{NULL}},
		texts : {{value : NULL, size : -1}}
	}
	,
	{  //CROSSBAR
		name : CROSSBAR_NAME,
		panel : {NULL, {0, 0}},
		INFINITY,
		buttons_generation_func : NULL,
		buttons : {{NULL}},
		images_generation_func : NULL,
		images : {
			{
				image_name : "crossbar",
				position : {1920 / 2, 1080 / 2},
				size : {16, 16},
				split_info : {1, 1, 0}
			}, {NULL}
		},
		texts : {{value : NULL, size : -1}}
	}
	,
	{  //INVENTORY BACKGROUND
		name : INVENTORY_BACKGROUND_NAME,
		panel : {texture_path : "background_inventory",
			{.x = 1920, .y = 1080}},
		INFINITY,
		buttons_generation_func : NULL,
		buttons : {{NULL}},
		images_generation_func : NULL,
		images : {{NULL}},
		texts : {{value : NULL, size : -1}}
	}
	,
	{  //INVENTORY
		name : INVENTORY_NAME,
		panel : {texture_path : "panel", {.x = 225, .y = 510}},
		INFINITY,
		buttons_generation_func : NULL,
		buttons : {{NULL}},
		images_generation_func : &generate_inventory_slots,
		images : {{NULL}},
		texts : {{value : NULL, size : -1}}
	}
	,
	{  //LOADING_NEW_MAP_SCREEN
		name: LOADING_NEW_MAP_SCREEN,
		panel : {texture_path : "loading_map", {1920, 1080}},
		INFINITY,
		buttons_generation_func : NULL,
		buttons : {{NULL}},
		images_generation_func : NULL,
		images : {{NULL}},
		texts : {
			{
				value : "Loading map ...",
				size : 24,
				color : (sfColor){.r = 255, .g = 255,
					.b = 255, .a = 255},
				position : {.x = 1920 / 2 - 24 * 8 / 2,
					.y = 1080 / 2}
			}, {value : NULL, size : -1}
		}
	}
	,
	{  //POP-UP
		name: "TextBox",
		panel: {texture_path: "panel", {.x = 500, .y = 100}},
		6.0f,
		buttons_generation_func : NULL,
		buttons : {{NULL}},
		images_generation_func : NULL,
		images : {
			{
				image_name : "golden_apple",
				position : {500 - 80, 10},
				size : {70, 70},
				split_info : {1, 1, 0}
			},{NULL}
		},
		texts : {
			{
				value : "Text",
				size: 18,
				color : (sfColor){.r = 0, .g = 0, .b = 0,
					.a = 255},
				position : {.x = 10, .y = 15}
			}, {value : NULL, size : -1}
		}
	}
	, {  //STATS
		name : STATS_SCREEN, panel : {texture_path : "panel",
			{.x = 225, .y = 300}},
		INFINITY, buttons_generation_func : NULL, buttons : {
			{NULL}},
		images_generation_func : NULL,
		images : {
			{image_name : "stats_life", position : {.x = 35,
				.y = 50}, size : {40, 40}
				, split_info : {1, 1, 0}},
			{image_name : "stats_defence", position : {.x = 35,
				.y = 100}, size : {40, 40},
				split_info : {1, 1, 0}},
			{image_name : "stats_attack", position : {.x = 35,
				.y = 150}, size : {
				40, 40}, split_info : {1, 1, 0}},
			{image_name : "stats_experience", position :
				{.x = 35, .y = 200}, size : {
				40, 40}, split_info : {1, 1, 0}},
			{NULL}},
	        texts : {
			{value : NULL, size: 16, color : (sfColor){.r = 0,
				.g = 0, .b = 0, .a = 255}, position :
				{.x = 90, .y = 70}},
			{value : NULL, size: 16, color : (sfColor){.r = 0,
				.g = 0, .b = 0, .a = 255}, position :
				{.x = 90, .y = 120}},
			{value : NULL, size: 16, color : (sfColor){.r = 0,
				.g = 0, .b = 0, .a = 255}, position :
				{.x = 90, .y = 170}},
			{value : NULL, size: 16, color : (sfColor){.r = 0,
				.g = 0, .b = 0, .a = 255}, position :
				{.x = 90, .y = 220}},
			{value : NULL, size: 16, color : (sfColor){.r = 0,
				.g = 0, .b = 0, .a = 255}, position :
				{.x = 110, .y = 260}},
			{value : NULL, size : -1}}
	}
	,
	{  //PAUSE_SCREEN
	name : PAUSE_SCREEN_NAME,
		panel : {texture_path : "background_inventory",
			{.x = 1920, .y = 1080}},
		INFINITY,
		buttons_generation_func : NULL,
		buttons : {
			{
				text_value : "RESUME",
				text_size : 26,
				size : {300, 50},
				position : {810, 490},
				texture_path : "large_button",
				on_click : exit_pause
			},
			{
				text_value : "MENU",
				text_size : 26,
				size : {300, 50},
				position : {810, 550},
				texture_path : "large_button",
				on_click : goto_menu
			},
			{
				text_value : "QUIT",
				text_size : 26,
				size : {300, 50},
				position : {810, 610},
				texture_path : "large_button",
				on_click : exit_game
			},
			{NULL}
		},
		images_generation_func : NULL,
		images : {
			{image_name : "pause_logo", position : {.x = 1920 / 2 -
				630 / 2 - 40,
				.y = 50}, size : {630, 500}
				, split_info : {1, 1, 0}
			}, {NULL}
		},
		texts : {{value : NULL, size : -1}}
	}
	,
	{  //DEATH_SCREEN
		name : DEATH_SCREEN,
		panel : {texture_path : "background_inventory",
			{.x = 1920, .y = 1080}},
		INFINITY,
		buttons_generation_func : NULL,
		buttons : {
			{
				text_value : "RESPAWN",
				text_size : 26,
				size : {300, 50},
				position : {810, 550},
				texture_path : "large_button",
				on_click : goto_menu
			},
			{
				text_value : "QUIT",
				text_size : 26,
				size : {300, 50},
				position : {810, 610},
				texture_path : "large_button",
				on_click : exit_game
			},
			{NULL}
		},
		images_generation_func : NULL,
		images : {
			{
				image_name : "troll_loose",
				position : {.x = 1920 / 2 -
					630 / 2 - 20, .y = 50},
				size : {480, 450},
				split_info : {1, 1, 0}
			}, {NULL}

		},
		texts : {{value : NULL, size : -1}}
	}
	,
	{NULL}
};

//	UI
void update_ui(game_t *game);
void generate_ui(game_t *game);
ui_t *get_ui_by_name(game_t *game, char *name);

//	DRAW
void draw_ui(game_t *game);
void draw_image(game_t *game, image_t *image);
void draw_button(game_t *game, button_t *button);
void draw_button_text(game_t *game, button_t *button);
void draw_panel_text(game_t *game,  ui_t *ui, text_t *text);

//	UPDATE
void update_button(game_t *game, panel_t *panel, button_t *button);
void update_image(panel_t *panel, image_t *image);

//	TEXT
sfText *create_ui_text(char *value, int size);

//	BUTTON
button_t *get_ui_button(ui_t *ui, int id);
void button_set_texture(button_t *button, int texture_id);

//	IMAGES
image_t *get_ui_image(ui_t *ui, int id);
void image_set_texture(image_t *image);

//	SLOTS
int get_slot_id(int slot_num);
void set_slot_image(game_t *game, int slot_id, sfVector3f split);
void set_under_slot_image(game_t *game, int slot_id, int sheet_id);

//	TEMPLATES
ui_t *from_template_to_ui(game_t *game, list_t *textures,
	ui_template_t template);
text_t *from_template_to_text(text_template_t *template);

#endif //MY_RPG_UI_H
