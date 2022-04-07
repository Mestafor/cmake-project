#include <iostream>
#include <vector>
#include <string>
#include <GLFW/glfw3.h>

int main() {
    std::vector<std::string> msg {"Hello", "C++", "World", "from", "VS Code"};
    
    for(auto str: msg) {
        std::cout << str << " ";
    }

    std::cout << std::endl;


    GLFWwindow* window;

    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        exit( EXIT_FAILURE );
    }

    window = glfwCreateWindow( 300, 300, "Gears", NULL, NULL );
    if (!window)
    {
        fprintf( stderr, "Failed to open GLFW window\n" );
        glfwTerminate();
        exit( EXIT_FAILURE );
    }

    // Main loop
    while( !glfwWindowShouldClose(window) )
    {
        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();

    // Exit program
    exit( EXIT_SUCCESS );


    return 0;
}