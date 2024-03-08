#include "raylib.h"
#include "sphysics.h"

int main() {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Point-Polygon Collision Detection");

    // Define the polygon (triangle)
    struct colidePolygon poly = {
        { 400, 100 },   // Point A
        { 300, 300 },   // Point B
        { 500, 323 }    // Point C
    };

    // Define the point
    struct point point = { 400, 200 };

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose()) {
        // Update

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        point.x = GetMouseX();
        point.y = GetMouseY();

        // Convert struct points to Vector2
        Vector2 v1 = { poly.a.x, poly.a.y };
        Vector2 v2 = { poly.b.x, poly.b.y };
        Vector2 v3 = { poly.c.x, poly.c.y };

        // Draw the polygon
        DrawTriangle(v1, v2, v3, RED);

        // Draw the point
        DrawCircle(point.x, point.y, 5, BLUE);

        // Check for collision
        if (doesPointAndPolyColide(&poly, &point)) {
            DrawText("Collision Detected!", 10, 10, 20, GREEN);
        }

        EndDrawing();
    }

    // Close window and OpenGL context
    CloseWindow();

    return 0;
}