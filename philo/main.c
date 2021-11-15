/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdenisse <sdenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 17:54:34 by sdenisse          #+#    #+#             */
/*   Updated: 2021/11/15 15:24:18 by sdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*checker(void *ph)
{
	t_philo		*philo;
	int			i;
	long long	time;

	i = 0;
	philo = (t_philo *)ph;
	while (1)
	{
		if (i >= philo->data->count - 1)
			i = 0;
		time = get_time();
		if ((time >= philo[i].last_meal + philo->data->death_time
				&& !philo[i].eat)
			|| (philo->data->eating_number >= 0 && philo->data->eating_number
				<= philo[i].meal_count) || philo->data->death == 1)
		{	
			philo->data->death = 1;
			if (!(philo->data->eating_number >= 0 && philo->data->eating_number
					<= philo[i].meal_count))
				print_state(&philo[i], 4);
			return (ph);
		}
		i++;
	}
	return (ph);
}

int	main(int argc, char **argv)
{
	t_ph_data		*data;
	t_philo			*philo;
	pthread_t		viewer;

	if (argc < 5 || argc > 6)
		return (1);
	data = data_init(argv, argc);
	if (!data)
		return (1);
	data->mutexes = mutex_init(data->count);
	if (!data->mutexes)
		return (1);
	if (pthread_mutex_init(&(data->turn), NULL) < 0)
		return (1);
	if (pthread_mutex_init(&(data->print), NULL) < 0)
		return (1);
	philo = philo_init(data);
	if (!philo)
		return (1);
	if (pthread_create(&viewer, NULL, checker, philo))
		return (1);
	join_ph(philo, viewer);
}
