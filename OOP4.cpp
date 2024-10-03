/*Write a C++ program that creates an output file, writes information
to it, closes the file, open it again as an input file and read the
information from the file.*/


#include<iostream>
#include<fstream>
using namespace std;
class student{   //DECLARING CLASS STUDENT
    string name, dob;
    int roll_no;
    double contactno, drivinglno;
    public:
    void getdata(){
        cout<<"Enter the name of student: ";
        cin.ignore();   //IGNORE HELPS US IGNORE NUMBERS AND EXTRA CHARACTERS
        getline(cin, name);  //GETLINE HELPS US WRITE STUDENT'S NAME WITH SPACES
        cout<<"Enter roll no. of the student: ";
        cin>>roll_no;
        cout<<"Enter Date of birth of student: ";
        cin>>dob;
        cout<<"Enter contact number of student: ";
        cin>>contactno;
        cout<<"Enter Driving license number of the student: ";
        cin>>drivinglno;
    }
    void displaydata(){
        cout<<"Name of student: "<<name<<endl;
        cout<<"Roll no. of student: "<<roll_no<<endl;
        cout<<"DOB of student: "<<dob<<endl;
        cout<<"Contact no. of student: "<<contactno<<endl;
        cout<<"Driving license no. of student: "<<drivinglno<<endl;
    }
};
int main(){
    student obj[5];
    fstream f;
    int i,n;
    f.open("aa.txt", ios::out);
    cout<<"\nEnter the number of student u want to store: ";
    cin>>n;
    for(i=0; i<n; i++){
        cout<<"\nEnter information of student "<<i+1<<endl;
        obj[i].getdata();
        f.write((char*)&obj[i], sizeof obj[i]);
    }
    f.close();
    f.open("aa.txt", ios::in);
    cout<<"\n..............STUDENT INFORMATION............"<<endl;
    for(i=0; i<n;i++){
        cout<<"Student "<<i+1<<endl;
        f.write((char*)&obj[i], sizeof obj[i]);
        obj[i].displaydata(); 
    }
    f.close();
    return 0;
}


//expected output:
/*Enter the number of student u want to store: 3

Enter information of student 1
Enter the name of student: Mili Chothani
Enter roll no. of the student: 24
Enter Date of birth of student: 24/02/2005
Enter contact number of student: 12345
Enter Driving license number of the student: 12345

Enter information of student 2
Enter the name of student: Rasika mekhe
Enter roll no. of the student: 12
Enter Date of birth of student: 24/02/2005
Enter contact number of student: 12345
Enter Driving license number of the student: 12345

Enter information of student 3
Enter the name of student: Aditi konde
Enter roll no. of the student: 05
Enter Date of birth of student: 24/02/2005
Enter contact number of student: 12345
Enter Driving license number of the student: 123345

..............STUDENT INFORMATION............
Student 1
Name of student: Mili Chothani
Roll no. of student: 24
DOB of student: 24/02/2005
Contact no. of student: 12345
Driving license no. of student: 12345
Student 2
Name of student: Rasika mekhe
Roll no. of student: 12
DOB of student: 24/02/2005
Contact no. of student: 12345
Driving license no. of student: 12345
Student 3
Name of student: Aditi konde
Roll no. of student: 5
DOB of student: 24/02/2005
Contact no. of student: 12345
Driving license no. of student: 123345 */
