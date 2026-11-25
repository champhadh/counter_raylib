#include "raylib.h"

int main(void){
    const int screenWidth = 800;
    const int screenLength = 450; 

    Rectangle addButton = {300, 300, 100, 100};
    Rectangle subButton = {425, 300, 100, 100};
    Rectangle resetButton = {360, 420, 100, 25};

    InitWindow(screenWidth, screenLength, "Counter");


    SetTargetFPS(60);

    int counter = 0; 

    while (!WindowShouldClose()) {

        // checks where the mouse
        Vector2 mousePos = GetMousePosition();
        
        BeginDrawing(); // startings the frame
            ClearBackground(RAYWHITE);

            DrawText("Counter", 360, 50, 20, LIGHTGRAY);
            DrawText("Number: ", 300, 175, 20, LIGHTGRAY);


            DrawRectangleRec(addButton, Fade(GREEN, 0.5f));
            DrawRectangleRec(subButton, Fade(RED, 0.5f));
            DrawRectangleRec(resetButton, Fade(RED, 0.5f));

            DrawText("+", 310, 280, 150, WHITE);

            DrawText("-", 445, 280, 150, WHITE);



    
        // checkcollisionpointrec(...) is the mouse on the button?
        // ismousebuttonpredded did mouse click
        if (CheckCollisionPointRec(mousePos, addButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            counter += 1;
        } else if (CheckCollisionPointRec(mousePos, subButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            if (counter > 0) {
                counter -= 1;
            }
        } else if (CheckCollisionPointRec(mousePos, resetButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            counter = 0;
        }

        DrawText("Reset", 380, 420, 20, BLACK);
        DrawText(TextFormat("%d", counter), 400, 175, 20, BLACK);

        EndDrawing();

    }

    CloseWindow();

    return 0;
}