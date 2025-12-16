/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:16:22 by oamairi           #+#    #+#             */
/*   Updated: 2025/12/16 11:42:07 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	check_argv(int argc, char **argv)
{
	int	i;

	if (argc != 5 && argc != 6)
		return (ft_putstr_fd("NBR ARG ERROR\n", 2), false);
	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) <= 0)
			return (ft_putstr_fd("ARG ERROR\n", 2), false);
		i++;
	}
	return (true);
}

void	init_data
