#include <stdio.h>
#include <stdbool.h>
#include "raylib.h"

typedef struct Player 
{
    Vector2 position;
    float speed;
    bool canJump;
} Player;

bool has = 0;

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "sumit's window");
    
    Player player = { 0 };
    player.position = (Vector2){ 400, 280 };
    player.speed = 0;
    player.canJump = false;
      
    
    Rectangle playerRect = { player.position.x - 20, player.position.y - 40, 20, 20 };
    
    Rectangle obstacles = { 20, 30, 10 ,100};
    
    bool crash = CheckCollisionRecs(playerRect,obstacles);
  
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (WindowShouldClose() == 0)    // Detect window close button or ESC key
    {
        // Update
        //---------------------------------------------------------------------------------
        
        if(IsKeyDown(KEY_RIGHT)) playerRect.x += 3.0f;
        if(IsKeyDown(KEY_LEFT)) playerRect.x -= 3.0f;
        if(IsKeyDown(KEY_UP)) playerRect.y -= 3.0f;
        if(IsKeyDown(KEY_DOWN)) playerRect.y += 3.0f;
        
        if(crash)
        {
            has = 1;
        }
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);
        //HERE
        DrawText("GUI Game !", 10, 10, 20, BLACK);
        
        DrawRectangleRec(playerRect, RED);
        if(has)
        {
            DrawText("cashed ",50,50,20,BLUE);
        }
        
        DrawRectangleRec(obstacles,GRAY);
        
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}