/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erro.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:13:12 by tgrunho-          #+#    #+#             */
/*   Updated: 2025/03/09 17:03:14 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	error(char *error)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(error, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
