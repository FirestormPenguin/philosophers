#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_philos
{
	int id;
	int sleep;
	int eat;
	int think;
	int live;
	pthread_t thread;
	struct s_philos *next;
}	t_philos;

typedef struct s_data
{
	int philos_nb;
	int time_to_eat;
	t_philos *philos;
	t_philos *philos_h;
	pthread_mutex_t lock;
}	t_data;

t_philos	*ft_lstnew(int id, t_data *data)
{
	data->philos = NULL;
	data->philos = malloc(sizeof(t_philos));
	if (!data->philos)
		return (0);
	data->philos->id = id;
	data->philos->sleep = 0;
	data->philos->eat = 0;
	data->philos->think = 0;
	data->philos->live = 1;
	data->philos->next = NULL;
	return (data->philos);
}

void	*init_struct(t_data *data)
{
	int i;

	i = 0;
	data->philos_h = NULL;
	while(i < data->philos_nb)
	{
		if (i == 0)
		{
			data->philos = ft_lstnew(i, data);
			data->philos_h = data->philos;
			data->philos = data->philos->next;
		}
		else
		{
			data->philos = ft_lstnew(i, data);
			data->philos = data->philos->next;
		}
		i++;
	}
}

void  *routine(t_data *data)
{
	printf("enter routine %d\n", data->philos->id);
	while (data->philos->live == 1)
	{
		pthread_mutex_lock(&data->lock);
		data->philos->eat = 1;
		printf("philo %d is eating\n", data->philos->id);
		sleep(data->time_to_eat);
		pthread_mutex_unlock(&data->lock);
		sleep(data->time_to_eat);
	}
	return (NULL);
}

void scroll_philos(t_data *data)
{
	data->philos = data->philos_h;
	while (data->philos)
	{
		printf("philo id: %d\nsleep: %d\neat: %d\nthink: %d\nlive: %d\n\n", data->philos->id, data->philos->sleep, data->philos->eat, data->philos->think, data->philos->live);
		//pthread_create(&data->philos->thread, NULL, &routine, data);
		//pthread_detach(&data->philos->thread);
		data->philos = data->philos->next;
		printf("philo next %d", data->philos->next->id);
	}
}

void scroll_philos2(t_data *data)
{
	data->philos = data->philos_h;
	while (data->philos)
	{
		pthread_join(data->philos->thread, NULL);
		data->philos = data->philos->next;
	}
}

int main(int argc, char **argv)
{
	t_data		data;

	if (argc != 3)
	{
		printf("Error: arguments number invalid!\n");
		return (1);
	}
	data.philos_nb = atoi(argv[1]);
	data.time_to_eat = atoi(argv[2]);
	init_struct(&data);
	pthread_mutex_init(&data.lock, NULL);
	scroll_philos(&data);
	//scroll_philos2(&data);
	pthread_mutex_destroy(&data.lock);
}
