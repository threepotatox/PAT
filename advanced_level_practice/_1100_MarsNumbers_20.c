/*
设计思路：
输入数据的处理利用库函数简化，分类输出即可
*/

#include <stdio.h>
#include <string.h>

int printmars(int number, char *units[], char *tens[]);
int printearth(char *num, char *units[], char *tens[]);
int marsearth(char *s, char *units[], char *tens[]);

int main()
{
    char *units[] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    char *tens[] ={"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    int n, number;
    char num[11];
    int i;
    
    fgets(num, 11, stdin);
    sscanf(num, "%d", &n);
    for(i = 0; i < n; i++){
        fgets(num, 11, stdin);
        if(isdigit(num[0])){
            sscanf(num, "%d", &number);
            printmars(number, units, tens);
        }
        else{ 
            printearth(num, units, tens);
        }
    }
    
    return 0;
}

int printmars(int m, char *units[], char *tens[])
{
    if(m / 13 && m % 13){
        printf("%s %s\n", tens[m / 13 - 1], units[m % 13]);
    }
    if(m / 13 && m % 13 == 0){
        printf("%s\n", tens[m / 13 - 1]);
    }
    if(m / 13 == 0){
        printf("%s\n", units[m % 13]);
    }
    return 0;
}
int printearth(char *num, char *units[], char *tens[])
{
    int m;
    m = marsearth(strtok(num, " \n"), units, tens);
    m += marsearth(strtok(NULL, " \n"), units, tens);
    printf("%d\n", m);
    return 0;
}

int marsearth(char *s, char *units[], char *tens[])
{
    int i;
    if(s){
        for(i = 0; i < 13; i++){
            if(strcmp(s, units[i]) == 0){
                return i;
            }
        }
        for(i = 1; i < 13; i++){
            if(strcmp(s, tens[i -1]) == 0){
                return i * 13;
            }
        }
    }
}
