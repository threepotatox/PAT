/*
设计思路：
1.先按照题意排好序
2.printphoto(int m, student *p) 函数利用指针 p 输出每一排的 m 个人
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student{
    char name[9];
    int height;
}student;

int printphoto(int m, student *p);
int comp(const void *a, const void *b);

int main()
{
    int n, k;
    student students[10000] = {0}, *p = students;
    int i;

    scanf("%d %d", &n, &k);
    for(i = 0; i < n; i++)
        scanf("%s %d", students[i].name, &students[i].height);
    
    qsort(students, n, sizeof(students[0]), comp);

    printphoto(n - n / k * (k - 1), p + n / k * (k - 1));
    p = p + n / k * (k - 2); 
    while(p >= students){
        printphoto(n / k, p);
        p -= n / k;
    }

    return 0;
}

int printphoto(int m, student *p)
{
    int i;
    for(i = m % 2; i < m; i += 2)
        printf("%s ", p[i].name);
    for(i = m - 1; i >= 0; i -= 2)
        printf("%s%c", p[i].name, i - 2 < 0 ? '\n' : ' ');
    return 0;
}

int comp(const void *s1, const void *s2)
{
    student *a = (student *)s1;
    student *b = (student *)s2;
    if(a->height != b->height)
        return a->height - b->height;
    return strcmp(b->name, a->name);
}
