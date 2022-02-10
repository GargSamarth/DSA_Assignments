#include <iostream>
#define m 4
using namespace std;


struct mstnode{
    int cnt;
    int keys[m-1];
    mstnode *cptr[m];
};

typedef mstnode *mstptr;

void insert1(mstptr &MT, int x){
    if(MT->cnt == 0 || (MT->cnt < m-1 && MT->keys[MT->cnt-1] < x)){
        MT->keys[MT->cnt++] = x;
    }
    else{
        int i=0;
        while( i < m-1 && MT->keys[i] < x)
            i++;
        if(MT->cptr[i] == NULL){
            MT->cptr[i] = new mstnode;
            for(int j=0;j<m;j++)
                MT->cptr[i]->cptr[j] = NULL;
            MT->cptr[i]->cnt = 0;
        }
        insert1(MT->cptr[i],x);
    }
}

void printinoder(mstptr MT)
{
	if(MT!=NULL)
	{
		for(int i=0;i<=MT->cnt;i++)
		{
			printinoder(MT->cptr[i]);
			if(i < MT->cnt)
			    cout<<MT->keys[i]<<" ";
		}
	}
}

void insert2(mstptr MT, int x){
    if(MT->cnt < m-1 ){
        if(MT->cnt == 0 || MT->keys[MT->cnt-1] < x)
            MT->keys[MT->cnt++] = x;
        else{
            int j = MT->cnt - 1;
            while (j >= 0 && MT->keys[j] > x){  
                MT->keys[j + 1] = MT->keys[j];
                j = j - 1;  
            }
            MT->keys[j + 1] = x;
            MT->cnt++;
        }
    }
    else{
        int i=0;
        while(i < m-1 && MT->keys[i] < x )
            i++;
        if(MT->cptr[i] == NULL){
            MT->cptr[i] = new mstnode;
            for(int j=0;j<m;j++)
                MT->cptr[i]->cptr[j] = NULL;
            MT->cptr[i]->cnt = 0;
        }
        insert2(MT->cptr[i],x);
    }
}

int main(){
    mstptr MT = new mstnode;
    for(int i=0;i<m;i++)
        MT->cptr[i] = NULL;
    MT->cnt = 0;

    int x,t;
    cin>>t;

    cin>>x;
    while(x != 0){
        insert1(MT,x);
        cin>>x;
    }
    printinoder(MT);
    cout<< endl;

    mstptr MT1 = new mstnode;
    for(int i=0;i<m;i++)
        MT1->cptr[i] = NULL;
    MT1->cnt = 0;
    cin>>t;

    cin>>x;
    while(x != 0){
        insert2(MT1,x);
        cin>>x;
    }
    printinoder(MT1);
    cout<< endl;
    return 0;
}