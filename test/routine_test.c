#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

pthread_mutex_t lock;
int time_to_eat;

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
}	t_data;

t_philos	*ft_lstnew(int id)
{
	t_philos *philos;

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

t_philos	*init_struct(t_data *data)
{
	t_philos *philos_h;
	t_philos *philos;
	int i;

	i = 0;
	philos_h = NULL;
	while(i < data->philos_nb)
	{
		if (i == 0)
		{
			philos = ft_lstnew(i);
			philos_h = philos;
		}
		else 
		{
			philos->next = ft_lstnew(i);
			philos = philos->next;
		}
		i++;
	}
	return(philos_h);
}

void  *routine(t_philos *philos)
{
	printf("enter routine %d\n", philos->id);
	while (philos->live == 1)
	{
		pthread_mutex_lock(&lock);
		philos->eat = 1;
		printf("philo %d is eating\n", philos->id);
		sleep(time_to_eat);
		pthread_mutex_unlock(&lock);
	}
	return (NULL);
}

void scroll_philos(t_philos *philos)
{
	while (philos)
	{
		//printf("philo id: %d\nsleep: %d\neat: %d\nthink: %d\nlive: %d\n\n", philos->id, philos->sleep, philos->eat, philos->think, philos->live);
		pthread_create(&philos->thread, NULL, &routine, philos);
		pthread_join(philos->thread, NULL);
		philos = philos->next;
	}
}

int main(int argc, char **argv)
{
	t_philos *philos_h;
	t_data	data;
	pthread_t phil1, phil2, phil3, phil4, phil5;

	if (argc != 3)
	{
		printf("Error: arguments number invalid!\n");
		return (1);
	}
	data.philos_nb = atoi(argv[1]);
	time_to_eat = atoi(argv[2]);
	philos_h = init_struct(&data);
	pthread_mutex_init(&lock, NULL);
	scroll_philos(philos_h);
	pthread_mutex_destroy(&lock);
}
