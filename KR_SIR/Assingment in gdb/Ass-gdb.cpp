// 5. Recursive function to convert prefix expression to postfix expression

//       Prefix : *+AB-+CDEF        postfix : AB+CD+E-*F

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

void swap(int &a, int &b){
    int temp;
    a = b;
    b = temp;
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
        default: return 4;
                break;
    }
    return 4;
}

void braces(char &ch){

    int OSA[] = {'{', '[', '(', '<'};
    int CSA[] = {'}', ']', ')', '>'};

        for(int j=0;j<4;j++){
            if(ch == OSA[j])
                ch = CSA[j];
            
            else if(ch == CSA[j])
                ch = OSA[j];
        }
}

char *infix_to_postfix(string str, int n){

    stack s;
    s.top = -1;

    s.size = n;

    char *ch = new char [n];
    int j=0,z=0;
    for(int i=0;i<n;i++){
        if( (int(str[i]) > 47) && (int(str[i]) < 58) ){
            ch[j++] = str[i]; 
        }
            
        else{
            z++;
            if(s.top == -1 || priority(str[i])<priority(s.A[s.top]))
                push(s,str[i]);

            else{
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

char *infix_to_prefix(string str, int &n){

    stack s;
    s.top = -1;
    s.size = n;

    for(int i = 0;i<n;i++){
        push(s,str[i]);
    }

    for(int i = 0;i<n;i++){
        str[i] = pop(s);
    }

    for(int i = 0;i<n;i++){
        braces(str[i]);
    }

    s.top = -1;

    s.size = n;

    char *ch = new char [n];
    int j=0;

    for(int i=0;i<n;i++){
        if( (int(str[i]) > 47) && (int(str[i]) < 58) ){
            ch[j++] = str[i]; 
        }
            
        else{
            if(s.top == -1 || str[i] == '(' || priority(str[i]) < priority(s.A[s.top]) )
                push(s,str[i]);

            else{
                if(str[i] == ')'){
                    while(s.A[s.top] != '(')
                        ch[j++] = s.A[s.top--];

                    s.top--;
                }
                else{
                    while( priority(str[i]) >= priority(s.A[s.top]) && s.top>=0 ){
                        ch[j++] = s.A[s.top--];
                    }
                    s.A[++s.top] = str[i];
                }
            }
        }
    }
    while(s.top>-1)
        ch[j++] = s.A[s.top--];

    s.top = -1;

    for(int i = 0;i<j;i++){
        push(s,ch[i]);
    }

    for(int i = 0;i<j;i++){
        ch[i] = pop(s);
    }
    n = j;

    return ch;
}

char *postfix_to_infix(string str, int n){

    stack s;
    s.top = -1;

    s.size = 2*n;

    char *ch = new char [n];

    for(int i=0;i<n;i++){
        if( (int(str[i]) > 47) && (int(str[i]) < 58) ){
            //ch[j++] = str[i]; 
            push(s,str[i]);
            push(s,' ');
        }
            
        else{
            
            pop(s);

            char temp[10];
            int z=-1;

            while(s.A[s.top] != ' ')
                temp[++z] = pop(s);

            pop(s);
            push(s,str[i]);

            while(z>-1)
                push(s,temp[z--]);
            push(s,' ');

        }
    }
    pop(s);
    int j=n;
    while(s.top>-1)
        ch[--j] = pop(s);

    return ch;
}

char *prefix_to_infix(string str, int n){

    stack s;
    s.top = -1;

    s.size = 2*n;

    char *ch = new char [n];

    for(int i = 0;i<n;i++){
        push(s,str[i]);
    }

    for(int i = 0;i<n;i++){
        str[i] = pop(s);
    }

    for(int i=0;i<n;i++){
        if( (int(str[i]) > 47) && (int(str[i]) < 58) ){
            //ch[j++] = str[i]; 
            push(s,str[i]);
            push(s,' ');
        }
            
        else{
            
            pop(s);

            char temp[10];
            int z=-1;

            while(s.A[s.top] != ' ')
                temp[++z] = pop(s);

            pop(s);
            push(s,str[i]);

            while(z>-1)
                push(s,temp[z--]);
            push(s,' ');

        }
    }
    pop(s);
    int j=0;
    while(s.top>-1)
        ch[j++] = pop(s);
    
    return ch;

}

char *prefix_to_postfix(string str, int n){


    char *ch = new char [n];

    ch = prefix_to_infix(str,n);
    
    
    string str1;
    for(int i=0;i<n;i++)
        str1+=ch[i];
    delete ch;
    ch = new char[n];
    ch = infix_to_postfix(str1,n);
    return ch;
    
}

char *postfix_to_prefix(string str, int n){

    char *ch = new char [n];

    ch = postfix_to_infix(str,n);
    
    
    string str1;
    for(int i=0;i<n;i++)
        str1+=ch[i];

    cout<<endl<< "--------" << str1<<endl;
    delete ch;
    ch = new char[n];
    ch = infix_to_prefix(str1,n);
    return ch;
}

void program_control(int x){

    string str;
    cout<< "Type your string here: ";
    cin>>str;
    cout<< endl;
    int n = str.length();
    char *ch = new char [n];

    switch(x){
        case 1: ch = infix_to_prefix(str,n);
                break;
        case 2: ch = infix_to_postfix(str,n);
                break;
        case 3: ch = prefix_to_infix(str,n);
                break;
        case 4: ch = prefix_to_postfix(str,n);
                break;
        case 5: ch = postfix_to_infix(str,n);
                break;
        case 6: ch = postfix_to_prefix(str,n);
                break;
        default: cout<< "Incorrect choice, please choose again" << endl;
                break;
    }
    cout<< "Your output is: ";
    for(int i = 0;i<n;i++){
        cout<< ch[i];
    }
    cout<< endl << endl;
    return;
}

int main(){
    int choice;
    do{
        cout<< "\tPlease choose: "<<endl;
        cout<< "1 for Infix to prefix"<<endl;
        cout<< "2 for Infix to postfix"<<endl;
        cout<< "3 for Prefix to infix"<<endl;
        cout<< "4 for Prefix to postfix"<<endl;
        cout<< "5 for Postfix to infix"<<endl;
        cout<< "6 for Postfix to prefix"<<endl;
        cout<< "7 to quit"<<endl;

        cin>>choice;
        if(choice != 7)
        program_control(choice);

    }while(choice != 7);
    
    return 0;
}