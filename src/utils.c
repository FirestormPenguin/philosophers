#include "../include/philo.h"

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