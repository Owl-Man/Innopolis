#include "raylib.h"

typedef enum { IDLE, MOVING} EntityState;


typedef struct 
{
    Vector2 pos;
    Vector2 vel;
    float radius;
    Color color;
    EntityState state;
} Entity;


void update_entity(Entity *e, float dt) 
{
    e->pos.y += e->vel.x * dt;
    e->pos.y += e->vel.y * dt;

    if (e->pos.x < e->radius || e->pos.x > 800 - e->radius) 
    {
        e->vel.x *= -1;
        e->state = MOVING;
    }

    if (e->pos.x < e->radius || e->pos.x > 450 - e->radius) 
    {
        e->vel.y *= -1;
        e->state = MOVING;
    }
}

void draw_entity(Entity *e)
{
    DrawCircleV(e->pos, e->radius, e->color);
    if (e->state == MOVING)
    {
        DrawCircleLines(e->pos.x, e->pos.y, e->radius + 5, RED);
    }
}

void update_player(Entity *player, int screenWidth, int screenHeight, float dt)
{
    player->state = IDLE;

    if (IsKeyDown(KEY_W)) 
    {
        player->pos.y -= player->vel.y * dt;
        player->state = MOVING; 
    }

    if (IsKeyDown(KEY_S)) 
    {
        player->pos.y += player->vel.y * dt;
        player->state = MOVING; 
    }

    if (IsKeyDown(KEY_A)) 
    {
        player->pos.x -= player->vel.x * dt;
        player->state = MOVING; 
    }

    if (IsKeyDown(KEY_D)) 
    {
        player->pos.x += player->vel.x * dt;
        player->state = MOVING; 
    }

    if (player->pos.x < player->radius) player->pos.x = player->radius;
    if (player->pos.x > screenWidth - player->radius) player->pos.x = screenWidth - player->radius;
    if (player->pos.y < player->radius) player->pos.y = player->radius;
    if (player->pos.y > screenHeight - player->radius) player->pos.y = screenHeight - player->radius;
}

int main(int argc, char *argv[])
{
    InitWindow(800, 450, "SomethingEngine");
    SetTargetFPS(60);


    Entity player = 
    {
        .pos = {400, 255},
        .vel = {150, 100},
        .radius = 20,
        .color = BLUE,
        .state = IDLE
    };

    while (!WindowShouldClose()) 
    {
        float dt = GetFrameTime();
        // update_entity(&player, dt);
        update_player(&player, GetScreenWidth(), GetScreenHeight(), dt);

        BeginDrawing();
        ClearBackground(RAYWHITE);
        draw_entity(&player);
        DrawText("SomethingEngine", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
