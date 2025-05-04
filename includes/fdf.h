/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:49:41 by skomatsu          #+#    #+#             */
/*   Updated: 2025/05/04 16:15:45 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <fcntl.h>
#include <math.h>
#include "libft.h"
#include "get_next_line.h"
#include "ft_printf.h"
#include "mlx.h"
#include "stdlib.h"

typedef struct s_point
{
    int x;
    int y;
    int z;
}   t_point;

typedef struct s_map
{
    int width;
    int height;
    int color;
    int zoom;
    int shift_x;
    int shift_y;
    float rotation;
    void    *mlx_ptr;
    void    *win_ptr;
    t_point **points;  
}   t_map;



void    free_map(t_point **map, int index);
void    read_file(char *filename, t_map *data);
void    draw(t_map *map);
void    zoom(t_map *map, t_point p1, t_point p2);


#endif