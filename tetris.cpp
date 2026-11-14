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

            for (int i = 0; i < amountSquares; i++) {
                Rectangle square = basicSquare;
                int relativePos = GetRandomValue(0, 4);

                switch (relativePos) {
                case 0:
                    square.x += SQUARE_SIZE;
                    break;
                case 1:
                    square.y += SQUARE_SIZE;
                    break;
                case 2:
                    square.x -= SQUARE_SIZE;
                    break;
                case 3:
                    square.y -= SQUARE_SIZE;
                    break;
				case 4:
                default:
                    break;
                }

                shape.emplace_back(square);
            }
        }

		bool moveRight = false;
		bool moveLeft = false;

		if (IsKeyDown(KEY_RIGHT)) {
			moveRight = true;
		}

		if (IsKeyDown(KEY_LEFT)) {
			moveLeft = true;
		}
		
		for (auto& block : shape) { // moves all blocks down.
			block.y += 5;
			if (moveLeft) {
				block.x -= 10;
			} else if (moveRight) {
				block.x += 10;
			}
        }

        BeginDrawing();
        ClearBackground(BLACK);

        for (const auto& block : shape) {
            DrawRectangleRec(block, GREEN);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}