/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:25:05 by egiubell          #+#    #+#             */
/*   Updated: 2023/10/10 09:55:54 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_philos	*ft_lstnew(int id, t_philos *philos)
{
	philos = NULL;
	philos = malloc(sizeof(t_philos));
	if (!philos)
		return (0);
	philos->id = id;
	philos->sleep = 0;
	philos->eat = 0;
	philos->think = 0;
	philos->live = 1;
	pthread_mutex_init(&philos->fork, NULL);
	philos->next = NULL;
	return (philos);
}

void	init_struct(t_data *data)
{
	int i;

	i = -1;
	data->philos_h = NULL;
	while(++i < data->philos_nb)
	{
		if (i == 0)
		{
			data->philos = ft_lstnew(i, data->philos);
			data->philos_h = data->philos;
		}
		else
		{
			data->philos->next = ft_lstnew(i, data->philos);
			data->philos = data->philos->next;
		}
	}
	data->philos->next = data->philos_h;
	data->dead = 1;
	pthread_mutex_init(&data->lock, NULL);
}
