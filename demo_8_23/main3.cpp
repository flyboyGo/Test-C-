#include <iostream>
#include <string.h>

using namespace std;

class Point
{
     private :
        int x;
        int y;
     public :
        void setX(int x)
        {
            this->x = x;
        }
        int getX(void)const
        {
            return this->x;
        }
        void setY(int y)
        {
            this->y = y;
        }
        int getY(void)const
        {
            return this->y;
        }
};

class AdvCircle
{
     private :
         Point po;
         int radius;
     public :
         void setPoint(int x, int y)
         {
             po.setX(x);
             po.setY(y);
         }
         Point getPoint(void)
         {
             return this->po;
         }

         void setRadius(int radius)
         {
             this->radius = radius;
         }
         int getRadius(void)
         {
             return this->radius;
         }

         void isPointOnCircle(const Point &point)
         {
             int distance = (point.getX() - po.getX()) * (point.getX() - po.getX())
                          + (point.getY() - po.getY()) * (point.getY() - po.getY());

             int radiusS = this->radius * this->radius;

             if(distance < radiusS)
             {
                 cout << "点在圆内" << endl;
             }
             else if(distance > radiusS)
             {
                 cout << "点在圆外" << endl;
             }
             else
             {
                 cout << "点在圆上" << endl;
             }
         }
};



int main(int argc, char *argv[])
{
    Point p;
    p.setX(2);
    p.setY(2);

    AdvCircle ac;
    ac.setRadius(2);
    ac.setPoint(0,0);
    ac.isPointOnCircle(p);
}
