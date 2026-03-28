#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
struct Student {
	int id;
	char name[20];
	float score;
};//结构体末尾要加分号
int main()
{
	struct Student stu1 = { 11,"zhangsan",99 };
	printf("%d %s %.2f\n", stu1.id, stu1.name, stu1.score);
	struct Student* p = &stu1;
	p->id = 22;
	printf("%d", p->id);//结构体指针
	struct Student stu2;
	stu2.id = 33;
	strcpy(stu2.name, "lisi");
	stu2.score = 88;
	printf("%d %s %.2f\n", stu2.id, stu2.name, stu2.score);
	return 0;
}
