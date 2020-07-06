#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int max_rec(int **inp,int m,int n,int xi,int xj,int xii,int xjj,int yi,int yj,int yii,int yjj)
{
    int ans[m][n];
    memset(ans,0,m*n*sizeof(int));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=i;k<m;k++)
            {
                for(int l=j;l<n;l++)
                {
                    ans[i][j]+=inp[k][l];
                }
            }
        }
    }
    int total=ans[xi][xj];
    int lower=0;
    int right=0;
    int rem=0;
    if(yj<m)
    {
        right+=ans[yi][yj+1];
    }
    if(xii<n)
    {
        lower+=ans[xii+1][xjj];
        rem+=ans[yii+1][yjj+1];
    }
    cout<<total<<" "<<right<<" "<<lower<<" "<<ans<<endl;
    return 0;
}
int main()
{
    int m,n;
    cin>>m>>n;
    int** inp=new int*[m];
    for(int i=0;i<n;i++)
        inp[i]=new int[n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>inp[i][j];
        }
    }
    int xi,xj,xii,xjj,yi,yj,yii,yjj;
    cin>>xi>>xj>>xii>>xjj>>yi>>yj>>yii>>yjj;
    cout << max_rec(inp,m,n,xi,xj,xii,xjj,yi,yj,yii,yjj)<< endl;
    return 0;
}
