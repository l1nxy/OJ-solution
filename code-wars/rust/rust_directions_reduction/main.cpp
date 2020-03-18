#include <string>
#include <vector>
#include <iostream>

class DirReduction
{
public:
    static std::vector<std::string> dirReduc(std::vector<std::string> &arr){
        std::vector<std::string> v;
        for(size_t i = 0; i< arr.size(); ++i)
        {
            if(v.empty()) v.push_back(arr[i]);
            else{
            if(arr[i] == "NORTH" && v.back() == "SOUTH") v.pop_back();
            else if(arr[i] == "SOUTH" && v.back() == "NORTH") v.pop_back();
            else if(arr[i] == "WEST" && v.back() == "EAST") v.pop_back();
            else if(arr[i] == "EAST" && v.back() == "WEST") v.pop_back();
            else v.push_back(arr[i]);
            }
        }
        return v;
    }
};




int main(){
        std::vector<std::string> d1 = {"NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"};
        std::vector<std::string> ans1 = DirReduction::dirReduc(d1);
        std::vector<std::string> sol1 = {"WEST"};

        for(auto &i : ans1)
            std::cout<<i<<std::endl;
        std::vector<std::string> d2 = {"NORTH","SOUTH","SOUTH","EAST","WEST","NORTH", "NORTH"};
        std::vector<std::string> ans2 = DirReduction::dirReduc(d2);
        std::vector<std::string> sol2 = {"NORTH"};
        for(auto &i : ans2)
            std::cout<<i<<std::endl;
}
