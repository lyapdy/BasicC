#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char playingfield[14][21];
int i, asterisk = 0, speed;
float max_speed=6;
char key;
int ox, oy;
int x = 5, y = 11;
int ax = 8, ay = 3;

struct snakestail
{
    int old_x, old_y;
} snakestail_old[216];

void snakemovement(void);
char lvl(int asterisk);

int main()
{
    initscr();

    do
    {

        strcpy(playingfield[0], "####################");
        for (i = 1; i < 13; i++)
            strcpy(playingfield[i], "#                  #");
        strcpy(playingfield[13], "####################");

        if (x > ox)
            playingfield[y][x] = '>';
        else if (x < ox)
            playingfield[y][x] = '<';
        else if (y < oy)
            playingfield[y][x] = '^';
        else if (y > oy)
            playingfield[y][x] = 'v';
        else
            playingfield[y][x] = '@';

        if (asterisk > 0)
        {
            for (i = 0; i < asterisk; i++)
                playingfield[snakestail_old[i].old_y][snakestail_old[i].old_x] = '#';
        }

        playingfield[ay][ax] = '*';

        srand(time(NULL));

        move(0, 0);

        printw("Asterisk: %5d\n", asterisk);
        printw("Level:        ");
        lvl(asterisk);

        for (i = 0; i < 14; i++)
            printw("%s\n", playingfield[i]);
        refresh();

        if ((asterisk >= 0) && (asterisk < 2))
            speed = 10;
        else
            speed = 10 / asterisk;

        curs_set(0);
        noecho();

        halfdelay(speed);

        key = getch();

        ox = x;
        oy = y;

        switch (key)
        {
        case 'w':
            y--;
            break;
        case 's':
            y++;
            break;
        case 'a':
            x--;
            break;
        case 'd':
            x++;
            break;
        case ERR:
            snakemovement();
        }
        if (playingfield[y][x] == '#')
        {
            x = ox;
            y = oy;
        }

        if (playingfield[y][x] != '#')
        {
            for (i = asterisk; i >= 0; i--)
            {
                snakestail_old[i + 1].old_x = snakestail_old[i].old_x;
                snakestail_old[i + 1].old_y = snakestail_old[i].old_y;
            }
            snakestail_old[0].old_x = ox;
            snakestail_old[0].old_y = oy;
        }

        if (playingfield[y][x] == '#')
        {
            cbreak();
            move(9, 5);
            printw("GAME OVER");
            refresh();
            getch();
            break;
        }

        if ((x == ax) && (y == ay))
        {
            ax = rand() % (18 - 1) + 1;
            ay = rand() % (12 - 1) + 1;
            asterisk++;
        }

        if (((ax == x) && (y == ay)) || (playingfield[ay][ax] == '#') || ((ax == ox) && (ay == oy)))
        {
            ax = rand() % (18 - 1) + 1;
            ay = rand() % (12 - 1) + 1;
        }
    } while (key != 'q');

    endwin();
    return 0;
}

void snakemovement(void)
{
    if (playingfield[y][x] == '^')
        y--;
    else if (playingfield[y][x] == 'v')
        y++;
    else if (playingfield[y][x] == '<')
        x--;
    else if (playingfield[y][x] == '>')
        x++;
}

char lvl(int asterisk)
{

    if ((asterisk >= 0) && (asterisk < 2))
        printw("(x1.00)\n");
    else if ((asterisk >= 2) && (asterisk < 7))
        printw("(x%.2f)\n", (float)asterisk);
    else if (asterisk >= 7)
        printw("(x%.2f)\n", max_speed);
}