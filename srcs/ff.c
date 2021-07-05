/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ff.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbougssi <rbougssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:02:07 by rbougssi          #+#    #+#             */
/*   Updated: 2021/07/05 09:19:16 by rbougssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ff(t_ps *ps)
{
	t_lst	*tmp;

	free(ps->sorted);
	while (ps->first)
	{
		tmp = ps->first->next;
		free(ps->first);
		ps->first = tmp;
	}
	if (ps->a)
	{
		free(ps->a);
		ps->a = NULL;
	}
	if (ps->b)
	{
		free(ps->b);
		ps->b = NULL;
	}
}

void	excit(t_ps *ps)
{
	ff(ps);
	write(1, "Error\n", 6);
	exit(1);
}
