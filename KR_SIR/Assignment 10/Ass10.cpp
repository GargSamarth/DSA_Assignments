// 1. Infix expression evaluation using a single stack

// 2. Iterative Quick sort

// 3. Minimum number of bracket(symbol) reversals needed to make an expression balanced, if the given input expression is not balanced.

// 4. Recursive postfix evaluation ( without a stack)

// 5. Recursive function to convert prefix expression to postfix expression

//       Prefix : *+AB-+CDEF        postfix : AB+CD+E-*F


#include <iostream>

using namespace std;

struct stack{
    int top;
    int size;
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

int priority(char ch){
    
    switch(ch){
        case '-': return 3;
                break;
        case '+': return 2;
                break;
        case '*': return 1;
                break;
        case '/': return 0;
                break;
        default: return -1;
                break;
    }
    return -1;
}

int evaluate(int opr1,int opr2, char oprd){
    switch(oprd){
        case '+': return opr1+opr2;
                break;
        case '-': return opr1-opr2;
                break;
        case '*': return opr1*opr2;
                break;
        case '/': return opr1/opr2;
                break;
        default: return -12365;
                break;
    }
}

//Ques 3 - infix to postfix

char *infix_to_postfix(string str, int n){

    stack s;
    s.top = -1;

    s.size = n;

    char *ch = new char [n];
    int j=0;

    for(int i=0;i<n;i++){
        if( (int(str[i]) > 47) && (int(str[i]) < 58) ){
            ch[j++] = str[i]; 
        }
            
        else{
            if(s.top == -1 || priority(str[i])<priority(s.A[s.top]))
                push(s,str[i]);

            else{                   //if(int(str[i])<=int(stk.A[stk.top]))
                    while( priority(str[i]) >= priority(s.A[s.top]) && s.top>=0 ){
                        ch[j++] = s.A[s.top--];
                    }
                    s.A[++s.top] = str[i]; 
            }
        }
    }
    while(s.top>-1)
        ch[j++] = s.A[s.top--];

    return ch;
}

// Ques 3 - postfix evaluation

int evaluate_postfix(char *ch, int n){
    
    stack s;
    s.top = -1;

    s.size = n;

    int j=0;

    for(int i=0;i<n;i++){
        if( (int(ch[i]) > 47) && (int(ch[i]) < 58) ){
            push(s,ch[i]);
        }
            
        else{
            int temp1 = evaluate(int(s.A[s.top--])-48, int(s.A[s.top--])-48, ch[i]) + 48;
            char temp2 = (char)temp1;
            s.A[++s.top] = temp2;
            }
        }
    int ans = int(s.A[s.top])-48;
    return ans;
}

int main(){

    cout<< endl <<  "Enter the infix expression: ";
    string str;
    cin>>str;

    int n = str.length();
    char *ch = new char [n];
    ch = infix_to_postfix(str,n);

    for(int i=0;i<n;i++)
        cout<< ch[i]<< " ";

    cout<<endl;

    int ans = evaluate_postfix(ch,n);
    cout<< endl << "==========" << ans << "===========" << endl;
    
    return 0;
}