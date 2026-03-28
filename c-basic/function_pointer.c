#include<stdio.h>
int add(int a, int b) {
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}
int calculate(int x, int y, int*( op)(int, int))//op是返回int*的函数。
{
	return op(x, y);
}
int main()
{
	int (*func_ptr)(int, int) = add;//定义函数指针，指向add。函数指针的声明语法：返回类型 (*指针名)(参数列表)。
	printf("%d\n", func_ptr(10, 5));
	func_ptr = sub;//将函数指针指向sub。
	printf("%d\n", func_ptr(10, 5));
	printf("%d\n", calculate(10, 5, add));
	return 0;
}//函数指针和回调函数区别：在于调用者，前者由 main 直接调用，后者将调用权交给了 calculate 函数。


