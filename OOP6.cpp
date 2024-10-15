/*write a program for sorting and seraching
user defined records such as item records , name, cost, quantity and id
using vector container*/



#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Item{
 public:
 char name[10];
 int quantity;
 int cost;
 int code;
 bool operator==(const Item& i1){
 if(code==i1.code)
 return 1;
 return 0;
 }
 bool operator<(const Item& i1){
 if(code<i1.code)
 return 1;
 return 0;
 }
};
vector<Item> o1;
void print(Item &i1);
void display();
void insert();
void search();
void dlt();
bool compare(const Item &i1, const Item &i2){

 return i1.cost < i2.cost;
}
int main(){
 int ch;
 do{
 cout<<"\n___Menu___";
 cout<<"\n1.Insert item";
 cout<<"\n2.Display item";
 cout<<"\n3.Search item";
 cout<<"\n4.Sort item";
 cout<<"\n5.Delete item";
 cout<<"\n6.Exit";
 cout<<"\nEnter your choice:";
 cin>>ch;

 switch(ch){
 case 1:
 insert();
 break;

 case 2:
 display();
 break;

 case 3:
 search();
 break;

 case 4:
 sort(o1.begin(),o1.end(),compare);
 cout<<"\n\n Sorted on Cost";
 display();
 break;

 case 5:
 dlt();
 break;

 case 6:
 exit(0);
 }

 }while(ch!=7);
 return 0;
}
void insert(){
 Item i1;
 cout<<"\nEnter Item Name:";
 cin>>i1.name;
 cout<<"\nEnter Item Quantity:";
 cin>>i1.quantity;
 cout<<"\nEnter Item Cost:";
 cin>>i1.cost;
 cout<<"\nEnter Item Code:";
 cin>>i1.code;
 o1.push_back(i1);
}
void display(){
    cout<<"Items are: "<<endl;
 for_each(o1.begin(),o1.end(),print);
}
void print(Item &i1){
 cout<<"\n";
 cout<<"\nItem Name:"<<i1.name;
 cout<<"\nItem Quantity:"<<i1.quantity;
 cout<<"\nItem Cost:"<<i1.cost;
 cout<<"\nItem Code:"<<i1.code;
}
void search(){
 vector<Item>::iterator p;
 Item i1;
 cout<<"\nEnter Item Code to search:";
 cin>>i1.code;
 p=find(o1.begin(),o1.end(),i1);
 if(p==o1.end()){
 cout<<"\nNot found.";
 }
 else{
 cout<<"\nFound."<<endl;
 cout<<"Item Name : "<<p ->name<<endl;
 cout<<"Item Quantity : "<<p ->quantity<<endl;
 cout<<"Item Cost : "<<p ->cost<<endl;
 cout<<"Item Code: "<<p ->code<<endl;
 }
}
void dlt(){
 vector<Item>::iterator p;
 Item i1;
 cout<<"\nEnter Item Code to delete:";
 cin>>i1.code;
 p=find(o1.begin(),o1.end(),i1);
 if(p==o1.end()){
 cout<<"\nNot found.";
 }
 else{
 o1.erase(p);
 cout<<"\nDeleted.";
 }
}

//Output:

/*___Menu___
1.Insert item
2.Display item
3.Search item
4.Sort item
5.Delete item
6.Exit
Enter your choice:1

Enter Item Name:Pencil

Enter Item Quantity:5

Enter Item Cost:10

Enter Item Code:123

___Menu___
1.Insert item
2.Display item
3.Search item
4.Sort item
5.Delete item
6.Exit
Enter your choice:1

Enter Item Name:Pen

Enter Item Quantity:5

Enter Item Cost:20

Enter Item Code:456

___Menu___
1.Insert item
2.Display item
3.Search item
4.Sort item
5.Delete item
6.Exit
Enter your choice:1

Enter Item Name:Eraser

Enter Item Quantity:2

Enter Item Cost:5

Enter Item Code:789

___Menu___
1.Insert item
2.Display item
3.Search item
4.Sort item
5.Delete item
6.Exit
Enter your choice:2
Items are: 


Item Name:Pencil
Item Quantity:5
Item Cost:10
Item Code:123

Item Name:Pen
Item Quantity:5
Item Cost:20
Item Code:456

Item Name:Eraser
Item Quantity:2
Item Cost:5
Item Code:789
___Menu___
1.Insert item
2.Display item
3.Search item
4.Sort item
5.Delete item
6.Exit
Enter your choice:3

Enter Item Code to search:456

Found.
Item Name : Pen
Item Quantity : 5
Item Cost : 20
Item Code: 456

___Menu___
1.Insert item
2.Display item
3.Search item
4.Sort item
5.Delete item
6.Exit
Enter your choice:4


 Sorted on CostItems are: 


Item Name:Eraser
Item Quantity:2
Item Cost:5
Item Code:789

Item Name:Pencil
Item Quantity:5
Item Cost:10
Item Code:123

Item Name:Pen
Item Quantity:5
Item Cost:20
Item Code:456
___Menu___
1.Insert item
2.Display item
3.Search item
4.Sort item
5.Delete item
6.Exit
Enter your choice:5

Enter Item Code to delete:789

Deleted.
___Menu___
1.Insert item
2.Display item
3.Search item
4.Sort item
5.Delete item
6.Exit
Enter your choice:6*/
