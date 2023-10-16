#include "raylib.h"


int main() {
    // Determin the Game Window Width and Height
    const int screenWidth = 1280;
    const int screenHeight = 800;

    // Initialize the Window
    InitWindow(screenWidth, screenHeight, "So_pa_PO!");


    // Setting the Frames Per Second
    SetTargetFPS(60);


    // The Game Loop
while (WindowShouldClose() == false) {


  // Setup Canvas
        BeginDrawing();
        // Clear canvas to a specific color to avoid flicker
        //Creating game elements paddles, ball, and midcourt line
        DrawLine(screenWidth/2, 0, screenWidth/2, screenHeight, WHITE);
DrawCircle(screenWidth/2, screenHeight/2, 20, WHITE);
DrawRectangle(10,screenHeight / 2 - 60,25,120,WHITE);
DrawRectangle(screenWidth-35, screenHeight / 2 - 60, 25, 120, WHITE);
        EndDrawing();

}

        
    

//De-initialization

    CloseWindow();
    return 0;
}
