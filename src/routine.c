/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:31:40 by egiubell          #+#    #+#             */
/*   Updated: 2023/10/16 16:47:26 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine_monitor(void *args)
{
	t_philos	*philos;

	philos = args;
	while (philos->data->dead == 1)
	{
		pthread_mutex_lock(&philos->data->lock);
		if (ft_gettimeofday() >= philos->timestamp_death
			&& philos->eat == 0)
		{
			printf("%lu %d died\n", ft_gettimeofday()
				- philos->timestamp_start, philos->id);
			philos->data->dead = 0;
		}
		pthread_mutex_unlock(&philos->data->lock);
	}
	return (NULL);
}

void	*routine(void *args)
{
	t_philos	*philos;
	int			happy_meals;

	philos = args;
	happy_meals = 0;
	pthread_create(&philos->monitor, NULL, &routine_monitor, philos);
	while (philos->live == 1)
	{
		eat(philos);
		happy_meals++;
		if (happy_meals == philos->data->must_eat)
			break ;
		ft_sleep(philos);
		think(philos);
	}
	philos->data->finish_meals++;
	philos->next->data->finish_meals = philos->data->finish_meals;
	return (NULL);
}

void scroll_philos(t_philos *philos)
{
	while(philos->id != 0)
	{
		philos = philos->next;
	}
	printf("philos_h id %d\n\n", philos->id);
}

void	init_thread(t_philos *philos)
{
	int	i;

	i = -1;
	scroll_philos(philos);
	while (++i < philos->data->philos_nb)
	{
		pthread_mutex_init(&philos->fork, NULL);
		pthread_create(&philos->thread, NULL, &routine, philos);
		pthread_detach(philos->thread);
		ft_usleep(1);
		philos = philos->next;
	}
}
