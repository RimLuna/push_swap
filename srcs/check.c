/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbougssi <rbougssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 10:42:32 by rbougssi          #+#    #+#             */
/*   Updated: 2021/07/05 10:42:47 by rbougssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arg_check(char **av)
{
	int	i;
	int	j;
	int	n;

	j = 1;
	n = 0;
	while (av[j])
	{
		i = 0;
		while (av[j][i])
		{
			if ((!ft_isdigit(av[j][i]) && (av[j][i] != ' '
				&& av[j][i] != '-')) || (av[j][i + 1] == '-' &&
				ft_isdigit(av[j][i]))
				|| (av[j][i] == '-' && (!av[j][i + 1] || av[j][i + 1] == ' ')))
				return (0);
			i++;
		}
		if (!count_int(av[j]))
			return (0);
		n += count_int(av[j]);
		j++;
	}
	return (n);
}

int	ps_check(t_ps *ps, char **av)
{
	if (!arg_check(av))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	else
	{
		ps->a = (int *)malloc(sizeof(int) * arg_check(av));
		if (!ps->a)
			excit(ps);
		ps->size_a = arg_check(av);
		ps->b = (int *)malloc(sizeof(int) * arg_check(av));
		if (!ps->b)
			excit(ps);
		ps->size_b = 0;
		if (!init(av, ps->a))
			excit(ps);
	}
	return (1);
}
