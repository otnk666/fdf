/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 04:26:49 by skomatsu          #+#    #+#             */
/*   Updated: 2025/05/04 13:03:22 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int    ft_abs(int i)
{
    if(i < 0)
        return (-i);
    return(i);
}

void    drawDDA(t_map *map, t_point p1, t_point p2)
{
    float dx;
    float dy;
    float steps;
    float current_x;
    float current_y;

    map->color = ((int) p1.x-p2.x ||(int) p1.y-p2.y ) ? 0xe80c0c : 0xffffff;
    dx = ft_abs(p2.x - p1.x);
    dy = ft_abs(p2.y - p1.y);
    if (dx >= dy)
        steps = dx;
    else
        steps = dy;
    dx /= steps;
    dy /= steps;
    current_x = p1.x;
    current_y = p1.y;
    while (steps >= 0)
    {
        mlx_pixel_put(map->mlx_ptr,map->win_ptr,current_x,current_y,map->color);
        current_x += dx;
        current_y += dy;
        steps--;
    }    
}

void    draw(t_map *map)
{
    int x;
    int y;

    y = 0;
    while (y < map->height )
    {
        x = 0;
        while (x < map->width)
        {
            if (x < map->width - 1)
                drawDDA(map, map->points[y][x], map->points[y][x+1]);
            if (y < map->height - 1)
                drawDDA(map, map->points[y][x], map->points[y+1][x]);
            x++;
        }
        y++;
    }
}
