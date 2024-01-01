#include<bits/stdc++.h>
using namespace std;

int main()
{
    int item,maximum;
    cout<<"How many item do you want:"<<endl;
    cin>>item;
    int profit[item];
    int weight[item];
    cout<<"enter profit and weight:"<<endl;
    for(int i= 0; i<item;i++)
    {
        cin>>profit[i]>>weight[i];
    }
    cout<<"enter cap:";
    int cap;
    cin>>cap;
    int row = item+1;
    int col =cap+1;
    int v[row] [col];
    for(int i=0;i<row;i++)
    {
        for( int j=0;j<col;j++)
        {
            if (i==0 || j==0)
            {
                v[i][j]=0;
            }
            else if(weight[i-1]>j)
            {
                v[i][j]=v[i-1][j];
            }
            else
            {
                maximum=max(profit[i-1]+v[i-1][j-weight[i-1]],v[i-1][j]);
                v[i][j]=maximum;
            }
        }
    }
    cout<<v[item][cap];
}
