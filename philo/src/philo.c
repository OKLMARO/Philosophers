/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:20:14 by oamairi           #+#    #+#             */
/*   Updated: 2025/12/23 12:02:32 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->nb_philos == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
		sleep_prog(philo->data->time_to_die + 1);
		return (pthread_mutex_unlock(philo->left_fork), NULL);
	}
	if (philo->id % 2 == 0)
		usleep(100);
	while (true)
	{
		if (is_dead(philo->data) == true)
			return (NULL);
		take_forks(philo);
		eat(philo);
		drop_forks(philo);
		philo_sleep(philo);
		print_status(philo, "is thinking");
		if (is_dead(philo->data) == true)
			return (NULL);
	}
	return (NULL);
}

void	pegasus(t_data *data)
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

bool	stuxnet(t_data *data, int i)
{
	long	last_meal_time;

	pthread_mutex_lock(&data->philos[i].meal_lock);
	last_meal_time = data->philos[i].last_meal_time;
	pthread_mutex_unlock(&data->philos[i].meal_lock);
	if (get_time() - last_meal_time > data->time_to_die)
	{
		pthread_mutex_lock(&data->write_lock);
		printf("%ld %ld died\n", get_time() - data->start_time,
			data->philos[i].id);
		pthread_mutex_unlock(&data->write_lock);
		set_dead_flag(data);
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
			if (stuxnet(data, i) == false)
				return (NULL);
			i++;
		}
		if (data->must_eat_count != -1)
		{
			pegasus(data);
			if (is_dead(data) == true)
				return (NULL);
		}
		usleep(1000);
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
	if (init_forks(data) == false)
		return (cleanup(data), free(data), 1);
	if (init_philos(data) == false)
		return (cleanup(data), free(data), 1);
	data->start_time = get_time();
	i = 0;
	init_time_philo(data);
	while (i < data->nb_philos)
	{
		pthread_create(&data->philos[i].thread, NULL, philo_routine,
			&data->philos[i]);
		i++;
	}
	pthread_create(&data->thread, NULL, palantir, data);
	join(data);
	return (cleanup(data), free(data), 0);
}
