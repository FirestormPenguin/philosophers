/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:25:26 by egiubell          #+#    #+#             */
/*   Updated: 2023/10/09 12:49:26 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	data_debug(t_data *data)
{
	printf("philo_nb: %d\n", data->philos_nb);
	printf("time_to_die: %d\n", data->time_to_die);
	printf("time_to_eat: %d\n", data->time_to_eat);
	printf("time_to_sleep: %d\n", data->time_to_sleep);
	printf("must_eat: %d\n", data->must_eat);
}

int	args_checks(int argc, char **argv, t_data *data)
{
	if (argc <= 4 || argc > 6)
	{
		printf("%s\n", INPUT_ERR_3);
		return (1);
	}
	else if (parse_arg(data, argc, argv))
	{
		printf("%s\n", INPUT_ERR_1);
		return (1);
	}
	else
		data_debug(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data data;

	args_checks(argc, argv, &data);
	init_struct(&data);
	init_thread(&data);
	while(data.dead == 1)
		;
	pthread_mutex_destroy(&data.lock);
	return (0);
}
