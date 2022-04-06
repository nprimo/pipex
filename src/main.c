/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 09:59:42 by nprimo            #+#    #+#             */
/*   Updated: 2022/04/06 10:07:52 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av)
{
	if (ac > 4)
	{
		printf("Do something with %s and co\n", av[1]);
	}
	else
	{
		printf("Not enough arguments! Insert more than 4\n");
		return (1);
	}
	return (0);
}