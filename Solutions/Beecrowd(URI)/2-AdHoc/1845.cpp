#include <bits/stdc++.h>

using namespace std;

char Ajeita(char Ch)
{
    if  (Ch == 'b' || Ch == 'j' ||Ch == 'p' || Ch == 's' || Ch == 'v' || Ch == 'x' || Ch == 'z')
        return 'f';
    if  (Ch == 'B' || Ch == 'J' ||Ch == 'P' || Ch == 'S' || Ch == 'V' || Ch == 'X' || Ch == 'Z')
        return 'F';
    return Ch;
}

int main()
{
    char Last = 'a', Let;
    while(scanf("%c", &Let) != EOF)
    {
        Let = Ajeita(Let);
        if  (!((Last == 'f' || Last == 'F') && (Let == 'f' || Let == 'F')))
        {
            printf("%c", Let);
        }
        Last = Let;
    }
}