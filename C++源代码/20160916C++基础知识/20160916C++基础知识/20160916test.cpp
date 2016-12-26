#if 0
/*
开发一个软件是为了解决某些问题，这些问题所涉及的业务范围称为该软件的问题域。面向对象的编程语言将客观事物看成具有属性
和行为的对象，通过抽象找出同一类对象的共同属性和行为形成类。
*/
//位运算符：按位与
//将两个操作数对应的每一位进行逻辑与操作
#include<iostream>
using namespace std;
int main()
{
 int a = 1;
 a =  a & 0xfe;//这个操作将会让 变量a的最低位置0。
 cout<<a<<endl;
 char c,d = 2;
 c = d &0xff;//将d的低字节置于c中。
 cout<<c<<endl;
 return 0;
}
#endif
#if 0
//将两个操作数进行逻辑或操作。
#include<iostream>
using namespace std;
int main()
{
 int a = 2;
 a = a | 0xff;//将a的最低字节置为1
 cout<<a<<endl;
 return 0;
}
#endif
#include<iostream>
using namespace std;
#if 0
//按位异或  对每一位进行异或，如果对应位相同，则为0，不同，则为1.
//使用按位异或操作可以让操作数中的指定位翻转，如果使某位和0异或，结果是该位的原值，如果与1异或，
//结果与该位原来的值相反
int main() 
{
 
 return 0;
}
#endif
#if 1
//左移是按照指定的位数将一个数的二进制位向左移位，左移后，低位补0，移出的高位舍弃。
//右移是按照指定的卫视将一个数的二进制位右移，右移后，右移后，移出的低位舍弃，如果是无符号位则高位补0，
//如果是有符号位则高位补符号位。
int main()
{
 char a = -8;
 cout<<(a>>2)<<endl;
 char b = 2;
 cout<<(b<<1)<<endl;
 return 0;
}
#endif





