/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:55:27 by egiubell          #+#    #+#             */
/*   Updated: 2023/10/12 16:44:42 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static t_philos	*ft_lstnew(int id, t_data *data)
{
	t_philos *tmp;

	tmp = NULL;
	tmp = malloc(sizeof(t_philos));
	tmp->id = id;
	tmp->sleep = 0;
	tmp->eat = 0;
	tmp->think = 0;
	tmp->live = 1;
	tmp->data = data;
	pthread_mutex_init(&tmp->fork, NULL);
	tmp->next = NULL;
	return (tmp);
}

t_philos	*init_struct(t_data *data)
{
	int i;
	t_philos *philos_h;
	t_philos *philos;

	i = -1;
	philos_h = NULL;
	philos = NULL;
	while(++i < data->philos_nb)
	{
		if (i == 0)
		{
			philos = ft_lstnew(i, data);
			philos_h = philos;
		}
		else
		{
			philos->next = ft_lstnew(i, data);
			philos = philos->next;
		}
	}
	philos->next = philos_h;
	philos = philos_h;
	return(philos_h);
}
