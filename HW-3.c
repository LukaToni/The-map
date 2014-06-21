#include <stdio.h>
#include <stdlib.h>

#define between(x, lower, upper) (lower <= x && x < upper) //function

int main ()
{
    int x ,y, i, j;
    scanf("%d %d", &x, &y); //read height and length


    int **map = malloc (x * sizeof (int *));
    
    for (i = 0; i < x; i++)
        map[i] = malloc (y * sizeof (int));

    for(i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
                map[i][j] = 0;
                
    }

    int number = 1;
    map[0][0] = number;

    int a, b;

    while (scanf("%d %d", &a, &b) == 2)
    {
        if (between (a, 0, x) && between (b, 0 ,y))
        {
            map[a][b]= -1; //mine go to -1
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
                    if( between (i + 1, 0 ,x)  && map[i + 1][j] == -1 ) //up
                    {
                        map[i + 1][j] = number + 1;
                    }
                    if(  between (i - 1, 0 ,x) && map[i - 1][j] == -1 ) //down
                    {
                        map[i - 1][j] = number + 1;
                    }
                    if(  between (j + 1, 0 ,y) && map[i][j + 1] == -1 ) //right
                    {
                        map[i][j + 1] = number + 1;
                    }
                    if( between (j - 1, 0 ,y) && map[i][j - 1] == -1 ) //left
                    {
                        map[i][j - 1] = number + 1;
                    }
                }
            }
        }
        number++;
   }

//TEST TABLE
 /*  for(i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
        printf("%4d",map[i][j]);
        }
    printf("\n\n");
    }
 */

    printf ("%d", map[x - 1][y - 1]-1);
    return 0;
}
