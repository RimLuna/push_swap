/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbougssi <rbougssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 09:20:23 by rbougssi          #+#    #+#             */
/*   Updated: 2021/07/05 10:10:43 by rbougssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	findmax(t_ps *ps, int max)
{
	int	i;

	i = 0;
	while (i <= ps->size_a / 2)
	{
		if (ps->a[i] == max)
		{
			while (ps->a[ps->size_a - 1] != max)
				ra(&ps->a, ps->size_a, 'a', ps);
			pa(ps);
			return (ps->a[0]);
		}
		if (ps->a[ps->size_a - i - 1] == max)
		{
			while (ps->a[ps->size_a - 1] != max)
				rra(&ps->a, ps->size_a, 'a', ps);
			pa(ps);
			return (ps->a[0]);
		}
		i++;
	}
	return (max);
}

int	place(t_ps *ps, int max)
{
	if (ps->b[0] > max)
		return (findmax(ps, max));
	while (ps->a[0] < ps->b[0])
		ra(&ps->a, ps->size_a, 'a', ps);
	while (ps->a[0] > ps->b[0] && ps->a[ps->size_a - 1] > ps->b[0]
		&& ps->a[ps->size_a - 1] != max)
		rra(&ps->a, ps->size_a, 'a', ps);
	pa(ps);
	if (ps->a[0] > max)
		max = ps->a[0];
	return (max);
}

int	getsteps(int ikhane)
{
	if (ikhane == 5)
		return (3);
	return (7);
}

void	normpush7(t_ps *ps, int *max)
{
	pa(ps);
	*max = ps->a[0];
	pa(ps);
	if (ps->a[0] > *max)
		*max = ps->a[0];
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
