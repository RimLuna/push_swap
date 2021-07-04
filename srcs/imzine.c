/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imzine.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbougssi <rbougssi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 04:33:17 by rbougssi          #+#    #+#             */
/*   Updated: 2021/07/04 22:48:38 by rbougssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
