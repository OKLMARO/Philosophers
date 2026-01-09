/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:19:14 by oamairi           #+#    #+#             */
/*   Updated: 2026/01/09 16:57:38 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct s_data	t_data;

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
	pthread_t		thread;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_check_lock;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}					t_data;

long	get_time(void);
int		join(t_data *data);
void	eat(t_philo *philo);
void	cleanup(t_data *data);
bool	is_dead(t_data *data);
bool	init_forks(t_data *data);
void	count_meal(t_data *data);
size_t	ft_strlen(const char *s);
void	sleep_philo(long milisec);
bool	init_philos(t_data *data);
void	*philo_routine(void *arg);
char	*ft_strdup(const char *s);
long	ft_atoi(const char *nptr);
void	take_forks(t_philo *philo);
void	drop_forks(t_philo *philo);
void	set_dead_flag(t_data *data);
void	philo_sleep(t_philo *philo);
void	ft_putstr_fd(char *s, int fd);
void	init_time_philo(t_data *data);
void	ft_putnbr_fd(long long n, int fd);
bool	check_argv(int argc, char **argv);
t_data	*init_data(int argc, char **argv);
void	print_status(t_philo *philo, char *status);
void	destroy_mutex_data(pthread_mutex_t *mutex, t_philo *philo, size_t size);

#endif
