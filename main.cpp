#include <iostream>
#include <string>
#include <cstring>
using namespace std;



int main()
{
string first;
string second;
string sum;
string sub;

int f=0;
int s=0;

cout << "First number  >>";
cin >> first;
cout << "Second number  >>";
cin >> second;

f=first.length();
s=second.length();
int fn = f%9;
int sn = s%9;
int fm = f/9;
int sm = s/9;

if(f<=9&&s<=9)
{
    sum=stoi(first)+stoi(second);
    sub=stoi(first)-stoi(second);
    cout << "sum        >>" << sum << endl;
    cout << "sub        >>" << sub << endl;

    return;
}

else
{
    int fc[100];
    int i=1;
    if(fn!=0)
    {
    
    fc[0]=stoi(first.substr(0, fn));
    }
    else i--;

    for( i;i<=fm;i++)
    {
        fc[i]=stoi(first.substr(0, 9));
    }
//
    int sc[100];
    int j=1;
    if(sn!=0)
    {
    
    sc[0]=stoi(second.substr(0, 9));
    }
    else i--;

    for( j;j<=sm;j++)
    {
        sc[i]=stoi(second.substr(0, 9));
    }
//
    int total[100];
    int mtotal[100];
    if(i==j)
    {
        for(i;i>=0;i--)
        {
            total[i]=fc[i]+sc[i];
        
            if(total[i]>1000000000 && i!=0)
            {
                total[i-1]=total[i-1]+1;
                total[i]=total[i]-1000000000;
            }
            if(fc[0]>sc[0])
            {
                mtotal[i]=fc[i]-sc[i];
                mtotal[i-1]=mtotal[i-1]-1;
                mtotal[i]=mtotal[i]+1000000000;

            }
            if(fc[0]<sc[0])
            {
                mtotal[i]=sc[i]-fc[i];
                mtotal[i-1]=mtotal[i-1]-1;
                mtotal[i]=mtotal[i]+1000000000;

            }

        
        }

    }
    if(i>j)
    {

        int k = i-j;
        for(i;i>=0;i--)
        {
            total[i]=fc[i]+sc[i];
            mtotal[i]=fc[i]-sc[i];
            if(total[i]>1000000000 && i!=0)
            {
                total[i-1]=total[i-1]+1;
                total[i]=total[i]-1000000000;
            }

            if(mtotal[i]<0)
            {
                mtotal[i-1]=mtotal[i-1]-1;
                mtotal[i]=mtotal[i]+1000000000;

            }
        }

    }
    if(i<j)
    {
        for(i;i>=0;i--)
        {
            total[i]=fc[i]+sc[i];
            mtotal[i]=sc[i]-fc[i];
            if(total[i]>1000000000 && && i!=0)
            {
                total[i-1]=total[i-1]+1;
                total[i]=total[i]-1000000000;
            }

            if(mtotal[i]<0)
            {
                mtotal[i-1]=mtotal[i-1]-1;
                mtotal[i]=mtotal[i]+1000000000;

            }

        }

    }

}

}