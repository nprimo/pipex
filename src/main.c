/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 09:59:42 by nprimo            #+#    #+#             */
/*   Updated: 2022/04/11 17:34:57 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	if (ac > 4)
	{
		if (access(av[1], R_OK) != 0 || access(av[ac - 1], W_OK) != 0
			|| (ac == 5 && exec_simple_pipe(av, envp) == 1))
			exit(1); // verbose exit function - how do I pass the error code?
		printf("Do something with %s and %s\n", av[1], av[ac - 1]);
	}
	else
	{
		printf("Not enough arguments! Insert more than 4\n");
		return (1);
	}
	return (0);
}
