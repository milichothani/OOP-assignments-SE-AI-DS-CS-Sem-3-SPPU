/* Develop a program in c++ to create a database of studen't information system containing the following information.
Name, roll no., class, division, date of birth, blood group, contact address, telephone number, driving license number, and 
other. Construct the database with suitable member function. make use of constructor, default contructor, copy constructor,
destructor, static memeber functions, friend class, this pointer, inline code, and dynamic memeory allocation operators - 
new and delete as well as exception*/
#include<iostream>
#include<string.h>
using namespace std;
class studdata;
class student{
    string name, Class, dob;
    int roll_no;
    char* div;
    char* bloodgroup;
    static int count;
    public:
    //DEFAULT CONTRUCTOR
    student(){
        name=" ";
        roll_no=0;
        Class=" ";
        div= new char;  //USING NEW OPERATOR
        dob="dd/mm/yyyy";
        bloodgroup= new char[5];   //USING NEW OPERATOR
    }
    //DESTRUCTOR
    ~student(){
        delete div;
        delete[] bloodgroup; //USING DELETE OPERATOR
    }
    static int getcount(){  //STATIC MEMEBER FUNCTION
        return count;
    }
    void getdata(studdata*);
    void displaydata(studdata*);
};

class studdata{
    string address;
    long int* telno;
    long int* drivinglicense;
    friend class student;  //USING FRIEND FUNCTION
    public:
    //USING DEFAULT CONSTRUCTOR
    studdata(){
        address = " ";
        telno=new long;      // USING NEW OPERATOR
        drivinglicense=new long;  // USING NEW OPERATOR
    }
    //USING DESTRUCTOR
    ~studdata(){
        delete telno;
        delete drivinglicense;   //USING DELETE OPEARTOR
    }
    void getstuddata(){
        cout<<"Enter Address of student: ";
        cin.get();
        getline(cin, address);  //USING GETLINE FUNCTION TO GET A PROPER ADDRESS WITH SPACES 
        cout<<"Enter telephone no. of the student: ";
        cin>>*telno;
        cout<<"Enter driving license no. of student:";
        cin>>*drivinglicense;
        }
    void displaystuddata(){
        cout<<"Student address: "<<address<<endl;
        cout<<"student's telephone no.: "<<*telno<<endl;
        cout<<"Students's driving license no.: "<<*drivinglicense<<endl;
    }
};

inline void student::getdata(studdata*st){    //USING INLINE FUNCTION
    cout<<"Enter student's name: ";
    getline(cin, name);
    cout<<"Enter roll no. of student: ";
    cin>>roll_no;
    cout<<"Enter the class of student: ";
    cin.get();
    getline(cin, Class);
    cout<<"Enter the division of student: ";
    cin>>div;
    cout<<"Enter DOB of student: ";
    cin.get();
    getline(cin, dob);
    cout<<"Enter the bloodgroup of student: ";
    cin>>bloodgroup;
    st->getstuddata();   //USING THIS POINTER TO GET THE DATA OF CLASS STUDDATA
    count++;
}
inline void student :: displaydata(studdata*st1){
    cout<<"Name of student is: "<<name<<endl;
    cout<<"Roll no. of student is: "<<roll_no<<endl;
    cout<<"Class of student is: "<<Class<<endl;
    cout<<"Division of student is: "<<div<<endl;
    cout<<"Date of birth of student is: "<<dob<<endl;
    cout<<"Bloodgroup pf student is: "<<bloodgroup<<endl;
    st1->displaystuddata();     //USING THIS POINTER TO DISPLAY DATA OF CLASS STUDDATA
    }
    int student::count;
    int main(){
        student*stud1[100];
        studdata*stud2[100];
        int n=0;
        char ch;
        do{
            stud1[n]=new student;
            stud2[n]=new studdata;
            cout<<".........ENTER STUDENT DATA.............."<<endl;
            stud1[n]->getdata(stud2[n]);
            n++;
            cout<<"Do you want to add another student? press y for yes and n for no: ";
            cin>>ch;
            cin.get();
        }while(ch=='y' || ch=='Y');
        for(int i=0; i<n; i++){
            cout<<".............STUDENT DATABASE............."<<endl;
            stud1[i]->displaydata(stud2[i]);
        }
        cout<<"...........................";
        cout<<"Total student: "<<student::getcount();
        cout<<endl;
        for(int i=0; i<n;i++){
            delete stud1[i];
            delete stud2[i];
        }
         
        return 0; 
    }
//EXPECTED OUTPUT:
/*.........ENTER STUDENT DATA..............
Enter student's name: Mili Chothani
Enter roll no. of student: 24
Enter the class of student: SE
Enter the division of student: A
Enter DOB of student: 24/02/2005
Enter the bloodgroup of student: A+
Enter Address of student: pune
Enter telephone no. of the student: 123456
Enter driving license no. of student:123
Do you want to add another student? press y for yes and n for no: y
.........ENTER STUDENT DATA..............
Enter student's name: Rudra Chothani
Enter roll no. of student: 23
Enter the class of student: SE
Enter the division of student: A
Enter DOB of student: 26/04/2013
Enter the bloodgroup of student: B+
Enter Address of student: pune
Enter telephone no. of the student: 12345
Enter driving license no. of student:1234
Do you want to add another student? press y for yes and n for no: n
.............STUDENT DATABASE.............
Name of student is: Mili Chothani
Roll no. of student is: 24
Class of student is: SE
Division of student is: A
Date of birth of student is: 24/02/2005
Bloodgroup pf student is: A+
Student address: pune
student's telephone no.: 123456
Students's driving license no.: 123
.............STUDENT DATABASE.............
Name of student is: Rudra Chothani
Roll no. of student is: 23
Class of student is: SE
Division of student is: A
Date of birth of student is: 26/04/2013
Bloodgroup pf student is: B+
Student address: pune
student's telephone no.: 12345
Students's driving license no.: 1234
...........................Total student: 2*/
