#include"stack.h"

/*
bool check(const char *str)		//
{
	Stack<char> st(strlen(str));
	const char *p = str;		//p指向字符串的首字符
	while(*p)
	{
		switch(*p)				//没到串尾
		{
			case '(':
			case '{':
			case '[':
				st.push(*p++);		//左括号入栈
				break;
			case ')':
			case '}':
			case ']':
				{
					if(!st.Is_Empty())	//如果栈不空的话
					{
						if(! (st.base[st.top-1] == '(' && *p == ')' || st.base[st.top-1] == '{' && *p == '}' || st.base[st.top-1] == '[' && *p == ']'))
						{	//出现了三种匹配情况之外的
							cout<<"左右括号不匹配!"<<endl;
							exit(1);
						}
						st.pop();		//弹出栈顶元素
						p++;
						break;
					}
					else
						exit(0);
				}
				break;
			default:
				p++;
				break;
		}
	}
	if(st.Is_Empty())
		return true;
	else
		return false;
}
*/

int main()
{	
	/*
	Stack<int> my_stack;
	for(int i = 0; i < 5; ++i)
		my_stack.push(i);
	my_stack.show_stack();
	my_stack.pop();
	my_stack.show_stack();
	cout<<"头:"<<my_stack.GetTop()<<endl;
	*/
	/*
	char *str = "[([])([])]";

	bool flag = check(str);
	if(flag)
		cout<<"Ok."<<endl;
	else
		cout<<"error"<<endl;
	*/
	Stack<int> my_stack;
	int select = 1;
	ElemType Item;
	while(select)
	{
		cout<<"*****************************************************"<<endl;
		cout<<"[1]push                  [2]pop                     *"<<endl;
		cout<<"[3]show_stack            [4]quit_system             *"<<endl;
		cout<<"[5]Is_Empty              [6]Is_Full                 *"<<endl;
		cout<<"[7]"<<endl;
		cout<<"*****************************************************"<<endl;

	}
	return 0;
}
