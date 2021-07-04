#include "push_swap.h"
#include "stdio.h"

void sorta(t_ps *ps)
{
    int i;
    int j;

    ps->sorted = (int *)malloc(sizeof(int) * ps->size_a);
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

void    half(t_ps *ps, int len)
{
    while(ps->size_b < ps->size_a)
        if (ps->a[0] < ps->sorted[len / 2 + (len % 2)])
            pb(ps);
        else
            ra(&ps->a, ps->size_a, 'a', &ps->inst);
}

void    pushToA(t_ps *ps, int len)
{
    int i;
    int j;

    if (ps->ikhane > len)
        ps->ikhane = len / 2;
    j = ps->ikhane;
    while (ps->size_b)
    {
        i = 0;
        while (ps->size_b && i < ps->ikhane)
        {
            if (ps->b[0] >= ps->sorted[len - j])
            {
                pa(ps);
                i++;
            }
            else
                ra(&ps->b, ps->size_b, 'b',  &ps->inst);
        }
        j += ps->ikhane;
        if (len < j)
            j = len;
    }
    while (ps->size_b < len)
        pb(ps);
}

void    pushToB(t_ps *ps, int l)
{
    int j;
    int len;

    len = l / 2 + l % 2;
    j = ps->ikhane;
    while(ps->size_a)
    {
        while (ps->size_a && ps->size_b < len + j)
            if (ps->a[0] <= ps->sorted[len + j - 1])
                pb(ps);
            else
                ra(&ps->a, ps->size_a, 'a', &ps->inst);
        j += ps->ikhane;
        if (len < j)
            j = len - l % 2;
    }
}

int rotdir(int *a, t_ps *ps, int start)
{
    int i;

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

int     findMax(t_ps *ps, int max)
{
    int i;

    i = 0;
    while (i <= ps->size_a / 2)
    {
        if (ps->a[i] == max)
        {
            while (ps->a[ps->size_a - 1] != max)
                ra(&ps->a, ps->size_a, 'a',  &ps->inst);
            pa(ps);
            return(ps->a[0]);
        }
        if (ps->a[ps->size_a - i - 1] == max)
        {
            while (ps->a[ps->size_a - 1] != max)
                rra(&ps->a, ps->size_a, 'a',  &ps->inst);
            pa(ps);
            return(ps->a[0]);
        }
        i++;
    }
    return (max);
}

int    place(t_ps *ps, int max)
{
    if (ps->b[0] > max)
        return (findMax(ps, max));
    while (ps->a[0] < ps->b[0])
        ra(&ps->a, ps->size_a, 'a',  &ps->inst);
    while (ps->a[0] > ps->b[0] && ps->a[ps->size_a - 1] > ps->b[0]
    && ps->a[ps->size_a - 1] != max)
        rra(&ps->a, ps->size_a, 'a',  &ps->inst);
    pa(ps);
    if (ps->a[0] > max)
        max = ps->a[0];
    return (max);
}

void push7(t_ps *ps, int len)
{
    int j;
    int max;
    int i;

    i = 7;
    if (ps->ikhane == 5)
        i = 3;
    j = i;
    pa(ps);
    max = ps->a[0];
    pa(ps);
    if (ps->a[0] > max)
        max = ps->a[0];
    while(ps->size_b > 0)
    {
        while (ps->size_b > 0 && ps->size_a < j)
        {
            if (ps->b[0] >= ps->sorted[len - j])
                max = place(ps, max);
            else if (rotdir(ps->b, ps, len - j))
                ra(&ps->b, ps->size_b, 'b',  &ps->inst);
            else
                rra(&ps->b, ps->size_b, 'b',  &ps->inst);
        }
        j += i;
        if (len < j)
            j = len;
    }
     while (ps->a[0] != ps->sorted[0])
        rra(&ps->a, ps->size_a, 'a',  &ps->inst);
}

void    akhor(t_ps *ps)
{
    int len;

    len = ps->size_a;
    sorta(ps);
    half(ps, ps->size_a);
    pushToA(ps, ps->size_b);
    pushToB(ps, len);
    push7(ps, ps->size_b);
   
    // //printf("ret: %d\n", rotdir(ps->a, ps, len - 3));
}
