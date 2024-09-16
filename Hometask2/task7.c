#include <stdio.h>


int main() {
    while (1) {
        if (kbhit()) {
            char ch = getch();
            printf("yes");
        }
    }
    return 0;
}