/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbougssi <rbougssi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:02:34 by rbougssi          #+#    #+#             */
/*   Updated: 2021/07/04 23:00:29 by rbougssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int **a, int size_a, char what, t_ps *ps)
{
	if (size_a)
		swap(&a[0][0], &a[0][1]);
	if (what)
	{
		ps->inst->next = (t_lst *)malloc(sizeof(t_lst));
		if (!ps->inst->next)
			excit(ps);
		ps->inst = ps->inst->next; 
		ps->inst->str[0] = 's';
		ps->inst->str[1] = what;
		ps->inst->str[2] = '\n';
		ps->inst->str[3] = '\0';
		ps->inst->next = NULL;
	}
}

void	ss(t_ps *ps)
{
	sa(&ps->a, ps->size_a, 0, ps);
	sa(&ps->b, ps->size_b, 0, ps);
	ps->inst->next = (t_lst *)malloc(sizeof(t_lst));
	if (!ps->inst->next)
		excit(ps);
	ps->inst = ps->inst->next; 
	ps->inst->str[0] = 's';
	ps->inst->str[1] = 's';
	ps->inst->str[2] = '\n';
	ps->inst->str[3] = '\0';
	ps->inst->next = NULL;
}

void	pa(t_ps *ps)
{
	int	i;

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
	ps->inst->next = (t_lst *)malloc(sizeof(t_lst));
	if (!ps->inst->next)
		excit(ps);
	ps->inst = ps->inst->next; 
	ps->inst->str[0] = 'p';
	ps->inst->str[1] = 'a';
	ps->inst->str[2] = '\n';
	ps->inst->str[3] = '\0';
	ps->inst->next = NULL;
}

void	pb(t_ps *ps)
{
	int	i;

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
	ps->inst->next = (t_lst *)malloc(sizeof(t_lst));
	if (!ps->inst->next)
		excit(ps);
	ps->inst = ps->inst->next; 
	ps->inst->str[0] = 'p';
	ps->inst->str[1] = 'b';
	ps->inst->str[2] = '\n';
	ps->inst->str[3] = '\0';
	ps->inst->next = NULL;
}
