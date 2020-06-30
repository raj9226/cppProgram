#include <iostream>
#include<vector>
using namespace std;
//convex hull
struct points
{
    int x, y;
};
bool tochange(points p,points q, points r)
{
    int pqx=q.x-p.x;
    int pqy=q.y-p.y;

    int qrx=r.x-q.x;
    int qry=r.y-q.y;

    int value= (pqx*qry) - (pqy*qrx);
    return value > 0;

}
void convexHull(points pts[],int n)
{
    vector<points> hull;
    int l=0;
    for(int i=1;i<n;i++)
    {
        if(pts[i].x<pts[l].x)
        {
            l=i;
        }
    }
    int p=l;
    do
    {
        hull.push_back(pts[p]);
        int q=(p+1)%n;
        for(int i=0;i<n;i++)
        {
            if(tochange(pts[p],pts[q],pts[i]))
            {
                q=i;
            }
        }
        p=q;
    }while(p!=l);
    for(int i=0;i<hull.size();i++)
    {
        cout<<hull[i].x<<" "<<hull[i].y<<endl;
    }

}
int main()
{

    points p[]={{0,4},{1,1},{2,2},{4,4},{4,0},{0,0},{3,3}};
    convexHull(p,7);
    return 0;
}
