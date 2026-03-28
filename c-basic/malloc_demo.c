#include<stdio.h>
#include<stdlib.h>
int main()
{
	int* p = (int*)malloc(sizeof(int));
	if (p ==NULL) {
		printf("内存分配失败");
		return 1;
	}
	*p = 1;
	printf("%d\n", *p);
	free(p);
	int* leak = (int*)malloc(sizeof(int));
	*leak = 2;
	printf("%d", *leak);
	return 0;

}/*第一次动态分配后正确使用并释放了内存。

第二次动态分配未调用 free，程序结束时操作系统会回收该进程的所有内存资源，仍能正常输出结果。*/
//内存泄漏的后果
//
//程序占用的内存不断增长，最终耗尽系统内存，导致运行缓慢、崩溃或被操作系统终止。
//
//在短时间运行的小程序中可能看不出问题，但在服务器、嵌入式等长期运行场景下会累积成严重故障。

属于资源管理错误。


