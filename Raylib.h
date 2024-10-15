#include "WindowSprite.h"
#include <raylib.h>

// Classe RaylibWindow pour gérer une fenêtre avec Raylib
class RaylibWindow : public Window {
public:
    RaylibWindow() {}

    void InitWindow(int width, int height, const char* title) override {
        ::InitWindow(width, height, title);
    }

    bool WindowShouldClose() override {
        return ::WindowShouldClose();
    }

    void CloseWindow() override {
        ::CloseWindow();
    }

    void Refresh() override {
        ::BeginDrawing();
        ::ClearBackground(RAYWHITE);
        // On peut ajouter le dessin de sprites ici
        ::EndDrawing();
    }

    ~RaylibWindow() {
        CloseWindow();
    }
};

// Classe RaylibSprite pour gérer un sprite dans Raylib
class RaylibSprite : public Sprite {
    float x, y;
    float radius;
    float speedX, speedY;

public:
    RaylibSprite(float x, float y, float radius, float speedX, float speedY)
        : x(x), y(y), radius(radius), speedX(speedX), speedY(speedY) {}

    void Update() override {
        // Mise à jour des coordonnées du cercle
        x += speedX;
        y += speedY;

        // Rebond sur les murs
        if ((x - radius <= 0) || (x + radius >= ::GetScreenWidth())) speedX *= -1;
        if ((y - radius <= 0) || (y + radius >= ::GetScreenHeight())) speedY *= -1;
    }

    void Draw() override {
        ::DrawCircle(static_cast<int>(x), static_cast<int>(y), radius, BLUE);
    }
};







#endif