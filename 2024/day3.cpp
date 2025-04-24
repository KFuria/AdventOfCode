#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int getNum(int& i, std::string& s){
    int x = 0;
    while(x < 1000 && isdigit(s[i])){
        x = 10 * x + (s[i] - '0');
        i++;
    }
    if(1 <= x && x <= 999){
        return x;
    }
    return -1;
}

int main(){
    std::ifstream file ("day3_s.txt");
    std::string s;
    bool enb = true;
    long int ans = 0;
    if(file.is_open()){
        while(std::getline(file, s)){
            s+="#################";
            int n = (int)s.size();
            for(int i = 0; i < n-7; i++){
                if(s[i] == 'd' && s[i+1] == 'o'){
                    if(s[i+2] == '(' && s[i+3] == ')' ){
                        enb = true;
                        i += 4; 
                    }
                    else if(s[i+2] == 'n' && s[i+3] == '\'' && s[i+4] == 't' && s[i+5] == '(' && s[i+6] == ')'){
                        enb = false;
                        i += 7;
                    }
                }
                 
                if(enb && s[i] =='m'){
                    if(s[i+1] == 'u' && s[i+2] == 'l' && s[i+3] == '('){
                        i += 4;
                        int x = getNum(i, s);
                        if(s[i] == ','){
                            i += 1;
                            int y = getNum(i, s);
                            if(s[i] == ')'){
                                if(x != -1 && y != -1){
                                    ans += x*y;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    std::cout << ans << "\n";

    return 0;
}