/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdenisse <sdenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 15:14:55 by sdenisse          #+#    #+#             */
/*   Updated: 2021/11/15 15:20:30 by sdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_forks(t_philo	*philo)
{
	static int	counter;
	static int	current;
	int			i;
	int			temp;

	pthread_mutex_lock(&philo->data->turn);
	i = 0;
	change_state(philo, &counter, &current, &temp);
	while (i++ < philo->data->count / 2)
	{
		if (temp >= philo->data->count)
			temp = temp % philo->data->count;
		if (philo->number - 1 == temp)
		{
			counter++;
			if (try2eat(philo, temp) < 0)
				return (-1);
			return (1);
		}
		temp = temp + 2;
	}
	pthread_mutex_unlock(&philo->data->turn);
	return (0);
}

void	change_state(t_philo *philo, int *counter, int *current, int *temp)
{
	if (*counter == philo->data->count / 2)
	{
		*counter = 0;
		if (*current >= philo->data->count)
			*current = 0;
		(*current)++;
	}
	*temp = *current;
}

int	try2eat(t_philo *philo, int temp)
{
	forks_lock(philo, temp, pthread_mutex_lock);
	print_state(philo, 0);
	pthread_mutex_unlock(&philo->data->turn);
	if (philo->data->death || ph_eat(philo) < 0)
	{
		forks_lock(philo, temp, pthread_mutex_unlock);
		return (-1);
	}
	philo->meal_count++;
	forks_lock(philo, temp, pthread_mutex_unlock);
	return (1);
}

void	forks_lock(t_philo *philo, int temp, int (*fn)(pthread_mutex_t *))
{
	if (temp == philo->data->count - 1)
		fn(&philo->data->mutexes[0]);
	else
		fn(&philo->data->mutexes[temp + 1]);
	fn(&philo->data->mutexes[temp]);
}

int	ph_eat(t_philo *philo)
{
	long long	time;
	long long	current_time;

	time = get_time();
	if (time < 0 || philo->data->death)
		return (-1);
	current_time = time;
	philo->last_meal = current_time;
	philo->eat = 1;
	print_state(philo, 1);
	while (current_time < time + philo->data->eating_time)
	{
		usleep(50);
		current_time = get_time();
	}
	philo->eat = 0;
	return (0);
}
