/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ff.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbougssi <rbougssi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:02:07 by rbougssi          #+#    #+#             */
/*   Updated: 2021/06/29 19:02:07 by rbougssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void        ff(t_ps *ps)
{
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

void        excit(t_ps *ps)
{
    ff(ps);
    write(1, "Error\n", 6);
    exit(1);    
}
