#include <raylib.h>
#include <raygui.h>

int main() {
    InitWindow(400, 300, "Calculator");
    SetTargetFPS(60);
    
    while (!WindowShouldClose()) {

        BeginDrawing();
            ClearBackground(RAYWHITE);


            if (GuiButton((Rectangle){50, 50, 50, 25}, "1")) {
          
        }   
        EndDrawing();

    }

    CloseWindow();
    return 0;
}
