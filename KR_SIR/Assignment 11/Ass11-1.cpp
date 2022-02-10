#include <iostream>

using namespace std;

struct stack{

    int size;
    int top;
    int elements[50];
};

void push(stack &s, int x){
    if(s.top == s.size-1)
        cout<< "Stack is full"<<endl;
    else
        s.elements[++s.top] = x;
}

int pop(stack &s){
    if( s.top == -1){
        cout<< "Stack is empty" << endl;
        return -1;
    }
    else
        return s.elements[s.top--];
}

int peek(stack &s){
    if( s.top == -1){
        cout<< "Stack is empty" << endl;
        return -1;
    }
    else
        return s.elements[s.top];
}

void sort(stack &s1, int n){

    stack s2;   s2.top = -1;    s2.size = n;
    int temp = 0, ptr = s1.top;

    while(ptr > 0){
        if( s1.elements[ptr] < s1.elements[ptr-1] )
            ptr--;

        else{
            while(s1.top >= ptr){
                push(s2,pop(s1));
            }

            temp = pop(s1);
            int flag = 0;

            while(s2.top>-1){
                push(s1,pop(s2));

                if( (s2.elements[s2.top] < temp || s2.top == -1) && (flag == 0)){
                    push(s1,temp);
                    flag = 1;
                }
            }

            temp = 0;
        }
    }

}

int main(){
    stack s1;

    s1.top = -1;

    cin>>s1.size;

    for(int i=0;i<s1.size;i++){
        int n;
        cin>>n;
        push(s1,n);
    }
    
    sort(s1,s1.size);

    for(int i=0;i<s1.size;i++){
        cout<< pop(s1) << " ";
    }
    cout<< endl;
    return 0;
}