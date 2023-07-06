#include<bits/stdc++.h>
using namespace std;

const int bsize=9;
const int csize=3;

int board[bsize][bsize];

bool check(int x,int r,int c){  //check function to check validity of choice x
    for(int i=0;i<bsize;i++){
        if(i!=c && board[r][i]==x) return false;    //checking if the row of referred unit cell contains x already
    }

    for(int j=0;j<bsize;j++){
        if(j!=r && board[j][c]==x) return false;    //checking if column of referred unit cell contains x already
    }

    int topx=(r/csize)*csize;   //calculating row no. of the top cell of the cell block to which r,c belong
    int topy=(c/csize)*csize;   //calculating column no. of the top cell of the cell block to which r,c belong

    for(int dx=0;dx<csize;dx++){
        for(int dy=0;dy<csize;dy++){
            if(topx+dx==r && topy+dy==c)continue;       //checking if the cell block of 3x3 which contains cell (r,c) already contains x
            else {
                if(board[topx+dx][topy+dy]==x) return false;
            }
        }
    }
    return true;
}

int ans=0;
void rec(int i,int j){
    if(j==bsize){   //moving to the next row if col+1 goes out of bounds
        rec(i+1,0);
        return;
    }

    if(i==bsize){   //correct solution is achieved when row=9
        ans++;
        cout<<ans<<endl;    //printing number of solutions
        for(int ii=0;ii<bsize;ii++){
            for(int jj=0;jj<bsize;jj++){    //printing board with solution filled in
                cout<<board[ii][jj];
            }
            cout<<endl;
        }
        return;
    }

    if(board[i][j]==0){
        for(int x=1;x<=bsize;x++){  //using backtracking and brute force to place every possible x in cell(i,j) and check if its valid
            if(check(x,i,j)){
                board[i][j]=x;
                rec(i,j+1);
                board[i][j]=0;  //backtracking, i.e, reverting placement of x in cell (i,j)
            }
        }
    }
    else{
        if(check(board[i][j],i,j)){     //checking if already inplace cells are capable of generating valid solutions(optional)
            rec(i,j+1);
        }
    }

}

void solve(){
    for(int i=0;i<bsize;i++){
        
        for(int j=0;j<bsize;j++){
            cin>>board[i][j];       //inputing given sudoku board
        }
        
    }

    rec(0,0);   //calling recurrence starting from cell(0,0)
}

signed main(){
    ios_base::sync_with_stdio();
    cin.tie(0);cout.tie(0);

    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}