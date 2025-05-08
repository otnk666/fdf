/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 04:26:49 by skomatsu          #+#    #+#             */
/*   Updated: 2025/05/07 21:55:37 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    my_mlx_pixel_put(t_map *data, int x, int y, int color)
{
    char *dst;
    if(x >= 0 && y >= 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
    {
        dst = data->addr + (y*data->line_length + x*(data->bpp / 8));
        *(unsigned int *) dst = color;
    }
}

int    ft_abs(int i)
{
    if(i < 0)
        return (-i);
    return(i);
}

void    draw_line(t_map *map, t_point p1, t_point p2, float steps)
{
    float   dx;
    float   dy;
    float   x;
    float   y;
    int     i;

    dx = (p2.x - p1.x) / steps;
    dy = (p2.y - p1.y) / steps;
    x = p1.x;
    y = p1.y;
    i = 0;
    while (i <= steps)
    {
        my_mlx_pixel_put(map, (int)(x+0.5), (int)(y+0.5), map->color);
        x += dx;
        y += dy;
        i++;
    }
}

void    drawDDA(t_map *map, t_point p1, t_point p2)
{
    float   dx;
    float   dy;
    float   steps;
    // t_point p1_copy = p1;
    // t_point p2_copy = p2;
    
    // p1_copy = p1;
    // p2_copy = p2;
    map->color = (p1.z != 0 || p2.z != 0) ? 0xe80c0c : 0xffffff;
    transform(map, &p1, &p2);
    dx = p2.x - p1.x;
    dy = p2.y - p1.y;
    if (fabs(dx) >= fabs(dy))
        steps = fabs(dx);
    else
        steps = fabs(dy);
    if (steps < 1)
        steps = 1;
    draw_line(map,p1, p2, steps);
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
