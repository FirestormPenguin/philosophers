/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:55:16 by egiubell          #+#    #+#             */
/*   Updated: 2023/10/17 09:09:00 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	eat(t_philos *philos)
{
	//pthread_mutex_lock(&philos->fork);
	printf("pthread_mutex_lock(&philos->fork): %d\n", pthread_mutex_lock(&philos->fork));
	printf("fork in actions.c: %p\n", &philos->fork);
	fork_taken(philos);
	//pthread_mutex_lock(&philos->next->fork);
	printf("pthread_mutex_lock(&philos->next->fork): %d\n", pthread_mutex_lock(&philos->next->fork));
	printf("next->fork in actions.c: %p\n", &philos->next->fork);
	fork_taken(philos);
	pthread_mutex_lock(&philos->data->write);
	printf("%lu %d is eating\n", ft_gettimeofday()
		- philos->timestamp_start, philos->id);
	pthread_mutex_unlock(&philos->data->write);
	philos->timestamp_death = ft_gettimeofday()
		+ philos->data->time_to_die;
	philos->eat = 1;
	printf("philos->data->time_to_eat * 1000 = %d\n", philos->data->time_to_eat * 1000);
	ft_usleep(philos->data->time_to_eat);
	printf("finish eating\n");
	pthread_mutex_unlock(&philos->next->fork);
	printf("next->fork is unlocked\n");
	pthread_mutex_unlock(&philos->fork);
	printf("fork is unlocked\n");
}

void	fork_taken(t_philos *philos)
{
	pthread_mutex_lock(&philos->data->write);
	printf("%lu %d has taken a fork\n", ft_gettimeofday()
		- philos->timestamp_start, philos->id);
	pthread_mutex_unlock(&philos->data->write);
}

void	ft_sleep(t_philos *philos)
{
	pthread_mutex_lock(&philos->data->write);
	printf("%lu %d is sleeping\n", ft_gettimeofday()
		- philos->timestamp_start, philos->id);
	philos->eat = 0;
	pthread_mutex_unlock(&philos->data->write);
	ft_usleep(philos->data->time_to_sleep);
}

void	think(t_philos *philos)
{
	pthread_mutex_lock(&philos->data->write);
	printf("%lu %d is thinking\n", ft_gettimeofday()
		- philos->timestamp_start, philos->id);
	philos->eat = 0;
	pthread_mutex_unlock(&philos->data->write);
}
