/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:42:30 by skomatsu          #+#    #+#             */
/*   Updated: 2025/05/29 16:11:52 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	perror_and_exit(char *msg, t_map *data)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	if (data)
		free_all_resources(data);
	exit(EXIT_FAILURE);
}
