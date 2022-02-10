#include <iostream>

using namespace std;

struct seg_tree{
    int S[20];
    int size;
};

typedef seg_tree *sptr;

int sum_seg_create(sptr S, int *A, int i, int l, int h){
    if(l == h){
        S->S[i] = A[l];
        return S->S[i];
    }
    else{
       int mid = (l+h)/2;
        S->S[i] = sum_seg_create(S,A,2*i+1,l,mid) + sum_seg_create(S,A,2*i+2,mid+1,h);
        return S->S[i];
    }
}

int max_of_two(int a, int b){
    if(a > b)
        return a;
     else
        return b; 
}

int min_of_two(int a, int b){
    if(a < b)
        return a;
     else
        return b; 
}

int max_seg_create(sptr S, int *A, int i, int l, int h){
    if(l == h){
        S->S[i] = A[l];
        return S->S[i];
    }
    else{
        int mid = (l+h)/2;
        S->S[i] = max_of_two(max_seg_create(S,A,2*i+1,l,mid),max_seg_create(S,A,2*i+2,mid+1,h));
        return S->S[i];
    }
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

int query_sum(sptr S, int i, int sl, int sh, int l, int h){
    if(l>=sl && h<=sh)
        return S->S[i];
    else{
        if(l>sh || h<sl)
            return 0;

        else{
            int mid = (l+h)/2;
            return query_sum(S,2*i+1, sl,sh,l,mid) + query_sum(S,2*i+2,sl,sh,mid+1,h);
        }
    }
}

int query_max(sptr S, int i, int sl, int sh, int l, int h){
    if(l>=sl && h<=sh)
        return S->S[i];
    else{
        if(l>sh || h<sl)
            return 0;

        else{
            int mid = (l+h)/2;
            return max_of_two(query_max(S,2*i+1, sl,sh,l,mid), query_max(S,2*i+2,sl,sh,mid+1,h));
        }
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

void update(sptr S, int from, int to){
    int i=0;
    while(S->S[i] != from)
        i++;

    int difference = to - from;

    while(i >= 0){
        S->S[i]+=difference;
        i=(i-1)/2;
    }
}

int main(){
    int n;
    cin>>n;

    int *A = new int [n];
    for(int i=0;i<n;i++)
        cin>>A[i];
    
    sptr S = new seg_tree;
    S->size = 2*n+1;

    sptr S1 = new seg_tree;
    S1->size = 2*n+1;

    sptr S2 = new seg_tree;
    S2->size = 2*n+1;

    sum_seg_create(S,A,0,0,n-1);
    max_seg_create(S1,A,0,0,n-1);
    min_seg_create(S2,A,0,0,n-1);

    cout<< "Sum b/w 2 and 4 : ";
    cout<< query_sum(S,0,2,4,0,5)<< endl;

    cout<< "Max b/w 2 and 4 : ";
    cout<< query_max(S1,0,2,4,0,5)<< endl;

    cout<< "Min b/w 2 and 4 : ";
    cout<< query_min(S2,0,2,4,0,5)<< endl;

    cout<< "previous segment tree : "<< endl;

    return 0;
}