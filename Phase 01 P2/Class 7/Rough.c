#include <stdio.h>

#define p printf
#define d "%d"
#define c "%c"
#define s scanf

int main()
{
    int n;
    s(d,&n);

    switch(n) {
        case 2: 
            p("got\n");
            break;
        case 8:
            p("got\n");
            break;
        default :
            p("didn't get\n");
    }

    return 0;
}