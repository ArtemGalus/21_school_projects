/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdenisse <sdenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:00:05 by sdenisse          #+#    #+#             */
/*   Updated: 2021/11/14 17:53:38 by sdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*life_cycle(void *ph)
{
	t_philo	*philo;
	int		check;

	philo = (t_philo *)ph;
	while (!philo->data->death)
	{
		while (1)
		{
			check = take_forks(philo);
			if (check < 0 || philo->data->death == 1)
			{
				philo->data->death = 1;
				return (ph);
			}
			if (check > 0)
				break ;
		}
		if (ph_sleep(philo) < 0)
		{
			philo->data->death = 1;
			return (ph);
		}
		print_state(philo, 3);
	}
	return (ph);
}

int	ph_sleep(t_philo *philo)
{
	long long	time;
	long long	current_time;

	time = get_time();
	if (time < 0 || philo->data->death)
		return (-1);
	current_time = time;
	print_state(philo, 2);
	while (current_time < time + philo->data->sleeping_time)
	{
		current_time = get_time();
		usleep(50);
	}
	return (0);
}

long long	get_time(void)
{
	struct timeval	day_time;
	long long		time;

	if (gettimeofday(&day_time, NULL) < 0)
		return (-1);
	time = day_time.tv_sec * 1000 + day_time.tv_usec / 1000;
	return (time);
}

void	print_state(t_philo *philo, int flag)
{
	char	*s[5];

	s[0] = "has taken a fork";
	s[1] = "is eating";
	s[2] = "is sleeping";
	s[3] = "is thinking";
	s[4] = "died";
	if (philo->data->death && flag != 4)
		return ;
	pthread_mutex_lock(&philo->data->print);
	printf("%lli %d %s\n", (get_time() - philo->data->start_time),
		philo->number, s[flag]);
	pthread_mutex_unlock(&philo->data->print);
}

void	join_ph(t_philo *philo, pthread_t viewer)
{
	void	*status;
	int		i;

	i = 0;
	while (i < philo->data->count)
		pthread_join(philo[i++].id, &status);
	pthread_join(viewer, &status);
}
