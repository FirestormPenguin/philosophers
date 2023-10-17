/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:04:22 by egiubell          #+#    #+#             */
/*   Updated: 2023/10/17 13:00:49 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/*Structure for global data shared among philosophers*/
struct	s_philos;

typedef struct s_data
{
	int				philos_nb;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				dead;
	int				finish_meals;
	struct s_philos	*philos;
	u_int64_t		data_death;
	u_int64_t		data_start;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
}	t_data;

/*Structure for the philosophers*/
typedef struct s_philos
{
	int				id;
	int				eat;
	int				live;
	pthread_t		thread;
	pthread_t		monitor;
	pthread_mutex_t	fork;
	u_int64_t		timestamp_death;
	u_int64_t		timestamp_start;
	t_data			*data;
	struct s_philos	*next;
}	t_philos;

/*The global functions*/

/*		TIME		*/
u_int64_t			ft_gettimeofday(void);
int					ft_usleep(useconds_t time);

/*		INPUT		*/
int					parse_arg(t_data *data, int argc, char **argv);

/*		OTHER		*/
t_philos			*init_struct(t_data *data);
void				init_thread(t_philos *philos);
void				ft_exit(t_philos *philos);
long				ft_atoi(const char *str);

/*		ACTIONS		*/
void				eat(t_philos *philos);
void				fork_taken(t_philos *philos);
void				ft_sleep(t_philos *philos);
void				think(t_philos *philos);

#endif