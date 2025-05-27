/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:50:17 by skomatsu          #+#    #+#             */
/*   Updated: 2025/05/24 17:37:56 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(t_point **map, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_all_resources(t_map *map)
{
	if (map)
	{
		if (map->points)
			free_map(map->points, map->height);
		if (map->mlx_ptr)
		{
			if (map->img_ptr)
				mlx_destroy_image(map->mlx_ptr, map->img_ptr);
			if (map->win_ptr)
				mlx_destroy_window(map->mlx_ptr, map->win_ptr);
			mlx_destroy_display(map->mlx_ptr);
			free(map->mlx_ptr);
		}
		free(map);
	}
}
