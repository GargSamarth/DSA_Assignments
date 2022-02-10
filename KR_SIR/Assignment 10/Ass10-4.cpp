//4. Recursive postfix evaluation ( without a stack)

#include <iostream>

using namespace std;

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

int recursion(char *array, int j, char *ch, int n){
    
    if(n>-1){
        if( (int(ch[n]) > 47) && (int(ch[n]) < 58) ){
            array[++j] = ch[n];
        }
            
        else{
            int temp1 = evaluate(int(array[j--])-48, int(array[j--])-48, ch[n]) + 48;
            char temp2 = (char)temp1;
            array[++j] = temp2;
            
        }
        return recursion(array,j,ch,n-1);
    }
    else{
        int ans = int(array[j])-48;
        return ans;
    }
}

int evaluate_postfix(char *ch, int n){

    char *reverse = new char [n];

    for(int i=0;i<n;i++)
        reverse[i] = ch[n-1-i];
    
        

    char *array = new char [n];
    int ans=0;
    ans = recursion(array,-1,reverse,n-1);
    return ans;
}

int main(){
    int n;
    cout<< "Enter the number of terms: ";
    cin>>n;
    char *ch = new char[n];
    cout<< endl <<  "Enter the postfix expression: ";
    for(int i=0;i<n;i++)
        cin>> ch[i];

    cout<<endl;

    int ans = evaluate_postfix(ch,n);
    cout<< endl << "========== " << ans << " ===========" << endl;
    
    return 0;
}