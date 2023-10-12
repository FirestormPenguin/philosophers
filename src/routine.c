/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:31:40 by egiubell          #+#    #+#             */
/*   Updated: 2023/10/12 17:07:12 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void *routine_monitor(void *args)
{
	t_philos *philos;
	
    philos = args;
	while(philos->data->dead == 1)
	{
		pthread_mutex_lock(&philos->data->lock);
		if (ft_gettimeofday() >= philos->data->timestamp_death && philos->eat == 0)
		{	
			printf("%lu %d died",ft_gettimeofday() 
				- philos->data->timestamp_start , philos->id);
			philos->data->dead = 0;
		}
		pthread_mutex_unlock(&philos->data->lock);
	}
	return (NULL);
}

void    *routine(void *args)
{
    t_philos *philos;
	int meals;
	
    philos = args;
	meals = 0;
	pthread_create(&philos->monitor, NULL, &routine_monitor, philos);
    while (philos->live == 1)
	{
		eat(philos);
		meals++;
		if (meals == philos->data->must_eat)
			break ;
		ft_sleep(philos);
		think(philos);
	}
	// ft_exit(philos);
	philos->data->finish_meals = 0;
	return (NULL);
}

void    init_thread(t_philos *philos)
{
	int i;

	i = -1;
	while (++i < philos->data->philos_nb)
	{
		pthread_mutex_init(&philos->fork, NULL);
        pthread_create(&philos->thread, NULL, &routine, philos);
		pthread_detach(philos->thread);
		philos = philos->next;
	}
}
