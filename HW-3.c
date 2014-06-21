#include <stdio.h>
#include <stdlib.h>
#define between(x, lower, upper) (lower <= x && x < upper) //funkcija

int main ()
{
    int x ,y, i, j;
    scanf("%d %d", &x, &y); //preberemo velikost 2-dimenzionalne tabele


    int **map; // naredimo tabelo
    map = malloc (x * sizeof (int *));
    for (i = 0; i < x; i++)
        map[i] = malloc (y * sizeof (int));

    for(i = 0; i < x; i++)
    {
            for (j = 0; j < y; j++)
            {
                map[i][j] = -1;
            }
    }

    int number = 0;
    map[0][0] = number;

    int a, b;

    while (scanf("%d %d", &a, &b) == 2)
    {
        if (between (a, 0, x) && between (b, 0 ,y))
        {
            map[a][b]= -8; //nastavimo mino na -8
        }

    }

 int k;

    for (k = 0; k < x*y ; k++)
    {
        for(i = 0; i < x; i++)
        {
            for (j = 0; j < y; j++)
            {

                if (map[i][j] == number)
                {
                    if( between (i + 1, 0 ,x)  && map[i + 1][j] == -1 ) //gor
                    {
                        map[i + 1][j] = number + 1;
                    }
                    if(  between (i - 1, 0 ,x) && map[i - 1][j] == -1 ) //dol
                    {
                        map[i - 1][j] = number + 1;
                    }
                    if(  between (j + 1, 0 ,y) && map[i][j + 1] == -1 ) //gor
                    {
                        map[i][j + 1] = number + 1;
                    }
                    if( between (j - 1, 0 ,y) && map[i][j - 1] == -1 ) //gor
                    {
                        map[i][j - 1] = number + 1;
                    }
                }
            }
        }
        number++;
   }

//testiranje tabele
  /*  for(i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
        printf("%4d",map[i][j]);
        }
    printf("\n\n");
    }
  */

    printf ("%d", map[x - 1][y - 1]);
    return 0;
}
