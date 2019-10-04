/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

#define MAX_BALLS 30


typedef struct Circles{
    float radius;
    Vector2 bola;
    Vector2 speed;
    Color color;
}Circles;

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Rebota Rebota en tu array explota");
    
    
    Circles ball[MAX_BALLS];
    
    for (int i = 0; i<MAX_BALLS; i++)
    {
        ball[i].radius = GetRandomValue (10,20);
        ball[i].bola.x = GetRandomValue (ball[i].radius,screenWidth-ball[i].radius);
        ball[i].bola.y = GetRandomValue (ball[i].radius,screenHeight-ball[i].radius);
        ball[i].speed.x = GetRandomValue (-9,9);
        ball[i].speed.y = GetRandomValue (-9,9);
        ball[i].color.r = (GetRandomValue (0,255));
        ball[i].color.g = (GetRandomValue (0,255));
        ball[i].color.b = (GetRandomValue (0,255));
        ball[i].color.a = (255);
    }
    
    
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //---------------------------------------------------------------------------------
        for (int i = 0; i<MAX_BALLS; i++)
        {
            ball[i].bola.x += ball[i].speed.x;
            ball[i].bola.y += ball[i].speed.y;
            if (ball[i].bola.x + ball[i].radius >= screenWidth || ball[i].bola.x - ball[i].radius <=0)
            {
            ball[i].speed.x *= -1;
            }
            if (ball[i].bola.y + ball[i].radius >= screenHeight || ball[i].bola.y -ball[i].radius <=0)
            {
            ball[i].speed.y *= -1;
            }
            for (int j= 0; j<MAX_BALLS; j++)
            {
                if (i==j)
                {
                    j++;
                    if (j >= MAX_BALLS)
                    {
                        break;
                    }
                }
                if (CheckCollisionCircles (ball[i].bola , ball[i].radius, ball[j].bola, ball[j].radius))
                {  
                    if (ball[i].speed.x>0)
                    {
                        if (ball[j].speed.x>0)
                        {
                            if (ball[i].speed.y>0)
                            {
                                if (ball[j].speed.y >0)
                                {
                                  if (ball[i].speed.y> ball[j].speed.y)  
                                  {
                                    ball[i].speed.y *= -1;
                                    ball[i].speed.x *= -1;
                                  }
                                  if (ball[j].speed.y> ball[i].speed.y)  
                                  {
                                    ball[j].speed.y *= -1;
                                    ball[j].speed.x *= -1;
                                  } 
                                }
                                if (ball[j].speed.y<0)
                                {
                                    ball[i].speed.y *= -1;
                                    ball[j].speed.y *= -1;
                                }
                            }
                            if (ball[i].speed.y<0)
                            {
                                if (ball[j].speed.y<0)
                                {
                                  if (ball[i].speed.y< ball[j].speed.y)  
                                  {
                                    ball[i].speed.y *= -1;
                                    ball[i].speed.x *= -1;
                                  }
                                  if (ball[j].speed.y< ball[i].speed.y)  
                                  {
                                    ball[j].speed.y *= -1;
                                    ball[j].speed.x *= -1;
                                  }
                                }
                                if (ball[j].speed.y>0)
                                {
                                    ball[i].speed.y *= -1;
                                    ball[j].speed.y *= -1;
                                } 
                            }
                        }
                    }
                    if (ball[i].speed.x<0)
                    {
                        if (ball[j].speed.x<0)
                        {
                            if (ball[i].speed.y>0)
                            {
                                if (ball [j].speed.y>0)
                                {
                                  if (ball[i].speed.y> ball[j].speed.y)  
                                  {
                                    ball[i].speed.y *= -1;
                                    ball[i].speed.x *= -1;
                                  }
                                  if (ball[j].speed.y> ball[i].speed.y)  
                                  {
                                    ball[j].speed.y *= -1;
                                    ball[j].speed.x *= -1;
                                  }
                                }
                                if (ball[j].speed.y<0)
                                {
                                    ball[i].speed.y *= -1;
                                    ball[j].speed.y *= -1;
                                }
                            }
                            if (ball[i].speed.y<0)
                            {
                                if (ball[j].speed.y<0)
                                {
                                  if (ball[i].speed.y< ball[j].speed.y)  
                                  {
                                    ball[i].speed.y *= -1;
                                    ball[i].speed.x *= -1;
                                  }
                                  if (ball[j].speed.y< ball[i].speed.y)  
                                  {
                                    ball[j].speed.y *= -1;
                                    ball[j].speed.x *= -1;
                                  }
                                }
                                if (ball[j].speed.y>0)
                                {
                                  ball[i].speed.y *= -1;
                                  ball[j].speed.y *= -1;
                                }
                            }
                        }
                    }

                    else
                    {
                        if (ball[i].speed.y <0 || ball[i].speed.y >0)
                        {
                            if (ball[j].speed.y <0 || ball[j].speed.y >0 )
                            {
                                ball[i].speed.x *= -1;
                                ball[j].speed.x *= -1;
                            }
                        }
                        
                        else
                        {
                            ball[i].speed.y *= -1;
                            ball[j].speed.y *= -1;
                            ball[i].speed.x *= -1;
                            ball[j].speed.x *= -1;
                        }
                    }
                }
            }
        }

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

          ClearBackground(RAYWHITE);
          
          for (int i = 0; i<MAX_BALLS; i++)
          {
              DrawCircle (ball[i].bola.x, ball[i].bola.y, ball[i].radius, ball[i].color);
          }

          

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}