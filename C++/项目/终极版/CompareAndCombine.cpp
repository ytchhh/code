#include<iostream>
#include<fstream>
#include<string>
#include<list>

using namespace std;

int main()
{
	//先进行文件的比较
	ifstream in1("old.txt");
	ifstream in2("new.txt");
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
	/*
	ifstream in4("old.txt");
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
	*/
	return 0;
}
