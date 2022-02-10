#include <iostream>

using namespace std;

struct seg_tree{
    int S[20];
    int size;
};

typedef seg_tree *sptr;

int min_of_two(int a, int b){
    if(a < b)
        return a;
     else
        return b; 
}

int min_seg_create(sptr S, int *A, int i, int l, int h){
    if(l == h){
        S->S[i] = A[l];
        return S->S[i];
    }
    else{
        int mid = (l+h)/2;
        S->S[i] = min_of_two(min_seg_create(S,A,2*i+1,l,mid),min_seg_create(S,A,2*i+2,mid+1,h));
        return S->S[i];
    }
}

int query_min(sptr S, int i, int sl, int sh, int l, int h){
    if(l>=sl && h<=sh)
        return S->S[i];
    else{
        if(l>sh || h<sl)
            return 9632;

        else{
            int mid = (l+h)/2;
            return min_of_two(query_min(S,2*i+1, sl,sh,l,mid), query_min(S,2*i+2,sl,sh,mid+1,h));
        }
    }
}

int comman_range(int i, int l, int h, sptr S1, sptr S2){
    if(l == h)
        return;
    else{
        if(S1->S[i] == S2->S[i])
            cout<< l << " " << h <<endl;
        int mid = (l+h)/2;
        comman_range(2*i+1,l,mid,S1,S2);
        comman_range(2*i+2,mid+1,h,S1,S2);;
    }
}

int main(){
    int n1,n2;
    cin>>n1;

    int *A1 = new int [n1];
    for(int i=0;i<n1;i++)
        cin>>A1[i];
    
    cin>>n2;

    int *A2 = new int [n2];
    for(int i=0;i<n2;i++)
        cin>>A2[i];
    
    sptr S1 = new seg_tree;
    S1->size = 2*n1+1;

    sptr S2 = new seg_tree;
    S2->size = 2*n2+1;

    min_seg_create(S1,A1,0,0,n1-1);
    min_seg_create(S2,A2,0,0,n2-1);

    comman_range(0,0,n1-1,S1,S2);

    return 0;
}