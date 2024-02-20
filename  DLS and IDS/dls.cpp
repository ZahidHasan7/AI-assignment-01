#include <bits/stdc++.h>
using namespace std;

/*ADJACENCY MATRIX*/

int source,X,Y;
int v[20];


vector<vector<int> >a(100);

void DLS(int p, int limit)
{

    if(p+1 == source){
    cout << p+1 << endl;
    return;
    }
     int q;
    if(v [p] == 0){
    v [p]=1;
    printf(" %d->",p+1);
    }
    if(limit > 0){
    for(q=0; q<a[p].size(); q++)
    {
        int k = a[p][q];

        if(v [k]==0)
            DLS(k, limit-1);
    }
    }

}
int main()
{
    int p,q,x1,x2;
 
    cout << "The number of edges:";
    cin >> Y;
    cout << "The number of vertices:";
    cin >>X;

    /*creating edges : */
    for(p=0; p<Y; p++)
    {
        cout << "Enter the  edges : ";
        cin >> x1 >> x2;


        a[x1-1].push_back(x2-1);
        a[x2-1].push_back(x1-1);
    }

    cout << "Enter the goal: ";
    cin >> source;
    int lim;
     cout << "Enter limit: ";
    cin >> lim;
    DLS(0, lim);
    return 0;
}
 
 