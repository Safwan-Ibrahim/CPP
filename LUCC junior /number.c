#include <stdio.h>

int main() {


    // 1.initialize 2. condition 3. increment or decrement
    // condition then code run then increment or decrement
    // for (int a = 1; a <= 10; a = a + 1) {
    //     printf("%d ", a);
    // }

    // i = i + 5 // i += 5;
    // 


    // 1 x 12 = 12 
    // 2 x 12 = 24

    // for (int i = 10; i <= 30; i = i + 1) {
    //     if (i % 5 == 0) {
    //         break;
    //     }
    //     printf("%d\n", i);
    // }

    // for (int i = 10; i <= 30; i++) {
    //     if (i % 5 == 0 || i % 3 == 0) {
    //         continue;
    //     }
    //     else if (i % 7 == 0) {
    //         break;
    //     }
    // }

    int a = 10;
    while(a <= 20) {
        printf("%d\n", a);
        a = a + 1;
    }

    for (int a = 10; a <= 20; a = a + 1) {
        printf("%d\n", a);
    }


    return 0;
}