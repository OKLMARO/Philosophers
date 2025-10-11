/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:19:14 by oamairi           #+#    #+#             */
/*   Updated: 2025/10/11 12:39:22 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>

typedef struct s_fourchette
{
	int					id;
	pthread_mutex_t		fourchette;
	struct s_fourchette	*next;
	struct s_fourchette	*previous;
}						t_fourchette;

typedef	struct s_philo
{
	int					id;
	pthread_t			philo;
	struct s_philo		*next;
	struct s_philo		*previous;
}						t_philo;

typedef struct s_table
{
	t_philo			**philosophe;
	t_fourchette	**fourchettes;
}					t_table;

void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

#endif
