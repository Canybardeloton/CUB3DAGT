/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:32:01 by agiliber          #+#    #+#             */
/*   Updated: 2024/12/19 14:34:03 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*get_file_texture(char *file)
{
	int		i;
	char	*texture;

	i = 0;
	if (!file)
		return (NULL);
	while (file[i] != ' ')
		i++;
	if (!file)
		return (NULL);
	if (file[i + 1] != '\0')
		i++;
	texture = ft_strdup(&file[i]);
	return (texture);
}

int	textures_n_s(t_game_data *game, char *file)
{
	if (!file)
		return (-1);
	if (file[0] == 'N')
	{
		game->north_texture = NULL;
		game->north_texture = get_file_texture(file);
		if (game->north_texture == NULL)
			return (-1);
		if (open_texture(game->north_texture) == -1)
			return (-1);
	}
	else if (file[0] == 'S')
	{
		game->south_texture = NULL;
		game->south_texture = get_file_texture(file);
		if (game->south_texture == NULL)
			return (-1);
		if (open_texture(game->south_texture) == -1)
			return (-1);
	}
	return (0);
}

int	textures_w_e(t_game_data *game, char *file)
{
	if (!file)
		return (-1);
	if (file[0] == 'W')
	{
		game->west_texture = NULL;
		game->west_texture = get_file_texture(file);
		if (game->west_texture == NULL)
			return (-1);
		if (open_texture(game->west_texture) == -1)
			return (-1);
	}
	else if (file[0] == 'E')
	{
		game->east_texture = NULL;
		game->east_texture = get_file_texture(file);
		if (game->east_texture == NULL)
			return (-1);
		if (open_texture(game->east_texture) == -1)
			return (-1);
	}
	return (0);
}

int	textures(t_game_data *game, char *file)
{
	if (!file)
		return (-1);
	if (textures_n_s(game, file) == -1)
		return (-1);
	if (textures_w_e(game, file) == -1)
		return (-1);
	return (0);
}

int	get_textures(t_game_data *game, char **file)
{
	int	i;

	i = 0;
	if (!*file)
		return (-1);
	while (file[i])
	{
		if (textures(game, file[i]) == -1)
			return (-1);
		else if (get_colors(game, file[i]) == -1)
			return (-1);
		i++;
	}
	if (game->north_texture == NULL || game->south_texture == NULL
		|| game->west_texture == NULL || game->east_texture == NULL)
		return (-1);
	else if (game->ceiling_color == NULL || game->floor_color == NULL)
		return (-1);
	return (0);
}
