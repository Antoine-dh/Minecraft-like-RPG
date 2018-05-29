/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#include "game.h"

sfIntRect sheet_split(const sfTexture *sheet, const sfVector2u *tile_size,
	int id)
{
	sfIntRect rect;
	sfVector2u texture_size = sfTexture_getSize(sheet);

	rect.left = id % (texture_size.x / tile_size->x) * tile_size->x;
	rect.top = id / (texture_size.x / tile_size->x) * tile_size->y;
	rect.width = tile_size->x;
	rect.height = tile_size->y;
	return (rect);
}

sfVector2f uv_sheet_split(const sfTexture *texture, const sfVector2f *uv,
	const sfVector2u *tile_size, int id)
{
	sfVector2f result;
	sfVector2u texture_size = sfTexture_getSize(texture);

	result.x = id % (texture_size.x / tile_size->x) * tile_size->x +
		uv->x * tile_size->x;
	result.y = id / (texture_size.x / tile_size->x) * tile_size->y +
		uv->y * tile_size->y;
	result.x = result.x / texture_size.x;
	result.y = result.y / texture_size.y;
	return (result);
}
