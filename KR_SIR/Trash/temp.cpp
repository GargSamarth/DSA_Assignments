#include<iostream>
using namespace std;
typedef struct btnode * btptr;
#define null NULL

struct btnode{
    btptr lc,rc;
    char data;
};

void insert(btptr &t,char k)
{
    if(t==null){
        t=new(btnode);
        t->data=k;
        t->rc=t->lc=null;
    }
    char ch;
    cout<<"enter lc of "<<k<<endl;
    cin>>ch;
    if(ch!='.')insert(t->lc,ch);
    cout<<"enter rc of "<<k<<endl;
    cin>>ch;
    if(ch!='.')insert(t->rc,ch);
}

void serialize(btptr t,string &s)
{
    if(t==null){
        s=s+".";
        return;
    }
    s=s+""+t->data;
    serialize(t->lc,s);
    serialize(t->rc,s);
}
int findIndex(string ldr,char c)
{
    for(int i=0;i<9;i++){
        if(ldr[i]==c)return i;
    }
    return 0;
}
void construct(btptr &T,string ldr,string dlr,int l,int h)
{
    static int j=0;
    if(l>h)return;
    T=new(btnode);
    T->data=dlr[j];
    T->lc=T->rc=null;
    int i = findIndex(ldr,dlr[j]);
    j++;
    if(l==h)return;
    construct(T->lc,ldr,dlr,l,i-1);
    construct(T->rc,ldr,dlr,i+1,h);
}
int main()
{
    btptr t=null;
    string s="";
    string ldr="BMFDAJHRK";
    string dlr="AMBDFJRHK";
    construct(t,ldr,dlr,0,9);
    serialize(t,s);
    cout<<s;
    return 0;
}