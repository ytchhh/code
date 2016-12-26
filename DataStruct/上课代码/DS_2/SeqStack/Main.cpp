#include"stack.h"

bool Check(const char *str)
{
	//
}
///////////////////////////////////////

void main()
{
	char *str = "[([])([])]";

	bool flag = Check(str);
	if(flag)
		cout<<"OK."<<endl;
	else
		cout<<"Error."<<endl;
}

/*
void main()
{
	Stack<int> st;
	for(int i=1; i<=5; ++i)
	{
		st.push(i);
	}
	st.show_stack();
	cout<<"----------"<<endl;
	cout<<st.gettop()<<"³öÕ»."<<endl;
	st.pop();
	cout<<st.gettop()<<"³öÕ»."<<endl;
	st.pop();
	st.show_stack();
}
*/