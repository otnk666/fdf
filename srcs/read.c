/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:48:08 by skomatsu          #+#    #+#             */
/*   Updated: 2025/05/13 12:02:14 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     count_width(char *str, char c)
{
    int count;

    count = 0;
    while (*str)
    {
        if (*str != c)
        {
            count++;
            while(*str && *str != c)
                str++;
        }
        while(*str == c)
            str++;
    }
    return(count);
}

void    get_dimension(char *file_name, t_map *data)
{
    int fd; 
    char *line;
    
    fd = open(file_name, O_RDONLY);
    if (fd < 0)
        return;
    data->height = 0;
    data->width = 0;
    while(1)
    {
        line = get_next_line(fd);
        if(!line)
            break;
        if(data->height == 0)
            data->width = count_width(line,' ');
        data->height++;
        free(line);
    }
    close(fd);
}
    
void   map_memory(t_map *data)
{
    int i;
    int j;
    i = 0;
    
    data->points = (t_point**) malloc (sizeof (t_point *)* (data->height));
    if(!data->points)
        return ;
    while ( i < data->height )
    {
        data->points[i] = (t_point*) malloc (sizeof (t_point) * (data->width));
        if(!data->points[i])
        {
            free_map(data->points, i);
            return ;
        }
        j = 0;
        while( j < data->width)
        {
            data->points[i][j].x = j;
            data->points[i][j].y = i;
            data->points[i][j].z = 0;
            data->points[i][j].color = 0;
            j ++;
        }
        i++;
    }
}

void    read_file(char *filename, t_map *data)
{ 
    get_dimension(filename, data);
    map_memory(data);
    get_fill(filename, data);   
}
