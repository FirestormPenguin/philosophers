/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:31:40 by egiubell          #+#    #+#             */
/*   Updated: 2023/10/10 16:27:39 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void    *routine(void *args)
{
    t_philos *philos;
	int meals;
	
    philos = args;
	meals = 0;
    while (philos->live == 1)
	{
		//pthread_mutex_lock(&philos->fork);
		//pthread_mutex_lock(&philos->next->fork);
		printf("philo %d is eating\n", philos->id);
		meals++;
		printf("philo %d meal: %d\n", philos->id, meals);
		ft_usleep(philos->data->time_to_eat);
		//pthread_mutex_unlock(&philos->fork);
		//pthread_mutex_unlock(&philos->next->fork);
		printf("philo %d is sleeping\n", philos->id);
		ft_usleep(philos->data->time_to_sleep);
        printf("philo %d is thinking\n", philos->id);
	}
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
