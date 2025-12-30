/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 10:32:18 by oamairi           #+#    #+#             */
/*   Updated: 2025/12/30 10:26:46 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_sleep(t_philo *philo)
{
	print_status(philo, "is sleeping");
	sleep_philo(philo->data->time_to_sleep);
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
	pthread_mutex_lock(&philo->data->dead_lock);
	pthread_mutex_lock(&philo->data->write_lock);
	if (philo->data->dead_flag == false)
	{
		printf("%ld %ld %s\n", get_time() - philo->data->start_time,
			philo->id, status);
	}
	pthread_mutex_unlock(&philo->data->write_lock);
	pthread_mutex_unlock(&philo->data->dead_lock);
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

void	count_meal(t_data *data)
{
	int	i;
	int	compteur;

	i = 0;
	compteur = 0;
	while (i < data->nb_philos)
	{
		pthread_mutex_lock(&data->philos[i].meal_lock);
		if (data->philos[i].meals_eaten >= data->must_eat_count)
			compteur++;
		pthread_mutex_unlock(&data->philos[i].meal_lock);
		i++;
	}
	if (compteur == data->nb_philos)
		set_dead_flag(data);
}
