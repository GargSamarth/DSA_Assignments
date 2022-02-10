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

int avg_seg_create(sptr S, int *A, int i, int l, int h){
    if(l == h){
        S->S[i] = A[l];
        return S->S[i];
    }
    else{
       int mid = (l+h)/2;
        S->S[i] = (sum_seg_create(S,A,2*i+1,l,mid) + sum_seg_create(S,A,2*i+2,mid+1,h))/2;
        return S->S[i];
    }
}

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

int query_avg(sptr S, int i, int sl, int sh, int l, int h){
    if(l>=sl && h<=sh)
        return S->S[i];
    else{
        if(l>sh || h<sl)
            return 0;

        else{
            int mid = (l+h)/2;
            return (query_sum(S,2*i+1, sl,sh,l,mid) + query_sum(S,2*i+2,sl,sh,mid+1,h))/2;
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

void update1(sptr S, int range, int to, int i, int l, int h){
    if(l == h){
        if(l == range)
            S->S[i] = to;
        return;
    }
    else{
        int mid = (l+h)/2;
        if(range >=l && range <= h){
            if(S->S[i] > to)
                S->S[i] = to;
            update1(S,range,to,2*i+1,l,mid);
            update1(S,range,to,2*i+2,mid+1,h);
        }
        else return;
    }
}

void update2(sptr S, int from, int to){
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

    int n,q;
    cin>>n;

    int *A = new int [n];
    for(int i=0;i<n;i++)
        cin>>A[i];
    
    cin>>q;

    sptr S1 = new seg_tree;
    sptr S2 = new seg_tree;
    sptr S3 = new seg_tree;
    sum_seg_create(S1,A,0,0,n-1);
    min_seg_create(S2,A,0,0,n-1);
    avg_seg_create(S3,A,0,0,n-1);

    while(q--){
        int type,L,R;
        cin>>type>>L>>R;

        if(type == 0){
            int from = A[L-1];
            A[L-1] = R;
            update1(S2,L-1,R,0,0,n-1);
            update2(S1,from,R);
        }
        else if(type == 1){
            cout<< query_sum(S1,0,L-1,R-1,0,n-1)<< endl;
        }
        else if(type == 2){
            cout<< query_min(S2,0,L-1,R-1,0,n-1)<< endl;
        }
        else{
            cout<< query_avg(S2,0,L-1,R-1,0,n-1)<< endl;
        }
    }
    return 0;
}