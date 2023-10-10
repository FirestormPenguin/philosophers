/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:31:40 by egiubell          #+#    #+#             */
/*   Updated: 2023/10/10 17:20:18 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void    *routine(void *args)
{
    t_philos *philos;
	int happy_meals;
	
    philos = args;
	happy_meals = 0;
	printf("id %d\n", philos->id);
    // while (philos->live == 1)
	// {
	// 	//pthread_mutex_lock(&philos->fork);
	// 	//pthread_mutex_lock(&philos->next->fork);
	// 	printf("philo %d is eating\n", philos->id);
	// 	meals++;
	// 	if (meals == philos->data->must_eat)
	// 		break;
	// 	printf("philo %d meal: %d\n", philos->id, meals);
	// 	ft_usleep(philos->data->time_to_eat);
	// 	//pthread_mutex_unlock(&philos->fork);
	// 	//pthread_mutex_unlock(&philos->next->fork);
	// 	printf("philo %d is sleeping\n", philos->id);
	// 	ft_usleep(philos->data->time_to_sleep);
    //     printf("philo %d is thinking\n", philos->id);
	// }
	// // ft_exit(philos);
	return (NULL);
}

void    init_thread(t_philos *philos)
{
	int i;

	i = -1;
	while (++i < philos->data->philos_nb)
	{
		// pthread_mutex_init(&philos->fork, NULL);
        // pthread_create(&philos->thread, NULL, &routine, philos);
		// pthread_detach(philos->thread);
		philos = philos->next;
	}
}
