/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdenisse <sdenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:05:42 by sdenisse          #+#    #+#             */
/*   Updated: 2021/11/15 15:22:55 by sdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
typedef struct s_ph_data
{
	int				count;
	int				death_time;
	int				eating_time;
	int				sleeping_time;
	int				eating_number;
	int				death;
	long long		start_time;
	pthread_mutex_t	*mutexes;
	pthread_mutex_t	turn;
	pthread_mutex_t	print;
}	t_ph_data;

typedef struct s_philo
{
	pthread_t	id;
	int			number;
	int			meal_count;
	int			eat;
	long long	last_meal;
	t_ph_data	*data;
}	t_philo;

t_ph_data		*data_init(char **argv, int argc);
pthread_mutex_t	*mutex_init(int count);
t_philo			*philo_init(t_ph_data *data);
int				take_forks(t_philo	*philo);
void			*life_cycle(void *ph);
int				ph_sleep(t_philo *philo);
int				ph_eat(t_philo *philo);
long long		get_time(void);
void			*checker(void *ph);
void			print_state(t_philo *philo, int flag);
int				atoi_ph(const char *str, int *result);
void			join_ph(t_philo *philo, pthread_t viewer);
void			change_state(t_philo *philo, int *counter,
					int *current, int *temp);
int				try2eat(t_philo *philo, int temp);
void			forks_lock(t_philo *philo, int temp,
					int (*fn)(pthread_mutex_t *));

#endif