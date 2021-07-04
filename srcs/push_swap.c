/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbougssi <rbougssi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 04:33:09 by rbougssi          #+#    #+#             */
/*   Updated: 2021/07/04 23:19:54 by rbougssi         ###   ########.fr       */
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

int	sorted(t_ps ps)
{
	int	i;

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

t_lst*	change(t_lst *first, int c, char t, char r)
{
	t_lst *save;
	t_lst *last;
	t_lst *tmp;
	int i;
	
	i = 0;
	save = first;
	while (first && first->str[0] == 'r' && first->str[c] == t)
	{
		i++;
		last = first;
		first = first->next;
	}
	while (first && first->str[0] == 'r' && first->str[c] == r && i)
	{
		i--;
		save->str[c] = 'r';
		save = save->next;
		tmp = first->next;
		free(last->next);
		last->next = tmp;
		first = tmp;
	}
	return (first);
}

t_lst*	check(t_lst *first)
{
	int c;
	char t;
	char r;

	if (first->str[1] == 'r')
	{
		c = 2;
		t = first->str[2];
	}
	else
	{
		c = 1;
		t = first->str[1];
	}
	if (t == 'a')
		r = 'b';
	else
		r = 'a';
	return (change(first, c, t, r));
}

void	less(t_lst *first)
{
	while (first)
	{
		if (first->str[0] == 'r')
			first = check(first);
		if (first)		
			first = first->next;
	}

}

void last(t_lst *first)
{
	less(first);
	while (first->next)
	{
		first = first->next;
		int i = -1;
		while (first->str[++i] != 0)
			write(1, &first->str[i], 1);
	}
}

int	main(int ac, char **av)
{
	t_ps	ps;
	t_lst	*first;

	ps.a = NULL;
	ps.b = NULL;
	ps.inst = (t_lst *)malloc(sizeof(t_lst));
	ps.inst->next = NULL;
	first = ps.inst;
	ps.first = first;
	if (ac < 2 || !ps_check(&ps, av))
		return (0);
	if (sorted(ps))
		return (0);
	ps.ikhane = 15 + ps.size_a / 20;
	if (ps.size_a <= 5)
		imzine(&ps, 0);
	else
		algikhane(&ps);
	last(first);
	ff(&ps);
	return (0);
}
