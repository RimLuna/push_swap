/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbougssi <rbougssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:02:23 by rbougssi          #+#    #+#             */
/*   Updated: 2021/06/30 09:34:48 by rbougssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	unique_check(int n, int *a, int j)
{
	int	i;

	i = 0;
	while (i < j)
		if (n == a[i++])
			return (0);
	a[j] = n;
	return (1);
}

int	checkyoself(char *av, int i, int j, int *a)
{
	long	n;
	int		neg;

	n = 0;
	neg = 1;
	if (av[i] == '-')
	{
		i++;
		neg = -1;
	}
	while (ft_isdigit(av[i]) && av[i])
		n = n * 10 + av[i++] - '0';
	n = n * neg;
	if (!unique_check(n, a, j) || (n < -2147483648 || n > 2147483647))
		return (0);
	return (i);
}

int	init(char **av, int *a)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	k = 1;
	while (av[k])
	{
		i = 0;
		while (av[k][i])
		{
			if ((ft_isdigit(av[k][i]) || av[k][i] == '-') && av[k][i])
			{
				i = checkyoself(av[k], i, j, a);
				if (!i)
					return (0);
				j++;
			}
			else
				i++;
		}
		k++;
	}
	return (1);
}
