#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EASY_COUNT 10
#define ROW 9
#define COL 9
#define ROWS ROW + 2
#define COLS COL + 2

// 初始化棋盘.
void InitBoard(char board[ROWS][COLS], int row, int col, int set);

// 打印棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col);

// 布置雷
void SetMine(char board[ROWS][COLS], int row, int col);

// 排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

// 获取周围雷的数量.
int GetMineCount(char mine[ROWS][COLS], int x, int y);
