/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:12:22 by nprimo            #+#    #+#             */
/*   Updated: 2022/04/06 10:18:27 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_fd(const char *filepath, int flag)
{
	int	fd;

	fd = open(filepath, flag);
	if (fd < 0)
	{
		perror("Error: ");
		return (free_and_exit());
	}
	return(fd);
}