// 2. Iterative Quick sort
#include <iostream>
#include <math.h>

using namespace std;

struct low_high{
    int l;
    int h;
};

struct stack{
    int top;
    int size;
    low_high A[50];

};

void push(stack &s, low_high x){
    if(s.top == s.size-1)
        cout<< "Stack is full"<<endl;
    else{
        s.A[++s.top] = x;
    }
}

low_high pop(stack &s){
    low_high temp;
    temp.l = -1;
    temp.h = -1;

    if( s.top == -1){
        cout<< "Stack is empty" << endl;
        return temp;
    }
    else
        return s.A[s.top--];
}

low_high peek(stack &s){
    low_high temp;
    temp.l = -1;
    temp.h = -1;

    if( s.top == -1){
        cout<< "Stack is empty" << endl;
        return temp;
    }
    else
        return s.A[s.top];
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *A, int l, int h ){
    int i = l+1, j = h-1;
    int pivot = A[l];

    while(i<j){
        while(A[i] < pivot)
            i++;
        while(A[j] > pivot )
            j--;
        if(i<j)
            swap(A[i],A[j]);
    }
    if(A[l] > A[j])
        swap(A[j],A[l]);

    return j;
}

int *sort(int *A, int l, int h){
    //int *strg1, *strg2, count1=1,count2=1;
    stack s;    s.top = -1;    s.size = 50;
    int j;
    low_high temp1,temp2;
    j = partition(A,l,h);
    temp1.l = l;
    temp1.h = j;

    temp2.l = j+1;
    temp2.h = h;

    push(s,temp1);
    push(s,temp2);

    do{
        low_high temp = pop(s);
        l = temp.l;
        h = temp.h;

        j = partition(A,l,h);
    
        if(h-l > 2){
            temp1.l = l;
            temp1.h = j;

            temp2.l = j+1;
            temp2.h = h;

            push(s,temp1);
            push(s,temp2);
        }

    }while(s.top>-1);

    return A;
}

int main(){
    int *a = new int [7];
    for(int i=0;i<7;i++)
        cin>>a[i];

    a = sort(a,0,7);
    for(int i=0;i<7;i++)
        cout<< a[i] << " ";

    cout<<endl;
    return 0;
}