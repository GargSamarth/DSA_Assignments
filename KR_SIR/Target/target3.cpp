#include <iostream>

using namespace std;

struct multi_ll{
    int data;
    int num;
    int num2;
    multi_ll *next[3];
};

//type_define
typedef multi_ll *lptr;

struct stack{
    int size;
    int top;
    lptr elements[50];
};

void func(lptr ML, stack stk, int &flag, int t);

void insert(lptr ML, int num){

    if(num != 0){

        if(num == 1){

            lptr T = new multi_ll;
            cin>> T->data;
            T->num = T->num2 = 0;

            while(ML->next[0] != NULL)
                ML = ML->next[0];

            ML->num = ML->num2 = 1;

            ML->next[0] = T;

            for(int i=0;i<3;i++)
                T->next[i] = NULL;

            cin>>num;

            if(num != 0)
                insert(ML,num);
        }

        else if(num > 1){

            while(ML->next[0] != NULL)
                ML = ML->next[0];

            ML->num = ML->num2 = num;

            for(int i=0;i<num;i++){

                lptr T = new multi_ll;

                for(int i=0;i<3;i++)
                    T->next[i] = NULL;
                T->num = T->num2 = 0;
                cin>> T->data;
                int num2;
                cin>>num2;

                if(num2 != 0)
                    insert(T,num2);

                ML->next[i] = T;
            }
        }
        
    }
    return;
}

void push(stack &s, lptr x){
    if(s.top == s.size-1)
        cout<< "Stack is full"<<endl;
    else
        s.elements[++s.top] = x;
}

lptr pop(stack &s){
    lptr temp;
    if( s.top == -1){
        cout<< "Stack is empty" << endl;
        return temp;
    }
    else
        return s.elements[s.top--];
}

lptr peek(stack &s){
    lptr temp;
    if( s.top == -1){
        cout<< "Stack is empty" << endl;
        return temp;
    }
    else
        return s.elements[s.top];
}

void find(lptr ML, int k, lptr &ptr){

    if(ML != NULL && ML->num >= 0){

        if(ML->num == 1){
            if(ML->data == k){
                ptr = ML;
            }
            find(ML->next[0],k,ptr);
        }

        else{
            if(ML->data == k){
                ptr = ML;
            }
            for(int i=0;i<ML->num;i++)
                find(ML->next[i],k,ptr);
        }

    }

}

void reset(lptr ML){

    if(ML != NULL){
        if(ML->num2 == 1){
            ML->num = ML->num2;
            reset(ML->next[0]);
        }

        else{
            ML->num = ML->num2;
            for(int i=0;i<ML->num2;i++)
                reset(ML->next[i]);
        }
    }
    return;
}

void target(lptr ML, int s, int t){
    int count = 1;

    lptr T = ML;
    lptr ptr;

    find(T, s, ptr);
    stack stk;
    stk.top = -1;
    stk.size = 18;
    T = ptr;

    do{

        for(;;){
            push(stk,T);

            if(T->num == 1){
                T = T->next[0];
            }

            else if(T->num == 0)
                break;

            else{
                    lptr temp = new multi_ll;
                    temp->data = -1;
                    int index = T->num-1;
                    T->num--;
                    T = T->next[index];
                    push(stk,temp);                   
            }  
        }
        if(stk.top != -1 && peek(stk)->data != t){
            while(stk.top != -1 && peek(stk)->data != -1)
                pop(stk);

            pop(stk);
            T = pop(stk);
        }
        
    }while(peek(stk)->data != t);

    stack temp;
    temp.top = -1;
    temp.size = 20;

    while(stk.top != -1)
        push(temp,pop(stk));

    while(temp.top != -1){
        int x = pop(temp)->data;

        if(x != -1)
        cout<< x << " ";
    }
    reset(ML);
    cout<< endl;
}

int main(){
    lptr ML = new multi_ll;
    
    for(int i=0;i<3;i++)
        ML->next[i] = NULL;

    int n;
    cin>>ML->data;

    cin>>n;
    insert(ML,n);
    int s, t;
    cin>>s>>t;
    lptr ptr = ML;
    target(ptr,s,t);
    cin>>s>>t;
    ptr = ML;
    target(ptr,s,t);

    return 0;
}