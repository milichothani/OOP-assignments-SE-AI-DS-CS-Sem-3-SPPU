/*Implement a class Complex which represents the Complex Number data type. Implement the
following 1. Constructor (including a default constructor which creates the complex
number 0+0i). 2. Overload operator+ to add two complex numbers. 3. Overload operator* to multiply two complex numbers.
4. Overload operators << and >> to print and read Complex Numbers*/


#include<iostream>
using namespace std;
class complex{   //DECLARING CLASS COMPLEX
double real, imag;
public:
complex();
//USINF FRIEND FUNCTION
friend istream  &operator >> (istream &, complex&);   //TAKING INPUT
friend ostream &operator << (ostream &,  const complex &);
complex operator + (complex);  //PERFORMING ADDITION
complex operator * (complex);  //PERFORMING MULTIPLICATION
};
complex::complex(){  //DEFAULT CONSTRUCTOR
    real = 0;
    imag = 0;
}
istream & operator >>(istream&,complex & i){
    cin>>i.real>>i.imag;
    return cin;
}
ostream & operator <<(ostream&, const complex & d){
    cout<<d.real<<"+"<<d.imag<<"i"<<endl;
    return cout;
}
complex complex::operator + (complex c1){   //OVERLOADING THE '+' OPERATOR
    complex temp;
    temp.real = real + c1.real;
    temp.imag = imag +c1.imag;
    return temp;
}
complex complex:: operator * (complex c2){   //OVERLOADING THE '*' OPERATOR
    complex temp;
    temp.real = real*c2.real - imag*c2.imag;
    temp.imag = real*c2.imag + imag*c2.real;
    return temp;

}
int main(){
    complex c1, c2, c3, c4;
    int flag =1;
    char b;
    while(flag==1){
        cout<<"Enter Real and imaginary part of the first complex number:\n ";
        cin>>c1;
        cout<<"Enter the Real and Imaginary part of second complex number: \n";
        cin>>c2;
        int f=1;
        while(f==1){
            cout<<"First complex number: "<<c1<<endl;
            cout<<"Second complex number: "<<c2<<endl;
            cout<<"\n.............MENU............."<<endl;
            cout<<"1. Additiong of two complex number: "<<endl;
            cout<<"2. Multiplication of two complex numbers: "<<endl;
            cout<<"3.EXIT"<<endl;
            int ch;
            cout<<"Enter your choice from the above menu from 1 to 3: ";
            cin>>ch;
            if(ch==1){
                c3=c1+c2;
                cout<<"Addition of two complex numbers is: "<<c3<<endl;
                cout<<"Do you want to perfrom again? (y/n): \n";
                cin>>b;
                if(b=='y' || b=='Y'){
                    f=1;
                }
                else{
                    cout<<"Thanks for using this program :)"<<endl;
                    flag=0;
                    f=0;
                }
            }
            else if(ch==2){
                c4 = c1*c2;
                cout<<"Multiplication of two complex numbers is: "<<c4<<endl;
                cout<<"Do you want to perfrom again? (y/n): \n";
                cin>>b;
                if(b=='y' || b=='Y'){
                    f=1;
                }
                else{
                    cout<<"Thanks for using this program :)"<<endl;
                    flag=0;
                    f=0;
                }
            }
        }

    }
    return 0;
}
