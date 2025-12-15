/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 18:13:16 by oamairi           #+#    #+#             */
/*   Updated: 2025/12/15 18:20:43 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	i;
	int	is_negative;
	int	res;

	i = 0;
	is_negative = 1;
	res = 0;
	while (((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ') && nptr[i] != '\0')
		i = i + 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			is_negative = is_negative * -1;
		i++;
	}
	while (nptr[i] != '\0' && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		res = res * 10 + (nptr[i] - '0');
		i = i + 1;
	}
	res = res * is_negative;
	return (res);
}
