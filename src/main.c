/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 09:59:42 by nprimo            #+#    #+#             */
/*   Updated: 2022/04/06 10:23:15 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av)
{
	int	fdes[2];

	if (ac > 4)
	{
		fdes[0] = get_fd(av[0], O_RDONLY);
		fdes[1] = get_fd(av[ac - 1], O_WRONLY);
		if (fdes[0] < 0 || fdes[1] < 0)
			return (free_and_exit());
		printf("Do something with %s and %s\n", av[1], av[ac - 1]);
	}
	else
	{
		printf("Not enough arguments! Insert more than 4\n");
		return (1);
	}
	return (0);
}