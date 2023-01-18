#include <iostream>
#include <GLFW/glfw3.h>
#include <window-config.h>
#include <string>
#include <stdexcept>
#ifdef USE_ADDER
#include "adder.h"
#endif

int main(int argc, char **argv)
{
    std::string s1 = "";
    std::string s2 = "";
    try
    {
        if (argc < 3)
            throw std::invalid_argument("Not enough arguments were passed to the program\n");
        s1 = argv[1];
        s2 = argv[2];
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << e.what() << '\n';
        s1 = "0";
        s2 = "0";
    }
    int n1 = std::stoi(s1);
    int n2 = std::stoi(s2);
    std::cout << argv[0] << "Version: " << WINDOW_VERSION_MAJOR << "." << WINDOW_VERSION_MINOR << "\n";
    std::cout << "Hello from window" << std::endl;
#ifdef USE_ADDER
    std::cout << "Using adder: " << customadder69::add(n1, n2) << "\n";
#else
    std::cout << "Not using adder: " << n1 + n2 << "\n";
#endif
    GLFWwindow *window;

    if (!glfwInit())
    {
        fprintf(stderr, "Failed to initalize GLFW\n");
        exit(EXIT_FAILURE);
    }
    window = glfwCreateWindow(800, 800, "Tetsing", NULL, NULL);
    if (!window)
    {
        fprintf(stderr, "Failed to open GLFW window\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    while (!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    return 0;
}