#if 0
#include<iostream>
#include<fstream>
using namespace std;
struct Date
{
	int mondy,day,year;
};
int main()
{
	Date dt = {6,10,92};
	ofstream file("1.txt",ios_base::binary);
	file.(reinterpret_cast<char*>(&dt),sizeof(dt));
	file.close();
	return 0;
}
#endif

#if 0
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	ifstream in;	//ifstream读文件,(ofstream写文件)
	string filename;	//建议将文件名定义为string类型
	getline(cin,filename,'\n');//获取文件名

	//in.open(filename);//不加的话则以默认以in打开

	if(!in)
		{
			cerr<<"打开文件失败!"<<endl;
			return 1;
		}
	char ch;
	while(!in.eof())	//当未到达文件末尾
	{
		in.read(&ch,1);//参数一是接受字符的指针，参数二是接受字符
		cout<<ch;	//输出读取的字符
	}

	in.close();
	return 0;
}
#endif

#if 0
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string line;
	cout<<"Type a Line terminated by '\n'"<<endl;
	getline(cin,line,'\n');
	cout<<line<<endl;
	return 0;
}
#endif

#if 0
#include<iostream>
#include<fstream>
using namespace std;

int main()

	ofstream outfile,fout;
	outfile.open("1.txt");
	char s[50];
	cin>>s;
	cout<<"Make and model:"<<endl;
	outfile<<"PPS Make and model:"<<endl;//将输出写入写入文件中，所有cout的函数都可以用
	outfile.close();
	return 0;
}
#endif

#if 0
#include<iostream>
#include<fstream>
#include<string.h>
#define MAXLENGTH 123456
using namespace std;

int my_strcmp(const char* str1,const char* str2);

int main()
{
	fstream file1("1.txt",ios::in);
	fstream file2("2.txt",ios::in);
	ofstream file3;
	file3.open("3.txt");

	char ch1[MAXLENGTH];
	char ch2[MAXLENGTH];
	int buf[MAXLENGTH][MAXLENGTH];
	if( !file1.fail() && !file2.fail() )
		{
			while( !file1.fail() && !file2.fail())
				{
					file1.getline(ch1,MAXLENGTH,'\n');
					file2.getline(ch2,MAXLENGTH,'\n');
					if( my_strcmp(ch1,ch2) == 0 )
					{
								
					}
					else
					{
						
					}
					
				}
		}
	else
		cout<<"error: can not open"<<endl;
	
	file1.close();
	file2.close();
	file3.close();
	
	return 0;
}

int my_strcmp(const char* str1,const char* str2)
{
			while(*str1 == *str2)
				{
					if(*str1 == '\n')
						return 0;
					++str1;
					++str2;
				}
			return (*str1 - *str2);
}
#endif

#include<iostream>
#include<fstream>
#include<string>
#include<list>

using namespace std;

int main()
{
	//先进行文件的比较
	ifstream in1("1.txt");
	ifstream in2("2.txt");
	fstream in3("differ.txt");
	if(!in1 || !in2)
	{
		cerr<<"无法打开输入文件"<<endl;
	}
	
	string line1,line2,line3;
	list<string> words1,words2;
	while(getline(in1,line1))
	{
		words1.push_back(line1);
	}
	in1.close();
	
	while(getline(in2,line2))
	{
		words2.push_back(line2);
	}
	in2.close();
	
	list<string>::iterator it1 = words1.begin(),it3,it5;
	list<string>::iterator it2 = words2.begin(),it4,it6;
	
	while(it1 != words1.end() && it2 != words2.end())
	{
		if(*it1 == *it2)
		{
			in3<<endl;
			++it1;++it2;
		}
		else
		{
			it5 = it3 = it1;
			it6 = it4 = it2;
			++it3;++it4;
			while(*it4 != *it1 && *it4 != *it3 && *it3 != *it2)
			{ 	  //增加			//替换			//删除
				++it3;++it4;
			}
			if(*it4 == *it1)//增加的情况
			{   in3<<"insert"<<endl;
				while(*it2 != *it4)
				{
					in3<<*it2<<endl;
					++it2;
				}
				in3<<"end"<<endl;
			}
			else if(*it4 == *it3)//替换的情况
			{	in3<<"replace"<<endl;
				while(*it2 != *it4)
				{
					in3<<*it2<<endl;
					++it2;
					++it1;
				}
				in3<<"end"<<endl;
			}
			else if(*it3 == *it2)//删除的情况
			{
				in3<<"delete"<<endl;		
				while(*it1 != *it3)
				{
					in3<<*it1<<endl;
					++it1;
				}
				in3<<"end"<<endl;
			}
		}
	}
	if(it1 == words1.end())
	{
		while(it2 != words2.end())
		{
			in3<<*it2<<endl;
			++it2;
		}
	}
	else if(it2 == words2.end())
	{
		while(it1 != words1.end())
		{
			in3<<*it1<<endl;
			++it1;
		}
	}
	in3.close();//文件的比较初步完成，以后的完善后续加入.
	
	//下面是文件的合并
	
	ifstream in4("1.txt");
	ifstream in5("differ.txt");
	fstream in6("end.txt");
	if(!in4 || !in5 || !in6)
	{
		cerr<<"无法打开输入文件"<<endl;
	}
	
	list<string> words3,words4;
	while(getline(in4,line1))
	{
		words3.push_back(line1);
	}
	in4.close();
	
	while(getline(in5,line2))
	{
		words4.push_back(line2);
	}
	in5.close();
	
	it1 = words3.begin();
	it2 = words4.begin();
	
	while(it1 != words3.end() && it2 != words4.end())
	{
		if(*it2 == "")
		{
			in6<<*it1<<endl;
			++it1;++it2;
		}
		else if(*it2 == "delete")
		{
			while(*++it2 != "end")
					++it1;
			++it2;
		}
		else if(*it2 == "insert")
		{
			while(*++it2 != "end")
				in6<<*it2<<endl;
			++it2;
		}
		else if(*it2 == "replace")
		{
			while(*++it2 != "end")
			{	
				in6<<*it2<<endl;
				++it1;
			}
			++it2;
		}
	}
	if(it1 == words3.end())
	{
		while(it2 != words4.end())
		{
			in6<<*it2<<endl;
			++it2;
		}
	}
	else
	{
		while(it1 != words3.end())
		{
			in6<<*it1<<endl;
			++it1;
		}
	}

	in3.close();
	
	return 0;
}
