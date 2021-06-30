/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbougssi <rbougssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:02:56 by rbougssi          #+#    #+#             */
/*   Updated: 2021/06/30 09:28:25 by rbougssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rot_direction(int *tab, int size, int median)
{
	int	left;
	int	right;
	int	i;

	i = 0;
	left = 0;
	right = 0;
	while (tab[i++] > median)
		left++;
	i = size - 1;
	while (tab[i--] > median)
		right++;
	return (right >= left);
}

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
