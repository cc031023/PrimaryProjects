#include "game.h"

void menu() {
    printf("*********************************\n");
    printf("*********************************\n");
    printf("************ 1. Play ************\n");
    printf("************ 0. Exit ************\n");
    printf("*********************************\n");
    printf("*********************************\n");
}

void game() {
    char show[ROWS][COLS]; // 存放摆好的地雷.
    char mine[ROWS][COLS]; // 存排查的雷的数量.
    // 初始化棋盘.
    // show为全'*'.
    InitBoard(show, ROWS, COLS, '*');
    // mine为全'0'.
    InitBoard(mine, ROWS, COLS, '0');
    // 打印棋盘.
    DisplayBoard(show, ROW, COL);
    // 随机布置雷.
    SetMine(mine, ROW, COL);
    // 排查雷.
    FindMine(mine, show, ROW, COL);
}

int main() {
    int input = 0;
    srand((unsigned int)time(NULL));
    do {
        menu();
        printf("请输入数字确认是否游戏>:");
        scanf("%d", &input);
        switch (input) {
            case 1:
                printf("进入游戏加载中...\n");
                Sleep(1000);
                game();
                break;
            case 0:
                printf("退出游戏成功!\n");
                system("pause");
                break;
            default:
                printf("输入非法!请重新输入!\n");
                break;
        }
    } while (input);

    return 0;
}