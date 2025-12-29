/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 09:40:57 by oamairi           #+#    #+#             */
/*   Updated: 2025/12/29 20:35:01 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	is_dead(t_data *data)
{
	pthread_mutex_lock(&data->dead_lock);
	if (data->dead_flag == false)
		return (pthread_mutex_unlock(&data->dead_lock), false);
	return (pthread_mutex_unlock(&data->dead_lock), true);
}

void	set_dead_flag(t_data *data)
{
	pthread_mutex_lock(&data->dead_lock);
	data->dead_flag = true;
	pthread_mutex_unlock(&data->dead_lock);
}

void	take_forks(t_philo *philo)
{
	if (is_dead(philo->data) == true)
		return ;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
	}
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal_time = get_time();
	philo->meals_eaten = philo->meals_eaten + 1;
	pthread_mutex_unlock(&philo->meal_lock);
	print_status(philo, "is eating");
	sleep_philo(philo->data->time_to_eat);
}
