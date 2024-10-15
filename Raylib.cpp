#include "Raylib.h"

// Implémentation de RaylibWindow
RaylibWindow::RaylibWindow() {}

void RaylibWindow::InitWindow(int width, int height, const char* title) {
    ::InitWindow(width, height, title);
}

bool RaylibWindow::WindowShouldClose() {
    return ::WindowShouldClose();
}

void RaylibWindow::CloseWindow() {
    ::CloseWindow();
}

void RaylibWindow::Refresh() {
    ::BeginDrawing();
    ::ClearBackground(RAYWHITE);
    ::EndDrawing();
}

RaylibWindow::~RaylibWindow() {
    CloseWindow();
}

// Implémentation de RaylibSprite
RaylibSprite::RaylibSprite(float x, float y, float radius, float speedX, float speedY)
    : x(x), y(y), radius(radius), speedX(speedX), speedY(speedY) {}

void RaylibSprite::Update() {
    x += speedX;
    y += speedY;

    if ((x - radius <= 0) || (x + radius >= ::GetScreenWidth())) speedX *= -1;
    if ((y - radius <= 0) || (y + radius >= ::GetScreenHeight())) speedY *= -1;
}

void RaylibSprite::Draw() {
    ::DrawCircle(static_cast<int>(x), static_cast<int>(y), radius, BLUE);
}

