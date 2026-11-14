#include "raylib.h"
#include <vector>

#define SQUARE_SIZE 40

int main() {
    int windowWidth = 400;
    int windowHeight = 800;

    InitWindow(windowWidth, windowHeight, "tetris");
    SetTargetFPS(60);

    Rectangle basicSquare = {100, 100, SQUARE_SIZE, SQUARE_SIZE};
    std::vector<Rectangle> shape;
    bool itsAttached = true;

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_SPACE)) {
            shape.clear();
            int amountSquares = GetRandomValue(1, 5);

            for (int i = 0; i < amountSquares; ++i) {
                Rectangle square = basicSquare;
                int relativePos = GetRandomValue(0, 3);

                switch (relativePos) {
                case 0:
                    square.x += SQUARE_SIZE * (i + 1);
                    break;
                case 1:
                    square.y += SQUARE_SIZE * (i + 1);
                    break;
                case 2:
                    square.x -= SQUARE_SIZE * (i + 1);
                    break;
                case 3:
                    square.y -= SQUARE_SIZE * (i + 1);
                    break;
                default:
                    break;
                }

                shape.emplace_back(square);
            }
        }

        BeginDrawing();
        ClearBackground(BLACK);

        for (const auto& block : shape) {
            DrawRectangleRec(block, GREEN);
        }

        DrawRectangleRec(basicSquare, RED);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}