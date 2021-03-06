/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple_pipe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:29:20 by nprimo            #+#    #+#             */
/*   Updated: 2022/04/18 17:07:37 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exec_simple_pipe(char **av, char **envp)
{
	int		fd_in;
	int		fd_out;
	int		fd_pipe[2];
	char	**av0;
	char	**av1;

	fd_in = open(av[1], O_RDONLY);
	fd_out = open(av[4], O_WRONLY);
	if (fd_in == -1 || fd_out == -1)
		exit(1); //verbose
	if (pipe(fd_pipe) == -1)
		exit(1);
	av0 = ft_split(av[2], ' ');
	if (!av0)
		return (1);
	exec_command(fd_in, fd_pipe[1], av0, envp);
	av1 = ft_split(av[3], ' ');
	if (!av1)
		return (1);
	exec_command(fd_pipe[0], fd_out, av1, envp);
	free_split(av0);
	free_split(av1);
	if (close(fd_in) == -1 || close(fd_out) == -1)
		return (1);
	return (0);
}
