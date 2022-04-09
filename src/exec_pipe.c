/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 09:07:02 by nprimo            #+#    #+#             */
/*   Updated: 2022/04/09 12:06:23 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#define PATH_LS "/bin/ls"
#define PATH_WC "/usr/bin/wc"

int	exec_pipe(int fd[2], char **av_in, char **av_out)
{
	pid_t	pid[2];

	pid[0] = fork();
	if (pid[0] < 0)
		exit(1); // verbose exit function - how do I pass the error code?
	if (pid[0] == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		if (close(fd[0]) == -1 || close(fd[1]) == -1)
			exit(1); // verbose exit function - how do I pass the error code?
		execve(av_in[0], av_in, NULL); // do I need to check if success?
	}
	pid[1] = fork();
	if (pid[1] < 0)
		exit(1); // verbose exit function - how do I pass the error cod e?
	if (pid[1] == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		if (close(fd[0]) == -1 || close(fd[1]) == -1)
			exit(1); // verbose exit function - how do I pass the error code?
		execve(av_out[0], av_out, NULL); // do I need to check if success?
	}
	if (close(fd[0]) < 0 || close(fd[1]) < 0)
		exit(1); // verbose exit function - how do I pass the error code?
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
	return (0);
}

// int	main(void)
// {
// 	int		fd[2];
// 	char	*av_in[] = {PATH_LS, NULL};
// 	char	*av_out[] = {PATH_WC, NULL};

// 	if (pipe(fd) != 0)
// 		exit(1); // verbose
// 	if (exec_pipe(fd, av_in, av_out) != 0)
// 		exit(1); // verbose;
// 	if (close(fd[0]) < 0 || close(fd[1]) < 0)
// 		exit(1); // verbose exit function - how do I pass the error code?
// 	return (0);
// }
