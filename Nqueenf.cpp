#include<iostream>
#include<vector>
using namespace std;


//THings to remember
//Return statement in solve final answer
//filling vector in main -that statement (n,vector<int>(n,0))
//return true in issafe()
//r >= b.size() in solve function



void print(vector<vector<int>> &board)
{
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board.size();j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
}

bool isSafe(vector<vector<int>> &board,int row,int col)
{
    int i=row;
    int j=col;
    while(j>=0)
    {
        if(board[i][j]==1)
        {
            return false;
        }
        j--;
    }

    i=row;
    j=col;
    while(j>=0 && i>=0)
    {
        if(board[i][j]==1)
        {
            return false;
        }
        i--;
        j--;
    }

    i=row;
    j=col;
    while(j>=0 && i<board.size())
    {
        if(board[i][j]==1)
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
//return true in issafe()


//r >= b.size() in solve function
//Return statement in solve final answer
void solve(vector<vector<int>>&board,int col)
{
    if(col>=board.size())
    {
        cout<<"------------------------------------------Final Answer-----------------------------------------------------"<<endl;
        print(board);
        cout<<"----------------------------------------------------------------------------------------------------------"<<endl;
        return ; //IMP
    }
    

    for(int row=0;row<board.size();row++)
    {
        if(isSafe(board,row,col))
        {
            cout<<"Placing Queen at ( "<<row<<" , "<<col<<" ) "<<endl;
            board[row][col]=1;
            print(board);
            solve(board,col+1);
            board[row][col]=0;
            cout<<"----BackTracking----"<<endl;
            print(board);
        }
    }
}

//filling vector in main -that statement (n,vector<int>(n,0))
int main()
{
    cout<<"Enter value of N "<<endl;
    int n;
    cin>>n;
    if(n==0 || n==1 || n==2 || n==3)
    {
        cout<<"Solution Not Exists "<<endl;
        return 0;
    }
    int row=0;
    int col=0;
    vector<vector<int>> board(n,vector<int>(n,0));
    solve(board,col);
    return 0;
}