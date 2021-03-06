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
	char *av_def[] = {"cat", "file1", NULL};
	if (ac > 4)
	{
		if (ac == 5 && exec_simple_pipe(av, envp) == 1)
			exit(1); // verbose exit function - how do I pass the error code?
		printf("Do something with %s and %s\n", av[1], av[ac - 1]);
		if (ac == 6)
		{
			exec_2_pipe(av, envp);
		}
	}
	else
	{
		exec_command(0, 1, av_def, envp);
		printf("Not enough arguments! Insert more than 4\n");
		return (1);
	}
	return (0);
}
