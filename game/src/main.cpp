#include "raylib.h"
#include "raymath.h"
#include "raygui.h"

int main()
{
    InitWindow(800, 800, "Physics-1"); // creates a window that is 800 pixels wide and 800 pixels tall
    InitAudioDevice(); // starts the audio system 
    SetTargetFPS(60); // Makes the program run at 60 frames per second
     
    float x = 400.0f; // Sets the purple circle's starting horizontal position X to 400
    float y = 400.0f; // Sets the purple circle's starting vertical position Y to 400
    float a = 10.0f;    // amplitude (radius of movement)
    float b = 4.0f;     // frequency (rate of movement)

    Vector2 pos = { 100.0f, 400.0f }; // Sets the starting position of the red circle X (100) and Y (400)

    while (!WindowShouldClose())  // Keeps the game running until the window closes
    {
        float dt = GetFrameTime(); 
        float t = GetTime();

        pos += Vector2UnitX * 100.0f * dt; // Moves the red circle to the right every frame because of the Vector2UnitX

        y = y + (cos(t * 10.0f)) * 10.0f * 4.0f * dt; // Changes the purple circle's Y position using the cosine part of the equation. The cosine uses the game time to create a changing up-and-down movement. The 10 controls the frequency, the 4 controls the amplitude, and dt accounts for the time between frames.
        x = x + (-sin(t * 10.0f)) * 10.0f * 4.0f * dt; // Changes the purple circle's X position using the sine part of the equation. The sine function creates the left-and-right movement

        BeginDrawing();

            ClearBackground(WHITE); // Makes the background white
            DrawCircleV(pos, 20.0f, RED); // Controls the size of the red circle
            DrawText("Game Physics - Shayaan Faisal 101551744", 20, 770, 20, RED); // Displays information at the bottom left of the screen
            DrawCircleV(GetMousePosition(), 20.0f, YELLOW); // Shows a yellow circle which follows wherever the mouse is at
            const char* timeText = TextFormat("Time: %.2f", t); // Creates text that shows the game timer
            DrawText(timeText, 680, 20, 20, BLACK); // Displays the timer at the top right of the screen
            DrawCircle(x, y, 25.0f, PURPLE); // Controls the size of the purple circle

        EndDrawing();
    }

    CloseAudioDevice(); // Turns off the audio system when the program ends
    CloseWindow(); // Closes the game window when the program ends
    return 0; // Tells the computer that the program ended successfully
}