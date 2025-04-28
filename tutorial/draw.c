/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:53:38 by skomatsu          #+#    #+#             */
/*   Updated: 2025/04/09 19:17:48 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include <math.h>

float     ft_abs(float i)
{
    if (i < 0)
        i *= -1;
    return(i);
}
float     ft_max(float a, float b)
{
    if (a > b)
        return(a);
    return(b);
}

void    isometric(float *x, float *y, int z)
{
    float prev_x = *x;
    float prev_y = *y;
    
    *x = (prev_x - prev_y) * cos(0.8);
    *y = (prev_x + prev_y) * sin(0.8) - z;
}


void    bresenham(float x1, float y1, float x2, float y2, t_fdf *data)
{
    float x_step;
    float y_step;
    float max;
    int z;
    int z1;
    int x_offset = 150;  // 中心に表示するためのオフセット
    int y_offset = 150;
    
    z = data->z_matrix[(int)y1][(int)x1];
    z1 = data->z_matrix[(int)y2][(int)x2];

    //zoom
    x1 *= data->zoom;
    x2 *= data->zoom;
    y1 *= data->zoom;
    y2 *= data->zoom;
    
    //color
    data->color = (z || z1) ? 0xe80c0c : 0xffffff;
    
    //3d
    isometric(&x1, &y1, z);
    isometric(&x2, &y2, z1);

    x1 += data->shift_x;
    y1 += data->shift_y;
    x2 += data->shift_x;
    y2 += data->shift_y;
     
    x_step = (x2 - x1);
    y_step = (y2 - y1);
    
    max = ft_max(ft_abs(x_step),ft_abs(y_step));
    x_step /= max;
    y_step /= max;

    while ((int)(x1-x2) || (int)(y1-y2))
    {
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x1, y1, data->color);
        x1 += x_step;
        y1 += y_step;
    }
}

void    draw(t_fdf *data)
{
    int x;
    int y;

    y = 0;
    while (y < data->height )
    {
        x = 0;
        while (x < data->width)
        {
            if (x < data->width - 1)
                bresenham(x, y, x+1, y, data);
            if (y < data->height - 1)
                bresenham(x, y, x, y+1, data);
            x++;
        }
        y++;
    }
}
