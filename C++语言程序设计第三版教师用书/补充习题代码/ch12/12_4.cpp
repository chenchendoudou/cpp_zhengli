//12_4.cpp
#include <iostream>
using namespace std;

int main()
{
	cout<<"开始\n";
	try
	{
		cout<<"进入try块\n";
		throw 999;
		cout<<"该语句不应执行";
	}
	catch(double i)
	{
		cout<<"捕捉的异常为：";
		cout<<i<<endl;
	}
	cout<<"结束";
   return 0;
}
/*
运行结果：
开始
进入try块
然后出现运行错误！
*/