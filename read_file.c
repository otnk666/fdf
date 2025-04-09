/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:07:11 by skomatsu          #+#    #+#             */
/*   Updated: 2025/03/27 10:16:36 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include <stdio.h>

int	count_width(const char *str, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str == c)
			in_word = 0;
		else if (!in_word)
		{
			count++;
			in_word = 1;
		}
		str++;
	}
	return (count);
}

void get_dimensions(t_fdf *data, int fd)
{
    char *line;
    
    line = get_next_line(fd);
    if (line)
    {
        data->width = 0;
        data->width = count_width(line,' ');
        data->width--;
        data->height++;
        free(line);
        line = get_next_line(fd);
        while(line)
        {
            data->height++;
            free(line);
            line = get_next_line(fd);
        }
        free(line);
    }
}
/*
int get_height(int fd)
{
    int height;
    char *line;
    height = 0;
    
    line = get_next_line(fd);
    
    while(line)
    {
        height++;
        free(line);
        line = get_next_line(fd);
    }
    return (height);
}
*/

/*
int get_width(int fd)
{
    char *line;
    size_t width;

    line = get_next_line(fd);
    width = count_width(line,' ');
    free(line);
    return(width);
}*/

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
        printf("nums[%d] = %s\n", i, nums[i]);
        
        z_line[i] = ft_atoi(nums[i]);
        free(nums[i]);
        i++;
    }
    free(nums);
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

    i = 0;
    while(i < data->height)
    {
        j = 0;
        while(j < data->width)
        {
            printf("%3d", data->z_matrix[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }

    for (i = 0; i < data->height; i++)
        free(data->z_matrix[i]);
    free(data->z_matrix);
    free(data);

    return (0);
}