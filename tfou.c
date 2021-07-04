#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int ac, char **av)
{
    char c;
    char tab[4];
    int i;
    int a, b, r;

    i = 0;
    a = 0;
    b = 0;
    r = 0;
    while ((c = getchar()) != EOF)
    {
        // write(1, &c, 1);
        tab[i++] = c;
        if (c == '\n')
        {
            i = 0;
            if (!strcmp(tab, "rra\n"))
            {
                if (b == 3)
                {
                    a--;
                    r++;
                }
                else
                {
                    a++;
                    b = 1;
                }
            }

        }
    }

}