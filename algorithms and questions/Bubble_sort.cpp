//bubble sort for an array
#include <iostream>

using namespace std;

class Bubble_sort{
public: 

    void BS(int arr[], int n){
        bool swapped;
        for(int i=0; i<n-1; i++){
            swapped = false;
            for (int j = 0;j<n-i-1;j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j], arr[j+1]);
                    swapped = true;
                }

            }
            if(swapped == false){
                break;
            }
        }
    }
    //function for array printing
    void print_Arr(int arr[], int s){
        for(int i=0; i<s; i++){
            cout<<arr[i]<<" ";

        }
    }

    //function to find index value;
    int find_index(int arr[], int index, int s){
        if(index >=0 && index<s){
            cout<<"Element at "<<index<<"is: "<<arr[index]<<endl;
            return arr[index];
        }
        else{
            cout<<"Out of bounds";
        }
    }

};

int main(){
    int s;
    cin>>s;

    int a[s];
    for(int i = 0;i<s;i++){
        cin>>a[i];
    }

    Bubble_sort b;
    cout<<"Original array:"<<endl;
    b.print_Arr(a, s);
    cout<<endl;
    b.BS(a, s);
    cout<<"Sorted array:"<<endl;
    b.print_Arr(a, s);

    int i;
    cout<<"Enter index to find value: ";
    cin>>i;
    b.find_index(a,i,s);
    return 0;

}