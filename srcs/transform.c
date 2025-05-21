/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:37:09 by skomatsu          #+#    #+#             */
/*   Updated: 2025/05/17 17:52:36 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_point *p, t_map *map)
{
	int	temp_x;
	int	temp_y;

	temp_x = p->x;
	temp_y = p->y;
	p->x = (temp_x - temp_y) * cos(map->rotation);
	p->y = -(p->z) + (temp_x + temp_y) * sin(map->rotation);
}

void	transform(t_map *map, t_point *p1, t_point *p2)
{
	p1->x *= map->zoom;
	p2->x *= map->zoom;
	p1->y *= map->zoom;
	p2->y *= map->zoom;
	p1->z *= map->zoom / 10;
	p2->z *= map->zoom / 10;
	isometric(p1,map);
	isometric(p2,map);
	p1->x += map->shift_x;
	p2->x += map->shift_x;
	p1->y += map->shift_y;
	p2->y += map->shift_y;
}
