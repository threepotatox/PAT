/*
 * 设计思路：
 * 此题难点在于大数的相加。思路是让数组存数字时，个位数在数组低位 a[0] 上，此时两数相加可直接进位，省去进位移动数组的麻烦
 * 1.读取初始值时特殊处理一次即可
 * 2.利用自定义函数逆转数组，输出数组即可
 */

#include <stdio.h>
#include <string.h>

int reverse_ab(char a[], char b[]);
int add_ab(char a[], char b[]);
int is_palindrome(char a[]);
int print_ab(char a[], char b[]);
int print_str(char a[]);

int main()
{
	char a[1011] = {0}, b[1011] = {0};
	int i = 0;

	scanf("%s", b);
	if (!is_palindrome(b)) {
		reverse_ab(b, a);
		print_ab(a, b);
		for (i = 1; i < 10 && !is_palindrome(a); i++) {
			reverse_ab(a, b);
			print_ab(a, b);
		}
	}
	
	if (i == 10) {
		printf("Not found in 10 iterations.");
	} else {
		i > 0 ? print_str(a) : print_str(b);
		printf(" is a palindromic number.");
	}

	return 0;
}

int reverse_ab(char a[], char b[])
{
	int len = strlen(a);
	int i;
	for (i = 0; i < len; i++)
		b[len - i - 1] = a[i];
	return 0;
}

int add_ab(char a[], char b[])
{
	int len = strlen(a);
	int i, sum, carry = 0;
	for (i = 0; i < len; i++) {
		sum = a[i] - '0' + b[i] - '0' + carry;
		a[i] = sum % 10 + '0';
		carry = sum / 10;
	}
	if (carry)
		a[i] = carry + '0';
	return 0;
}

int is_palindrome(char a[])
{
	int len = strlen(a);
	int i;
	for (i = 0; i < len / 2; i++)
		if (a[i] != a[len - i - 1])
			return 0;
	return 1;
}

int print_ab(char a[], char b[])
{
	print_str(a);
	printf(" + ");
	print_str(b);
	printf(" = ");

	add_ab(a, b);

	print_str(a);
	printf("\n");
	return 0;
}

int print_str(char a[])
{
	int i = strlen(a) - 1;
	for (; i >= 0; i--)
		printf("%c", a[i]);
	return 0;
}
