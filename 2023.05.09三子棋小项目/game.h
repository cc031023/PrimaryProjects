#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include <Windows.h>
#include <stdio.h>
#include <time.h>

#define ROW 3
#define COL 3

// 初始化棋盘.
void InitBoard(char board[ROW][COL], int row, int col);
// 打印棋盘.
void DisplayBoard(char board[ROW][COL], int row, int col);
// 玩家下棋.
void PlayerMove(char board[ROW][COL], int row, int col);
// 电脑下棋.
void ComputerMove(char board[ROW][COL], int row, int col);

// 判断输赢('*'玩家, '#'电脑)
int IsWin(char board[ROW][COL], int row, int col);
// 补充1: 判断落子是否合法.
int CheckMove(char board[ROW][COL], int row, int col, int r, int l);

// 补充2: 宣布胜利.
void WhoWin(char winner);

// 补充3: 判断这个位置的棋子能否赢.
int CheckWin(char board[ROW][COL], int row, int col, int r, int l);