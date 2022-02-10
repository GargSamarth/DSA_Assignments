#include <iostream>

using namespace std;

int main(){
    int n,m;

    cin>>n>>m;
    int **A;
    A = new int* [n];
    for(int i=0;i<n;i++){
        A[i] = new int[m];
        for(int j=0;j<m;j++)
            cin>>A[i][j];
    }

    int s,sum=0;
    cin>>s;
    for(int i=0;i<n;i++){
        sum+=A[i][0];
    }

    if(sum < s){
        
    }
}