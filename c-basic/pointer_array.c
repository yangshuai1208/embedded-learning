#include<stdio.h>
int main()
{
	int  arr[3] = { 1,2,3 };
	int (*p)[3] =&arr;
	//printf("%d %d %d\n", *p, p[1], *p[1]);p[1] 是指针运算（越界），用 %d 打印地址。
	// *p[1] 先越界取指针，再解引用，访问非法内存。p[1] 等价于 *(p+1)，跨过一个步长。
	printf("%d %d %d\n", *(p), (*p) + 1, (*p)[1]);/*前两项为地址，后一项为1。*/
	printf("%p %p %d\n", (void*)*(p), (void*)((*p) + 1), (*p)[1]);
	printf("%d", &*p);/*&*p 等价于 p。输出地址的十进制。*/
	int a = 1, b = 2, c = 3;
	int* arr2[3] = { &a,&b,&c };
	for (int i = 0; i < 3;i++)
	{
		printf("*arr2[%d]=%d\n", i, *arr2[i]);
	}



	return 0;
}
