/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 22:54:52 by skomatsu          #+#    #+#             */
/*   Updated: 2025/04/28 17:30:14 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <fcntl.h>
#include <math.h>
#include "../libft/includes/libft.h"
#include "../libft/includes/ft_printf.h"
#include "../libft/includes/get_next_line.h"
#include "../minilibx-linux/mlx.h"

typedef struct s_fdf
{
    int width;
    int height;
    int **z_matrix;
    int zoom;
    int color;
    int shift_x;
    int shift_y;
    float rotation;
    void *mlx_ptr;
    void *win_ptr;
}   t_fdf;

void    draw(t_fdf *data);
void    read_file(t_fdf *data, char *file_name);
void    bresenham(float x1, float y1, float x2, float y2, t_fdf *data);


#endif

