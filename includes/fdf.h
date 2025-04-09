/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 22:54:52 by skomatsu          #+#    #+#             */
/*   Updated: 2025/03/27 09:56:29 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "../libft/includes/libft.h"
#include "../libft/includes/ft_printf.h"
#include "../libft/includes/get_next_line.h"
//#include "../minilibx_macos/mlx.h"//

typedef struct s_fdf
{
    int width;
    int height;
    int **z_matrix;
    int zoom;
    int color;
    int shift_x;
    float rotation;
    void *mlx_ptr;
    void *win_ptr;
}   t_fdf;

#endif

