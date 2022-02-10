#include<iostream>
using namespace std;

struct btnode
{
    struct btnode* left;
    int data;
    struct btnode* right;
};

void create(struct btnode* & , int );

int main()
{
    btnode* T=NULL; int k;
    cout<<"\nEnter first element: ";cin>>k;
    create(T,k);
    return 0;
}

void create(struct btnode* &T, int k)
{	
	int ch;
    if (T==NULL)
    {
        T = new(btnode);
        T->left=NULL;
        T->right=NULL;
        T->data=k;
    }
    cout<<"\nEnter left child for "<<k<<": "; cin>>ch;
    if(ch!=0){ 
		create(T->left,ch);
	}
    cout<<"\nEnter right child for "<<k<<": "; cin>>ch;
    if(ch!=0) create(T->right,ch);

}