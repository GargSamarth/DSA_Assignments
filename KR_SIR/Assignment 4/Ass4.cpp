#include <iostream>

using namespace std;

//ques 4

string Fibonacci(int n){
    
    if(n==0)
        return "a";
    else if(n==1)
        return "bc";
    else{
       return (Fibonacci(n-2) + Fibonacci(n-1));
    }
}

char charachter(int n,int k){
    string s = Fibonacci(n);
    return s[k-1];
}


//ques 1
void sumItUp(int n, int i,int tag){
    static int temp = n,r=0;
    if(n > 0){
        cout<< n;
        if(i>1){
            int t=0;
            if(i > temp/2)
                cout<< " + ";
            else{
                cout<< " + ";
                cout<< i;
                cout<< ", ";   
            }
            sumItUp(n,0,2);
            if(tag == 1)
                r++;

            sumItUp(i-r,t+1,2);
        }
        
        else if(i == 1){
            cout<< " + " << i << ", ";
            if(tag == 2)
                return;
        }
        
        else if(i==0 && n == temp){
            cout<< ", ";
            if(tag == 2)
                return;
        }
        
        else if(i==0 && n < temp){
            cout<< " + ";
            return;
        }    
        sumItUp(n-1,i+1,1);
    }
    return ;
}


//ques 2
void subsequesnt(string str1, string str2, int l1, int l2){

    if(str1[l1] == str2[l2] && l1>-1 && l2>-1){
        //cout<< endl << l1 << "&" << l2 <<endl;
        subsequesnt(str1,str2,l1-1,l2-1);
    }

    else if(str1[l1] != str2[l2] && l1>-1 && l2>-1){
        //cout<< endl << l1 << "&" << l2 <<endl;
        subsequesnt(str1,str2,l1,l2-1);
    }

    else{
        //cout<< endl << l1 << "&" << l2 <<endl;
        if(l1 == -1)
            cout<< boolalpha << true << endl;
        else 
            cout<< boolalpha << false << endl;
    }
}

//ques 3

int fact(int n){
    if(n==1)
        return 1;
    else
        return n*fact(n-1);
}

int Noofparentheses(int n){
    int num = fact(2*n);
    int denom = fact(n+1)*fact(n);
    return num/denom;
}


void parentheses(int n, int tag){
    if(n>0 && tag==1){
        cout<< "(";
        //if()
        parentheses(n,2);
        
    }
    else if(n>0 && tag==2){
        cout<< ")";
        parentheses(n-1,1);
    }
}


int main(){
    cout<< charachter(4,3) << endl;
    int n;
    cin>>n;
    sumItUp(n,0,1);
    //print_of_sum_it_up(5, 0);
    cout<< endl;
    
    subsequesnt("bat", "table", 2, 4);
    //cout<< endl;
    
    parentheses(3,1);
    cout<< endl;
    
    return 0;
}








