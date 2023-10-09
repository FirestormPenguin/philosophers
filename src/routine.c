/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:31:40 by egiubell          #+#    #+#             */
/*   Updated: 2023/10/09 10:36:12 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void    *routine(void *args)
{
    t_philos *philos;

    philos = args;
	
    while (philos->live == 1)
	{
		pthread_mutex_lock(&philos->fork);
		pthread_mutex_lock(&philos->next->fork);
		printf("philo %d is eating\n", philos->id);
		philos->eat = 1;
		philos->sleep = 0;
		philos->think = 0;
		sleep(2);
		pthread_mutex_unlock(&philos->fork);
		pthread_mutex_unlock(&philos->next->fork);
		printf("philo %d is thinking\n", philos->id);
		sleep(2);
	}
	return (NULL);
}

void    init_thread(t_data *data)
{
	int i;

	i = -1;
	while (++i < data->philos_nb)
	{
		//printf("id: %d\nsleep: %d\neat: %d\nthink: %d\nlive: %d\n\n", data->philos->id, data->philos->sleep, data->philos->eat, data->philos->think, data->philos->live);
		pthread_mutex_init(&data->philos->fork, NULL);
		//pthread_create(&data->philos->thread, NULL, &routine, data->philos);
        pthread_create(&data->philos->thread, NULL, &routine, data);
		pthread_detach(&data->philos->thread);
		data->philos = data->philos->next;
	}
}
