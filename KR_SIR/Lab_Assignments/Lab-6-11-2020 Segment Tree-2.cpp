#include <iostream>

using namespace std;

struct all_in_one{
    int min,max,sum,avg;
};

struct seg_tree{
    all_in_one S[20];
    int size;
};

typedef seg_tree *sptr;

int sum_seg_create(sptr S, float *A, int i, int l, int h){
    if(l == h){
        S->S[i].sum = A[l];
        return S->S[i].sum;
    }
    else{
       int mid = (l+h)/2;
        S->S[i].sum = sum_seg_create(S,A,2*i+1,l,mid) + sum_seg_create(S,A,2*i+2,mid+1,h);
        return S->S[i].sum;
    }
}

float avg_seg_create(sptr S, float *A, int i, int l, int h){
    if(l == h){
        S->S[i].avg = A[l];
        return S->S[i].avg;
    }
    else{
       int mid = (l+h)/2;
        S->S[i].avg = (avg_seg_create(S,A,2*i+1,l,mid)*(mid-l+1) + avg_seg_create(S,A,2*i+2,mid+1,h)*(h-mid))/(h-l+1);
        return S->S[i].avg;
    }
}

int min_of_two(int a, int b){
    if(a < b)
        return a;
     else
        return b; 
}

int max_of_two(int a, int b){
    if(a > b)
        return a;
     else
        return b; 
}

int max_seg_create(sptr S, float *A, int i, int l, int h){
    if(l == h){
        S->S[i].max = A[l];
        return S->S[i].max;
    }
    else{
        int mid = (l+h)/2;
        S->S[i].max = max_of_two(max_seg_create(S,A,2*i+1,l,mid),max_seg_create(S,A,2*i+2,mid+1,h));
        return S->S[i].max;
    }
}

int min_seg_create(sptr S, float *A, int i, int l, int h){
    if(l == h){
        S->S[i].min = A[l];
        return S->S[i].min;
    }
    else{
        int mid = (l+h)/2;
        S->S[i].min = min_of_two(min_seg_create(S,A,2*i+1,l,mid),min_seg_create(S,A,2*i+2,mid+1,h));
        return S->S[i].min;
    }
}

float query_sum(sptr S, int i, int sl, int sh, int l, int h){
    if(l>=sl && h<=sh)
        return S->S[i].sum;
    else{
        if(l>sh || h<sl)
            return 0;
        else{
            int mid = (l+h)/2;
            return query_sum(S,2*i+1, sl,sh,l,mid) + query_sum(S,2*i+2,sl,sh,mid+1,h);
        }
    }
}

int query_min(sptr S, int i, int sl, int sh, int l, int h){
    if(l>=sl && h<=sh)
        return S->S[i].min;
    else{
        if(l>sh || h<sl)
            return 9632;
        else{
            int mid = (l+h)/2;
            return min_of_two(query_min(S,2*i+1, sl,sh,l,mid), query_min(S,2*i+2,sl,sh,mid+1,h));
        }
    }
}

int query_max(sptr S, int i, int sl, int sh, int l, int h){
    if(l>=sl && h<=sh)
        return S->S[i].max;
    else{
        if(l>sh || h<sl)
            return 0;

        else{
            int mid = (l+h)/2;
            return max_of_two(query_max(S,2*i+1, sl,sh,l,mid), query_max(S,2*i+2,sl,sh,mid+1,h));
        }
    }
}

void update2(sptr S, int range, int difference, int i, int l, int h){
    if(range < l || range > h)
        return;
    else{
        int mid = (l+h)/2;
        S->S[i].sum+= difference;
        if(l == h)
            return;
        update2(S,range,difference,2*i+1,l,mid);
        update2(S,range,difference,2*i+2,mid+1,h);
    }
}

void update3(sptr S, int range, int to, int i, int l, int h){
    if(l == h){
        if(l == range)
            S->S[i].max = to;
        return;
    }
    else{
        int mid = (l+h)/2;
        if(range >=l && range <= h){
            if(S->S[i].max < to)
                S->S[i].max = to;
            update3(S,range,to,2*i+1,l,mid);
            update3(S,range,to,2*i+2,mid+1,h);
        }
        else return;
    }
}

int update1(sptr S, int i, int range, int l, int h, int to){

    if(l == h ){
        S->S[i].min = to;
        return S->S[i].min;
    }
    else{
        int mid=(l+h)/2;
        if(range <= mid){
            update1(S,(2*i)+1,range,l,mid,to);
        }
        else{
            update1(S,(2*i)+2,range,mid+1,h,to);
        }
        if(S->S[(2*i)+1].min > S->S[(2*1)+2].min)
            S->S[i].min = S->S[(2*1)+2].min;
        else 
            S->S[i].min = S->S[(2*i)+1].min;
        return S->S[i].min;
    }
}

int main(){
    int n,q;
    cin>>n;
    float *A = new float [n];
    for(int i=0;i<n;i++)
        cin>>A[i];
    cin>>q;
    sptr S1 = new seg_tree;
    sum_seg_create(S1,A,0,0,n-1);
    min_seg_create(S1,A,0,0,n-1);
    avg_seg_create(S1,A,0,0,n-1);
    max_seg_create(S1,A,0,0,n-1);

    while(q--){
        int type,L,R;
        cin>>type>>L>>R;

        if(type == 0){
            int from = A[L];
            update1(S1,0,L,0,n-1,R);
            update2(S1,L,R-from,0,0,n-1);
            update3(S1,L,R,0,0,n-1);
            // A[L] = R;
            // min_seg_create(S1,A,0,0,n-1);
        }
        else if(type == 1){
            cout<< query_min(S1,0,L,R,0,n-1)<< endl;
        }
        else if(type == 2){
            cout<< query_max(S1,0,L,R,0,n-1)<< endl;
        }
        else if(type == 3){
            cout<< query_sum(S1,0,L,R,0,n-1)<< endl;
        }
        else{
            float a = query_sum(S1,0,L,R,0,n-1)/(R-L+1); 
            cout<< a << endl;
        }
    }
    return 0;
}