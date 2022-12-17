#include <iostream>

int main(int c, char **argv)
{
    int i = 1;
    std::string name = "";
    std::cout << "Args Count: " << c << std::endl;
    while (i < c)
    {
        name += argv[i];
        std::cout << argv[i] << std::endl;
        i++;
    }

    name.erase(0, name.find_first_not_of(" \t\n\r\f\v"));
    name.erase(name.find_last_not_of(" \t\r\n\f\v"));
    std::cout << "Names: " << name << std::endl;
    std::cin.get();
    return 0;
}