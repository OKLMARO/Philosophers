/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:19:14 by oamairi           #+#    #+#             */
/*   Updated: 2025/12/18 11:24:47 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_philo
{
	long			id;
	long			meals_eaten;
	long			last_meal_time;
	pthread_t		thread;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*data;
}					t_philo;

typedef struct s_data
{
	long			nb_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			must_eat_count;
	long			start_time;
	bool			dead_flag;
	bool			all_ate;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_check_lock;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}					t_data;

char	*ft_strdup(const char *s);
int		ft_atoi(const char *nptr);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
bool	check_argv(int argc, char **argv);
void	destroy_mutex_data(pthread_mutex_t *mutex, t_philo *philo, size_t size);

#endif
