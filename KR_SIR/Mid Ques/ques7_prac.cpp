#include <iostream>

using namespace std;

struct list1 {
    int data;
    list1* dlink;
    list1* next;
};

typedef list1* lptr1;

struct queue{
    int f,r,size;
    lptr1 elements[20];
};

void enqueue(queue &q, lptr1 s){
    if((q.r+1)%q.size == q.f)
        cout<< "Queue is full"<<endl;

    else{   
        if(q.f == -1){
            q.f=0;  q.r=0;
        }
        else{
            q.r = (q.r+1)%q.size;
        }
        q.elements[q.r] = s;
    }
}

lptr1 dequeue(queue &q){
    if(q.f == -1){
        cout<< "Queue is empty"<<endl;
        return NULL;
    }
    else{
        lptr1 temp = q.elements[q.f];

        if(q.f == q.r){
             q.f = q.r = -1;
        }
        else
            q.f = (q.f+1)%q.size;

        return temp;
    }
}

void insert(lptr1 &ML, int x){
    if (x != -1) {
        if(ML == NULL){
            ML = new list1;
            ML->data = x;
            ML->next = ML->dlink = NULL;
            cin>>x;
            insert(ML,x);
            return;
        }
        else{
            if(x != 0){
                lptr1 T1 = ML;
                while(T1->dlink != NULL)
                    T1 = T1->dlink; 
                lptr1 T = new list1;
                T->data = x;
                T->next = T->dlink = NULL;
                T1->dlink = T;
                cin>>x;
                insert(ML,x);
                return;
            }
            else if(x == 0){
                cin>>x;
                insert(ML->next,x);
                return;
            }
        }
    }
    else
        return;
}

void compare_print(lptr1 MLL){

    queue main, hold;
    main.f = main.r = hold.f = hold.r = -1;
    main.size = hold.size = 5;
    int *A = new int[12];
    enqueue(main,MLL);
    int i=0;

    while(main.f != -1){
        lptr1 a=NULL, b=NULL, min=NULL;
        a = dequeue(main);

        if(main.f != -1)
            b = dequeue(main);
        
        if(b == NULL)
            min = a;
        else{

            if(a->data < b->data){
                min = a;
                enqueue(main,b);
            }
            else{
                min = b;
                enqueue(main,a);
            }
        }
        A[i++] = min->data;

        if(min->next != NULL && min->dlink != NULL){
            if(min->next->data < min->dlink->data){
                enqueue(main,min->next);
                enqueue(hold,min->dlink);
            }
            else{
                enqueue(main,min->dlink);
                enqueue(hold,min->next);
            }
        }
        else if(min->next == NULL && min->dlink != NULL){
            enqueue(hold,min->dlink);
        }
        else if(min->next != NULL && min->dlink == NULL){
            enqueue(hold,min->dlink);
        }

        if(main.f - main.r == 0){
            lptr1 temp1, temp2;
            if(hold.f != -1)
                temp1 = dequeue(hold);
            else
                continue;

            if(hold.f != -1){
                temp2 = dequeue(hold);

                if(temp1->data < temp2->data){
                    enqueue(main, temp1);
                    enqueue(hold,temp2);
                }
                else{
                    enqueue(main, temp2);
                    enqueue(hold,temp1);
                }
            }
            else
                enqueue(main,temp1);
        }
    }
    for(int j=i-1;j>=0;j--)
        cout<< A[j] << " ";
    cout<< endl;
}

int main() {
    lptr1 ML = NULL;
    int x;

    cin>>x;
    if(x != -1)
    insert(ML, x);
    
    compare_print(ML);

    return 0;
}