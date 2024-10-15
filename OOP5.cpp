/*OOP aasignment on sorting array elements of 
integer values and float values using templates*/



#include<iostream>
using namespace std;
template<class T>
   void Ssort(T A[], int n){
        T temp;
        int i,min,m,j;
        //float i;
        for(int i=0;i<n-1;i++){
            min=i;
        
        for(j=i+1;j<n;j++){
            if(A[j]<A[min]){
                min=j;
            }
        }
       temp=A[i];
       A[i]=A[min];
       A[min]=temp;
        }
        for(int m=0;m<n;m++){
            cout<<A[m];
            cout<<"\n";
        }
     }
       int main(){
        int ch,op;
        int A[10];
         int n;
         float B[10];
        
        do{
            cout<<"\n..................MENU.................";
            cout<<"\n1. Selection sort for integer type";
            cout<<"\n2. Selection sort for float type";
            cout<<"\nEnter your choice: ";
            cin>>ch;
            cout<<"\nEnter the number of elements: ";
            cin>>n;
            switch(ch){
                    case 1:
                    cout<<"\nEnter array elements: "<<endl;;
                    for(int m=0;m<n;m++){
                        cin>>A[m];
                        cout<<' ';
                    }
                    cout<<"Sorting for integer value: "<<endl;
                    Ssort(A,n);
                    break;
                    case 2:
                     cout<<"\nEnter Float Elememts:"<<endl;
                    for( int i=0;i<n;i++){
                    cin>>B[i];
                    }
                    cout<<"\nSorting for float values: "<<endl;
                    Ssort(B,n);

                    break;
                   
}
            cout<<"\nDo you want to perform again? Press 1 for yes else press 0: ";
            cin>>op;
        }while(op==1);
        return 0;
     }


//output:
/*..................MENU.................
1. Selection sort for integer type
2. Selection sort for float type
Enter your choice: 1

Enter the number of elements: 5

Enter array elements: 
7
 3
 9
 1
 6
 Sorting for integer value: 
1
3
6
7
9

Do you want to perform again? Press 1 for yes else press 0: 1

..................MENU.................
1. Selection sort for integer type
2. Selection sort for float type
Enter your choice: 2

Enter the number of elements: 5

Enter Float Elememts:
6.9
9.2
1.9
2.6
5.7

Sorting for float values: 
1.9
2.6
5.7
6.9
9.2

Do you want to perform again? Press 1 for yes else press 0: 0 */
