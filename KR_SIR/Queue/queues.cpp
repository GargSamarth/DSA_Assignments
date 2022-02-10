#include <iostream>

using namespace std;

union U
{
    int x;
    float ft;
    char ch;
};

struct queue{
    int size;
    int f;
    int r;
    int tag[50];
    U elements[100];
};

void enqueue(queue &q, U s){
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

U dequeue(queue &q){
    U temp;
    if(q.f == -1){
        cout<< "Queue is empty"<<endl;
        return temp;
    }
    else{
        temp = q.elements[q.f];

        if(q.f == q.r){
             q.f = q.r = -1;
        }
        else
            q.f = (q.f+1)%q.size;

        return temp;
    }
}

void print(queue q, int n){

        for(int i=0;i<=n;i++){

            U temp;
            temp = dequeue(q);

            if(q.tag[i] == 3 && temp.ch == '.'){
                cout<< endl;
                continue;
            }

            if(q.tag[i] == 1)
                cout<< temp.x << "\t";

            else if(q.tag[i] == 2)
                cout<< temp.ft << "\t";

            else if(q.tag[i] == 3)
                cout<< temp.ch << "\t";

        }
        
        cout<< endl;
}

int main(){
    queue q;
    
    q.f = q.r = -1;
    int size1, size2,x,i=-1;
    float ft;
    char ch;
    
    cout<< "enter the size of queue: ";
    cin>>size2;
    q.size = 30;

    while(size2--){

        cout<< "enter the size of current element: ";
        cin>>size1;
        int n;

        U temp;

        while(size1--){

            cout<< "Enter 1 for int, 2 for float, 3 for char: ";
            cin>>n;

            if(n==1){
                q.tag[++i] = 1;
                cin>>x;
                temp.x = x;
                enqueue(q,temp);
            }
            else if(n==2){
                q.tag[++i] = 2;
                cin>>ft;
                temp.ft = ft;
                enqueue(q,temp);
            }
            else if(n == 3){
                q.tag[++i] = 3;
                cin>>ch;
                temp.ch = ch;
                enqueue(q,temp);
            }
            else
                cout<< "Incorrect input please try again"<< endl;
                
        }
        q.tag[++i] = 3;
        temp.ch = '.';
        enqueue(q,temp);
    }

    cout<< endl;
    print(q,i);

    return 0;
}