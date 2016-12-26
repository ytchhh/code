#if 0
#ifndef _POINT_H
#define _POINT_H
class Point//基类Point类的定义
{
 public:
    void initPoint(float x=0,float y=0)
	{
	 this -> x = x;
	 this -> y = y;
	}
	void move(float offx,float offy)
	{
	 x+=offx;
	 y+=offy;
	}
	float getX() const {return x;}
	float getY() const {return y;}
 private:
    float x,y;
};
#endif
#endif
#if 1
#ifndef _POINT_H
#define _POINT_H
class Point
{
	public:
		void initPoint(float x = 0,float y = 0)
		{
			this -> x = x;
			this -> y = y;
		}
		void move(float offx,float offy){x+=offx,y+=offy;}
		float getX() const {return x;}
		float getY() const {return y;}
	private:
		float x,y;
};
#endif
#endif
