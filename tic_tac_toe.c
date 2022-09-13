#include <stdio.h>

void display(char m[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%c ", m[i][j]);
        }
        printf("\n");
    }
}

int vldpos(char m[3][3], char i, char j)
{
    if (m[i][j] == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int success(char m[3][3], int r, int c)
{

    if ((m[r][0] == m[r][1]) && (m[r][1] == m[r][2]))
    {
        return 1;
    }
    if ((m[0][c] == m[1][c]) && (m[1][c] == m[2][c]))
    {
        return 1;
    }
    if (r == c || r + c == 2)
    {
        if ((m[0][2] == m[1][1]) && (m[1][1] == m[2][0]))
        {
            return 1;
        }
        if ((m[0][0] == m[1][1]) && (m[1][1] == m[2][2]))
        {
            return 1;
        }
    }
    return 0;
}

void main()
{
    int i = 0, pos[2], plyr;
    char key, xo[3][3] = {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};

    /* ODD i --> o will play
       EVEN i --> x will play
       79-->O
       88-->X */

    while (i < 9)
    {
        key = (char)((i % 2) * 79 + (((i + 1) % 2) * 88));
        plyr = (i % 2) * 2 + ((i + 1) % 2) * 1;

        printf("PLAYER %d:Enter the postion of %c:\n", plyr, key);
        scanf("%d\t%d", pos, pos + 1);

        if (vldpos(xo, pos[0] - 1, pos[1] - 1))
        {
            xo[pos[0] - 1][pos[1] - 1] = key;
            printf("\n");
            display(xo);
            i += 1;
        }

        else
        {
            printf("Enter valid position! \n");
            continue;
        }
        if (i >= 5)
        {
            if (success(xo, pos[0] - 1, pos[1] - 1) == 1)
            {
                printf("Player %d won the game", plyr);
                break;
            }

            else if (i == 9)
            {
                printf("Game TIED!");
            }
        }
    }
}
