/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:55:16 by egiubell          #+#    #+#             */
/*   Updated: 2023/10/12 17:07:25 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void    eat(t_philos *philos)
{
    pthread_mutex_lock(&philos->fork);
    fork_taken(philos);
	pthread_mutex_lock(&philos->next->fork);
    fork_taken(philos);
    pthread_mutex_lock(&philos->data->write);
	printf("%lu %d is eating\n",ft_gettimeofday()
        - philos->data->timestamp_start, philos->id);
    pthread_mutex_unlock(&philos->data->write);
	philos->data->timestamp_death = ft_gettimeofday() + philos->data->time_to_die;
    philos->eat = 1;
    philos->sleep = 0;
	philos->think = 0;
	ft_usleep(philos->data->time_to_eat);
	pthread_mutex_unlock(&philos->next->fork);
	pthread_mutex_unlock(&philos->fork);
}

void    fork_taken(t_philos *philos)
{
    pthread_mutex_lock(&philos->data->write);
    printf("%lu %d has taken a fork\n",ft_gettimeofday()
        - philos->data->timestamp_start, philos->id);
    pthread_mutex_unlock(&philos->data->write);
}

void    ft_sleep(t_philos *philos)
{
    pthread_mutex_lock(&philos->data->write);
    printf("%lu %d is sleeping\n",ft_gettimeofday()
        - philos->data->timestamp_start, philos->id);
    philos->eat = 0;
	philos->sleep = 1;
	philos->think = 0;
    pthread_mutex_unlock(&philos->data->write);
	ft_usleep(philos->data->time_to_sleep);
}

void    think(t_philos *philos)
{
    pthread_mutex_lock(&philos->data->write);
    printf("%lu %d is thinking\n",ft_gettimeofday()
        - philos->data->timestamp_start, philos->id);
    philos->eat = 0;
	philos->sleep = 0;
	philos->think = 1;
    pthread_mutex_unlock(&philos->data->write);
}