#include "game.h"

// 初始化棋盘.
void InitBoard(char board[ROWS][COLS], int rows, int cols, int set) {
    int i = 0;
    for (i = 0; i < rows; ++i) {
        int j = 0;
        for (j = 0; j < cols; ++j) {
            board[i][j] = set;
        }
    }
}

// 打印棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col) {
    int i = 0;
    printf("--------扫雷游戏--------\n");
    for (int i = 0; i <= col; ++i) {
        printf("%d%c", i, " \n"[i == col]);
    }

    for (i = 1; i <= row; ++i) {
        printf("%d ", i);
        int j = 0;
        for (j = 1; j <= col; ++j) {
            printf("%c%c", board[i][j], " \n"[j == col]);
        }
    }
}

// 布置雷
void SetMine(char mine[ROWS][COLS], int row, int col) {
    // 随机生成10雷.
    int count = EASY_COUNT;
    // 这里代码规范最好写不等于0, 让别人知道这是整型变量.
    while (count != 0) {
        int x = rand() % row + 1;
        int y = rand() % col + 1;
        // 如果能放炸弹.
        if (mine[x][y] == '0') {
            mine[x][y] = '1';
            --count;
        }
    }
}

// 排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) {
    int x = 0;
    int y = 0;
    int win = 0;
    while (win < row * col - EASY_COUNT) {
        printf("请输入1代表排查操作, 2代表标记动作>:");

        int opt = 0;
        scanf("%d", &opt);

        if (opt == 1) {
            printf("请输入排查坐标>:");
            scanf("%d%d", &x, &y);
            // 判断是否越界.
            if (x >= 1 && x <= row && y >= 1 && y <= col) {
                if (mine[x][y] == '1') {
                    printf("很遗憾, 你踩到地雷了!\n");
                    DisplayBoard(mine, row, col);
                    system("pause");
                    system("cls");
                    return;
                } else {
                    ++win;
                    show[x][y] = GetMineCount(mine, x, y) + '0';
                    system("cls");
                    DisplayBoard(show, row, col);
                }
            } else {
                printf("输入坐标非法!请重试!\n");
            }

        } else {
            printf("请输入标记雷坐标>:");
            scanf("%d%d", &x, &y);
            // 判断是否越界.
            if (x >= 1 && x <= row && y >= 1 && y <= col) {
                show[x][y] = '@';
                system("cls");
                DisplayBoard(show, row, col);
            } else {
                printf("输入坐标非法!请重试!\n");
            }
        }
    }
    printf("恭喜你!排除了所有的地雷!\n");
    system("pause");
    system("cls");
}

// 获取周围雷的数量.
int GetMineCount(char mine[ROWS][COLS], int x, int y) {
    // 周围的格子全部加上.
    return (mine[x - 1][y] + mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] + mine[x][y + 1] + mine[x - 1][y + 1] - 8 * '0');
}