/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbougssi <rbougssi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:02:12 by rbougssi          #+#    #+#             */
/*   Updated: 2021/06/29 19:02:13 by rbougssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_isdigit(int c)
{
	return ((c >= 48 && c <= 57));
}

void	swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

int	count_int(char *av)
{
	int i;
	int n;

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
