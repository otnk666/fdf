/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 04:26:49 by skomatsu          #+#    #+#             */
/*   Updated: 2025/05/07 18:59:56 by skomatsu         ###   ########.fr       */
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

void    drawDDA(t_map *map, t_point p1, t_point p2)
{
    float   dx;
    float   dy;
    float   steps;
    float   current_x;
    float   current_y;
    t_point p1_copy;
    t_point p2_copy;

    map->color = (p1.z != 0 || p2.z != 0) ? 0xe80c0c : 0xffffff;
    
    p1_copy = p1;
    p2_copy = p2;
    
    transform(map, &p1_copy, &p2_copy);
    
    dx = p2_copy.x - p1_copy.x;
    dy = p2_copy.y - p1_copy.y;
    
    if (fabs(dx) >= fabs(dy))
        steps = fabs(dx);
    else
        steps = fabs(dy);
        
    if (steps < 1)
        steps = 1;
    
    dx /= steps;
    dy /= steps;
    
    current_x = p1_copy.x;
    current_y = p1_copy.y;
   
    int i = 0;
    while (i <= steps)
    {
        my_mlx_pixel_put(map, (int)(current_x+0.5), (int)(current_y+0.5), map->color);
        current_x += dx;
        current_y += dy;
        i++;
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
