// A simple program that computes the square root of a number
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>
#include <iostream>
#include <typeinfo>
#include <functional>

#include <tuple>
#include <iostream>
#include <string>
#include <stdexcept>

std::tuple<double, char, std::string> get_student(int id)
{
    if (id == 0) return std::make_tuple(3.8, 'A', "Lisa Simpson");
    if (id == 1) return std::make_tuple(2.9, 'C', "Milhouse Van Houten");
    if (id == 2) return std::make_tuple(1.7, 'D', "Ralph Wiggum");
    throw std::invalid_argument("id");
}



int main ()
{
    // auto stuff
    std::cout << "Hello World" << std::endl;
    auto map = std::pair<int, float>(11,20.7f);
    std::cout << map.first << std::endl;
    std::cout << map.second << std::endl;
    auto b = 3.3;
    std::cout << b << std::endl;
    auto x{9};
    decltype(x) t;
    std::cout << t << std::endl;
    std::cout << sizeof(x) << std::endl;
    std::cout << x << std::endl;

    // Tuple
    std::cout << std::endl << "Tuple Fun:" << std::endl;
    auto student0 = get_student(0);
    std::cout << "ID: 0, "
              << "GPA: " << std::get<0>(student0) << ", "
              << "grade: " << std::get<1>(student0) << ", "
              << "name: " << std::get<2>(student0) << '\n';

    double gpa1;
    char grade1;
    std::string name1;
    std::tie(gpa1, grade1, name1) = get_student(1);
    std::cout << "ID: 1, "
              << "GPA: " << gpa1 << ", "
              << "grade: " << grade1 << ", "
              << "name: " << name1 << '\n';

    // Iteratoren
    std::cout << std::endl << "Iterators:" << std::endl;

    std::vector<int> list;

    list.push_back(2);
    list.push_back(4);
    list.push_back(8);
    list.push_back(27);

    std::cout << "Print list quadratic" << std::endl;
    for(auto i = list.cbegin(); i != list.cend(); ++i)
        std::cout << (*i)*(*i) << std::endl;
    std::cout << std::endl;

    std::cout << "Print constant list" << std::endl;
    for(auto i = list.cbegin(); i != list.cend(); ++i)
        std::cout << *i << std::endl;
    std::cout << std::endl;

    std::vector<int> container(4);
    std::cout << "Print container" << std::endl;
    for (auto it = container.begin(); it != container.end(); it++)
    {
        *it = random();
        std::cout << "Iterator : " << *it << std::endl;
    }
    std::cout << std::endl << std::endl;

    std::cout << "Print map container" << std::endl;
    std::map<int, std::string> highscores;

    highscores.insert(std::pair<int, std::string>(10, "Manfred"));
    highscores.insert(std::pair<int, std::string>(15, "Timo"));
    highscores.insert(std::pair<int, std::string>(32, "Paul"));
    highscores.insert(std::pair<int, std::string>(55, "Baal"));
    highscores.insert(std::pair<int, std::string>(8, "Herbert"));
    highscores.insert(std::pair<int, std::string>(17, "Gerd"));

    //std::sort(highscores.begin(), highscores.end());

    for(auto i = highscores.begin(); i != highscores.end(); ++i)
        std::cout << i->second << ":\t" << i->first << std::endl;

    std::cout << highscores.find(17)->second << std::endl;

    for(auto i = highscores.begin(); i !=highscores.lower_bound(16); i++)
        std::cout << i->second << ":\t" << i->first << std::endl;

    for(auto i = highscores.lower_bound(8); i !=highscores.upper_bound(35); i++)
        std::cout << i->second << ":\t" << i->first << std::endl;


    return 0;
}
