/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imzine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbougssi <rbougssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 09:58:16 by rbougssi          #+#    #+#             */
/*   Updated: 2021/07/05 09:58:18 by rbougssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_median(int *a, int len)
{
	int	i;
	int	j;
	int	upper;
	int	lower;

	j = 0;
	while (j < len)
	{
		upper = 0;
		lower = 0;
		i = 0;
		while (i < len)
		{
			if (a[i] < a[j])
				lower++;
			else if (a[i] > a[j])
				upper++;
			i++;
		}
		if (lower == upper || lower + 1 == upper)
			return (a[j]);
		j++;
	}
	return (0);
}

void	smowl(t_ps *ps)
{
	if (ps->a[0] > ps->a[1])
		sa(&ps->a, ps->size_a, 'a', ps);
	if (sorted(*ps))
		return ;
	rra(&ps->a, ps->size_a, 'a', ps);
	smowl(ps);
}

void	imzine(t_ps *ps, int size)
{
	while (ps->size_a > 3)
	{
		if (ps->a[0] < get_median(ps->a, ps->size_a))
		{
			pb(ps);
			size++;
		}
		else
			ra(&ps->a, ps->size_a, 'a', ps);
	}
	smowl(ps);
	while (size-- > 0)
	{
		if (ps->size_b == 2 && ps->b[0] < ps->b[1])
			sa(&ps->b, ps->size_b, 'b', ps);
		pa(ps);
	}
}
