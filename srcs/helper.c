/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbougssi <rbougssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:02:12 by rbougssi          #+#    #+#             */
/*   Updated: 2021/07/05 09:18:50 by rbougssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotdir(int *a, t_ps *ps, int start)
{
	int	i;

	i = 1;
	while (i < ps->size_b / 2)
	{
		if (a[i] >= ps->sorted[start])
			return (1);
		if (a[ps->size_b - i] >= ps->sorted[start])
			return (0);
		i++;
	}
	return (0);
}

void	sorta(t_ps *ps)
{
	int	i;
	int	j;

	ps->sorted = (int *)malloc(sizeof(int) * ps->size_a);
	if (!ps->sorted)
		excit(ps);
	i = -1;
	while (++i < ps->size_a)
		ps->sorted[i] = ps->a[i];
	i = 0;
	while (i < ps->size_a)
	{
		j = i;
		while (++j < ps->size_a)
			if (ps->sorted[j] < ps->sorted[i])
				swap(&ps->sorted[j], &ps->sorted[i]);
		i++;
	}
}

int	ft_isdigit(int c)
{
	return ((c >= 48 && c <= 57));
}

void	swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

int	count_int(char *av)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (av[i])
	{
		if (ft_isdigit(av[i]) && !ft_isdigit(av[i + 1]))
			n++;
		i++;
	}
	return (n);
}
