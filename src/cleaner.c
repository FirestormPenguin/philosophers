/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:41:43 by egiubell          #+#    #+#             */
/*   Updated: 2023/10/17 11:51:42 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_exit(t_philos *philos)
{
	int	i;
	int	tmp_nb;

	i = -1;
	tmp_nb = philos->data->philos_nb;
	while (++i < tmp_nb)
	{
		pthread_mutex_destroy(&philos->data->write);
		pthread_mutex_destroy(&philos->data->lock);
		pthread_mutex_destroy(&philos->fork);
		if (philos)
			free(philos);
		philos = philos->next;
	}
}
