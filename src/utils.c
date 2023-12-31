/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:25:17 by egiubell          #+#    #+#             */
/*   Updated: 2023/10/17 13:01:01 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_data(t_data *data)
{
	data->dead = 1;
	data->finish_meals = 0;
	data->data_death = ft_gettimeofday() + data->time_to_die;
	data->data_start = ft_gettimeofday();
	pthread_mutex_init(&data->lock, NULL);
	pthread_mutex_init(&data->write, NULL);
}

int	parse_arg(t_data *data, int argc, char **argv)
{
	data->philos_nb = ft_atoi(argv[1]);
	if (data->philos_nb < 1)
		return (1);
	data->time_to_die = ft_atoi(argv[2]);
	if (data->time_to_die < 1)
		return (1);
	data->time_to_eat = ft_atoi(argv[3]);
	if (data->time_to_eat < 1)
		return (1);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (data->time_to_sleep < 1)
		return (1);
	if (argc == 6)
	{
		data->must_eat = ft_atoi(argv[5]);
		if (data->must_eat < 1)
			return (1);
	}
	else
		data->must_eat = 0;
	init_data(data);
	return (0);
}

u_int64_t	ft_gettimeofday(void)
{
	struct timeval	time_value;

	if (gettimeofday(&time_value, NULL))
		printf("%s\n", GET_TIME_ERR);
	return ((time_value.tv_sec * (u_int64_t)1000)
		+ (time_value.tv_usec / 1000));
}

int	ft_usleep(useconds_t time)
{
	u_int64_t	start;

	start = ft_gettimeofday();
	while ((ft_gettimeofday() - start) < time)
		usleep(100);
	return (0);
}
