#include <iostream>
#include <math.h>

using namespace std;

struct stack{
    int top;
    int size;
    char A[50];

};

void push(stack &s, int x){
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

int evaluate(int opr2,int opr1, char oprd){
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

// infix to postfix

char *infix_to_postfix(string str, int n, int *brk_pts){

    stack s;
    s.top = -1;

    s.size = n;

    char *ch = new char [n];
    int j=0,z=0;
    brk_pts = new int [20];
    for(int i=0;i<n;i++){
        if( (int(str[i]) > 47) && (int(str[i]) < 58) ){
            ch[j++] = str[i]; 
        }
            
        else{
            brk_pts[z] = j-1;
            z++;
            if(s.top == -1 || int(str[i])<int(s.A[s.top]))
                push(s,str[i]);

            else{                   //if(int(str[i])<=int(stk.A[stk.top]))
                    while( int(str[i]) >= int(s.A[s.top]) && s.top>=0 ){
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

// postfix evaluation

int evaluate_postfix(char *ch, int n, int *brk_pts){
    
    stack s;
    s.top = -1;

    s.size = n;

    //char *ch = new char [n];
    int j=0;

    for(int i=0;i<n;i++){
        if( (int(ch[i]) > 47) && (int(ch[i]) < 58) ){
            push(s,ch[i]);
        }
            
        else{
            int temp1 = evaluate(int(pop(s))-48, int(pop(s))-48, ch[i]) + 48;
            char temp2 = (char)temp1;
            s.A[++s.top] = temp2;
            }
        }
    int ans = int(s.A[s.top])-48;
    return -ans;
}

int main(){

    cout<< endl <<  "Enter the infix expression: ";
    string str;
    cin>>str;

    int n = str.length();
    char *ch = new char [n];
    int *brk_pts;
    ch = infix_to_postfix(str,n,brk_pts);

    for(int i=0;i<n;i++)
        cout<< ch[i]<< " ";

    cout<<endl;

    int ans = evaluate_postfix(ch,n,brk_pts);
    cout<< endl << "========== " << ans << " ===========" << endl;
    
    return 0;
}