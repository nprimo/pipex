/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:19:00 by nprimo            #+#    #+#             */
/*   Updated: 2022/04/06 10:30:41 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	free_and_exit(int fdes[2])
{
	while (*fdes)
	{
		if (*fdes > 0 && close(*fdes) == 0)
			fdes++;
		else
			break ;
	}
	exit(1);
	return (1);
}