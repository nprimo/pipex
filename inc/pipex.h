/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:01:04 by nprimo            #+#    #+#             */
/*   Updated: 2022/04/11 17:36:27 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

# define PATH_LS "/bin/ls"
# define PATH_CAT "/bin/cat"
# define PATH_WC "/usr/bin/wc"

int		exec_command(int fd_in, int fd_out, char **av);
int		exec_simple_pipe(char **av);

char	**ft_split(char const *s, char c);

#endif