#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"
#include <vector>
#include <map>

struct strData{
    std::string Region;
    int Date;
    std::string Studio;
    std::string Author;
    std::string Director;
    std::string Producer;
    std::map<std::string, std::string> RoleActor;

};




int main() {
    std::map<std::string, strData> newCinema;
    nlohmann::json cinemaBase;
    std::ifstream fileJson("../cinema.json");
    fileJson >> cinemaBase;
    for (auto& x : cinemaBase["Films"].items())
    {
        //std::cout << "key: " << x.key() << ", value: " << x.value() << '\n';
        for(auto& y : x.value().items())
        {
            std::cout << "key: " << y.key() << ", value: " << y.value() << '\n';
        }
    }
    //std::cout << cinemaBase["Data"]["Actor"] << std::endl;
    //std::cout << cinemaBase["Data"]["Actor"].at(0) << std::endl;
    return 0;
}
