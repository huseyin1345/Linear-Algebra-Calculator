#include <iostream>
#include "Application.h"


int main(int argc, const char * argv[])
{
    
    Application* app = new Application();
    app->run();
    delete app;

    return 0;
}