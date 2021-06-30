/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbougssi <rbougssi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:02:44 by rbougssi          #+#    #+#             */
/*   Updated: 2021/06/29 19:02:44 by rbougssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(int **a, int size_a, char what)
{
	int tmp;
	int i;

	if (size_a)
	{
		i = size_a;
		tmp = a[0][i - 1];
		while (--i > 0)
			a[0][i] = a[0][i - 1];
		a[0][0] = tmp;
	}
	if (what)
	{
		write(1, "rr", 2);
		write(1, &what, 1);
		write(1, "\n", 1);
	}
}

void	rrr(t_ps *ps)
{
	rra(&ps->a, ps->size_a, 0);
	rra(&ps->b, ps->size_b, 0);
	write(1, "rrr\n", 4);
}

void	ra(int **a, int size_a, char what)
{
	int tmp;
	int	i;

	if (size_a)
	{
		tmp = a[0][0];
		i = -1;
		while (++i < size_a - 1)
			a[0][i] = a[0][i + 1];
		a[0][size_a - 1] = tmp;
	}
	if (what)
	{
		write(1, "r", 1);
		write(1, &what, 1);
		write(1, "\n", 1);
	}
}

void	rr(t_ps *ps)
{
	ra(&ps->a, ps->size_a, 0);
	ra(&ps->b, ps->size_b, 0);
	write(1, "rr\n", 3);
}
