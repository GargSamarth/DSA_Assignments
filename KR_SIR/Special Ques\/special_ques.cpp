#include <iostream>

using namespace std;

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
            cout<< create(hash,str,a-1,b)<< endl;
        }
    }
    return 0;
}