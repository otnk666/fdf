/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:25:23 by skomatsu          #+#    #+#             */
/*   Updated: 2025/05/15 13:32:43 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, t_map *data)
{
	ft_printf("%d\n", key);
	if (key == XK_Up)
		data->shift_y -= 10;
	if (key == XK_Down)
		data->shift_y += 10;
	if (key == XK_Left)
		data->shift_x -= 10;
	if (key == XK_Right)
		data->shift_x += 10;
	if (key == XK_z && data->zoom > 1.0)
		data->zoom -= 1;
	if (key == XK_x && data->zoom < 100)
		data->zoom += 1;
	if (key == XK_Escape)
		close_window(data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	ft_bzero(data->addr, WIN_WIDTH * WIN_HEIGHT * (data->bpp / 8));
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_map	*data;

	if (argc != 2)
	{
		printf("Error: usage: ./fdf filename\n");
		return (1);
	}
	data = (t_map *)malloc(sizeof(t_map));
	if (!data)
		return (1);
	data->width = 0;
	data->height = 0;
	data->points = NULL;
	read_file(argv[1], data);
	fdf(data);
}
