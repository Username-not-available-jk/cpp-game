#include "raylib.h"
#include <vector>

int main() {
	int windowWidth = 400;
	int windowHeight = 800;
	InitWindow(windowWidth, windowHeight, "My Game");
	SetTargetFPS(60);

	Rectangle player = {0, (float)(windowHeight - 40), 40, 40};
	int playerSpeedMult = 5;
	Rectangle enemy = {40, 300, 40, 40};
	int enemySpeed = 6;
	int speedMutiplier = 1;
	std::vector<Rectangle> bullets;
	int bulletsSpeed = 20;
	int killsCounter = 0;



	while (!WindowShouldClose()) {
		if ((killsCounter/2) > 1 && (killsCounter/2) < 5){
			speedMutiplier = killsCounter/2;
		}
		// movement and position of the player
		if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
			player.x += playerSpeedMult * speedMutiplier;
		}

		if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
			player.x -= playerSpeedMult * speedMutiplier;
		}

		if (player.x <= 0) {
			player.x = 0;
		}

		if (player.x >= (windowWidth - 40)) {
			player.x = windowWidth - 40;
		}

		if (IsKeyPressed(KEY_SPACE)) {
			Rectangle bullet = {player.x + 20, player.y, 5, 15};
			bullets.push_back(bullet);
		}

		for (int i = 0; i < bullets.size(); ) {
			bullets[i].y -= bulletsSpeed;

			if (bullets[i].y < 0) {
				bullets.erase(bullets.begin() + i);
			} else {
				i++;
			}
		}

		enemy.y += enemySpeed * speedMutiplier;

		if (enemy.y > windowHeight) { //if enemy leaves the window (touches the ground) it resets the values
			enemy.y = 10;
			enemy.x = (float)GetRandomValue(0, windowWidth - 40);
			killsCounter = 0;
			speedMutiplier = 1;
		}
		

		for (int i = 0; i < bullets.size(); i++) {
			if (CheckCollisionRecs(bullets[i], enemy)) {
				bullets.erase(bullets.begin() + i);
				enemy.y = 0;
				enemy.x = (float)GetRandomValue(0, windowWidth - 40);
				killsCounter++;
			}
		}

		BeginDrawing();

		ClearBackground(BLACK);

		for (const auto& bullet : bullets) {
			DrawRectangleRec(bullet, YELLOW);
		}

		DrawRectangleRec(player, GREEN);
		DrawRectangleRec(enemy, RED);

		DrawText(TextFormat("Enemies Killed: %d", killsCounter), 0, 0, 20, RED);
		EndDrawing();
	}
	return 0;
}