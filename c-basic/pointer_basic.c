#include<stdio.h>
int main()
{
	int  a = 0;
	int* p = &a;
	int b = *p + 1;
	//printf("%d  %d", p, b);P输出为地址。
	//printf("%d %d", &p, b);&p 是变量 p 在内存中的地址。
	printf("%d %d\n", *p, b);//指针运算
	int c[3] = { 1,2,3 };
	int* q = c;
	//int d = c + 1/会报错，c是数组名，在大多数表达式中指向数组首元素地址。c=&[0]。
	int e = q + 1;//输出结果为地址，q是c[0]的地址，q+1是c[1]的地址。不是地址加1。
	int f = *q + 1;//输出结果为2，*q是c[0]的值，即1。
	int g = *c + 1;//输出结果为2，*c是c[0]的值，即1。
	printf("%d %d %d\n", e, f, g);
	for (int i = 0;i <3;i++)
	{
		printf("%d %d %d %d\n", i, c[i], *(c + i), (c + i));//c+i不是地址数值加 1，而是加 sizeof(int）字节。
	}


	return 0;
}
