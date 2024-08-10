/*Create a circular linked list to simulate a multiplayer game lobby. Each player joining the lobby should be represented as a node in the list, and the list should support operations like 
adding new players, removing players, and rotating the list to determine the next player's turn.

Implement the following function.
addPlayer(String playerName)
removePlayer(String playerName) 
rotateList()
displayPlayers()
*/
#include <iostream>
#include <string>
using namespace std;

struct PlayerNode{
    string playerName;
    PlayerNode* next;
    
    PlayerNode(string name): playerName(name), next(nullptr){}
};

PlayerNode* head = nullptr;

void addP(string playerName){
    PlayerNode* newNode = new PlayerNode(playerName);
    if(head ==nullptr){
        head =newNode;
        newNode->next = head;
    }
    
    else{
        PlayerNode* temp = head;
        while(temp->next !=head){
            temp=temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    
    cout<<"Player "<<playerName<<" added to the lobby."<<endl;
}

void remP(string playerName){
    if(head ==nullptr){
        cout<<"The lobby is empty"<<endl;
        return;
    }
    
    PlayerNode* c=head;
    PlayerNode* p = nullptr;
    
    do{
        if(c->playerName == playerName){
            break;
        }
        p=c;
        c=c->next;
    }while(c!=head);
    
    if(c->playerName != playerName){
        cout<<"Player "<<playerName<<" is not in the lobby."<<endl;
        return;
    }
    
    if(c==head){
        if(head->next ==head){
            head ==nullptr;
        }
        else{
            PlayerNode* temp=head;
            while(temp->next !=head){
                temp=temp->next;
            }
            temp->next = head->next;
        }
    }
    else{
        p->next = c->next;
    }
    delete c;
    cout<<"Player "<<playerName<<" removed from the lobby."<<endl;
}

void rotate(){
    if(head ==nullptr){
        cout<<"The lobby is empty."<<endl;
        return;
    }
    head=head->next;
    cout<<"Next player's turn: "<<head->playerName<<endl;
}

void display(){
    if(head ==nullptr){
        cout<<"The lobby is empty"<<endl;
        return;
    }
    PlayerNode* temp = head;
    cout<<"Players in the lobby: ";
    do{
        cout<<temp->playerName<<" ";
        temp=temp->next;
    }while(temp != head);
    cout<<endl;
}

int main(){
    int ch;
    string n;
    while(true){
        cin>>ch;
        cin.ignore();
        
        switch(ch){
            case 1:
                getline(cin,n);
                addP(n);
                break;
            case 2:
                getline(cin, n);
                remP(n);
                break;
            case 3:
                rotate();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                cout<<"Invalid choice. Please try again."<<endl;
                break;
        }
    }
    return 0;
}
