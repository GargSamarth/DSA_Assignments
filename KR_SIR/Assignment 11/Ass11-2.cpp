#include <iostream>

using namespace std;

struct stack{
    int top;
    int size;
    char elements[50];
};

void push(stack &s, char x){
    if(s.top == s.size-1)
        cout<< "Stack is full";
    else
        s.elements[++s.top] = x;
}

char pop(stack &s){
    if(s.top == -1){
        cout<< "Stack is empty";
        return -1;
    }
    else
        return s.elements[s.top--];
}

char peek(stack &s){
    if(s.top == -1){
        cout<< "Stack is empty";
        return -1;
    }
    else
        return s.elements[s.top];
}

int score_calculator(string str, int n){

    int count = 0,flag = 0,ans=0;
    stack s,temp;
    s.top = temp.top = -1;
    s.size = temp.size = n;

        int sum = 0;

        for(int i=0;i<n;i++){
            if(str[i] == '('){
                ans = ans + sum;
                sum = 0;
                count ++;
                flag = 1;
                push(s,str[i]);
            }
            
            else if( str[i] == ')'){
                pop(s);
                if(flag == 1){
                    sum =  1;
                }
                else if(flag != 1 && count>0){
                    sum = sum * 2;
                }
                else{
                    ans = ans + sum;
                    ans = ans * 2;
                }
                flag--;
                count--;
            }
        }
        if(flag == 0)
        ans+=sum;

    return ans;
}

int main(){
    string str;

    cin >>str;
    cout<< score_calculator(str,str.length())<< endl;

    return 0;
}