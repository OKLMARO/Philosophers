/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 10:31:29 by oamairi           #+#    #+#             */
/*   Updated: 2025/12/20 10:57:06 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo/include/philo.h"

int	main(void)
{
	struct timeval current_time;

	gettimeofday(&current_time, NULL);
	ft_putnbr_fd(current_time.tv_sec * 1000 + current_time.tv_usec / 1000, 1);
	return (0);
}
