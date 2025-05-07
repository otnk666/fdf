/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:25:23 by skomatsu          #+#    #+#             */
/*   Updated: 2025/05/07 16:52:25 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     deal_key(int key, t_map *data)
{
    ft_printf("%d\n",key);
    if (key == 65362)
        data-> shift_y -= 10;
    if (key == 65364)
        data-> shift_y += 10;
    if (key == 65361)
        data-> shift_x -= 10;
    if (key == 65363)
        data-> shift_x += 10;
    mlx_clear_window(data->mlx_ptr, data->win_ptr);
    draw(data);
    return(0);
}
int main(int argc, char *argv[])
{
    t_map *data;
    
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
    
    // i = 0;
    // while(i < data->height)
    // {
    //     j = 0;
    //     while(j < data->width)
    //     {
    //         printf("%3d", data->points[i][j].z);
    //         j++;
    //     }
    //     printf("\n");
    //     i++;
    // }
    
    // free_map(data->points, data->height);
    // free(data);
        
    // return(0);
}
