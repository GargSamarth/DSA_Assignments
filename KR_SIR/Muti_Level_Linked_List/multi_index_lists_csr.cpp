#include <iostream>
#include <string.h>

using namespace std;

struct course;
struct student;

struct registration{

    int rno;

    registration *next;
    registration *sfr;
    registration *sbr;
    registration *cfr;

    char c_name;

};

struct course{

    char course_name;
    registration *next_registration;

};

struct student{

    int r_no;
    registration *next_registration;

};

typedef registration *reg;
typedef course *cor;
typedef student *st;

void register_a_course(cor C[], char ch){

    C[int(ch)-65]->course_name = ch;    

}

void register_a_student(st S[], int student_no){

    S[student_no-1]->r_no = student_no;

}

void insert(char ch, cor C[], st S[], int student_no, reg &R){

    //index
        int index = student_no-1;

    //new registration (course/student)
        reg new_reg = new registration;
        new_reg->rno = student_no;
        new_reg->c_name = ch;
        new_reg->cfr = NULL;
        new_reg->sfr = NULL;
        new_reg->sbr = NULL;
        new_reg->next = NULL;

    //temp reg variable
        reg RT = R;

    //Reg connected to other reg
        while(RT->next != NULL)
            RT = RT->next;        
        RT->next = new_reg;

    //connected to student table
    if(S[index]->next_registration == NULL)
        S[index]->next_registration = new_reg;

    
    else{

        //cout<< index << " else"<<endl;
        reg temp = S[index]->next_registration;

        while(temp->sfr != NULL)
            temp = temp->sfr;
        
        //front connection
        temp->sfr = new_reg;

        //reverse connection
        new_reg->sbr = temp;

    }//end of std table


    //connected to course table
    if(C[int(ch)-65]->next_registration == NULL)
        C[int(ch)-65]->next_registration = new_reg;

    
    else{

        reg temp = C[int(ch)-65]->next_registration;

        while(temp->cfr != NULL)
            temp = temp->cfr;
        
        temp->cfr = new_reg;
    } 
    //end of course table
}

void print_corresponding(int tag, int student_no, char course, cor *C, st *S){

    if(tag == 1){

        if(C[char(course)-65]->next_registration == NULL)
            cout<< "No one registered for this course."<< endl;
        
        else{
            reg temp = C[char(course)-65]->next_registration;

            while(temp != NULL){                
                
                cout<< temp->rno<< " ";

                temp = temp->cfr;
            }
        }
    }

    else if(tag == 2){

        int index = student_no-1;

        if(S[index]->next_registration == NULL)
            cout<< "This student opted nothing."<< endl;

        else{
            reg temp =S[index]->next_registration;

            while(temp != NULL){
                
                cout<< temp->c_name << " ";

                temp = temp->sfr;
            }
        }
    }
    
}

void swap(char &a, char &b){

    char temp = a;  
    a = b;  
    b = temp;  
}  
  
void sort(char *arr, int n)
{  

    for (int i = 0; i < n-1; i++)       
    for (int j = 0; j < n-i-1; j++)  
        if (arr[j] > arr[j+1])  
            swap(arr[j], arr[j+1]);
} 

void swap(int &a, int &b){

    int temp = a;  
    a = b;  
    b = temp;  
}  
  
void sort(int *arr, int n)
{  

    for (int i = 0; i < n-1; i++)       
    for (int j = 0; j < n-i-1; j++)  
        if (arr[j] > arr[j+1])  
            swap(arr[j], arr[j+1]);
} 

void print_duo(int tag, int student_no1, int student_no2, char course1, char course2, cor *C, st *S){

     if(tag == 2){

        int index1 = student_no1-1;
        int index2 = student_no2-1;

            reg temp1 =S[index1]->next_registration;
            reg temp2 =S[index2]->next_registration;

            char *arr = new char[10];
            int i=0;
            while(temp1 != NULL && temp2 != NULL){
                
                    arr[i++] = temp1->c_name;

                    temp1 = temp1->sfr;
                    temp2 = temp2->sfr;
            }
            sort(arr,i);

            for(int j=0;j<i;j++){

                if(arr[j] == arr[j+1])
                    continue;
                
                else
                    cout<< arr[j]<< " ";

            }
    }

    else if(tag == 1){

            reg temp1 = C[char(course1)-65]->next_registration;
            reg temp2 = C[char(course2)-65]->next_registration;
            int *arr = new int[2];
            int i=0;
            while(temp1 != NULL && temp2 != NULL){                
                
                if(temp1->rno == temp2->rno)
                    arr[i++] = temp1->rno;

                temp1 = temp1->cfr;
                temp2 = temp2->cfr;
            }
            sort(arr,i);

            for(int j=0;j<i;j++)
            cout<< arr[j] << " ";
        
    }

}

int main(){

    cor C[4];

    st S[8];
    for(int i=0;i<8;i++){
        S[i] = new student;
        S[i]->next_registration = NULL;
    }

    for(int i=0;i<4;i++){
        C[i] = new course;
        C[i]->next_registration = NULL;
    }

    reg R = new registration;
    R->next = NULL;
    R->cfr = NULL;
    R->sbr = NULL;
    R->sfr = NULL;
    char course_name;
    int student_no;

    while(course_name != '#' && student_no != -1){
        
        cin>>student_no;
        cin>>course_name;
        

        if(course_name != '#' && student_no != -1){
            
            register_a_course(C,course_name);
            register_a_student(S,student_no);
            insert(course_name,C,S,student_no,R);

        }

    }
    
    string str;

    for(int i=0;i<5;i++){

        getline(cin,str);

        if(str.length() == 1 ){

            if(int(str[0])>64 && int(str[0])<91){
                print_corresponding(1,0,str[0],C,S);
                cout<< endl;
            }
            
            else{
                int a = stoi(str);
                print_corresponding(2,a,str[0],C,S);
                cout<< endl;
            }
        }

        else{

            if(int(str[0])>64 && int(str[0])<91){
                print_duo(1,0,0,str[0],str[1],C,S);
                cout<< endl;
            }
                
            else if(int(str[0])>47 && int(str[0])<58){
                    
                int a = int(str[0])-48;
                int b = int(str[2])-48;
                print_duo(2,a,b,str[0],str[1],C,S);
                cout<< endl;
            }

        }

    }

    R = R->next;
    while(R != NULL){
        cout<< R->rno << " ";
        cout<< R->c_name << " ";
        R = R->next;
    }
    cout<< endl;
    
    return 0;
}