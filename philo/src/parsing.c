/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:16:22 by oamairi           #+#    #+#             */
/*   Updated: 2025/12/17 11:03:53 by oamairi          ###   ########.fr       */
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

bool	init_data_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->write_lock, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&data->dead_lock, NULL) != 0)
	{
		pthread_mutex_destroy(&data->write_lock);
		return (false);
	}
	if (pthread_mutex_init(&data->meal_check_lock, NULL) != 0)
	{
		pthread_mutex_destroy(&data->write_lock);
		pthread_mutex_destroy(&data->dead_lock);
		return (false);
	}
	return (true);
}

t_data	*init_data(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->nb_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->must_eat_count = ft_atoi(argv[5]);
	else
		data->must_eat_count = -1;
	data->start_time = 0;
	data->dead_flag = false;
	data->all_ate = false;
	data->forks = NULL;
	data->philos = NULL;
	if (init_data_mutex(data) == false)
		return (free(data), NULL);
	return (data);
}

bool	init_forks(t_data *data)
{
	
}
