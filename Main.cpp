#include "raylib.h"

//Defining ball parameters
class Ball{
public: 
float x, y;
int speed_x, speed_y;
int radius;

void Draw () {
    DrawCircle(x, y, radius, WHITE);
}

};

Ball ball;


int main() {
    // Determin the Game Window Width and Height
    const int screenWidth = 1280;
    const int screenHeight = 800;

    // Initialize the Window
    InitWindow(screenWidth, screenHeight, "So_pa_PO!");


    // Setting the Frames Per Second
    SetTargetFPS(60);

//Setting ball radius
ball.radius = 20;
ball.x = screenWidth/2;
ball.y = screenHeight/2;
ball.speed_x = 7;
ball.speed_y = 7;

    // The Game Loop
while (WindowShouldClose() == false) {


  // Setup Canvas
        BeginDrawing();
        // Clear canvas to a specific color to avoid flicker
        //Creating game elements paddles, ball, and midcourt line
        DrawLine(screenWidth/2, 0, screenWidth/2, screenHeight, WHITE);
ball.Draw();
DrawRectangle(10,screenHeight / 2 - 60,25,120,WHITE);
DrawRectangle(screenWidth-35, screenHeight / 2 - 60, 25, 120, WHITE);
        EndDrawing();

}

        
    

//De-initialization

    CloseWindow();
    return 0;
}
