#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int main() {
    char map[10][21]; // Поле 10 строк по 20 символов + '\0'
    int tail_x = 5, tail_y = 6;  // хвост змейки (будет рядом с игроком)
    int x = 5, y = 5;            // позиция игрока
    int ax, ay;                  // позиция еды
    int key;                     // для нажатой клавиши
    int score = 0;               // счет
    int old_x, old_y;            // старые координаты игрока

    srand(time(NULL));           // рандом для еды

    ax = rand() % 15 + 1;        // еда случайно
    ay = rand() % 8 + 1;

    do {
        // рамка
        sprintf(map[0],  "#################");
        for (int i = 1; i < 9; i++) {
            sprintf(map[i], "#               #");
        }
        sprintf(map[9],  "#################");

        // ставим еду
        map[ay][ax] = '*';

        // ставим хвост
        map[tail_y][tail_x] = 'o';

        // ставим игрока
        map[y][x] = '@';

        system("cls");             // очистка

        for (int i = 0; i < 10; i++) {
            printf("%s\n", map[i]);
        }
        printf("Score = %d\n", score);

        key = getch();

        old_x = x;
        old_y = y;

        // движение
        if (key == 'w' || key == 'W') y--;
        if (key == 's' || key == 'S') y++;
        if (key == 'a' || key == 'A') x--;
        if (key == 'd' || key == 'D') x++;

        // границы
        if (x < 1) x = 1;
        if (x > 15) x = 15;
        if (y < 1) y = 1;
        if (y > 8) y = 8;

        // хвост туда где была голова
        tail_x = old_x;
        tail_y = old_y;

        // проверка еды
        if (x == ax && y == ay) {
            score++;

            // новая еда
            ax = rand() % 15 + 1;
            ay = rand() % 8 + 1;
        }

    } while (key != 'e' && key != 'E');

    return 0;
}
