﻿// IHT.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
struct Student
{
	char id[20];//标识符：学号
	char age[10];//准标识符：年龄
	char region[20];//准标识符：地区
	char class_num[10];//准标识符：班级
	char health[20];//敏感信息：健康状况
	//不知道为什么重载==后语法没有报错 但是读取this.准表示符报错ctrl+k+c,ctrl+k+u//知道原因了是循环条件写错了写了flag=1
	bool operator==(const Student& rhs)//操作运算符重载：==表示Student中的准标识符相等
	{
		return (strcmp(age, rhs.age) == 0) && (strcmp(region, rhs.region) == 0) && (strcmp(class_num, rhs.class_num) == 0);
	}
}data[12] = { "8116005131","27","guangzhou","14248","HIV","8116005132","28","qingyuan","14207","HIV","8116005133","26","guangzhou","14246","cancer","8116005134","25","qingyuan","14249","cancer","8116005135","41","jinan","13053","hepatitis","8116005136","48","qingdao","13074","phthisis","8116005137","45","yantai","13064","asthma","8116005138","42","yantai","13062","heart_disease","8116005139","33","guangzhou","14242","flu","3116005110","37","qingyuan","14204","flu","8116005111","36","qingyuan","14205","flu","8116005112","35","guangzhou","14248","indigestion" };
//guangdong-guangzhou/qingyuan shandong-jinan/qingdao/yantai
//bool structcmp(Student data1,Student data2) 
//{
//	if ((strcmp(data1.age, data2.age) == 0) && (strcmp(data1.region, data2.region) == 0) && (strcmp(data1.class_num, data2.class_num) == 0))return true;
//	else
//	{
//		return false;
//	}
//}
void printdata() //输出数据
{
	printf("     学号             年龄             籍贯           班级            健康状况     \n");
	for (int i = 0; i < 12; i++)
	{
		printf("     %10s%10s%20s   %10s   %20s\n", data[i].id, data[i].age, data[i].region, data[i].class_num, data[i].health);
	}
}
bool check(Student data[12],int k)
{
	int flag = 1;//flag标志第i条数据是否满足k匿名检测，1表示真：满足，0表示假：不满足
	for (int i = 0; i < 12&&flag==1; i++)
	{
		for (int t = 0,j=1; t < 12; t++)
		{
			if (t==i)
			{
				continue;
			}
			if (data[i]==data[t])
			{
				j++;
			}
			if (j==k)
			{
				flag = 1;
				break;
			}
			flag = 0;
		}
	}
	return flag;
}
int datafly(Student data[12],int k)
{
	//对每个准标识符的属性的取值个数进行统计
	int a[12];//age中不同的标识符
	a[0] = 0;//先存放一个
	int r[12];//regin中不同的标识符的下标
	r[0] = 0;//先放一个
	int c[12];//class_num中不同的标识符的下标
	c[0] = 0;//先放一个
	//int h[12];//health中不同的标识符的下标
	//h[0] = 0;//先放一个//
	int n[3] = {1, 1, 1};//表示五个数值各自的当前长度,即为统计值
	for (int i = 1; i < 12; i++)//遍历2-12，11组数据
	{
		//再统计regin的统计值
		for (int j = 0; j < n[0]; j++)//将data[i].regin于r[12]里头所有的下标对应的data[r[j]]对比,若重复break。否则添加到r[n[1]],n[1]++;
		{
			if (strcmp(data[i].age, data[a[j]].age) == 0)
			{
				break;
			}
			else if ((j + 1) == n[0])
			{
				a[n[0]] = i;
				n[0]++;
				break;
			}
		}

	}
	printf("age的统计值为：%d\n", n[0]);
	for (int i = 1; i < 12; i++)//遍历2-12，11组数据
	{
		//再统计regin的统计值
		for (int j = 0; j < n[1]; j++)//将data[i].regin于r[12]里头所有的下标对应的data[r[j]]对比,若重复break。否则添加到r[n[1]],n[1]++;
		{
			if (strcmp(data[i].region,data[r[j]].region)==0)//data[i].regin == data[r[j]].regin//)
			{
				break;
			}
			else if ((j + 1) == n[1])
			{
				r[n[1]] = i;
				n[1]++;
				break;
			}
		}

	}
	printf("region的统计值为：%d\n", n[1]);
	for (int i = 1; i < 12; i++)//遍历2-12，11组数据
	{
		//再统计class_num的统计值
		for (int j = 0; j < n[2]; j++)//将data[i].regin于r[12]里头所有的下标对应的data[r[j]]对比,若重复break。否则添加到r[n[1]],n[1]++;
		{
			if (strcmp(data[i].class_num, data[c[j]].class_num)==0)
			{
				break;
			}
			else if ((j + 1) == n[2])
			{
				c[n[2]] = i;
				n[2]++;
				break;
			}
		}

	}
	printf("class_num的统计值为：%d\n", n[2]);
	//for (int i = 1; i < 12; i++)//遍历2-12，11组数据
	//{
	//	//再统计health的统计值
	//	for (int j = 0; j < n[3]; j++)//将data[i].regin于r[12]里头所有的下标对应的data[r[j]]对比,若重复break。否则添加到r[n[1]],n[1]++;
	//	{
	//		if (strcmp(data[i].health, data[h[j]].health)==0)
	//		{
	//			break;
	//		}
	//		else if ((j + 1) == n[3])
	//		{
	//			h[n[3]] = i;
	//			n[3]++;
	//			break;
	//		}
	//	}

	//}
	//printf("health的统计值为：%d\n", n[3]);
	//取出统计值最大的准标识符进行一个层级的泛化。
	int max = 0;
	int temp = 0;
	for (int i = 0 ; i < 3; i++)
	{
		if (n[i] > temp)
		{
			temp = n[i];
			max = i;
		}
	}
	printf("最大的统计值为：%d\n",temp);
	switch (max)
	{
	case 0:
		printf("对应的最大表示符为：age\n");
		if ((strcmp(data[0].age, "<30") != 0) || (strcmp(data[0].age, ">40") != 0) || (strcmp(data[0].age, "3*") != 0))
		{
			for (int i = 0; i < 12; i++)
			{
				if (strcmp(data[i].age, "30") < 0)
				{
					strcpy_s(data[i].age, 10, "<30");
				}
				else if (strcmp(data[i].age, "40") > 0)
				{
					strcpy_s(data[i].age, 10, ">40");
				}
				else
				{
					strcpy_s(data[i].age, 10, "3*");
				}
			}
		}
		else
		{
			for (int i = 0; i < 12; i++)
			{
				strcpy_s(data[i].age, 10, "*");
			}
		}
		break;
	case 1:
		printf("对应的最大表示符为：region\n");
		if ((strcmp(data[0].region, "guangdong") != 0) || (strcmp(data[0].class_num, "shandong") != 0) || (strcmp(data[0].class_num, "other") != 0))
		{
			for (int i = 0; i < 12; i++)
			{
				if ((strcmp(data[i].region, "guangzhou") == 0) || (strcmp(data[i].region, "qingyuan") == 0))
				{
					strcpy_s(data[i].region, 20, "guangdong");
				}
				else if ((strcmp(data[i].region, "jinan") == 0) || (strcmp(data[i].region, "yantai") == 0) || (strcmp(data[i].region, "qingdao") == 0))
				{
					strcpy_s(data[i].region, 20, "shandong");
				}
				else
				{
					strcpy_s(data[i].region, 20, "other");
				}
			}
		}
		else
		{
			for (int i = 0; i < 12; i++)
			{
					strcpy_s(data[i].region, 20, "*");
			}
		}
		break;
	case 2:
		printf("对应的最大表示符为：class_num\n");
		if (data[0].class_num[4]!='*')//第一次泛化class_num
		{
			for (int i = 0; i < 12; i++)
			{
				data[i].class_num[4] = '*';
					/*if ((strcmp(data[i].class_num, "14250") < 0) && (strcmp(data[i].class_num, "14240") > 0))
					{
						strcpy_s(data[i].class_num, 10, "1424*");
					}
					else if ((strcmp(data[i].class_num, "14210") < 0) && (strcmp(data[i].class_num, "14200") > 0))
					{
						strcpy_s(data[i].class_num, 10, "1420*");
					}
					else if ((strcmp(data[i].class_num, "13060") < 0) && (strcmp(data[i].class_num, "13050") > 0))
					{
						strcpy_s(data[i].class_num, 10, "1305*");
					}
					else if ((strcmp(data[i].class_num, "13070") < 0) && (strcmp(data[i].class_num, "13060") > 0))
					{
						strcpy_s(data[i].class_num, 10, "1306*");
					}
					else if ((strcmp(data[i].class_num, "13080") < 0) && (strcmp(data[i].class_num, "13070") > 0))
					{
						strcpy_s(data[i].class_num, 10, "1307*");
					}
					else
					{
						strcpy_s(data[i].class_num, 10, "*");
					}*/
			}
		}
		else if (data[0].class_num[4]=='*'/*(strcmp(data[0].class_num, "0000*") > 0) && (strcmp(data[0].class_num, "9999*") < 0) */)//第二次泛化class_num
		{
			for (int i = 0; i < 12; i++)
			{
				data[i].class_num[3] = '*';
				/*if ((strcmp(data[i].class_num, "1424*") == 0) || (strcmp(data[0].class_num, "1420*") == 0))
				{
					strcpy_s(data[i].class_num, 10, "142**");
				}
				else if ((strcmp(data[i].class_num, "1305*") == 0) || (strcmp(data[i].class_num, "1306*") == 0) || (strcmp(data[i].class_num, "1307*") > 0))
				{
					strcpy_s(data[i].class_num, 10, "130**");
				}
				else
				{
					strcpy_s(data[i].class_num, 10, "*");
				}*/
			}
		}
		else if(data[0].class_num[3] == '*')//最后一次泛化 
		{
			for (int i = 0; i < 12; i++) {
				strcpy_s(data[i].class_num, 10, "*");
			}
		}
		break;
	//case 3:
	//	printf("对应的最大表示符为：health");
	//	break;
	default:
		break;
	}



	return 0;
}

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
	int k = 0;
	printf("进行k-匿名化，k取：");
	scanf_s("%d", &k);
	printf("-----------------------------------------原始数据--------------------------------------------------\n");
	printdata();
	printf("---------------------------------------------------------------------------------------------------\n");
	while (check(data,k)==0)//泛化后的表格进行k匿名检测。
	{
		datafly(data,k);//如果泛化后的数据表符合k匿名检测，则输出，如果不符合，goto1。
		printf("因此再进行一级泛化\n\n");
	}
	printf("---------------------------------datafly算法匿名化后数据--------------------------------------------\n");
	printdata();
	printf("---------------------------------------------------------------------------------------------------\n");

	//bool answer=check(data,k);
	//printf("check的结果：%d\n",answer);
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
