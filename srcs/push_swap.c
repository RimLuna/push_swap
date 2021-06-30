/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbougssi <rbougssi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 04:33:09 by rbougssi          #+#    #+#             */
/*   Updated: 2021/06/30 04:33:10 by rbougssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arg_check(char **av)
{
	int i;
	int j;
	int n;

	j = 1;
	n = 0;
	while (av[j])
	{
		i = 0;
		while (av[j][i])
		{
			if ((!ft_isdigit(av[j][i]) && (av[j][i] != ' '
			&& av[j][i] != '-')) || (av[j][i + 1] == '-' && ft_isdigit(av[j][i]))
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

int	ps_check(t_ps *ps, int ac, char **av)
{
	if (!arg_check(av) || ac < 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	else
	{
		if (!(ps->a = (int*)malloc(sizeof(int) * arg_check(av))))
			excit(ps);
		ps->size_a = arg_check(av);
		if (!(ps->b = (int*)malloc(sizeof(int) * arg_check(av))))
			excit(ps);
		ps->size_b = 0;
		if (!init(av, ps->a))
			excit(ps);
	}
	return (1);
}

int	sorted(t_ps ps)
{
	int i;

	i = 0;
	while (i < ps.size_a - 1)
	{
		if (ps.a[i] < ps.a[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_ps		ps;

	ps.a = NULL;
	ps.b = NULL;
	if (!ps_check(&ps, ac, av))
		return (0);
	if (sorted(ps))
		excit(&ps);
	if (ps.size_a <= 5)
		smol(&ps, 0);
	a2b(&ps, ps.size_a);
	ff(&ps);
	return (0);
}
