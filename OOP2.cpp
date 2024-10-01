#include<iostream>
using namespace std;
class publication{ //DECLARING CLASS PUBLICATION
private:
string title;
float price;
public:
void getdata1(){
cout<<"......ENTER THE PUBLICATION INFORMATION........"<<endl;
cout<<"Enter the title of publication: ";
cin.ignore(); //IGNORE ALLOWS TO IGNORE THE NO. OF CHARACTERS FROM THE INPUT STREAM
getline(cin, title); //GETLINE HELPS US WRITE THE NAME WITH SPACES W/O SHOWING ANY
ERRORS OR GARBAGE VALUES
cout<<"Enter the price of publication: ";
cin>>price;
}
void displaydata1(){
cout<<"Title of Publication is: "<<title;
cout<<"Price of publication is: "<<price;
}
};
class book: public publication{ //DECALRING CLASS BOOK WHICH INHERITS CLASS PUBLICATION

private:
int pagecount;
public:
void getdata2(){
cout<<"Enter page count of the book: ";
cin>>pagecount;
}
void displaydata2(){
if(pagecount==0){
cout<<"INVALID PAGE COUNT!!!!";
}
else{
cout<<"Page count of the book is: "<<pagecount;
}
}

};
class tape:public publication{ //DECLARING CLASS TAPE WHICH INHERITS CLASS PUBLICATION
private:
float playtime;
public:
void getdata3(){
cout<<"Enter the play duration of the tape in minutes: ";
cin>>playtime;
}

void displaydata3(){
if(playtime==0){
cout<<"INVALID PLAY TIME!!!!!";
}
else{
cout<<"Play time of the book is: "<<playtime;
}
}

};
int main(){
book obj1[10]; //OBJECT OF CLASS BOOK
tape obj2[10]; //OBJECT OF CLASS TAPE //WE DON'T CREATE OBJECT OF PARENT CLASS
int ch, b_count=0, t_count=0;
do{
cout<<"\n..........PUBLICATION DATABASE............."<<endl;
cout<<"\n.................MENU..............."<<endl;
cout<<"1. Add information to books: "<<endl;
cout<<"2. Add information to tapes: "<<endl;
cout<<"3. Display infromation for books: "<<endl;
cout<<"4. Display information for tapes: "<<endl;
cout<<"5. EXIT"<<endl;
cout<<"Enter your choice from 1 to 5: "<<endl;
cin>>ch;
switch(ch){

case 1:
obj1[b_count].getdata2();
b_count++;
break;
case 2:
obj2[t_count].getdata3();
t_count++;
break;\
case 3:
cout<<"\n..........BOOK PUBLICATION DATABASE..........."<<endl;
for(int j=0; j<b_count; j++){
obj1[j].displaydata2();
}
break;
case 4:
cout<<"\n............TAPE PUBLICATIOB DATABASE.........."<<endl;
for(int j=0; j<t_count; j++){
obj2[j].displaydata3();
}
break;
case 5:
exit(0);
}
}while(ch!=5);
return 0; }
