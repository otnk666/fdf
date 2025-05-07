/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:10:47 by skomatsu          #+#    #+#             */
/*   Updated: 2025/05/07 19:04:01 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    fdf(t_map *data)
{
    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr,WIN_WIDTH,WIN_HEIGHT, "FdF");
    data->img_ptr = mlx_new_image(data->mlx_ptr,WIN_WIDTH,WIN_HEIGHT);
    data->addr = mlx_get_data_addr(data->img_ptr, &(data->bpp), &(data->line_length),&(data->endian));
    data->zoom = 20;
    data->shift_x = WIN_WIDTH / 2;
    data->shift_y = WIN_HEIGHT / 2;
    draw(data);
    mlx_put_image_to_window(data->mlx_ptr,data->win_ptr,data->img_ptr, 0, 0);
    mlx_key_hook(data->win_ptr, deal_key, data);
    mlx_loop(data->mlx_ptr);
    
}   