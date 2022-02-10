// 3. Minimum number of bracket(symbol) reversals needed to make an expression balanced, if the given input expression is not balanced.

#include <iostream>

using namespace std;

void open_brace(char ch, int &a,int &b, int &c){
    switch(ch){
        case '{': ++a;
                break;
        case '[':  ++b;
                break;
        case '(':  ++c;
                break;
        default: return;
                break;
    }
}

void close_brace(char ch, int &a,int &b, int &c){
    switch(ch){
        case '}': if(a == 0) a=3;
                else --a;
                break;

        case ']':if(b == 0) b=3;
                else --b;
                break;

        case ')':if(c == 0) c=3;
                else --c;
                break;

        default: return;
                break;
    }
}

int symbols(string str , int n){
    int a=0,b=0,c=0;

    int OSA[] = {'{', '[', '('};
    int CSA[] = {'}', ']', ')'};
    if(n%2 != 0){
        cout<< "Impossible to balance"<<endl;
        return 0;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            if(str[i] == OSA[j])
                open_brace(str[i],a,b,c);
            
            else if(str[i] == CSA[j]){
                close_brace(str[i],a,b,c);
            }
        }
    }
    int sum;
    return (a+b+c)/2;
}

int main(){

    string str;
    cin>>str;
    int n = str.length();
    cout<< symbols(str,n)<<endl;

    return 0;
}