#include <bits/stdc++.h>
using namespace std;

/*ADJACENCY MATRIX*/

int source,X,Y;
int visited[20];


vector<vector<int> >a(100);

bool IDS(int p, int limit)
{

    if(p+1 == source){
    cout << p+1 << endl;
    return true;
    }
     int q;
    if(visited[p] == 0){
    visited[p]=1;
    printf(" %d->",p+1);
    }
    if(limit > 0){
    for(q=0; q<a[p].size(); q++)
    {
        int k = a[p][q];

        if(visited[k]==0){
           if( IDS(k, limit-1)) return true;
        }
    }
    }

   return false;

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
        cout << "Enter the edges : ";
        cin >> x1 >> x2;


        a[x1-1].push_back(x2-1);
        a[x2-1].push_back(x1-1);
    }

    cout << "Enter the goal: ";
    cin >> source;
    int lim;
     /*cout << "Enter limit: ";
    cin >> lim;*/
    for(int i=0;i<10 ;){
            for(int j=0;j<20;j++){
                visited[j] = 0;
            }
        cout << "Level : ";
       if(IDS(0, i)){
        cout << "Node found" << endl;
        break;
       }
       else{
        i++;
       }
       cout << endl;
    }
    return 0;
}