#include <iostream>

using namespace std;

int sum;

    float operations(int A[], int n, int tag){
        if(tag == 1){
            if(n==0)
            return A[n];
            else{
                n--;
                return (A[n] > operations(A,n,tag) ? operations(A,n,tag):A[n]);
            }
        }
        else if(tag == 2){
            if(n==0)
                return A[n];
            else{
                n--;
                return (A[n] < operations(A,n,tag) ? operations(A,n,tag):A[n]);
            }
        }
        else if(tag == 3){
            if(n==0)
                return 0;
            else{
                n--;
                return (A[n] + operations(A,n,tag));
            }
        }
        else{
            cout<< "Invalid input please try again"<<endl;
            return 0;
        }
    }

    int main(){
        int n,*A,tag;
        cout<< "Tag =1 for min, Tag =2 for max, Tag=3 for average: ";
        cin>>tag;
        cout<< "Enter the number of elements: ";
        cin>>n;
        
        A = new int [n];
        cout<< "Enter the elements: "<<endl;
        for(int i=0;i<n;i++)
            cin>> A[i];
            
        float ans = operations(A,n,tag);
        //cout<< "-------------------"<< ans <<"---------------"<<endl;
        if (tag == 3)
            ans = ans/n;
        cout<<endl << "Your ans is: "<< ans << endl;
        
        return 0;
    }

