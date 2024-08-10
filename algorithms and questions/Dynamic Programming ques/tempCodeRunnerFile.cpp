#include<iostream>
#include<algorithm>
using namespace std;
 
int lis(int a[], int n){
    
    if(n==0){
        return 0;//return 0 when there is no elements
    }
    
    else{
        
        //initalizing the lis array
        int dp[n];
        for(int i=0;i<n;i++){
            dp[i] = 1;
        }
        
        //fill the data by comparing and interating
        //i => 1 to n-1
        for(int i=1;i<n;i++){
            //j => 0 to i-1 (subsequence condition)
            for(int j=0;j<i;j++){
                //increasing subsequence condition
                if(a[i]>a[j]){
                    //length computation for the increasing subsequence
                    int temp1 = dp[j]+1;
                    int temp2 = dp[i];
                    dp[i] = temp1 > temp2 ? temp1 : temp2;
                }
            }
        }
        
        //return the maximum value of the dp array (longest increasing subsequence)
        int maxlen = 0;
        // maxlen = *max_element(dp, dp+n);
        for(int i=0;i<n;i++){
            if(dp[i]>maxlen){
                maxlen = dp[i];
            }
        }
        return maxlen;
    }
}
 
int main(){
    
    int n; //length of the array;
    cin>>n;
    
    int a[n]; //array to store the sequence
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    //function call to find the lis
    cout<<"Longest increasing subsequence for the given list is: "<<lis(a,n);
}