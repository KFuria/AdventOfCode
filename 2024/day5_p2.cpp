#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

void topo(int a, std::vector<int>& order, std::map<int,std::vector<int>>& rules, std::map<int,int>& in, const std::set<int>& present){
    order.push_back(a);
    for(int b : rules[a]){
        if(present.count(b)){
            if(--in[b] == 0){
                topo(b, order, rules, in, present);
            }
        }
    }
}


int main(){
    //read input
    std::map<int, std::vector<int>> rules;
    long int total_correct_sum = 0;
    long int total_incorrect_sum = 0;

    std::ifstream file ("day5_in.txt");
    
    if(file.is_open()){
        std::string s;
        while(std::getline(file, s)){
            if(s.empty() || !isdigit(s[0])){
                continue;
            }
            // read page ordering rules
            if(s[2]=='|'){
                int a = (s[0] - '0') * 10 + (s[1] - '0');
                int b = (s[3] - '0') * 10 + (s[4] - '0');
                rules[a].push_back(b);
            }
            // read the update
            if(s[2] == ','){
                int s_size = s.size();
                std::set<int> earlier;
                std::set<int> present;
                std::map<int,int> in;       // number of page nums that should come before the current pg num
                std::vector<int> update;
                bool correct = true;
                
                for(int i = 0; i < s_size; i+=3){
                    int a = (s[i] - '0') * 10 + (s[i+1] - '0');
                    update.push_back(a);    // add page num to update vector
                    present.insert(a);      // add page num to present set
                }

                // for each page num in update,
                // add it to earlier set to keep track of page num in update
                // for each page num in "rule" of current page num, 
                // if it appears in the earlier set, the update is incorrect.
                // for each page num in "rule" of current page num,
                // if it appears in the present set, increment the count in the "in" map 
                for(int i = 0; i < (int) update.size(); i++){
                    int a = update[i]; 
                    for(int b: rules[a]){
                        if(earlier.count(b)){
                            correct = false;
                        }
                        if(present.count(b)){
                            ++in[b];
                        }
                    }
                    earlier.insert(a);
                }
                if(correct){
                    total_correct_sum += update[update.size()/2];
                }
                else{
                    std::vector<int> order;
                    std::vector<int> starting;
                    for(int x : update){
                        if(in[x] == 0){
                            starting.push_back(x);
                        }
                    }
                    for(int x : starting){
                        topo(x, order, rules, in, present);
                    }
                    total_incorrect_sum += order[order.size()/2];
                }
            }
        }
    }
    std::cout << total_incorrect_sum << "\n";
    return 0;
}