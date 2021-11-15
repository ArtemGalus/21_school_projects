/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdenisse <sdenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:05:57 by sdenisse          #+#    #+#             */
/*   Updated: 2021/11/15 15:05:52 by sdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_ph_data	*data_init(char **argv, int argc)
{
	t_ph_data	*data;

	data = malloc(sizeof(t_ph_data));
	if (!data)
		return (NULL);
	if (atoi_ph(argv[1], &(data->count)) || !data->count)
		return (NULL);
	if (atoi_ph(argv[2], &(data->death_time)) || !data->death_time)
		return (NULL);
	if (atoi_ph(argv[3], &(data->eating_time)))
		return (NULL);
	if (atoi_ph(argv[4], &(data->sleeping_time)))
		return (NULL);
	if (argc == 6)
	{
		if (atoi_ph(argv[5], &(data->eating_number)))
			return (NULL);
	}
	else
		data->eating_number = -1;
	data->start_time = get_time();
	return (data);
}

pthread_mutex_t	*mutex_init(int count)
{
	pthread_mutex_t	*bag;
	int				i;

	bag = malloc(sizeof(pthread_mutex_t) * count);
	if (!bag)
		return (NULL);
	i = -1;
	while (++i < count)
	{
		if (pthread_mutex_init(&bag[i], NULL))
		{
			while (--i > 0)
			{
				pthread_mutex_destroy(&bag[i]);
				free(bag);
				return (NULL);
			}
		}
	}
	return (bag);
}

t_philo	*philo_init(t_ph_data *data)
{
	int		i;
	t_philo	*philo;

	philo = malloc(sizeof(t_philo) * data->count);
	if (!philo)
		return (NULL);
	i = 0;
	while (i < data->count)
	{
		philo[i].data = data;
		philo[i].number = i + 1;
		philo[i].meal_count = 0;
		philo[i].eat = 0;
		philo[i].last_meal = (philo[i].data)->start_time;
		(philo[i].data)->death = 0;
		if (pthread_create(&philo->id, NULL, life_cycle, &(philo[i])))
			return (NULL);
		i++;
	}
	return (philo);
}

int	atoi_ph(const char *str, int *result)
{
	*result = 0;
	while (*str && *str >= '0' && *str <= '9')
		*result = *result * 10 + *str++ - '0';
	if (*str)
		return (1);
	return (0);
}
