/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:25:05 by egiubell          #+#    #+#             */
/*   Updated: 2023/10/10 17:42:52 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_philos	*ft_lstnew(int id, t_philos *philos)
{
	philos->id = id;
	philos->sleep = 0;
	philos->eat = 0;
	philos->think = 0;
	philos->live = 1;
	pthread_mutex_init(&philos->fork, NULL);
	philos->next = NULL;
	return (philos);
}

void	init_struct(t_philos *philos)
{
	int i;
	t_philos *philos_h;

	i = -1;
	philos_h = NULL;
	while(++i < philos->data->philos_nb)
	{
		if (i == 0)
		{
			philos = ft_lstnew(i, philos);
			philos_h = philos;
		}
		else
		{
			philos->next = ft_lstnew(i, philos_h);
			philos->next->data = philos_h->data;
			philos = philos->next;
		}
		//printf("id cose %d\n", philos->id);
	}
	philos->next = philos_h;
	
	int j = -1;
	while (++j < philos->data->philos_nb)
	{
		printf("id %d\n", philos->id);
		philos = philos->next;
	}
}
