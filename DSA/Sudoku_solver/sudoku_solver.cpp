#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve();
// int main(){
//     solve();
//     return 0;
// }
#define io freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    io
    #endif
    solve();
    return 0;
}

// T.C. = O(9^x), where x is number of empty cell , S.C. = O(1)

// 0 represents empty cell in sudoku and rest of cells are filled with integers from 1 to 9
// take a 9 X 9 matrix as input
bool isSafe(ll row,ll col,vector<vector<ll>>&sudoku,ll val){
    ll n = sudoku.size();
    for(ll i=0;i<n;i++){
        // row check
        if(sudoku[row][i] == val){
            return false;
        }
        // col check
        if(sudoku[i][col] == val){
            return false;
        }
        // check 3X3 matrix
        ll mat_row = 3*(row/3) + i/3;
        ll mat_col = 3*(col/3) + i%3;
        if(sudoku[mat_row][mat_col] == val){
            return false;
        }
    }
    return true;
}
bool sudoku_solver(ll n,ll m,vector<vector<ll>>&sudoku){
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            // cell empty
            if(sudoku[i][j] == 0){
                for(ll val = 1;val<=9;val++){
                    if(isSafe(i,j,sudoku,val)){
                        sudoku[i][j] = val;
                        // recursive call
                        bool nextPossible = sudoku_solver(n,m,sudoku);
                        if(nextPossible){
                            return true;
                        }
                        else{
                            // backtrack
                            sudoku[i][j] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>a(n,vector<ll>(n,0));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    if(sudoku_solver(n,m,a)){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    cout<<" sudoku solved"<<endl;
}