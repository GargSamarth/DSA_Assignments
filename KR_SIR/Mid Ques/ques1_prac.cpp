
#include <iostream>

using namespace std;

struct node{
    char data;
    node *next;
};

typedef node* lptr;

struct stack{

    int size;
    int top;
    lptr elements[20];
};

void push(stack &s, lptr x){
    if(s.top == s.size-1)
        cout<< "Stack is full"<<endl;
    else
        s.elements[++s.top] = x;
}

lptr pop(stack &s){
    if( s.top == -1){
        cout<< "Stack is empty" << endl;
        return NULL;
    }
    else
        return s.elements[s.top--];
}

lptr peek(stack &s){
    if( s.top == -1){
        //cout<< "Stack is empty" << endl;
        return NULL;
    }
    else
        return s.elements[s.top];
}

void insert(lptr LL, char ch){
    
    while(LL->next != NULL){
        LL = LL->next;
    }
    
    lptr T = new node;
    T->data = ch;
    T->next = NULL;
    LL->next = T;
}

int main(){
    stack s1;
    s1.top = -1;
    s1.size = 5;
    
    char ch;
    
    do{
        cin>>ch;

        if(ch != '*'){
            lptr LL = new node;
            LL->data = ch;
            LL->next = NULL;
            cin>> ch;
            while(ch != '#' && ch != '*'){
                insert(LL, ch);
                cin>>ch;
            }
            push(s1,LL);
        }
        
    }while(ch != '*');
    
    while(s1.top != -1){
        lptr T = pop(s1);
        
        while(T != NULL){
            cout<< T->data << " ";
            T = T->next;
        }
        cout<< endl;
    }
    
    
    return 0;
}
