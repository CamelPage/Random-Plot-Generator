#include <raylib.h>
#include "plot.hpp"

int main()
{
    Color darkGreen = Color{20, 160, 133, 255};
    int PPS = 15;
    int plt[15*PPS+1] = {0};

    plot test_plot(plt, 1, -10, 10, "Jakis Plot", BLUE, true, BLUE, PPS, 600, 800);

    test_plot.info();


    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Okno");
    SetTargetFPS(24);

    int random_i = 2;

    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(darkGreen);

        // Rysuje Przerwę ok. 30px przed punktem
        test_plot.show();

        EndDrawing();

        plt[random_i] = {(rand() % (10 - -10 + 1)) + -10};

        test_plot.change_plot(plt, random_i);

        random_i++;

        if(random_i>=15*PPS) {
            
            BeginDrawing();
            ClearBackground(darkGreen);
            test_plot.sec_update(10);
            random_i = 2;
            std::fill_n(plt, 15*PPS, 0);
            EndDrawing();
        }


    }

    CloseWindow();
    return 0;
    
}
