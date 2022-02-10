#include <iostream>

using namespace std;

//structure
struct RTnode{
    string data;
    RTnode *lc;
    RTnode *rc;
};

//define
typedef RTnode *rtptr;

void construct(string str, rtptr &R, int i, int len){
        if(R == NULL){
            R = new RTnode;
            R->lc = R->rc = NULL;
            R->data = str;
            return;
        }
        else{
            if(str[i] == '1')
                construct(str,R->rc,(i+1)%len,len);
            else if(str[i] == '0')
                construct(str,R->lc,(i+1)%len,len);
        }
}

void preorder(rtptr T){
    if(T != NULL){
        cout<< T->data << " ";
        preorder(T->lc);
        preorder(T->rc);
    }
}

int main(){
    rtptr R = NULL;
    string in;
    cin>>in;

    while(in != "-1"){
        int len = in.length();
        construct(in,R,0,len);
        cin>>in;
    }

    preorder(R);
    cout<< endl;
}