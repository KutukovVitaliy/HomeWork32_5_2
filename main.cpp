#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"
#include <vector>

struct strData{
    std::string Region;
    int Date;
    std::string Studio;
    std::string Author;
    std::string Director;
    std::string Producer;
    std::vector<std::string> Role;
    std::vector<std::string> Actor;
};

struct cinema{
    std::string Film;
    strData Data;
};

int main() {
    cinema newCinema;
    newCinema.Film = "Дюна";
    newCinema.Data.Region = "США";
    newCinema.Data.Date = 2021;
    newCinema.Data.Studio = "Warner Bros";
    newCinema.Data.Author = "Джон Спейтс";
    newCinema.Data.Director = "Дени Вильнёв";
    newCinema.Data.Producer = "Кэйл Бойтер";
    newCinema.Data.Role.emplace_back("Пол");
    newCinema.Data.Role.emplace_back("Софи");
    newCinema.Data.Actor.emplace_back("Тимоти Шалане");
    newCinema.Data.Actor.emplace_back("Ребекка Фергюсон");
    nlohmann::json cinemaBase;
    std::ifstream fileJson("../cinema.json");
    fileJson >> cinemaBase;
    std::cout << cinemaBase["Data"]["Actor"] << std::endl;
    std::cout << cinemaBase["Data"]["Actor"].at(0) << std::endl;
    return 0;
}
