/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbougssi <rbougssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 04:33:51 by rbougssi          #+#    #+#             */
/*   Updated: 2021/06/30 09:40:11 by rbougssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_ps
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}				t_ps;

int				sorted(t_ps ps);
int				init(char **av, int *tab);
void			sa(int **a, int size_a, char what);
void			ss(t_ps *ps);
void			pa(t_ps *ps);
void			pb(t_ps *ps);
void			ra(int **a, int size_a, char what);
void			rr(t_ps *ps);
void			rra(int **a, int size_a, char what);
void			rrr(t_ps *ps);
void			a2b(t_ps *ps, int len);
void			b2a(t_ps *ps, int len);
int				sorted(t_ps ps);
int				rot_direction(int *tab, int size, int median);
int				get_median(int *a, int len);
void			smol(t_ps *ps, int pb);
void			excit(t_ps *ps);
void			ff(t_ps *ps);
void			swap(int *a, int *b);
int				ft_isdigit(int c);
int				count_int(char *av);
#endif
