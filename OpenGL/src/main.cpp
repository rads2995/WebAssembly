#include <emscripten/emscripten.h>
#include <emscripten/html5.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <GLES3/gl3.h>

#include <iostream>

// glfw: window object declaration
GLFWwindow* window;

// Inifinite loop from Emscripten
void draw() {
    
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
        
    // Initialize everything here!


    // Check and call events and swap the buffers
    glfwSwapBuffers(window);
    glfwPollEvents();
}

int main() {
   
    // glfw: initialize and configure
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // glfw: window object definition
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", nullptr, nullptr);

    if (window == nullptr) {
        std::cout << "failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    
    // Rendering commands here
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    emscripten_set_main_loop(draw, 60, 1);

    return 0;
}
