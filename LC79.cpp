#include <bits/stdc++.h>

using namespace std;


class Solution{

private:
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

public:
    bool exist(vector<vector<char>>& board, string word){
        string res="";
        for(int m=0; m<board.size(); ++m){
            for(int n=0; n<board[0].size(); ++n){
                if(dfs(board, word, 0, res, m, n)){
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int index, string& res, int row, int col){
        if(!inArea(board,row,col) || board[row][col] == '#'){
            return false;
        }

        if(board[row][col] != word[index]){
            return false;
        }

        if(index == word.size()-1){
            return true;
        }
        char c = board[row][col];
        res += c;
        board[row][col] = '#';
        bool found=false;
        for(int i=0;i<4; ++i){
            if(dfs(board, word, len+1, res, row+dirs[i][0], col+dirs[i][1])){
                found=true;
                break;
            }
        }

        res.pop_back();
        board[row][col]=c;
        return found;
    }

    bool inArea(vector<vector<char>>& board, int& row, int& col){
        return row>=0 && row <board.size() && col>=0 && col<board[0].size();
    }
};



int main(){
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";

    Solution solution;
    cout<<solution.exist(board,word);
}