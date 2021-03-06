/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbougssi <rbougssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 04:33:51 by rbougssi          #+#    #+#             */
/*   Updated: 2021/07/05 10:43:57 by rbougssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_lst
{
	char			str[5];
	struct s_lst	*next;
}				t_lst;

typedef struct s_ps
{
	int		*a;
	int		*b;
	int		*sorted;
	int		size_a;
	int		size_b;
	int		ikhane;
	t_lst	*inst;
	t_lst	*first;
}				t_ps;

int				arg_check(char **av);
int				ps_check(t_ps *ps, char **av);
void			normpush7(t_ps *ps, int *max);
int				getsteps(int ikhane);
void			push7(t_ps *ps, int len);
int				place(t_ps *ps, int max);
int				findmax(t_ps *ps, int max);
int				rotdir(int *a, t_ps *ps, int start);
void			push2b(t_ps *ps, int l);
void			push2a(t_ps *ps, int len);
void			half(t_ps *ps, int len);
void			sorta(t_ps *ps);
int				sorted(t_ps ps);
void			push7(t_ps *ps, int len);
int				init(char **av, int *tab);
void			sa(int **a, int size_a, char what, t_ps *ps);
void			ss(t_ps *ps);
void			pa(t_ps *ps);
void			pb(t_ps *ps);
void			ra(int **a, int size_a, char what, t_ps *ps);
void			rr(t_ps *ps);
void			rra(int **a, int size_a, char what, t_ps *ps);
void			rrr(t_ps *ps);
void			a2b(t_ps *ps, int len);
void			b2a(t_ps *ps, int len);
int				sorted(t_ps ps);
int				rot_direction(int *tab, int size, int median);
int				get_median(int *a, int len);
void			imzine(t_ps *ps, int pb);
void			excit(t_ps *ps);
void			ff(t_ps *ps);
void			swap(int *a, int *b);
int				ft_isdigit(int c);
int				count_int(char *av);
void			algikhane(t_ps *ps);
#endif
