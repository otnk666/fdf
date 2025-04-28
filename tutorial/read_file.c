/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:07:11 by skomatsu          #+#    #+#             */
/*   Updated: 2025/04/09 19:25:57 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include <stdio.h>

int	count_width(const char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;

    while (str[i] == c)
        i++;
    
	while (str[i])
	{
		if (str[i] != c)
        {
            count++;
            while(str[i] && str[i] != c)
                i++;
        }
        while (str[i] == c)
            i++;
    }
	return (count);
}

void get_dimensions(t_fdf *data, int fd)
{
    char *line;
    
    data->height = 0;
    line = get_next_line(fd);
    if (line)
    {
        data->width = 0;
        data->width = count_width(line,' ');
        data->height = 1;
        free(line);
        line = get_next_line(fd);
        while(line)
        {
            data->height++;
            free(line);
            line = get_next_line(fd);
        }
        
    }
}

void fill_matrix(int *z_line, char *line)
{
    char **nums;
    int i;

    if (!z_line || !line) 
        return;
        
    nums = ft_split(line, ' ');
    if (!nums) 
        return;
        
    i = 0;
    while (nums[i])
    {
        // ft_atoiを呼び出す前にnums[i]の値を確認（デバッグ用）
        // printf("nums[%d] = %s\n", i, nums[i]);
        
        z_line[i] = ft_atoi(nums[i]);
        free(nums[i]);
        i++;
    }
    
}

void read_file(t_fdf *data, char *file_name)
{
    int fd;
    fd = open(file_name, O_RDONLY);
    get_dimensions(data,fd);
    close(fd);
    

    data->z_matrix = (int **) malloc (sizeof(int *) * (data->height));
    int i = 0;
    while ( i < data->height )
    {
        data->z_matrix[i] = (int *) malloc (sizeof(int) * (data->width));
        i++;
    }
    fd = open(file_name, O_RDONLY);
    i = 0;

    char * line;
    line = get_next_line(fd);
    while (line)
    {
        fill_matrix(data->z_matrix[i], line);
        free(line);
        i++;
        line = get_next_line(fd);
    }
    close(fd);
}   

int     deal_key(int key, t_fdf *data)
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
    t_fdf *data;
    int i;
    int j;

    if (argc != 2)
    {
        printf("使用法: %s filename\n", argv[0]);
        return (1);
    }

    data = (t_fdf*)malloc(sizeof(t_fdf));
    read_file(data, argv[1]);

    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
    data->zoom = 20;
    draw(data);
    mlx_key_hook(data->win_ptr, deal_key, data);
    mlx_loop(data->mlx_ptr);
}