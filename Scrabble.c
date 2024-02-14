//头文件
#include <stdio.h>
#include "cs50.h"
#include <string.h>
#include <stdlib.h>
//函数声明
int conpute_score(char * word);

//得分对照
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    //获取玩家输入
    char * word1 = get_string("Player1: ");
    char * word2 = get_string("Player2: ");

    //计算得分
    int score1 = conpute_score(word1);
    int score2 = conpute_score(word2);

    //输出得分
    if(score1 > score2)
    {
        printf("Winner is Player1.\n");
    }
    else if(score1 < score2)
    {
        printf("Winner is Player2.\n");
    }
    else
    {
        printf("Even.\n");
    }
    free(word1);
    free(word2);
}

//计算玩家得分
int conpute_score(char * word)
{
    int score = 0;
    for(int i = 0, n = strlen(word); i < n; i++)
    {
        char c = toupper(word[i]);
        if(c == 'A' || c == 'E' || c == 'I' || c == 'L' || c == 'N' || c == 'O' || c == 'S' || c == 'T' || c == 'U' || c == 'R')
        {
            score += 1;
        }
        else if(c == 'D' || c == 'G')
        {
            score += 2;
        }
        else if(c == 'B' || c == 'C' || c == 'M' || c == 'P')
        {
            score += 3;
        }
        else if(c == 'F' || c == 'H' || c == 'V' || c == 'W' || c == 'Y')
        {
            score += 4;
        }
        else if(c == 'K')
        {
            score += 5;
        }
        else if(c == 'J' || c == 'X')
        {
            score += 8;
        }
        else if(c == 'Q' || c == 'Z')
        {
            score += 10;
        }
        else
        {
            score += 0;
        }
    }
    return score;
}

