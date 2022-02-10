#include <iostream>
using namespace std;

struct gtnode{
	char data;
	struct gtnode *ns;
	struct gtnode *fc;
};
typedef struct gtnode *gtptr;
struct queue
{
    int r;
    int f;
    int size;
    gtptr a[50];
};
void enqueue(struct queue &q,gtptr x)
{
	if((q.r+1)%q.size==q.f)
	cout<<"queue full";
	else{
		if(q.f==-1)
		q.f=0 , q.r=0;
		else 
		q.r=(q.r+1)%q.size;
		q.a[q.r]=x;
	}
}
gtptr dequeue(struct queue &q)
{
	if(q.f==-1){
	    cout<<"queue empty";
        return NULL;
    }
	else
	{
	    gtptr t;
		if(q.f==q.r)
		{
		t=q.a[q.f];
		q.r=-1;
		q.f=-1;
		}
		else{
			t=q.a[q.f];
			q.f=(q.f+1)%q.size;
		}	
		return t;
	}
}

void insert(gtptr &T,char ch)
{
    if(T==NULL)
    {
        T=new (gtnode);
        T->data=ch;
        T->ns=NULL;
        T->fc=NULL;
    }
        cin>>ch;
        if(ch!='.')
        insert(T->fc,ch);
        cin>>ch;
        if(ch!='.')
        insert(T->ns,ch);
}

void print_level(gtptr T,struct queue q)
{
    if(T==NULL)
    return;
    enqueue(q,T);
    enqueue(q,NULL);
    while(q.r!=0)
    {
        gtptr T1=dequeue(q);
        if(T1==NULL)
        {
        	cout<<endl;
        	enqueue(q,NULL);
		}
		else
		{
		    while(T1!=NULL)
		    {
		        if(T1->fc!=NULL)
		        enqueue(q,T1->fc);
		        cout<<T1->data<<" ";
		        T1=T1->ns;
		    }
			
		}
    }
}

int main()
{
    gtptr T = NULL;
    struct queue q;
    q.size=20;
    q.f=-1;
    q.r=-1;
    char x;
    cin>>x;
    insert(T,x);
    print_level(T,q);
}