/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#include <fcntl.h>
#include <stdio.h>
#include "my.h"
#include "saving.h"

save_t *save_create(const char *name, char **data)
{
	save_t *save = malloc(sizeof(save_t));

	if (save == NULL || name == NULL || data == NULL)
		return (NULL);
	save->name = my_strdup(name);
	if (save->name == NULL)
		return (NULL);
	save->data = data;
	return (save);
}

static void save_entry_write(int fd, save_t *save)
{
	size_t len = my_array_len((void **)save->data);

	write(fd, save->name, my_strlen(save->name));
	write(fd, "=", 1);
	for (size_t i = 0 ; i < len ; ++i) {
		write(fd, save->data[i], my_strlen(save->data[i]));
		if (i < len - 1)
			write(fd, ":", 1);
	}
	write(fd, "\n", 1);
}

bool_t save_write(list_t *save, const char *filename)
{
	int fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644);

	if (fd == -1)
		return (FALSE);
	for (list_t *tmp = save ; tmp != NULL ; tmp = tmp->next)
		save_entry_write(fd, tmp->data);
	return (TRUE);
}

save_t *save_entry_load(const char *line)
{
	save_t *save;
	char **entry = my_str_split(line, "=");
	char **arr;

	if (entry == NULL || my_array_len((void **)entry) != 2)
		return (free(entry), NULL);
	arr = my_str_split(entry[1], ":");
	if (arr == NULL) {
		my_free_array((void **)entry);
		return (NULL);
	}
	save = save_create(entry[0], arr);
	return (save);
}

list_t *save_load(const char *path)
{
	list_t *list = NULL;
	char *line = NULL;
	size_t size = 0;
	FILE *file = fopen(path, "r");
	save_t *save;

	if (file == NULL)
		return (NULL);
	while (getline(&line, &size, file) != -1) {
		save = save_entry_load(my_str_rstrip(line, " \t\n"));
		if (save != NULL)
			list_push(&list, save);
	}
	return (list);
}
