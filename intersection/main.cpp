#include <iostream>
#include<algorithm>
using namespace std;
class points
{
public:
    double x,y;
};
class line
{
public:
    points *p;
    line(int n)
    {
        p=new points[n];
    }
};

//To find the intersection of line passing through two points*/
void intesecLine(line l1,line l2)
{

    double A1=l1.p[1].y-l1.p[0].y;
    double B1=l1.p[0].x-l1.p[1].x;
    double C1=A1*(l1.p[0].x) + B1*(l1.p[0].y);

    double A2=l2.p[1].y-l2.p[0].y;
    double B2=l2.p[0].x-l2.p[1].x;
    double C2=A2*(l2.p[0].x) + B2*(l2.p[0].y);

    double determinant=(A1*B2)-(A2*B1);

    if(determinant==0)
    {
        cout<<"The lines are parallel";
    }
    else
    {
        double x=((B2*C1)-(B1*C2))/determinant;
        double y=((A1*C2)-(A1*C1))/determinant;

        if(x>=min((l1.p[0].x),(l1.p[1].x)) && x<=max((l1.p[0].x),(l1.p[1].x)))
            if(y>=min((l1.p[0].y),(l1.p[1].y)) && y<=max((l1.p[0].y),(l1.p[1].y)))
            {
                cout<<"The lines are intersecting at ("<<x<<" "<<y<<") Coordinates"<<endl;
            }
            else{
                cout<<"No intersection"<<endl;
            }

    }

}
//To find the intersection of line segment passing through two points*/
/*
void intesecLine(line l1,line l2)
{

    double A1=l1.p[1].y-l1.p[0].y;
    double B1=l1.p[0].x-l1.p[1].x;
    double C1=A1*(l1.p[0].x) + B1*(l1.p[0].y);

    double A2=l2.p[1].y-l2.p[0].y;
    double B2=l2.p[0].x-l2.p[1].x;
    double C2=A2*(l2.p[0].x) + B2*(l2.p[0].y);

    double determinant=(A1*B2)-(A2*B1);

    if(determinant==0)
    {
        cout<<"The lines are parallel";
    }
    else
    {
        double x=((B2*C1)-(B1*C2))/determinant;
        double y=((A1*C2)-(A1*C1))/determinant;

        cout<<"The lines are intersecting at ("<<x<<" "<<y<<") Coordinates"<<endl;
    }

}
*/
int main()
{
    line l1(2);
    line l2(2);
    cout<<"Enter the x and y coordinates of two points on line A"<<endl;
    cin>>l1.p[0].x>>l1.p[0].y;
    cin>>l1.p[1].x>>l1.p[1].y;

    cout<<"Enter the x and y coordinates of two points on line B"<<endl;
    cin>>l2.p[0].x>>l2.p[0].y;
    cin>>l2.p[1].x>>l2.p[1].y;
    intesecLine(l1,l2);






}
