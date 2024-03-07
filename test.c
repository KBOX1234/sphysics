#include "raylib.h"
#include "sphysics.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "test window");

    SetTargetFPS(60);

    Vector2 box1 = {100, 100};
    Vector2 box1size = {100, 100};
    struct point mouse; 

    struct colideBox hitbox = {{box1.x, box1.y}, {box1.x+100, box1.y+100}};
    while (!WindowShouldClose())
    {
        BeginDrawing();
            
            mouse.x = GetMouseX();
            mouse.y = GetMouseY();

            ClearBackground(RAYWHITE);

            if(doesBoxAndPointColide(&hitbox, &mouse) == 1){
                DrawRectangleV(box1, box1size, RED);
            }
            else DrawRectangleV(box1, box1size, GREEN);
      
            

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
