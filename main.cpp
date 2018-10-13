#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int sudoku[10][10],f=0;;

int menu(){
    int choice;
    try{
        cout<<"1. 2x2\n";
        cout<<"2. 3x3\n";
        cout<<"3. 4x4\n";
        cout<<"4. Exit\n";
        cout<<"\nEnter size of sudoku (nxn) : ";
        cin>>choice;
        return choice;
    }
    catch(exception e){
        return -1;
    }
}

void getArray(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>sudoku[i][j];
            if(sudoku[i][j]>n || sudoku[i][j]<=0)
                f=1;
        }
    }
}

bool checkRow(int n){
    if(f==1)
        return false;
    bool visited[n+1];
    for(int i=0;i<n;i++){
        memset(visited,false,sizeof(visited));
        for(int j=0;j<n;j++){
            visited[sudoku[i][j]]=true;
        }
        for(int j=1;j<=n;j++){
            if(visited[j]==false)
                return false;
        }
    }
    return true;
}

bool checkCol(int n){
    bool visited[n+1];
    for(int i=0;i<n;i++){
        memset(visited,false,sizeof(visited));
        for(int j=0;j<n;j++){
            visited[sudoku[j][i]]=true;
        }
        for(int j=1;j<=n;j++){
            if(visited[j]==false)
                return false;
        }
    }
    return true;
}

bool checkBox(int n){
    bool visited[n+1];
    int sqt=sqrt(n);
    for(int i=0;i<=n-sqt;i=i+sqt){
        for(int j=0;j<=n-sqt;j=j+sqt){
            memset(visited,false,sizeof(visited));
            for(int x=i;x<i+sqt;x++){
                for(int y=j;y<j+sqt;y++){
                    visited[sudoku[x][y]]=true;
                }
            }
            for(int j=1;j<=n;j++){
                if(visited[j]==false)
                    return false;
            }
        }
    }
    return true;
}

int main(){
    while(true){
        int choice=menu();
        switch(choice){
            case 1:{
                int flag=0;
                cout<<"\nEnter the sudoku array :\n";
                getArray(4);
                if(checkRow(4)){
                    if(checkCol(4)){
                        if(checkBox(4)){
                            cout<<"VALID SUDOKU!!!\n";
                            flag=1;
                            f=0;
                        }
                    }
                }
                if(flag==0){
                    cout<<"INVALID SUDOKU!!!\n";
                    f=0;
                }
                break;
            }
            case 2:{
                int flag=0;
                cout<<"\nEnter the sudoku array :\n";
                getArray(9);
                if(checkRow(9)){
                    if(checkCol(9)){
                        if(checkBox(9)){
                            cout<<"VALID SUDOKU!!!\n";
                            flag=1;
                            f=0;
                        }
                    }
                }
                if(flag==0){
                    cout<<"INVALID SUDOKU!!!\n";
                    f=0;
                }
                break;
            }
            case 3:{
                int flag=0;
                cout<<"\nEnter the sudoku array :\n";
                getArray(16);
                if(checkRow(16)){
                    if(checkCol(16)){
                        if(checkBox(16)){
                            cout<<"VALID SUDOKU!!!\n";
                            flag=1;
                            f=0;
                        }
                    }
                }
                if(flag==0){
                    cout<<"INVALID SUDOKU!!!\n";
                    f=0;
                }
                break;
            }
            case 4:{
                cout<<"THANK YOU!!";
                return 0;
            }
            default:
                cout<<"Wrong Input!! Try AGAIN";
        }
    }
    return -1;
}
