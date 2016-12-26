#if 0
#ifndef _RECTANGLE_H
#define _RECTANGLE_H
#include"Point.h"
class Rectangle:public Point
{
	public:
		void initRectangle(float x,float y,float w,float h)
		{
			initPoint(x,y);
			this -> w = w;
			this -> h = h;
		}
		float getH() const {return h;}
		float getW() const {return w;}
	private:
		float w,h;
};
#endif
#endif
#if 1
#ifndef _RECTANGLE_H
#define _RECTANGLE_H
#include"Point.h"
class Retangle:private Point
{
 public:
   void initRectangle(float x,float y,float w,float h)
   {
    initPoint(x,y);
	this -> w = w;
	this -> h = h;
   }
   void move(float offx,float offy){Point::move(offx,offy);}
   float getX() const {return Point::getX();}
   float getY() const {return Point::getY();}
   float getH() const {return h;}
   float getW() const {return w;}
 private:
   float w,h;
};
#endif
#endif
