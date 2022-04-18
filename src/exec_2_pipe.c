/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_2_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:54:35 by nprimo            #+#    #+#             */
/*   Updated: 2022/04/18 17:31:25 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exec_2_pipe(char **av, char **envp)
{
	int		fd_in;
	int		fd_out;
	int		fd_pipe[2];
	int		fd_pipe1[2];
	char	**av0;
	char	**av1;
	char	**av2;

	fd_in = open(av[1], O_RDONLY);
	fd_out = open(av[5], O_WRONLY);
	if (fd_in == -1 || fd_out == -1)
		exit(1); //verbose
	if (pipe(fd_pipe) == -1)
		exit(1);
	if (pipe(fd_pipe1) == -1)
		exit(1);
	av0 = ft_split(av[2], ' ');
	av1 = ft_split(av[3], ' ');
	av2 = ft_split(av[4], ' ');
	if (!av1)
		return (1);
	if (!av0)
		return (1);
	if (!av2)
		return (1);
	exec_command(fd_in, fd_pipe[1], av0, envp);
	sleep(1);
	exec_command(fd_pipe[0], fd_pipe[1], av1, envp);
	sleep(1);
	exec_command(fd_pipe[0], fd_out, av1, envp);
	free_split(av0);
	free_split(av1);
	return (0);
}
