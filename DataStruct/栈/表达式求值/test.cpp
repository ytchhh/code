#include"stack.h"

bool In(char c)
{//判断c是否为7种运算符之一
	switch(c)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '(':
		case ')':
		case '#':return true;
		default:return false;
	}
}

char Precede(char t1,char t2)
{
	char f;
	switch(t2)
	{
		case '+':
		case '-':if(t1 == '(' || t1 == '#')
					f = '<';	//t1<t2
				else
					f = '>';	//t1>t2
				break;
		case '*':
		case '/':
				if(t1 == '*' || t1 == '/' || t1 == ')')
					f = '>';	//t1>t2
				else
					f = '<';	//t1<t2
				break;
		case '(':
				if(t1 == ')')
				{
					cout<<"括号不匹配"<<endl;
					exit(1);
				}
				else
					f = '<';	//t1<t2
				break;
		case ')':
				switch(t1)
				{
					case '(':
							f = '=';	//t1 = t2
							break;
					case '#':
							cout<<"缺乏左括号"<<endl;
							exit(1);
					default:f = '>';	//t1 > t2
							
				}
				break;
		case '#':
				switch(t1)
				{
					case '#':
							f = '=';	//t1 = t2
					case '(':
							cout<<"缺乏右括号"<<endl;
							exit(1);
					default:
							f = '>';	//t1 > t2
				}
				break;
	}
	return f;
}

char Operate(int a,char theta,int b)
{
	switch(theta)
	{
		case '+':
				return	a + b;
		case '-':
				return  a - b;
		case '*':
				return  a * b;
	}
	return a/b;
}

int EvaluateExpression()
{//算术表达式求值的算符有限算法,设OPTR和OPND分别为运算符栈和运算数栈
	Stack<char> OPTR;
	Stack<int> OPND;
	int a,b,s;
	char c,x;
	OPTR.push('#');	//将换行符压入运算符栈OPTR的栈底
	cin>>c;		//由键盘读入1个字符到c
	x = OPTR.GetTop();	//将运算符OPTR的栈顶元素赋给x
	while(c != '#' || x != '#')	//c和x不都是换行符
	{
		if(In(c))	//c是7种运算符之一
			switch(Precede(x,c))	//判断x和c的优先级
			{
				case '<':
						OPTR.push(c);	//栈顶元素x的优先级低,入栈
						cin>>c;			//由键盘读入下一个字符到c
						break;
				case '=':
						OPTR.pop();		//x='('且c=')'情况,弹出栈顶元素
						cin>>c;			//由键盘读入下一个字符到c
						break;
				case '>':
						x = OPTR.GetTop();
						OPTR.pop();	//栈顶元素x的优先级高,弹出运算符顶的元素给x
						b = OPND.GetTop();
						OPND.pop();
						a = OPND.GetTop();
						OPND.pop();	//依次将OPND的栈顶元素给弹出来,分别给b,a.
						OPND.push(Operate(a,x,b));	//做运算a x b,并将运算结果如运算符栈
			}
		else if(c >= '0' && c <= '9')	//c是操作数
		{
			OPND.push(c-48);	//将该操作数的值
			cin>>c;				//由键盘读入下一个字符到c
		}
		else	//c是非法字符
		{
			cout<<"出现非法字符"<<endl;
			exit(1);
		}
		x = OPTR.GetTop();//将运算符栈的栈顶元素赋给x
	}
	s = OPND.GetTop();
	OPND.pop();			//将运算数栈的栈顶元素给x　并且弹出来.
	if(!OPND.Is_Empty())	//如果运算数栈OPND不空
	{
		cout<<"表达式不正确"<<endl;
		exit(1);
	}
	return s;
}


int main()
{
	cout<<"请输入算术表达式(输入的值要在0和9之间):"<<endl;
	cout<<EvaluateExpression()<<endl;
	return 0;
}
