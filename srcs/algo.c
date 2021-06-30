/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbougssi <rbougssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:01:27 by rbougssi          #+#    #+#             */
/*   Updated: 2021/06/30 09:28:12 by rbougssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push2a(t_ps *ps, int len, int median)
{
	int	turn;
	int	pushed;

	turn = 0;
	pushed = 0;
	while (pushed < (len / 2))
	{
		if (ps->b[0] > median && pushed++ > -1)
			pa(ps);
		else
		{
			if (rot_direction(ps->b, ps->size_b, median))
				ra(&ps->b, ps->size_b, 'b');
			else
				rra(&ps->b, ps->size_b, 'b');
			turn++;
		}
	}
	if (len / 2 + len % 2 != ps->size_b)
		while (turn-- > 0)
			rra(&ps->b, ps->size_b, 'b');
}

void	b2a(t_ps *ps, int len)
{
	int	i;
	int	median;

	i = -1;
	if (len <= 2)
	{
		if (len == 2 && ps->b[0] < ps->b[1])
			sa(&ps->b, ps->size_b, 'b');
		while (++i < len)
			pa(ps);
	}
	else
	{
		median = get_median(ps->b, len);
		push2a(ps, len, median);
		a2b(ps, len / 2);
		b2a(ps, len / 2 + len % 2);
	}
}

void	push2b(t_ps *ps, int len, int median)
{
	int	pushed;
	int	turn;

	pushed = 0;
	turn = 0;
	while (pushed < (len / 2 + len % 2))
	{
		if (ps->a[0] <= median && pushed++ > -1)
			pb(ps);
		else
		{
			if (rot_direction(ps->a, ps->size_a, median))
				ra(&ps->a, ps->size_a, 'a');
			else
				rra(&ps->a, ps->size_a, 'a');
			turn++;
		}
	}
	if (len / 2 != ps->size_a)
		while (turn-- > 0)
			rra(&ps->a, ps->size_a, 'a');
}

void	a2b(t_ps *ps, int len)
{
	int	median;

	if (sorted(*ps))
		return ;
	median = get_median(ps->a, len);
	push2b(ps, len, median);
	a2b(ps, len / 2);
	b2a(ps, len / 2 + len % 2);
}
