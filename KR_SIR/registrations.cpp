#include <iostream>

using namespace std;

struct course;
struct student;

struct registration{

    int tag1;

    union{
        registration *next_course;
        student *repeate_courses;
    }down;

    int tag2;

    union{
        registration *next_student;
        course *repeate_students;
    }right;

};

struct course{
    char course_name;
    registration *right_registration;
};

struct student{
    char name;
    registration *down_registration;
};

typedef registration *reg;
typedef course *cor;
typedef student *st;

void course_struct(cor A[]){

    for(int i=0;i<4;i++){
        char ch = char(65+i);
        //cout<< ch << "====" << endl;
        A[i] = new course;
        A[i]->course_name = ch;
        A[i]->right_registration = NULL;
    }

}

void register_a_student(st B[], int student_no){

    B[student_no-1]->name = char(64 + student_no);

}

void insert(char ch, cor A[], st B[], int student_no){

    int index = student_no-1;

        registration *new_reg = new registration;

        if(B[index]->down_registration == NULL){
            //cout<< index << " if"<<endl;
            B[index]->down_registration = new_reg;
            new_reg->tag1 = 0;
            new_reg->down.repeate_courses = B[index];
        }
        else{

            //cout<< index << " else"<<endl;
            registration *temp = B[index]->down_registration;
    
            while(temp->tag1 == 1){
                temp = temp->down.next_course;
            }

            temp->tag1 = 1;
            temp->down.repeate_courses = NULL;
            temp->down.next_course = new_reg;
            new_reg->down.repeate_courses = B[index];
            new_reg->tag1 = 0;

        }

        if(A[int(ch)-65]->right_registration == NULL){

            A[int(ch)-65]->right_registration = new_reg;
            new_reg->tag2 = 0;
            new_reg->right.repeate_students = A[int(ch)-65];

        }
        else{

            registration *temp = A[int(ch)-65]->right_registration;

            while(temp->tag2 == 1){
               temp = temp->right.next_student;
            }

            temp->tag2 = 1;
            temp->right.repeate_students = NULL;
            temp->right.next_student = new_reg;
            new_reg->right.repeate_students = A[int(ch)-65];
            new_reg->tag2 = 0;
        } 

}

void swap(int &a, int &b)  
{  
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

void print_corresponding(int tag, int student_no, char course, cor *A, st *B){

    if(tag == 1){

        if(A[char(course)-65]->right_registration == NULL)
            cout<< "No one registered for this course."<< endl;
        
        else{
            registration *temp = A[char(course)-65]->right_registration;

            int *arr = new int[20];
            int i=0;

            while(temp->tag2 != 2){
                registration *temp2 = temp;

                while(temp2->tag1 == 1)
                    temp2 = temp2->down.next_course;
                
                
                arr[i++] = (int(temp2->down.repeate_courses->name)-64);
                
                if(temp->tag2 == 0)
                    break;

                temp = temp->right.next_student;
            }
            sort(arr,i);

            for(int j=0;j<i;j++)
            cout<< arr[j] << " ";
        }
    }

    else if(tag == 2){

        int index = student_no-1;

        if(B[index]->down_registration == NULL)
            cout<< "This student opted nothing."<< endl;

        else{
            registration *temp = B[index]->down_registration;

            while(temp->tag1 != 2){
                registration *temp2 = temp;

                while(temp2->tag2 == 1)
                    temp2 = temp2->right.next_student;
                
                cout<< temp2->right.repeate_students->course_name << " ";

                if(temp->tag1 == 0)
                    break;
                temp = temp->down.next_course;
            }
        }
    }
}

int main(){

    int num_course, student_no;
    cor A[4];
    course_struct(A);

    st B[8];
    for(int i=0;i<8;i++){
        B[i] = new student;
        B[i]->down_registration = NULL;
    }

    char st1;
    int n;

    while(st1 != '#' && n != -1){
        
        cin>>n;
        cin>>st1;
        

        if(st1 != '#' && n != -1){
            
            register_a_student(B,n);
            insert(st1,A,B,n);

        }

    }

    for(int i=0;i<4;i++){

        string ch;
        cin>>ch;

        if(int(ch[0])>64 && int(ch[0])<91){
            print_corresponding(1,0,ch[0],A,B);
        }
        else{
            int a = stoi(ch);
            print_corresponding(2,a,ch[0],A,B);
        }
        cout<< endl;

    }
    
    //1C 1A 1C 3A 1C 4A 2C 2A 2C 5A 3C 1A 3C 3A 3C 4A 3C 5A 4C 2A 4C 4A -1
    return 0;
}