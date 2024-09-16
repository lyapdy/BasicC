#include <stdio.h>
//#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <conio.h>

/*int getch (void)
{
        int ch;
        struct termios oldt, newt;

        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON|ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

        return ch;
}*/

int main()
{
    char ch=0;
    printf("Press Q to quit\n");
    do
    {
        ch = getch();

        switch(ch)
        {
            case 'W':
            case 'w':
                printf("W was pressed \n");
                break;
            case 'A':
            case 'a':
                printf("A was pressed \n");
                break;
            case 's':
            case 'S':
                printf("S was pressed \n");
                break;
            case 'D':
            case 'd':
                printf("D was pressed \n");
                break;

        }

    }while (ch != 'Q' && ch!='q');
    return 0;
}
