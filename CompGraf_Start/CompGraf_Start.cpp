// CompGraf_Start.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <GLFW/glfw3.h>
#include "math.h"
const int steps = 100;
const float pi = 3.1415;
const float angle = pi*2.f/steps;

void drawZub(float radis, float xPos1, float yPos1, float rz, float bz, float gz)
{
    int stepz = 18;
    float angel1 = 2 * pi / stepz;
    for (int i = 0; i <= stepz; i += 2)
    {
        float newx1 = xPos1 + radis * sin(angel1 * i );
        float newy1 = yPos1 + radis * cos(angel1 * i );
        float newx2 = xPos1 + (radis * 6.4) / 5 * sin(2 * pi / 72 + angel1 * i);
        float newy2 = yPos1 + (radis * 6.4) / 5 * cos(2 * pi / 72 + angel1 * i);
        float newx3 = xPos1 + (radis * 6.4) / 5 * sin(2 * pi / 20 + angel1 * i);
        float newy3 = yPos1 + (radis * 6.4) / 5 * cos(2 * pi / 20 + angel1 * i);
        float newx4 = xPos1 + radis * sin(2 * pi / 15.65 + angel1 * i);
        float newy4 = yPos1 + radis * cos(2 * pi / 15.65 + angel1 * i);

        glBegin(GL_QUADS);
        glColor3f(rz, bz, gz);
        glVertex2f(newx1, newy1);
        glVertex2f(newx2, newy2);
        glVertex2f(newx3, newy3);
        glVertex2f(newx4, newy4);
        glEnd();
    }
}

void drawCircle(float xPos, float yPos, float radius, float r, float g, float b)
{
    float prevX = xPos;
    float prevY = yPos + radius;
    for (int i = 0; i <= steps; i++)
    {
        float newX = xPos + radius * sin(angle * i);
        float newY = yPos + radius * cos(angle * i);
        glBegin(GL_TRIANGLES);
        glColor3f(r, g, b);
        glVertex2f(xPos, yPos);
        glVertex2f(prevX, prevY);
        glVertex2f(newX, newY);
        glEnd();

        prevX = newX;
        prevY = newY;
        
    }
}


void drawShesternya(float x0, float y0, float r0, float r1, float R, float G, float B)
{
    drawCircle(x0, y0, r0, R, G, B);
    drawCircle(x0, y0, r1, 1, 1, 1);
    drawZub(r0, x0, y0, R, G, B);
}

int main()
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1640, 1640, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    //glLoadIdentity();
    /* Loop until the user closes the window */
    int k = 1;
    float speedrot = 0.0001;
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClearColor(1.0, 1.0, 1.0, 0);
       
   
        glClear(GL_COLOR_BUFFER_BIT);
        
        glPushMatrix();
        glTranslatef(0.38, 0.37, 0);
        glRotatef(speedrot*k, 0, 0,1);
        drawShesternya(0, 0, 0.45, 0.31, 0.1, 0.1, 0.1);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-0.395, -0.34, 0);
        glRotatef(speedrot * k, 0, 0, 1);
        drawShesternya(0, 0, 0.35, 0.25, 0.5, 1, 1);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-0.5, 0.4, 0);
        glRotatef(speedrot *(-k), 0, 0, 1);
        drawShesternya(0, 0, 0.3, 0.22, 1, 0.5, 0);
        drawCircle(0,0,0.25,1,0.5,0);
        glPopMatrix();
        if (speedrot * k >= 360)
            k = 0;
        k += 1;
        if (speedrot<0.5)
        {
            speedrot += 0.00002;
        }
        
        
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
        
        
    }

    glfwTerminate();
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
