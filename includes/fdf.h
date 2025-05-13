/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:49:41 by skomatsu          #+#    #+#             */
/*   Updated: 2025/05/13 11:47:14 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft.h"
#include "get_next_line.h"
#include "ft_printf.h"
#include "mlx.h"
#include <fcntl.h>
#include <math.h>
#include <stdlib.h>
#include <X11/keysym.h>

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

typedef struct s_point
{
    int x;
    int y;
    int z;
    int color;
}   t_point;

typedef struct s_map
{
    int width;
    int height;
    int zoom;
    int shift_x;
    int shift_y;
    float rotation;
    int color;
    void    *mlx_ptr;
    void    *win_ptr;
    void    *img_ptr;
    char    *addr;
    int     bpp;
    int     line_length;
    int     endian;
    
    t_point **points;  
}   t_map;



void    free_map(t_point **map, int index);
void    read_file(char *filename, t_map *data);
void  get_fill(char *file_name, t_map *data);
void    draw(t_map *map);
void    transform(t_map *map, t_point *p1, t_point *p2);
int     deal_key(int key, t_map *data);
void    fdf(t_map *data);
int     close_window(t_map *map);
#endif