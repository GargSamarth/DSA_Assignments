#include <iostream>

using namespace std;

struct stack{
    int size;
    int top;
    char A[50];
};

void push(stack &s, char x){
    if(s.top == s.size-1)
        cout<< "Stack is full"<<endl;
    else
        s.A[++s.top] = x;
}

char pop(stack &s){
    if( s.top == -1){
        cout<< "Stack is empty" << endl;
        return -1;
    }
    else
        return s.A[s.top--];
}

char peek(stack &s){
    if( s.top == -1){
        cout<< "Stack is empty" << endl;
        return -1;
    }
    else
        return s.A[s.top];
}

void symbols(stack &s1, stack &s2, char *ch, int n){

    int OSA[] = {'{', '[', '(', '<'};
    int CSA[] = {'}', ']', ')', '>'};

    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            if(ch[i] == OSA[j])
                push(s1,ch[i]);
            
            else if(ch[i] == CSA[j]){
                while(s1.A[s1.top] != OSA[j] && s1.top>-1)
                    push(s2,pop(s1));
                
                cout<< pop(s1) << ch[i]<< " ";
                while(s2.top > -1)
                    push(s1,pop(s2));
            }
        }
    }
    //while()
    cout<< endl;
}

int main(){

    char *ch;
    int n;
    
    stack s1,s2;
    s1.top = s2.top = -1;

    cin>>n;
    ch = new char [n];
    s1.size = s2.size = n;

    for(int i=0;i<n;i++)
        cin>>ch[i];

    symbols(s1,s2,ch,n);
    

    return 0;
}