/*Program that calculates the minimum number of currency notes needed to make up a given amount 
using a set of denominations.
First line of input is for amount needed
second line of input no. of currency coins we can use
third line of input is the denominations of the currency coins we can use

input:
800
9
2000 500 200 100 50 20 10 5 1
Output:
2000 500 200 100 50 20 10 5 1
Coin: 2000 the count is: 0
Coin: 500 the count is: 1
Coin: 200 the count is: 1
Coin: 100 the count is: 1
Coin: 50 the count is: 0
Coin: 20 the count is: 0
Coin: 10 the count is: 0
Coin: 5 the count is: 0
Coin: 1 the count is: 0
The total coins required are: 3
*/

#include<iostream>
#include<algorithm>
using namespace std;
 
void minimum_denomination(int coins[], int n, int amount){
    //counting the coins
    int coinCount[n] = {0};
    //total count
    int total = 0;
    
    //sort the coins in descending order
    sort(coins, coins+n, greater<int>());
    for(int i=0;i<n;i++){
        while(amount >= coins[i]){
            coinCount[i]++;
            amount = amount - coins[i];
            total++;
        }
    }
    
    for(int i=0;i<n;i++){
        cout<<"Coin: "<<coins[i]<<" the count is: "<<coinCount[i]<<endl;
    }
    
    
    cout<<"The total coins required are: "<<total<<endl;
}
 
int main(){
    //amount
    int am;
    cin>>am;
    
    //denomination length
    int n;
    cin>>n;
    
    //denomination array
    int de[n];
    for(int i=0;i<n;i++){
        cin>>de[i];
    }
    
    minimum_denomination(de,n,am);
}