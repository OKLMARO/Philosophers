/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 18:13:16 by oamairi           #+#    #+#             */
/*   Updated: 2025/12/18 11:26:59 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;

	dest = malloc(sizeof(char) * ft_strlen((char *) s) + 1);
	if (!dest)
		return (0);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

long	ft_atoi(const char *nptr)
{
	int		i;
	long	res;

	i = 0;
	res = 0;
	while (nptr[i] != '\0' && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		res = res * 10 + (nptr[i] - '0');
		i = i + 1;
	}
	if (ft_isdigit(nptr[i]) == 0 && nptr[i] != '\0')
		return (0);
	return (res);
}

void	destroy_mutex_data(pthread_mutex_t *mutex, t_philo *philo, size_t size)
{
	int	j;

	if (mutex)
	{
		j = 0;
		while (j < size)
		{
			pthread_mutex_destroy(&mutex[j]);
			j++;
		}	
	}
	if (philo)
	{
		j = 0;
		while (j < size)
		{
			pthread_mutex_destroy(&philo[j].meal_lock);
			j++;
		}
	}
}
