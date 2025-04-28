/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:25:23 by skomatsu          #+#    #+#             */
/*   Updated: 2025/04/28 19:49:57 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char *argv[])
{
    t_map *data;
    int i;
    int j;

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

    i = 0;
    while(i < data->height)
    {
        j = 0;
        while(j < data->width)
        {
            printf("%3d", data->points[i][j].z);
            j++;
        }
        printf("\n");
        i++;
    }
    
    free_map(data->points, data->height);
    free(data);
        
    return(0);
}
