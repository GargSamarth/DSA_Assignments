#include <iostream>

using namespace std;

struct seg_tree{
    string S[20];
    int size;
};

typedef seg_tree *sptr;

string sum_seg_create(sptr S, string A, int i, int l, int h){
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

string query_sum(sptr S, int i, int sl, int sh, int l, int h){
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

int create(int *hash, string str, int l, int h){
    int count=0;
    for(int i=l;i<h;i++){
        hash[int(str[i])-97] = 1;
    }
    for(int i=0;i<26;i++){
        if(hash[i] == 1)
            count++;
    }
    return count;
}

int main(){
    int q;
    string str;
    cin>>str;
    cin>>q;

    sptr S = new seg_tree;
    sum_seg_create(S,str,0,0,str.length()-1);

    while(q--){

        int type;
        cin>>type;
        if(type == 1){
            int a; char b;
            cin>>a>>b;
            str[a-1] = b;
        }
        else{
            int a,b;
            int *hash = new int[26];
            cin>>a>>b;
            string temp_str = query_sum(S,0,a-1,b-1,0,str.length()-1);
            cout<< create(hash,temp_str,0,temp_str.length())<< endl;
        }
    }

    return 0;
}