/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by lucas_ben
*/

#ifndef MY_RPG_QUEST_H
#define MY_RPG_QUEST_H

enum quest_steps_enum {
	QUEST_NULL = 0,
	WALK_SOMEWHERE,
	TALK_TO,
	HAVE,
	GIVE,
	REMOVE,
	NEW_QUEST
};

typedef struct {
	enum quest_steps_enum type;
	int data[10];
} quest_step_t;

typedef struct {
	int id;
	quest_step_t steps[10];
	quest_step_t rewards[10];
} quest_template_t;

typedef struct quest {
	int id;
	int step;
} quest_t;

typedef struct game game_t;

struct quest_step {
	enum quest_steps_enum step;
	int (*fptr)(game_t *game, const int data[10]);
};

/* walk: map_id, x, y, z, radius */
int quest_walk_somewhere(game_t *game, const int data[10]);

/* talk: npc_id */
int quest_talk_to(game_t *game, const int data[10]);

/* have: item_id, amount */
int quest_have(game_t *game, const int data[10]);

/* give: item_id, amount */
int quest_give(game_t *game, const int data[10]);

/* remove: item_id, amount */
int quest_remove(game_t *game, const int data[10]);

/* new: quest_id */
int quest_new(game_t *game, const int data[10]);

static const struct quest_step STEPS[] = {
	{WALK_SOMEWHERE, &quest_walk_somewhere},
	{TALK_TO, &quest_talk_to},
	{HAVE, &quest_have},
	{GIVE, &quest_give},
	{REMOVE, &quest_remove},
	{NEW_QUEST, &quest_new}
};

static const quest_template_t QUESTS[] = {
	{id : 1,
		steps : {
			{WALK_SOMEWHERE, {1, 1, 1}},
			{QUEST_NULL, {}}
		}
		,
		rewards : {
			{NEW_QUEST, {2}},
			{GIVE, {24, 1}},
			{QUEST_NULL, {}}
		}
	},
	{id : 2,
		steps : {
			{WALK_SOMEWHERE, {2, 1, 2}},
			{QUEST_NULL, {}}
		}
		,
		rewards : {
			{REMOVE, {24, 1}},
			{GIVE, {25}},
			{QUEST_NULL, {}}
		}
	},
	{-1, {{QUEST_NULL, {}}}, {{QUEST_NULL, {}}}}
};

void update_quest(game_t *game, quest_t *quest);
int quest_add(game_t *game, int id);

#endif //MY_RPG_QUEST_H
