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

    j = 35;
    while(ps->size_b)
    {
        i = 0;
        while (ps->size_b && i < 35)
            if (ps->b[0] >= ps->sorted[len - j])
            {
                pa(ps);
                i++;
            }
            else
                ra(&ps->b, ps->size_b, 'b',  &ps->inst);
        j += 35;
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
    j = 35;
    while(ps->size_a)
    {
        while (ps->size_a && ps->size_b < len + j)
            if (ps->a[0] <= ps->sorted[len + j - 1])
                pb(ps);
            else
                ra(&ps->a, ps->size_a, 'a', &ps->inst);
        j += 35;
        if (len < j)
            j = len - l % 2;
    }
}

int rotdir(int *a, t_ps *ps, int start)
{
    int i;

    i = 0;
    // FILE *f = fopen("miaw", "a+");
    // while (i < ps->size_a)
    //     fprintf(f,"%d\n",ps->a[i++]);
    // fclose(f);
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

void    sort3(t_ps *ps)
{
    if (ps->size_a == 2 && ps->b[0] > ps->a[0] && ps->b[0] > ps->a[1])
    {
        pa(ps);
        ra(&ps->a, ps->size_a, 'a', &ps->inst);
    }
    else if (ps->size_a > 2 && ps->b[0] > ps->a[0] && ps->b[0] > ps->a[1])
    {
        ra(&ps->a, ps->size_a, 'a', &ps->inst);
        pa(ps);
        sa(&ps->a, ps->size_a, 'a', &ps->inst);
        rra(&ps->a, ps->size_a, 'a', &ps->inst);
    }
    else if (ps->size_a > 1 && ps->b[0] > ps->a[0])
    {
        pa(ps);
        sa(&ps->a, ps->size_a, 'a', &ps->inst);
    }
    else
        pa(ps);
}

void push3a(t_ps *ps, int len)
{
    int j;

    j = 3;
    while(ps->size_b > 0)
    {
        while (ps->size_b > 0 && ps->size_a < j)
            if (ps->b[0] >= ps->sorted[len - j])
                sort3(ps);
            else if (rotdir(ps->b, ps, len - j))
                ra(&ps->b, ps->size_b, 'b',  &ps->inst);
            else
                rra(&ps->b, ps->size_b, 'b',  &ps->inst);
        j += 3;
        if (len < j)
            j = len;
    }
}

void    akhor(t_ps *ps)
{
    int len;

    len = ps->size_a;
    sorta(ps);
    half(ps, ps->size_a);
    pushToA(ps, ps->size_b);
    pushToB(ps, len);
    push3a(ps, ps->size_b);
    // printf("ret: %d\n", rotdir(ps->a, ps, len - 3));
}
