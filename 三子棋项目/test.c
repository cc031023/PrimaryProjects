#include "game.h"
// 执行游戏的主体.
void menu() {
    printf("*****************************\n");
    printf("********  1. play   *********\n");
    printf("********  0. exit   *********\n");
    printf("*****************************\n");
}

void game() {
    char board[ROW][COL] = {0};
    // 初始化.
    InitBoard(board, ROW, COL);
    // 显示棋盘.
    DisplayBoard(board, ROW, COL);
    int flag = 0;
    while (flag == 0) {
        // 玩家先走.
        PlayerMove(board, ROW, COL);
        // 走完显示棋盘.
        DisplayBoard(board, ROW, COL);
        // 这里优化了IsWin让其直接判断输赢情况与否.
        flag = IsWin(board, ROW, COL);  // 胜负若分则在函数中打印结果!
        if (flag == 1) {                // 已经分胜负了就退出.
            return;
        }
        // 电脑走.
        ComputerMove(board, ROW, COL);
        // 显示棋盘.
        DisplayBoard(board, ROW, COL);
        // 这里不用判断是否退出, 因为下次循环flag为变量可以直接判断.
        flag = IsWin(board, ROW, COL);
    }
}

int main() {
    int input = 0;
    srand((unsigned)time(NULL));

    do {
        menu();

        printf("请选择:>");
        scanf("%d", &input);

        switch (input) {
            case 0:
                printf("退出游戏成功!\n");
                break;
            case 1:
                printf("正在进入游戏!加载中...\n");
                Sleep(1000);
                game();
                break;
            default:
                printf("输入有误!请重新输入!\n");
                break;
        }
    } while (input);
    return 0;
}
