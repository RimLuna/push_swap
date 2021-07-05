/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbougssi <rbougssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 04:33:09 by rbougssi          #+#    #+#             */
/*   Updated: 2021/07/05 10:43:11 by rbougssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*change(t_lst *first, int c, char t, char r)
{
	t_lst	*save;
	t_lst	*last;
	t_lst	*tmp;
	int		i;

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

t_lst	*check(t_lst *first)
{
	int		c;
	char	t;
	char	r;

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

void	last(t_lst *first)
{
	int	i;

	less(first);
	while (first->next)
	{
		first = first->next;
		i = -1;
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
