#include "raylib.h"
#include "sphysics.h"

#define MAX_POLYGONS 5

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    // Initialize window
    InitWindow(screenWidth, screenHeight, "SPhysics Demo");

    // Initialize physics objects
    struct point pointA = { 100, 100 };
    struct point pointB = { 200, 200 };

    struct colideBox boxA = { { 300, 100 }, { 400, 200 } };
    struct colideBox boxB = { { 500, 100 }, { 600, 200 } };

    struct colidePolygon polyA = { { 100, 300 }, { 200, 400 }, { 800, 0 } };
    struct colidePolygon polyB = { { 300, 300 }, { 400, 400 }, { 200, 400 } };

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            pointA.x = GetMouseX();
            pointA.y = GetMouseY();
        }

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw physics objects
        DrawCircle(pointA.x, pointA.y, 5, RED);
        DrawRectangleLines(boxA.a.x, boxA.a.y, boxA.b.x - boxA.a.x, boxA.b.y - boxA.a.y, BLUE);
        DrawRectangleLines(boxB.a.x, boxB.a.y, boxB.b.x - boxB.a.x, boxB.b.y - boxB.a.y, BLUE);
        Vector2 triangleA[] = { { polyA.a.x, polyA.a.y }, { polyA.b.x, polyA.b.y }, { polyA.c.x, polyA.c.y } };
        Vector2 triangleB[] = { { polyB.a.x, polyB.a.y }, { polyB.b.x, polyB.b.y }, { polyB.c.x, polyB.c.y } };
        DrawTriangleLines(triangleA[0], triangleA[1], triangleA[2], GREEN);
        DrawTriangleLines(triangleB[0], triangleB[1], triangleB[2], GREEN);

        struct point org = {0, 0};

        if(IsKeyDown(KEY_A)){
            rotatePoly(&polyB, 1, org);
        }

        // Check collisions
        if (doesBoxAndPointColide(&boxA, &pointA)) DrawText("Box A collided with Point A", 10, 10, 20, BLACK);
        if (doesBoxAndPointColide(&boxB, &pointA)) DrawText("Box B collided with Point A", 10, 30, 20, BLACK);
        if (doesBoxAndBoxColide(&boxA, &boxB)) DrawText("Box A collided with Box B", 10, 50, 20, BLACK);
        if (doesPointAndPolyColide(&polyA, &pointA)) DrawText("Polygon A collided with Point A", 10, 70, 20, BLACK);
        if (doesPointAndPolyColide(&polyB, &pointA)) DrawText("Polygon B collided with Point A", 10, 90, 20, BLACK);
        if (doesPolyAndPolyColide(&polyA, &polyB)) DrawText("Polygon A collided with Polygon B", 10, 110, 20, BLACK);

        EndDrawing();
    }

    // Close window and OpenGL context
    CloseWindow();

    return 0;
}
