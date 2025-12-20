/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:20:14 by oamairi           #+#    #+#             */
/*   Updated: 2025/12/20 12:42:07 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_status(t_philo *philo, char *status)
{
	bool	is_dead;

	pthread_mutex_lock(&philo->data->dead_lock);
	is_dead = philo->data->dead_flag;
	pthread_mutex_unlock(&philo->data->dead_lock);
	if (is_dead == false)
	{
		pthread_mutex_lock(&philo->data->write_lock);
		printf("%ld %ld %s\n", get_time() - philo->data->start_time,
			philo->id, status);
		pthread_mutex_unlock(&philo->data->write_lock);
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;
	if (check_argv(argc, argv) == false)
		return (1);
	data = init_data(argc, argv);
	if (!data)
		return (1);
	if (init_forks(data) == false)
		return (cleanup(data), free(data), 1);
	if (init_philos(data) == false)
		return (cleanup(data), free(data), 1);
	return (0);
}
