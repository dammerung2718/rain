#include <raylib.h>
#include <stdio.h>

// config
const int dropsCount = 1024;
const int screenWidth = 800;
const int screenHeight = 600;
const int maxSpeed = 10;

// types
struct raindrop {
  Vector2 position;
  float speed;
  float length;
};

// entrypoint
int main() {
  int i;
  struct raindrop drops[dropsCount];

  InitWindow(screenWidth, screenHeight, "Raindrops in C");
  SetTargetFPS(60);

  for (i = 0; i < dropsCount; i++) {
    drops[i].position.x = GetRandomValue(0, screenWidth);
    drops[i].position.y = GetRandomValue(0, screenHeight);
    drops[i].speed = GetRandomValue(1, maxSpeed);
    drops[i].length = drops[i].speed;
  }

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);

    for (i = 0; i < dropsCount; i++) {
      drops[i].position.y += drops[i].speed;
      if (drops[i].position.y > screenHeight) {
        drops[i].position.y = 0;
        drops[i].position.x = GetRandomValue(0, screenWidth);
      }
      DrawLineEx(
          drops[i].position,
          (Vector2){drops[i].position.x, drops[i].position.y + drops[i].length},
          1, WHITE);
    }

    EndDrawing();
  }

  CloseWindow();
}
