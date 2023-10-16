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
// making the ball move
void Update() {
x += speed_x;
y += speed_y;

// Ball collisions
    if (y + radius >= GetScreenHeight() || y - radius <=0)
    {
            speed_y *= -1;
    }

    if (x + radius >= GetScreenWidth() || x - radius <=0)
    {
        speed_x *= -1;
    }

}

};

//Paddle class

class paddle {
    public:
    float x,y;
    float width, height;
    int speed;

    void Draw() {
        DrawRectangle(x,y, width, height, WHITE);
    }
    
    // Paddle movements

    void Update(){
        if (IsKeyDown(KEY_UP))
        {
            y = y - speed;
        }

        if(IsKeyDown(KEY_DOWN))

        {
            y = y + speed;
        }

        //Restricting Paddle movements to screen

        if(y <= 0)
        {
            y = 0;
        }
        if(y + height >= GetScreenHeight())
        {
            y = GetScreenHeight() - height;
        }
    }

};

//Computer Paddle to inherit from Player/paddle. 

class CpuPaddle: public paddle
{

//Update CPU paddle with Ai using Y co-ordinates
  public:

    void Update(int ball_y)
    {
        if(y + height/2 > ball_y)
        {
        y = y - speed;
        }

        if(y + height/2 <= ball_y)
        {
        y = y + speed;
        }

    }
  
};

//Objects

Ball ball;
paddle player;
CpuPaddle cpu;

int main() {
    // Determine the Game Window Width and Height
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

// Setting player/paddle parameters
    player.width = 25;
    player.height =120;
    player.x = screenWidth - player.width -10;
    player.y = screenHeight/2 - player.height/2;
    player.speed = 6;

//CPU paddle parameters

    cpu.height = 120;
    cpu.width = 25; 
    cpu.x = 10;
    cpu.y = screenHeight/2 - cpu.height/2;
    cpu.speed = 6;


    // The Game Loop
while (WindowShouldClose() == false) {


  // Setup Canvas
        BeginDrawing();
        
        // Update Methods
        ball.Update();
        player.Update();
        cpu.Update(ball.y);

    //Clearing canvas to remove ball trail
    ClearBackground(BLACK);

        //Creating game elements paddles, ball, and midcourt line
        DrawLine(screenWidth/2, 0, screenWidth/2, screenHeight, WHITE);

        //Add new draw protocols

        ball.Draw();
        player.Draw();
        cpu.Draw();

        EndDrawing();

}

//De-initialization

    CloseWindow(); 
    return 0;

};
        
    