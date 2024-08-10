//bubble sorting
#include <iostream>
using namespace std;

void bSort(int arr[], int n){
    for(int i = 0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]= arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int* createArray(int size){
    int* arr = new int[size];
    for(int i = 0;i<size;i++){
        cin>>arr[i];
    }
    return arr;

}

int main(){
    int size;
    cin>>size;

    int* a = createArray(size);
    bSort(a,size);

    for(int i = 0;i<size;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}