/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdenisse <sdenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 20:00:25 by sdenisse          #+#    #+#             */
/*   Updated: 2021/09/05 20:34:24 by sdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	print_symbol(void)
{
	char	c;

	c = g_symbol[1];
	write(1, &c, 1);
	return (1);
}

void	handler(int id, siginfo_t *siginfo, void *old)
{
	int	flag;

	(void)siginfo;
	(void)old;
	if (id == SIGUSR1)
		flag = 1;
	if (id == SIGUSR2)
		flag = 0;
	g_symbol[1] = (flag << g_symbol[0]) + g_symbol[1];
	g_symbol[0] += 1;
	if (g_symbol[0] == 8 && print_symbol())
		ft_bzero(g_symbol, sizeof(int) * 2);
}

void	ft_server_error(void)
{
	write(2, "Signal failed\n", 14);
	exit(1);
}

int	main(void)
{
	struct sigaction	sig_info;

	ft_bzero(g_symbol, sizeof(int) * 2);
	sig_info.sa_flags = SA_SIGINFO;
	sig_info.sa_sigaction = handler;
	if (sigaction(SIGUSR1, &sig_info, 0) == -1)
		ft_server_error();
	if (sigaction(SIGUSR2, &sig_info, 0) == -1)
		ft_server_error();
	write(1, "PID: ", 5);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
		pause();
}
