/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbougssi <rbougssi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:02:44 by rbougssi          #+#    #+#             */
/*   Updated: 2021/07/04 15:58:32 by rbougssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(int **a, int size_a, char what, t_lst **inst)
{
	int	tmp;
	int	i;

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
		(*inst)->next = (t_lst *)malloc(sizeof(t_lst));
		(*inst) = (*inst)->next;
		(*inst)->str[0] = 'r';
		(*inst)->str[1] = 'r';
		(*inst)->str[2] = what;
		(*inst)->str[3] = '\n';
		(*inst)->str[4] = '\0';
		(*inst)->next = NULL;
	}
}

void	rrr(t_ps *ps)
{
	rra(&ps->a, ps->size_a, 0, &ps->inst);
	rra(&ps->b, ps->size_b, 0, &ps->inst);
	ps->inst->next = (t_lst *)malloc(sizeof(t_lst));
	ps->inst = ps->inst->next;
	ps->inst->str[0] = 'r';
	ps->inst->str[1] = 'r';
	ps->inst->str[2] = 'r';
	ps->inst->str[3] = '\n';
	ps->inst->str[4] = '\0';
	ps->inst->next = NULL;
}

void	ra(int **a, int size_a, char what, t_lst **inst)
{
	int	tmp;
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
		(*inst)->next = (t_lst *)malloc(sizeof(t_lst));
		(*inst) = (*inst)->next;
		(*inst)->str[0] = 'r';
		(*inst)->str[1] = what;
		(*inst)->str[2] = '\n';
		(*inst)->str[3] = '\0';
		(*inst)->next = NULL;

	}
}

void	rr(t_ps *ps)
{
	ra(&ps->a, ps->size_a, 0, &ps->inst);
	ra(&ps->b, ps->size_b, 0, &ps->inst);
	ps->inst->next = (t_lst *)malloc(sizeof(t_lst));
	ps->inst = ps->inst->next;
	ps->inst->str[0] = 'r';
	ps->inst->str[1] = 'r';
	ps->inst->str[2] = '\n';
	ps->inst->str[3] = '\0';
	ps->inst->next = NULL;
}
