
#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/types.h>
# include <stdbool.h>
# include <stdint.h>

/*PHILO MESSAGE*/
# define DIE "is dead"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define FORKS "has taken a fork"

/*INPUT ERROR MESSAGE*/
# define INPUT_ERR_1 "INPUT ERROR: Invalid values"
# define INPUT_ERR_2 "INPUT ERROR: Invalid character"
# define INPUT_ERR_3 "INPUT ERROR: To many/few values"

/*OTHER ERROR*/
# define GET_TIME_ERR "TIME ERROR: my_gettimeofday Failed"

/*Structure for the philosophers*/

typedef struct s_data
{
	int				philos_nb;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				dead;
	u_int64_t		timestamp_death;
	u_int64_t		timestamp_eating;
	u_int64_t		timestamp_sleeping;
	u_int64_t		timestamp_start;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
	pthread_mutex_t	*forks;
	pthread_t		*tid;
}	t_data;

typedef struct s_philos
{
	int				id;
	int				sleep;
	int				eat;
	int				think;
	int				live;
	pthread_t		thread;
	pthread_mutex_t	fork;
	t_data			*data;
	struct s_philos	*next;
}	t_philos;

/*Structure for global data shared among philosophers*/


/*The global functions*/

/*		TIME		*/
u_int64_t			ft_gettimeofday(void);
int					ft_usleep(useconds_t time);

/*		INPUT		*/
int 				parse_arg(t_data *data, int argc, char **argv);

/*		OTHER		*/
void				init_struct(t_philos *philos);
void				init_thread(t_philos *philos);
void				ft_exit(t_philos *philos);
#endif