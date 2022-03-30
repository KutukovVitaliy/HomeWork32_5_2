#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"
#include <vector>
#include <map>

void PrintMap(std::map<std::string, std::map<std::string, std::string>>& newCinema){
    std::map<std::string, std::map<std::string, std::string>>::iterator it;
    std::map<std::string, std::string>::iterator internalMapIt;
    for(it = newCinema.begin(); it != newCinema.end(); ++it)
    {
        std::cout << "Films name: " << it->first << std::endl;
        for(internalMapIt = it->second.begin(); internalMapIt != it->second.end(); ++internalMapIt)
        {
            std::cout << "Role: " << internalMapIt->first << " -- Actor: " << internalMapIt->second << ";  ";
        }
        std::cout << std::endl;
    }
}

void PrintMap(std::map<std::string, std::vector<std::string>>& result){
    if(result.empty()) return;
    std::map<std::string, std::vector<std::string>>::iterator it;

    for(it = result.begin(); it != result.end(); ++it)
    {
        std::cout << "Films name: " << it->first << std::endl;
        std::cout << "Role: ";
        for(auto& el : it->second)
        {
            std::cout << el << "  ";
        }
        std::cout << std::endl;
    }
}

std::map<std::string, std::vector<std::string>> FindByActorName(std::map<std::string, std::map<std::string, std::string>>& newCinema, std::string& actorName){
    std::map<std::string, std::vector<std::string>> result;
    std::map<std::string, std::map<std::string, std::string>>::iterator it;
    std::map<std::string, std::string>::iterator internalMapIt;
    std::vector<std::string> role;
    for(it = newCinema.begin(); it != newCinema.end(); ++it)
    {
        for(internalMapIt = it->second.begin(); internalMapIt != it->second.end(); ++internalMapIt)
        {
            if(internalMapIt->second.find(actorName) != std::string::npos)
            {
                role.emplace_back(internalMapIt->first);
            }
        }
        if(!role.empty())
        {
            result.emplace(std::make_pair(it->first, role));
            role.clear();
        }
    }
    return result;
}

int main() {
    std::map<std::string, std::map<std::string, std::string>> newCinema;
    std::map<std::string, std::string> RoleActor;
    nlohmann::json cinemaBase;
    std::ifstream fileJson("../cinema.json");
    fileJson >> cinemaBase;
    for (auto& x : cinemaBase["Films"].items())
    {
        //std::cout << "key: " << x.key() << ", value: " << x.value() << '\n';
        for(auto& y : x.value().items())
        {
            //std::cout << "key: " << y.key() << ", value: " << y.value() << '\n';
            std::string filmName(y.key());
            for(auto& z : y.value()["Role"].items())
            {
                for(auto& w : z.value().items())
                {
                    RoleActor.emplace(std::make_pair(w.key(), w.value()));
                }

            }
            newCinema.emplace(std::make_pair(filmName, RoleActor));
            RoleActor.clear();
        }
    }
    PrintMap(newCinema);
    std::string actorName;
    while(true){
        std::cout << "Input actor name or \"exit\" to exit program: ";
        std::cin >> actorName;
        if(actorName == "exit") break;
        std::map<std::string, std::vector<std::string>> result = FindByActorName(newCinema, actorName);
        if(result.empty())
        {
            std::cout << "Not found!" << std::endl;
        }
        else
        {
            PrintMap(result);
        }
    }
    return 0;
}
