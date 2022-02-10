#include <iostream>

using namespace std;

struct queue{
    int size;
    int f;
    int r;
    int elements[50];
};

struct stack{
    int size;
    int top;
    int A[50];
};

void push(stack &s, int x){
    if(s.top == s.size-1)
        cout<< "Stack is full"<<endl;
    else
        s.A[++s.top] = x;
}

int pop(stack &s){
    if( s.top == -1){
        cout<< "Stack is empty" << endl;
        return 0;
    }
    else
        return s.A[s.top--];
}

void enqueue(queue &q, int s){
    if((q.r+1)%q.size == q.f)
        cout<< "Queue is full"<<endl;

    else{
        if(q.f == -1){
            q.f=0;  
            q.r=0;
        }
        else{
            q.r = (q.r+1)%q.size;
        }
        q.elements[q.r] = s;
    }
}

int dequeue(queue &q){
    if(q.f == -1){
        cout<< "Queue is empty"<<endl;
        return 0;
    }
    else{
        int s = q.elements[q.f];

        if(q.f == q.r){
             q.f = q.r = -1;
        }

        else{
            q.f = (q.f+1)%q.size;
        }

        return s;
    }
}

void do_interleave(queue &q, int n){

    stack s;
    s.top = -1;
    s.size = n/2;

    for(int i=0;i<n/2;i++){
        int temp = dequeue(q);
        //cout<< temp << "----- 2-----"<< q.f << " && "<< q.r <<endl;
        push(s,temp);
    }

    for(int i=0;i<n/2;i++){
        int temp = pop(s);
        //cout<< temp << "------- 3-----"<< q.f << " && "<< q.r <<endl;
        enqueue(q,temp);
    }

    for(int i=0;i<n/2;i++){
        int temp = dequeue(q);
        //cout<< temp << "------- 4-----"<< q.f << " && "<< q.r <<endl;
        enqueue(q,temp);
    }

    for(int i=0;i<n/2;i++){
        int temp = dequeue(q);
        //cout<< temp << "------- 5-----"<< q.f << " && "<< q.r <<endl;
        push(s,temp);
    }

    for(int i=0;i<n/2;i++){

        int temp = pop(s);
        //cout<< temp << "------- 6-----"<< q.f << " && "<< q.r <<endl;
        enqueue(q,temp);
        temp = dequeue(q);
        //cout<< temp << "------- 7-----"<< q.f << " && "<< q.r <<endl;
        enqueue(q,temp);

    }
    return;
}

int main(){
    queue q;
    q.r = q.f = -1;
    int n;
    cin>>n;
    q.size = n;

    int *x = new int [n];
    for(int i=0;i<n;i++){
        cin >> x[i];
        //cout<< x[i]<< " ";
        enqueue(q,x[i]);
    }
    //cout<< "------------------------------------------"<<endl;
    delete x;

    do_interleave(q,n);

    for(int i=0;i<n;i++){
        cout<< dequeue(q) << " ";
    }

    cout<< endl;
    return 0;
}