/*
设计思路：
1.在输入过程中将不录取数据丢弃，并返回录取人数
2.利用 qsort 函数进行快速排序，防止超时
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int d;
    int c;
    int sum;
    int r;
}Student;

int inputstudent(int n, int low, int high, Student s[]); /*input 并返回合格人数*/
int compstudent(const void *a, const void *b); /*为 qsort 提供比较函数*/
int cmpstudent(int n, Student s[]); /*此冒泡排序超时，弃用*/
int outputstudent(int m, Student s[]); /*output*/

int main()
{
    int n, low, high, m;
    Student students[100000];

    scanf("%d %d %d",&n, &low, &high);
    m = inputstudent(n, low, high, students);
    qsort(students, m, sizeof(students[0]), compstudent);
    outputstudent(m, students);

    return 0;
}

int inputstudent(int n, int low, int high, Student s[])
{
    int i,m=0;
    Student temp;
    for(i = 0; i < n-m; i++){
        scanf("%d %d %d", &s[i].id, &s[i].d, &s[i].c);
        s[i].sum = s[i].d + s[i].c;
        if(s[i].d < low || s[i].c < low){
            m++;
            i--;
        }
        else if(s[i].d >= high && s[i].c >= high){
            s[i].r = 4;
        }
        else if(s[i].d >= high){
            s[i].r = 3;
        }
        else if(s[i].d >= s[i].c){
            s[i].r = 2;
        }
        else{
            s[i].r =1;
        }
    }
    return n-m;
}

int compstudent(const void *s1, const void *s2)
{
    Student *a = (Student *)s1;
    Student *b = (Student *)s2;
    if(a->r != b->r)          return a->r - b->r;
    else if(a->sum != b->sum) return a->sum - b->sum;
    else if(a->d != b->d)     return a->d - b->d;
    else if(a->id != b->id)   return b->id - a->id;
    else                      return 0;
}

int outputstudent(int m, Student s[])
{
        int i;
        printf("%d\n", m);
        for(i = m-1; i >= 0; i--){
            printf("%d %d %d\n", s[i].id, s[i].d, s[i].c);
        }
        return 0;
}

int cmpstudent(int n, Student s[])
{
    int i, j;
    Student temp;
    for(i = 0; i < n; i++){
        for(j = 0; j < n-i-1; j++){
            if(s[j].r < s[j+1].r){
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
            else if(s[j].r == s[j+1].r && s[j].sum < s[j+1].sum){
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
            else if(s[j].r == s[j+1].r && s[j].sum == s[j+1].sum && s[j].d < s[j+1].d){
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
            else if(s[j].r == s[j+1].r && s[j].sum == s[j+1].sum &&(s[j].d == s[j+1].d && s[j].id > s[j+1].id)){
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;                                                              }

        }
    }
    return 0;
}
