#include "game.h"  // 自定义的头文件.

// 初始化棋盘.
void InitBoard(char board[ROW][COL], int row, int col) {
    int i = 0;
    for (i = 0; i < row; ++i) {
        int j = 0;
        for (j = 0; j < col; ++j) {
            board[i][j] = ' ';
        }
    }
}

// 打印棋盘.
void DisplayBoard(char board[ROW][COL], int row, int col) {
    int i = 0;
    for (i = 0; i < row; ++i) {
        int j = 0;
        for (j = 0; j < col; ++j) {
            printf(" %c %c", board[i][j], "|\n"[j == col - 1]);
        }  // j如果等于col - 1.
           // 则表达式返回1访问这个字符串下标为1的换行,否则就是'|'.
        if (i != row - 1) {
            for (j = 0; j < col; ++j) {
                printf("%s%c", "---", "|\n"[j == col - 1]);
            }
        }
    }
}
// 玩家下棋.
void PlayerMove(char board[ROW][COL], int row, int col) {
    int flag = 1;
    while (flag != 0) {
        printf("现在是你的回合!\n");
        printf("请输入你的落子坐标(1~9):>");
        int vis = 0;  // 棋子坐标的和.
        scanf("%d",
              &vis);  // 为了方便设置了1 ~ 9,后面-1再/3和%3是为了计算棋子坐标.
        int r = (vis - 1) / row;  // 第几行
        int l = (vis - 1) % col;  // 第几列
        if (CheckMove(board, ROW, COL, r, l) == 0) {
            // 非法.
            printf("输入非法!请重新输入!\n");
        } else {
            board[r][l] = '*';  // 赋值代表下子.
            flag = 0;           // 下次循环马上跳出去.
        }
    }
}
// 电脑下棋.
void ComputerMove(char board[ROW][COL], int row, int col) {
    printf("现在是电脑的回合!\n");
    Sleep(500);
    int x = rand() % row;
    int y = rand() % col;
    while (CheckMove(board, ROW, COL, x, y) == 0) {
        // 不符合就一直循环.
        x = rand() % row;
        y = rand() % col;
    }
    board[x][y] = '#';  // 电脑落子.
}

// 判断输赢('*'玩家, '#'电脑, 'Q'平局, 'C'继续)
int IsWin(char board[ROW][COL], int row, int col) {
    int i = 0;
    int flag = 0;  // 如果棋盘满了就是1,否则是0.
    for (i = 0; i < row; ++i) {
        int j = 0;
        for (j = 0; j < col; ++j) {
            if (board[i][j] != ' ') {
                if (CheckWin(board, row, col, i, j) == 1) {
                    // 宣布胜利.
                    WhoWin(board[i][j]);
                    return 1;
                }
            } else {
                flag = 1;  // 标记棋盘没满.
            }
        }
    }
    if (flag == 1) {
        // 棋盘没满而且没人赢.
        return 0;
    } else {
        WhoWin(' ');  // 平局.
        return 1;
    }
}

// 补充1: 判断落子是否合法.
int CheckMove(char board[ROW][COL], int row, int col, int r, int l) {
    if (r < 0 || r >= row || l < 0 || l >= col)
        return 0;
    else if (board[r][l] != ' ')
        return 0;
    else
        return 1;
}

// 补充2: 判断这个位置的棋子能否赢.
int CheckWin(char board[ROW][COL], int row, int col, int r, int l) {
    int i = 0;
    char winner = board[r][l];  // 决定赢的那个棋子的属性.
    for (i = 0; i < 3; ++i) {
        int j = 0;
        // 同一行.
        for (j = 0; j < col; ++j) {
            if (board[r][j] != winner)
                break;
        }
        if (j == col)  // 可以赢了跳出返回1.
            return 1;
        // 同一列.
        for (j = 0; j < row; ++j) {
            if (board[j][l] != winner)
                break;
        }
        if (j == col)  // 可以赢了跳出返回1.
            return 1;
        // 从左上到右下斜对角.
        int k = 0;
        for (j = 0, k = 0; j < row, k < col; ++j, ++k) {
            if (board[j][k] != winner)
                break;
        }
        if (j == row)  // 可以赢了跳出返回1.
            return 1;
        // 从右上到左下斜对角.
        for (j = 0, k = col - 1; j < row, k >= 0; ++j, --k) {
            if (board[j][k] != winner)
                break;
        }
        if (j == row)  // 可以赢了跳出返回1.
            return 1;
    }
    return 0;
}

// 补充3: 宣布胜利.
void WhoWin(char winner) {
    if (winner == ' ') {
        printf("平局!\n");
        system("pause");
        system("cls");
    } else if (winner == '*') {
        printf("玩家获胜!\n");
        system("pause");
        system("cls");
    } else {
        printf("电脑获胜!\n");
        system("pause");
        system("cls");
    }
}