/*
 * 设计思路：
 * * 把时间转化为以秒为单位，比较输出
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
	int n, intime = 86400, time, outtime = -1;
	char inname[16], name[16], outname[16];
	int hh, mm, ss;

	scanf("%d", &n);
	while (n--) {
		scanf("%s %d:%d:%d", name, &hh, &mm, &ss);
		time = (hh * 60 + mm) * 60 + ss;
		if (time < intime) {
			intime = time;
			strcpy(inname, name);
		}
		
		scanf("%d:%d:%d", &hh, &mm, &ss);
		time = (hh * 60 + mm) * 60 + ss;
		if (time > outtime) {
			outtime = time;
			strcpy(outname, name);
		}
	}

	printf("%s %s", inname, outname);

	return 0;
}
