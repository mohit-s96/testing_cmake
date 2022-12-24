#include <iostream>
#include <GLFW/glfw3.h>
#include <window-config.h>

int main(int argc, char **argv)
{
    std::cout << argv[0] << "Version: " << WINDOW_VERSION_MAJOR << "." << WINDOW_VERSION_MINOR << "\n";
    std::cout << "Hello from window" << std::endl;
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