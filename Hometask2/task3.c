#include </usr/include/conio.h>
#include <stdio.h>

void main()
{
    char tmp;
    do
    {
        tmp = getch();
        switch (tmp)
        {
        case 'H':
        {
            printf("up\n");
            break;
        }
        case 'K':
        {
            printf("left\n");
            break;
        }
        case 'P':
        {
            printf("down\n");
            break;
        }
        case 'M':
        {
            printf("right\n");
            break;
        }
        }
    } while (tmp != 27);
}