#include <iostream>

using namespace std;

struct seg_tree{
    int S[20];
    int size;
};

typedef seg_tree *sptr;

int max_of_two(int a, int b){
    if(a > b)
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

int query_max_odd(sptr S, int i, int sl, int sh, int l, int h){
    if(l>=sl && h<=sh){
        if(l == h){
            if(S->S[i]%2 != 0)
                return S->S[i];
            else return 0;
        }
        else{
            if(S->S[i]%2 != 0)
                return S->S[i];
            else{
                int mid = (l+h)/2;
                return max_of_two(query_max_odd(S,2*i+1, sl,sh,l,mid), query_max_odd(S,2*i+2,sl,sh,mid+1,h));
            }
        }
    }
    else{
        if(l>sh || h<sl)
            return 0;

        else{
            int mid = (l+h)/2;
            return max_of_two(query_max_odd(S,2*i+1, sl,sh,l,mid), query_max_odd(S,2*i+2,sl,sh,mid+1,h));
        }
    }
}

int query_max_even(sptr S, int i, int sl, int sh, int l, int h){
    
    if(l>=sl && h<=sh && S->S[i]%2 == 0){
        if(l == h){
            if(S->S[i]%2 == 0)
                return S->S[i];
            else return 0;
        }
        else
            return S->S[i];
    }
    else{
        if(l>sh || h<sl)
            return 0;

        else{
            int mid = (l+h)/2;
            return max_of_two(query_max_even(S,2*i+1, sl,sh,l,mid), query_max_even(S,2*i+2,sl,sh,mid+1,h));
        }
    }
}

void update(sptr S, int range, int to, int i, int l, int h){
    if(l == h){
        if(l == range)
            S->S[i] = to;
        return;
    }
    else{
        int mid = (l+h)/2;
        if(range >=l && range <= h){
            if(S->S[i] < to)
                S->S[i] = to;
            update(S,range,to,2*i+1,l,mid);
            update(S,range,to,2*i+2,mid+1,h);
        }
        else return;
    }
}

int main(){

    int n,q;
    cin>>n>>q;

    int *A = new int [n];
    for(int i=0;i<n;i++)
        cin>>A[i];

    sptr S = new seg_tree;
    max_seg_create(S,A,0,0,n-1);

    while(q--){
        int type;
        cin>>type;

        if(type == 1){
            int pos, to;
            cin>>pos>>to;
            A[pos] = to; 
            update(S,pos,to,0,0,n-1);
        }
        else if(type == 2){
            int L,R;
            cin>>L>>R;
            int a = query_max_even(S,0,L-1,R-1,0,n-1);
            if(a == 0)
                cout<< "DNE" << endl;
            else
                cout<< a << endl;
        }
        else{
            int L,R;
            cin>>L>>R;
            int a = query_max_odd(S,0,L-1,R-1,0,n-1);
            if(a == 0)
                cout<< "DNE" << endl;
            else
                cout<< a << endl;
        }
    }
    return 0;
}