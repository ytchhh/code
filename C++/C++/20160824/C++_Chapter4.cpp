#include<iostream>
using namespace std;
#if 0 //4-8
class Dog {
public:
	void Set(float tmpage,float tmpweight);
	void Get();
private:
	float age;
	float weight;
};
void Dog::Set(float tmpage,float tmpweight) {
	age = tmpage;
	weight = tmpweight;
}
void Dog::Get() {
	cout<<"age:"<<age<<"year,weight:"<<weight<<"kg"<<endl;
}
#endif
#if 0 //4-9
class Point {
public:
	Point(int x = 0,int y = 0):X(x),Y(y) {}
	int GetX() {
		return X;
	}
	int GetY() {
		return Y;
	}
private:
	int X;
	int Y;
};
class Rectangle {
public:
	Rectangle(int x1 = 0,int y1 = 0,int x2 = 0,int y2 = 0):RightUp(x1,y1),
LeftDown(x2,y2) {}
	int Area() {
	return (RightUp.GetY() - LeftDown.GetY()) * (RightUp.GetX() - LeftDown.GetX());
}
private:
	Point RightUp;
	Point LeftDown;
};
#endif
#if 1 //4-10
#include<string.h>
class Date {
public:
	Date(char *y = NULL,char *m = NULL,char *d = NULL) {
		strcpy(Year,y);
		strcpy(Month,m);
		strcpy(Day,d);
		//cout<<"Date's constructor called"<<endl;
	}
	Date(Date &date) {
		strcpy(Day,date.Day);
		strcpy(Month,date.Month);
		strcpy(Year,date.Year);
		//cout<<"Date's cp called"<<endl;
	}
	~Date() {
		//cout<<"Date's destructor called"<<endl;
	}
	char *GetDay() {
		return Day;
	}
	char *GetMonth() {
		return Month;
	}
	char *GetYear() {
		return Year;
	}
private:
	char Day[3];
	char Month[3];
	char Year[5];
};
/*class Human {
public:
	Human(char *num = NULL,char *sex = NULL,char *y = NULL,char *m = NULL,char *d = NULL,char *id = NULL):Birthday(y,m,d) {
		strcpy(Num,num);
		strcpy(Sex,sex);
		strcpy(ID,id);
		//cout<<"Human's constructor called"<<endl;
	}
	Human(Human &A):Birthday(A.Birthday) {
		strcpy(Num,A.Num);
		strcpy(Sex,A.Sex);
		strcpy(ID,A.ID);
		//cout<<"Human's cp called"<<endl;
	}
	~Human() {
		//cout<<"Human's destructor called"<<endl;
	}
	void Read();
private:
	char Num[3];
	char Sex[7];
	Date Birthday;
	char ID[20];
};
//void Human::Read() {
//	cout<<"Num:"<<Num<<endl;
//	cout<<"Sex:"<<Sex<<endl;
//	cout<<"Birthday:"<<Birthday.GetYear()<<"/";
//	cout<<Birthday.GetMonth()<<"/";
//	cout<<Birthday.GetDay()<<endl;
//	cout<<"ID:"<<ID<<endl;
//}*/
#endif
#if 0 //4-11
class Rectangle {
public:
	Rectangle(int length = 0,int width = 0):Length(length),Width(width) {}
	Rectangle(Rectangle & A) {
		Length = A.Length;
		Width = A.Width;
	}
	int area() {
		return Length * Width;
	}
private:
	int Length;
	int Width;
};
#endif 
#if 0 //4-12

#endif
int main()
{
	/*Human Jack("00","male","1995","08","21","610582199508216512");
	Human Tom("01","male","1996","05","22","610582199605226512");
	Human White(Jack);*/
	Date day("1995","08","21");
	Date day2(day);
	return 0;
}
