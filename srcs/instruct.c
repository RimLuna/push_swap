/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbougssi <rbougssi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:02:34 by rbougssi          #+#    #+#             */
/*   Updated: 2021/06/29 19:02:34 by rbougssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int **a, int size_a, char what)
{
	if (size_a)
		swap(&a[0][0], &a[0][1]);
	if (what)
	{
		write(1, "s", 1);
		write(1, &what, 1);
		write(1, "\n", 1);
	}
}

void	ss(t_ps *ps)
{
	sa(&ps->a, ps->size_a, 0);
	sa(&ps->b, ps->size_b, 0);
	write(1, "ss\n", 3);
}

void	pa(t_ps *ps)
{
	int i;

	if (ps->size_b)
	{
		i = ++ps->size_a;
		while (--i > 0)
			ps->a[i] = ps->a[i - 1];
		ps->a[0] = ps->b[0];
		i = -1;
		while (++i < ps->size_b)
			ps->b[i] = ps->b[i + 1];
		ps->size_b--;
	}
	write(1, "pa\n", 3);
}

void	pb(t_ps *ps)
{
	int i;

	if (ps->size_a)
	{
		i = ++ps->size_b;
		while (--i > 0)
			ps->b[i] = ps->b[i - 1];
		ps->b[0] = ps->a[0];
		i = -1;
		while (++i < ps->size_a)
			ps->a[i] = ps->a[i + 1];
		ps->size_a--;
	}
	write(1, "pb\n", 3);
}
