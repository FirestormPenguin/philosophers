#include "../include/philo.h"

int parse_arg(t_data *data, int argc, char **argv)
{
	data->philo_num = atoi(argv[1]);
	if (data->philo_num < 1)
		return (1);
	data->time_to_die = atoi(argv[2]);
	if (data->time_to_die < 1)
		return (1);
	data->time_to_eat = atoi(argv[3]);
	if (data->time_to_eat < 1)
		return (1);
	data->time_to_sleep = atoi(argv[4]);
	if (data->time_to_sleep < 1)
		return (1);
	if (argc == 6)
	{
		data->must_eat = atoi(argv[5]);
		if (data->must_eat < 1)
			return (1);
	}
	else
		data->must_eat = 0;
	return (0);
}

u_int64_t	ft_gettimeofday(void)
{
	struct timeval	time_value;

	if (gettimeofday(&time_value, NULL))
		printf("%s\n", GET_TIME_ERR);
	return ((time_value.tv_sec * (u_int64_t)1000) + (time_value.tv_usec / 1000));
}

int	ft_usleep(useconds_t time)
{
	u_int64_t	start;

	start = ft_gettimeofday();
	while ((ft_gettimeofday() - start) < time)
		usleep(time / 10);
	return (0);
}