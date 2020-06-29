#include <iostream>
#include<cmath>
using namespace std;
class Points
{
public:
    double x,y;
};
class Polygon{
public:
    Points *p;
    Polygon(int n)
    {
        p=new Points[n];
    }
};
double area(Polygon poly,int n)
{
    double farea=0;
    for(int i=1;i<n-1;i++)
    {
        double x1=poly.p[i].x-poly.p[0].x;
        double y1=poly.p[i].y-poly.p[0].y;

        double x2=poly.p[i+1].x-poly.p[0].x;
        double y2=poly.p[i+1].y-poly.p[0].y;

        double crossproduct=(x1*y2)-(x2*y1);

        farea+=crossproduct;

    }
    return abs(farea/2);
}
int main()
{
    cout<<"Enter the points in polygon"<<endl;
    int n;
    cin>>n;
    Polygon poly(n);
    cout<<"Enter the coordinates of points"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>poly.p[i].x;
        cin>>poly.p[i].y;
    }
    cout<<"Area of polygon is : "<<area(poly,n)<<endl;;
    return 0;
}
