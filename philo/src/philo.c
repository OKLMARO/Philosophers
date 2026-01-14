/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:20:14 by oamairi           #+#    #+#             */
/*   Updated: 2026/01/09 17:13:37 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	philo_routine_suite(t_philo *philo)
{
	if (is_dead(philo->data) == true)
		return (false);
	take_forks(philo);
	if (is_dead(philo->data) == true)
		return (drop_forks(philo), false);
	eat(philo);
	if (is_dead(philo->data) == true)
		return (drop_forks(philo), false);
	drop_forks(philo);
	if (is_dead(philo->data) == true)
		return (false);
	philo_sleep(philo);
	if (is_dead(philo->data) == true)
		return (false);
	print_status(philo, "is thinking");
	return (true);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->nb_philos == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
		sleep_philo(philo->data->time_to_die + 1);
		return (pthread_mutex_unlock(philo->left_fork), NULL);
	}
	if (philo->id % 2 == 0)
		usleep(1000);
	while (true)
	{
		if (philo_routine_suite(philo) == false)
			return (NULL);
	}
	return (NULL);
}

bool	check_if_died(t_data *data, int i)
{
	long	last_meal_time;

	pthread_mutex_lock(&data->philos[i].meal_lock);
	last_meal_time = data->philos[i].last_meal_time;
	pthread_mutex_unlock(&data->philos[i].meal_lock);
	if (get_time() - last_meal_time > data->time_to_die)
	{
		pthread_mutex_lock(&data->write_lock);
		set_dead_flag(data);
		printf("%ld %ld died\n", get_time() - data->start_time,
			data->philos[i].id);
		pthread_mutex_unlock(&data->write_lock);
		return (false);
	}
	return (true);
}

void	*palantir(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (true)
	{
		i = 0;
		while (i < data->nb_philos)
		{
			if (check_if_died(data, i) == false)
				return (NULL);
			i++;
		}
		if (data->must_eat_count != -1)
		{
			count_meal(data);
			if (is_dead(data) == true)
				return (NULL);
		}
		usleep(100);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		i;

	if (check_argv(argc, argv) == false)
		return (1);
	data = init_data(argc, argv);
	if (!data)
		return (1);
	if (init_forks(data) == false || init_philos(data) == false)
		return (cleanup(data), free(data), 1);
	data->start_time = get_time();
	i = 0;
	init_time_philo(data);
	while (i < data->nb_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL, philo_routine,
				&data->philos[i]) != 0)
			return (cleanup(data), free(data), 1);
		i++;
	}
	if (pthread_create(&data->thread, NULL, palantir, data) != 0
		|| join(data) != 0)
		return (cleanup(data), free(data), 1);
	return (cleanup(data), free(data), 0);
}
