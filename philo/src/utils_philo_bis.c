/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 10:32:18 by oamairi           #+#    #+#             */
/*   Updated: 2025/12/23 12:04:04 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i = i + 1;
	}
	return (i);
}

void	philo_sleep(t_philo *philo)
{
	print_status(philo, "is sleeping");
	sleep_prog(philo->data->time_to_sleep);
}

void	join(t_data *data)
{
	int	i;

	pthread_join(data->thread, NULL);
	i = 0;
	while (i < data->nb_philos)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
}

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

void	init_time_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		data->philos[i].last_meal_time = get_time();
		i++;
	}
}
