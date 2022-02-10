#include <iostream>
#define MAX 100
#include <math.h>

using namespace std;

// Ques 1 starts ------------
int fibonacci(int n){
    if(n<=2)
        return 1;
    else
        return (fibonacci(n-2) + fibonacci(n-1));
}

int check_fibonacci(int n, int k){
    if(k>0){
        if(n == fibonacci(k))
            return k;
        return check_fibonacci(n,k-1);
    }
    return 0;
}

int fit_to_no(int str, int count,int sum){
    int r = str%10;

    if(str > 0){
        if(r == 1)
            sum+=fibonacci(count);
        return fit_to_no(str/10,count+1,sum);
    }
    else
        return sum;
}

int *no_to_fit(int n, int sum, int i, int *A){
    if(sum<n){
        sum+=fibonacci(i);
        A[i] = 1;
        return no_to_fit(n,sum,i+1,A);

    }
    else{
        A[0] = i;
        if(sum == n)
            return A;

        else{
            int temp = sum - n;
            int check = check_fibonacci(temp,i);

            if(check>0){
                A[check] = 0;
                return A;
            }
             else{
                 int *p=new int[MAX];
                 p = no_to_fit(temp,0,1,p);
                 for(int t=1;t<=p[0];t++){
                     if(p[t] == 1)
                        A[t] = 0;
                 }
                 return A;
             }   
        }
    }
}

void fits(int ft_str, int k){

    int n = fit_to_no(ft_str, 1,0) + k;

    int *A = new int [MAX];

    A = no_to_fit(n,0,1,A);
    n = 0;
    for(int t=A[0];t>0;t--){
            cout<< A[t] << " ";
    }
    cout<<endl;

    return;
}
//Ques 1 ends -----------------------------


//Ques 2 starts ---------------------------
int *Insertion_Sort(int *A, int i, int j, int tag, int point, int n){
    if(tag == 1)
        point = A[i];
        //j=i-1;

    if(i < n){
        if(A[j] > point && j>=0){
            A[j+1] = A[j];
            return Insertion_Sort(A, i,j-1,2,point,n);
        }
        A[j+1] = point;
        return Insertion_Sort(A,i+1,i,1,point,n);
    }
    else
    {
        return A;
    }
}
//Ques 2 ends ------------------------------

//Ques 3 starts ----------------------------
int main(){

    //---------1-----------
    //second parameter is the number to be added in the string
    fits(101110,3);

    //---------2-----------
    int *A = new int [6];
    for(int i=0;i<6;i++)
        cin>> A[i];
    
    A = Insertion_Sort(A,1,0,1,0,6);
    for(int i=0;i<6;i++)
        cout<< A[i] << " ";

    cout<< endl;
    
    return 0;
}