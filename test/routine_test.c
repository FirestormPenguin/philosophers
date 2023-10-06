# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/types.h>
# include <stdbool.h>
# include <stdint.h>

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
	int time_to_sleep;
	int fork;
	t_philos *philos;
	t_philos *philos_h;
	pthread_mutex_t lock;
	int dead;
	pthread_attr_t attr;
}	t_data;

t_philos	*ft_lstnew(int id, t_philos *philos)
{
	philos = NULL;
	philos = malloc(sizeof(t_philos));
	if (!philos)
		return (0);
	philos->id = id;
	philos->sleep = 0;
	philos->eat = 0;
	philos->think = 0;
	philos->live = 1;
	philos->next = NULL;
	return (philos);
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
			data->philos = ft_lstnew(i, data->philos);
			data->philos_h = data->philos;
		}
		else
		{
			data->philos->next = ft_lstnew(i, data->philos);
			data->philos = data->philos->next;
		}
		i++;
	}
}

void  *routine(t_philos *philos)
{
	int i = 0;
	while (philos->live == 1)
	{
		printf("philo %d is eating\n", philos->id);
		sleep(1);
	}
	return (NULL);
}

void scroll_philos(t_data *data)
{
	data->philos = data->philos_h;
	while (data->philos)
	{
		//printf("id: %d\nsleep: %d\neat: %d\nthink: %d\nlive: %d\n\n", data->philos->id, data->philos->sleep, data->philos->eat, data->philos->think, data->philos->live);
		pthread_create(&data->philos->thread, NULL, &routine, data->philos);
		pthread_detach(&data->philos->thread);
		data->philos = data->philos->next;
	}
}

int main(int argc, char **argv)
{
	t_data		data;

	if (argc != 4)
	{
		printf("Error: arguments number invalid!\n");
		return (1);
	}
	data.philos_nb = atoi(argv[1]);
	data.time_to_eat = atoi(argv[2]);
	data.time_to_sleep = atoi(argv[3]);
	data.fork = 1;
	data.dead = 1;
	init_struct(&data);
	pthread_mutex_init(&data.lock, NULL);
	scroll_philos(&data);
	while(data.dead == 1)
		;
	pthread_mutex_destroy(&data.lock);
}
