/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdenisse <sdenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 23:36:23 by sdenisse          #+#    #+#             */
/*   Updated: 2021/09/05 20:41:05 by sdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_flag;

void	ft_client_error(int i)
{
	if (i == 1)
		write(2, "Error: Invalid numbers of arguments.\n", 37);
	else if (i == 2)
		write(2, "invalid PID\n", 12);
	else if (i == 3)
		write(2, "Signal failed\n", 14);
	exit(i);
}

void	send_msg(char *str, int pid)
{
	int	i;
	int	len;

	len = ft_strlen(str) + 1;
	while (len-- > 0)
	{
		i = 0;
		while (i < 8)
		{
			g_flag = 1;
			if ((*str >> i) & 1)
				if (kill(pid, SIGUSR1) == -1)
					ft_client_error(3);
			if (!((*str >> i) & 1))
				if (kill(pid, SIGUSR2) == -1)
					ft_client_error(3);
			i++;
			usleep(40);
		}
		str++;
	}
}

void	answer_handler(int id, siginfo_t *info, void *old)
{
	(void)info;
	(void)old;
	if (id == SIGUSR1)
		g_flag = 0;
}

int	main(int argc, char **argv)
{
	struct sigaction	answer;
	int					pid;

	answer.sa_flags = SA_SIGINFO;
	answer.sa_sigaction = answer_handler;
	if (sigaction(SIGUSR2, &answer, 0) == -1)
		ft_client_error(3);
	if (argc != 3)
		ft_client_error(1);
	pid = ft_atoi(argv[1]);
	g_flag = 0;
	if (!pid)
		ft_client_error(2);
	send_msg(argv[2], pid);
}
