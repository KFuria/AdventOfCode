#include <iostream>
#include <fstream>
#include <vector>
#include <string>


std::vector<std::pair<int,int>> diag1 {{1,1},{-1,-1}};
std::vector<std::pair<int,int>> diag2 {{1,-1},{-1,1}};
std::vector<std::vector<std::pair<int,int>>> dirs {diag1, diag2};
int dir_l = dirs.size();


bool checkW(std::vector<std::string> &matrix, int row, int col, int k){
    std::vector<std::pair<int,int>> dir = dirs[k];
    std::string c = "MS"; 
    bool m = false;
    bool s = false;
    for(int i = 0; i < 2; i++){
        int x = dir[i].first;
        int y = dir[i].second;
        if(matrix[row+y][col+x] == 'M'){
            m = true;
        }
        else if(matrix[row+y][col+x] == 'S'){
            s = true;
        }   
    }
    if(m && s){
        return true;
    }
    return false;

}

int main(){

    int count = 0;

    std::ifstream file ("day4_in.txt");
    if(file.is_open()){
        //read input into 2d array
        std::vector<std::string> matrix;
        std::string s;
        while(std::getline(file, s)){
            matrix.push_back(s);
        }
        int row_l = matrix.size();
        int col_l = s.size();

        for(int row = 1; row < row_l-1; row++){
            for(int col = 1; col < col_l-1; col++){
                if(matrix[row][col] == 'A'){
                    if(checkW(matrix, row, col, 0) && checkW(matrix, row, col, 1)){
                        count++;     
                    }
                }
            }
        }
        std::cout << count << "\n";
    }
    file.close();
    
    return 0;
}