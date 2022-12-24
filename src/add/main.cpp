#include <iostream>
#include <stdexcept>
#include <string>
#include "../deps/adder/adder.h"

int main(int c, char **argv)
{
    int i = 1;
    float sum = 0;
    bool flag = 0;
    while (i < c)
    {
        std::string arg = argv[i];
        try
        {
            std::size_t pos;
            float x = std::stoi(arg, &pos);
            if (pos < arg.size())
            {
                x = std::stof(arg, &pos);
                if (pos < arg.size())
                {
                    std::cerr << "Trailing characters after number: " << arg << '\n';
                    exit(1);
                }
                flag = 1;
                sum = customadder69::add(sum, x);
            }
            else
                sum = customadder69::add(sum, x);
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
    auto ans = flag ? sum : int(sum);
    std::cout << ans << std::endl;
    return 0;
}