
#ifndef PHILO_H
# define PHILO_H 

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

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


/*Structure for global data shared among philosophers*/
typedef struct s_data
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	u_int64_t		timestamp_death;
	u_int64_t		timestamp_eating;
	u_int64_t		timestamp_sleeping;
	u_int64_t		timestamp_start;
	struct t_philo	*philosoph;

	pthread_mutex_t	lock;
	pthread_mutex_t	write;
	pthread_mutex_t	*forks;

	pthread_t		*tid;
}	t_data;

/*Structure for the philosophers*/
typedef struct s_philo
{
	struct s_data	*data;
	int				id;
	int				philo_stat;
	int				meals_counter;

	pthread_mutex_t	lock;

}	t_philo;

/*The global functions*/

/*		TIME		*/
u_int64_t			ft_gettimeofday(void);
int					ft_usleep(useconds_t time)

/*		OTHER		*/
#endif