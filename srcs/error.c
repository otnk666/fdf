/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:42:30 by skomatsu          #+#    #+#             */
/*   Updated: 2025/05/21 15:59:32 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    perror_and_exit(char *msg)
{
    ft_putendl_fd(msg, STDERR_FILENO);
    exit(EXIT_FAILURE);
}