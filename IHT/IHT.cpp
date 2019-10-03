// IHT.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

struct Student
{
	char id[20];
	int age;
	char regin[20];
	char class_num[10];
	char health[20];
}data[12] = { "8116005131",27,"guangzhou","14248","HIV","8116005132",28,"qingyuan","14207","HIV","8116005133",26,"guangzhou","14246","cancer","8116005134",25,"qingyuan","14249","cancer","8116005135",41,"qingdao","13053","hepatitis","8116005136",48,"jinan","13074","phthisis","8116005137",45,"qingdao","13064","asthma","8116005138",42,"qingdao","13062","heart_disease","8116005139",33,"guangzhou","14242","flu","3116005110",37,"qingyuan","14204","flu","8116005111",36,"qingyuan","14205","flu","8116005112",35,"guangzhou","14248","indigestion" };
//guangdong-guangzhou/qingyuan shandong-jinan/qingdao
int main()
{

	char user[17];
	char pwd[21];
	int count = 0;

	do
	{
		if (count > 0)
			puts("Not logged in\n");
		printf("username = ");
		gets_s(user,17);
		printf("password = ");
		gets_s(pwd,21);
		count++;

	} while ((strcmp(user, USER)) || (strcmp(pwd, PWD)));

	puts("Successful user login!");
	int n = 0;
	printf("进行n-匿名化，n取：");
	scanf_s("%d", &n);

	return 0;
    //std::cout << "Hello World!\n"; 
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
