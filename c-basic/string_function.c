#include<stdio.h>
int my_strlen(const char* str);
char* my_strcpy(char* dest, const char* src);
int my_strcmp(const char* s1, const char* s2);
int my_strlen(const char* str)
{
	int len = 0;
	while (*str != '\0') {
		len++;
		str++;
	}
	return len;
}
char* my_strcpy(char* dest, const  char* src)//将 source 指向的字符串（包括结尾的 '\0'）复制到 destination 指向的内存区域，并返回 destination 的指针。


{
	char* p = dest;
	while ((*p++ = *src++)  != '\0');/*复制到 '\0' 时停止，并确保 '\0' 也被复制。*/
	return dest;
}
int my_strcmp(const char* s1, const char* s2)
{
	while (*s1 && (*s1 == *s2)) {
		s1++;
		s2++;
	}
	return *(unsigned char*)s1 - *(unsigned char*)s2;/*比较两个字符串的 ASCII 值，返回差值。标准规定 strcmp 将字符视为 unsigned char 进行比较*/
}
int main()
{
	char str1[] = "hello";
	char str2[20];
	//char str3 = "bit";不能将字符串赋给单个字符。
	char str3[] = "bit";
	printf("%d\n", my_strlen(str1));
	my_strcpy(str2, str1);
	printf("%s\n", str2);
	printf("%d", my_strcmp(str1, str3));
	
	return 0;
}
