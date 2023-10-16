#include "raylib.h"

//scoreboard
int player_score = 0;
int cpu_score = 0;

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

    if (x + radius >= GetScreenWidth()) // breaking if statement into 2 to allow for score count for CPU and removing the directional code
    {
        cpu_score++;
    }
    
     if(x - radius <=0)
    {
        player_score++;
    }

}

};

//Paddle class

class paddle 

{
// creating inherited method to reduce code 
protected:

void LimitMovement() {

    //copied from restricting paddle movements
      if(y <= 0)
        {
            y = 0;
        }
        if(y + height >= GetScreenHeight())
        {
            y = GetScreenHeight() - height;
        }
}

    public:
    float x,y;
    float width, height;
    int speed;

    void Draw() {
        DrawRectangle(x, y, width, height, WHITE);
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
        LimitMovement();
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

        LimitMovement();

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

        // Paddle & Ball collisions

        if(CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{player.x, player.y, player.width, player.height}))
        {
            ball.speed_x *= -1; 
        }
        
        if(CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{cpu.x, cpu.y, cpu.width, cpu.height} ))
        {
            ball.speed_x *= -1;
        }


    //Clearing canvas to remove ball trail
    ClearBackground(BLACK);

        //Creating game elements paddles, ball, and midcourt line
        DrawLine(screenWidth/2, 0, screenWidth/2, screenHeight, WHITE);

        //Add new draw protocols

        ball.Draw();
        player.Draw();
        cpu.Draw();
        // Text boxes
        DrawText(TextFormat("%i" ,cpu_score), screenWidth/4 -20, 20, 80, WHITE);
        DrawText(TextFormat("%i" ,player_score), 3 * screenWidth/4 -20, 20, 80, WHITE);
        EndDrawing();

}

//De-initialization

    CloseWindow(); 
    return 0;

};
        
    