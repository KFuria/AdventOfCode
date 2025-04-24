#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

bool isOk(std::vector<int> a){
    int k = (int)a.size();
    bool ok = true;
    bool only_inc = true;
    bool only_des = true;
    for(int j = 0; j < k - 1; j++ ){
        int diff = a[j+1] - a[j];
        if(diff > 0){
            only_des = false;
        }
        if(diff < 0 ){
            only_inc = false;
        }
        if(!(1 <= abs(diff) && abs(diff) <= 3)){
            ok = false;
            break;
        }  
    }
    return (ok && (only_des || only_inc));
}


int main (){
    std::ifstream file ("day2_in.txt");
    int count1 = 0;
    int count2 = 0;
    for(int i = 0; i < 1000; i++){
        std::vector<int> a;
        int z;
        while((file >> z)){
            std::cout << z << " ";
            a.push_back(z);
            if(file.peek()=='\n') break;
        }
        std::cout << "\n";

        if(isOk(a)){
            count1++;
        }

        bool anyOk = false;
        auto consider = [&](int j){
            std::vector<int> b = a;
            b.erase(b.begin() + j);
            if(isOk(b)){
                anyOk = true;
            }
        };

        int k = a.size();
        consider(0);
        for(int j = 0; j < k-1; j++){
            int diff = a[j+1] - a[j];
            if (abs(diff) < 1 || abs(diff) > 3){
                consider(j);
                consider(j+1);
                break;
            }
            if(j + 2 < k){
                int diff2 = a[j+2] - a[j+1];
                if((diff>0) != (diff2 > 0)){
                    consider(j);
                    consider(j+1);
                    consider(j+2);
                    break;
                }
            }
        }
        if (anyOk){
            count2++;
        }
    }
    std::cout << count1 << "\n";
    std::cout << count2 << "\n";
    return 0;
}