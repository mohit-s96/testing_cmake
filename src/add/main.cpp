#include <iostream>
#include <stdexcept>
#include <string>
#include "../deps/adder/adder.h"

int main(int c, char **argv)
{
    int i = 1;
    int sum = 0;
    while (i < c)
    {
        std::string arg = argv[i];
        try
        {
            std::size_t pos;
            int x = std::stoi(arg, &pos);
            if (pos < arg.size())
            {
                std::cerr << "Trailing characters after number: " << arg << '\n';
                exit(1);
            }
            sum += x;
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Invalid number: " << arg << '\n';
            exit(1);
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << "Number out of range: " << arg << '\n';
            exit(1);
        }
        i++;
    }

    std::cout << sum << std::endl;
    return 0;
}