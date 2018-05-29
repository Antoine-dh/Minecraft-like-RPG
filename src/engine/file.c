/*
** EPITECH PROJECT, 2018
** file
** File description:
** Created by lucas_ben,
*/

#include "game.h"

char *get_full_path(char *path, char *file)
{
	return (my_strcat_dup(my_strcat_dup(path, "/"), file));
}

int file_extension(const char *str, const char *extension)
{
	int extension_length = (int)my_strlen(extension);

	for (int i = 0 ; str[i] != '\0' ; i++)
		for (int j = 0 ; str[i + j] == extension[j] ; j++)
			if (j == extension_length)
				return (1);
	return (0);
}

char *get_filename(const char *path)
{
	char **arr = my_str_split(path, "/");
	char *filename = NULL;
	size_t len;
	size_t i;

	if (arr == NULL)
		return (NULL);
	len = my_array_len((void **)arr);
	if (len == 0)
		return (NULL);
	i = my_strlen(arr[len - 1]);
	if (my_strindex('.', arr[len - 1]) == -1) {
		filename = my_strdup(arr[len - 1]);
		return (my_free_array((void **)arr), filename);
	}
	for (; i > 0 && arr[len - 1][i] != '.' ; --i);
	filename = my_strndup(arr[len - 1], i);
	my_free_array((void **)arr);
	return (filename);
}

list_t *file_to_list(FILE *file)
{
	char *line = NULL;
	size_t line_length = 0;
	list_t *node = NULL;
	list_t *last = NULL;

	while (getline(&line, &line_length, file) != -1) {
		my_str_rstrip(line, " \t\n");
		if (my_strlen(line) == 0)
			continue;
		if (node == NULL)
			last = list_append(&node, my_strdup(line));
		else
			last = list_append(&last, my_strdup(line));
	}
	free(line);
	return (node);
}
