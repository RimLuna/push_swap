/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algikhane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbougssi <rbougssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 09:27:14 by rbougssi          #+#    #+#             */
/*   Updated: 2021/07/05 09:55:54 by rbougssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	half(t_ps *ps, int len)
{
	while (ps->size_b < ps->size_a)
	{
		if (ps->a[0] < ps->sorted[len / 2 + (len % 2)])
			pb(ps);
		else
			ra(&ps->a, ps->size_a, 'a', ps);
	}
}

void	push2a(t_ps *ps, int len)
{
	int	i;
	int	j;

	if (ps->ikhane > len)
		ps->ikhane = len / 2;
	j = ps->ikhane;
	while (ps->size_b)
	{
		i = 0;
		while (ps->size_b && i < ps->ikhane)
		{
			if (ps->b[0] >= ps->sorted[len - j])
			{
				pa(ps);
				i++;
			}
			else
				ra(&ps->b, ps->size_b, 'b', ps);
		}
		j += ps->ikhane;
		if (len < j)
			j = len;
	}
	while (ps->size_b < len)
		pb(ps);
}

void	push2b(t_ps *ps, int l)
{
	int	j;
	int	len;

	len = l / 2 + l % 2;
	j = ps->ikhane;
	while (ps->size_a)
	{
		while (ps->size_a && ps->size_b < len + j)
		{
			if (ps->a[0] <= ps->sorted[len + j - 1])
				pb(ps);
			else
				ra(&ps->a, ps->size_a, 'a', ps);
		}
		j += ps->ikhane;
		if (len < j)
			j = len - l % 2;
	}
}

void	push7(t_ps *ps, int len)
{
	int	j;
	int	max;
	int	i;

	i = getsteps(ps->ikhane);
	j = i;
	normpush7(ps, &max);
	while (ps->size_b > 0)
	{
		while (ps->size_b > 0 && ps->size_a < j)
		{
			if (ps->b[0] >= ps->sorted[len - j])
				max = place(ps, max);
			else if (rotdir(ps->b, ps, len - j))
				ra(&ps->b, ps->size_b, 'b', ps);
			else
				rra(&ps->b, ps->size_b, 'b', ps);
		}
		j += i;
		if (len < j)
			j = len;
	}
	while (ps->a[0] != ps->sorted[0])
		rra(&ps->a, ps->size_a, 'a', ps);
}

void	algikhane(t_ps *ps)
{
	int	len;

	len = ps->size_a;
	sorta(ps);
	if (ps->size_a <= 15)
	{
		ps->ikhane = 5;
		while (ps->size_a)
			pb(ps);
	}
	else
	{
		half(ps, ps->size_a);
		push2a(ps, ps->size_b);
		push2b(ps, len);
	}
	push7(ps, ps->size_b);
}
