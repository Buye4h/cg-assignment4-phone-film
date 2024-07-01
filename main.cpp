#undef GLFW_DLL
#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <vector>
#include <cmath>

#include "Libs/Shader.h"
#include "Libs/Window.h"
#include "Libs/Mesh.h"
#include "Libs/stb_image.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// 63050147 Tharita Watanapa sec1
// 63050166 Pilada Prasan sec2
// Assignment 4
const GLint WIDTH = 800, HEIGHT = 600;

Window mainWindow;
std::vector<Mesh *> meshList;
std::vector<Shader> shaderList;

glm::vec3 lightColour = glm::vec3(1.0f, 1.0f, 1.0f);

// float yaw = 0.0f, pitch = 0.0f;

// Vertex Shader
static const char *vShader = "Shaders/shader.vert";

// Fragment Shader
static const char *fShader = "Shaders/shader.frag";

void CreateOBJ()
{
    // Object about sea-----------------------------------------------------------------
    //ทราย
    Mesh *sand = new Mesh();
    bool loaded1 = sand->CreateMeshFromOBJ("Models/sand.obj");
    //ทะเล
    Mesh *sea = new Mesh();
    bool loaded2 = sea->CreateMeshFromOBJ("Models/sea.obj");
    //เรือ
    Mesh *boat = new Mesh();
    bool loaded3 = boat->CreateMeshFromOBJ("Models/boat.obj");
    //ที่นั่งเรือ
    Mesh *seatBoat = new Mesh();
    bool loaded4 = seatBoat->CreateMeshFromOBJ("Models/boat_seats.obj");
    //ท่าน้ำ
    Mesh *waterside = new Mesh();
    bool loaded5 = waterside->CreateMeshFromOBJ("Models/waterside.obj");

    // Object about sunbathe-----------------------------------------------------------------
    //ก้อนหิน 5 ก้อน
    Mesh *rock = new Mesh();
    bool loaded6 = rock->CreateMeshFromOBJ("Models/Rock.obj");
    //ร่มชายหาด
    Mesh *umbrella = new Mesh();
    bool loaded7 = umbrella->CreateMeshFromOBJ("Models/umbrella.obj");
    //เก้าอี้ชายหาด ซ้าย
    Mesh *chair_L = new Mesh();
    bool loaded8 = chair_L->CreateMeshFromOBJ("Models/chair_L.obj");
    //เก้าอี้ชายหาด ขวา
    Mesh *chair_R = new Mesh();
    bool loaded9 = chair_R->CreateMeshFromOBJ("Models/chair_R.obj");

    // Object about House-----------------------------------------------------------------
    //เสาใต้ถุน
    Mesh *pillars_lowest = new Mesh();
    bool loaded10 = pillars_lowest->CreateMeshFromOBJ("Models/pillar_lowest.obj");
    //เสาค้ำกากบาทใต้ถุน
    Mesh *pillars_cross = new Mesh();
    bool loaded11 = pillars_cross->CreateMeshFromOBJ("Models/pillar_cross.obj");
    //ฐานบ้าน
    Mesh *basehome_lowest = new Mesh();
    bool loaded12 = basehome_lowest->CreateMeshFromOBJ("Models/lowestBaseHome.obj");
    //ฐานบ้าน แผ่นพื้นไม้
    Mesh *basehome_wooden = new Mesh();
    bool loaded13 = basehome_wooden->CreateMeshFromOBJ("Models/WoodenBaseHome.obj");
    //เสาบน
    Mesh *pillars = new Mesh();
    bool loaded14 = pillars->CreateMeshFromOBJ("Models/pillars.obj");
    //ราวจับ
    Mesh *pillars_upper = new Mesh();
    bool loaded15 = pillars_upper->CreateMeshFromOBJ("Models/pillar_upper.obj");
    //ตัวบ้าน
    Mesh *home = new Mesh();
    bool loaded16 = home->CreateMeshFromOBJ("Models/house.obj");
    //หลังคา
    Mesh *roof = new Mesh();
    bool loaded17 = roof->CreateMeshFromOBJ("Models/roof.obj");
    //กันสาด
    Mesh *roof_front = new Mesh();
    bool loaded18 = roof_front->CreateMeshFromOBJ("Models/frontRoof.obj");
    //ป้ายไม้ติดบนประตูบ้าน
    Mesh *signhome = new Mesh();
    bool loaded19 = signhome->CreateMeshFromOBJ("Models/signHome.obj");
    //หน้าต่างกลม
    Mesh *window_circle = new Mesh();
    bool loaded20 = window_circle->CreateMeshFromOBJ("Models/window_circle.obj");
    //หน้าต่างเหลี่ยม หน้าบ้าน
    Mesh *window_regular = new Mesh();
    bool loaded21 = window_regular->CreateMeshFromOBJ("Models/window_reg.obj");
    //ประตูบ้าน
    Mesh *door = new Mesh();
    bool loaded22 = door->CreateMeshFromOBJ("Models/door.obj");
    //ลูกบิดประตู
    Mesh *door_knob = new Mesh();
    bool loaded23 = door_knob->CreateMeshFromOBJ("Models/knob.obj");

    // Object about decorations-----------------------------------------------------------------
    //ห่วงยาง หน้าบ้าน
    Mesh *swimring = new Mesh();
    bool loaded24 = swimring->CreateMeshFromOBJ("Models/swimring_home.obj");
    //ห่วงยาง ข้างบ้าน
    Mesh *swimring_side = new Mesh();
    bool loaded25 = swimring_side->CreateMeshFromOBJ("Models/swimring_01.obj");
    //ลังไม้ ฐานกลม ซ้าย
    Mesh *crate_L = new Mesh();
    bool loaded26 = crate_L->CreateMeshFromOBJ("Models/Crate_L.obj");
    //ลังไม้ ฐานกลม ขวา
    Mesh *crate_R = new Mesh();
    bool loaded27 = crate_R->CreateMeshFromOBJ("Models/Crate_R.obj");
    //ราวบันได
    Mesh *stair = new Mesh();
    bool loaded28 = stair->CreateMeshFromOBJ("Models/stairs.obj");
    //แผ่นบันไดไม้
    Mesh *stair_wood = new Mesh();
    bool loaded29 = stair_wood->CreateMeshFromOBJ("Models/wood_stair.obj");
    //เบ็ดตกปลา
    Mesh *rod = new Mesh();
    bool loaded30 = rod->CreateMeshFromOBJ("Models/rod.obj");
    //กล่องไม้ 3 กล่อง
    Mesh *woodcase = new Mesh();
    bool loaded31 = woodcase->CreateMeshFromOBJ("Models/woodCase.obj");

    // Loading
    //  Object about sea-----------------------------------------------------------------
    if (loaded1)
    {
        meshList.push_back(sand);
    }
    if (loaded2)
    {
        meshList.push_back(sea);
    }
    if (loaded3)
    {
        meshList.push_back(boat);
    }
    if (loaded4)
    {
        meshList.push_back(seatBoat);
    }
    if (loaded5)
    {
        meshList.push_back(waterside);
    }
    // Object about sunbathe-----------------------------------------------------------------
    if (loaded6)
    {
        meshList.push_back(rock);
    }
    if (loaded7)
    {
        meshList.push_back(umbrella);
    }
    if (loaded8)
    {
        meshList.push_back(chair_L);
    }
    if (loaded9)
    {
        meshList.push_back(chair_R);
    }
    // Object about House-----------------------------------------------------------------
    if (loaded10)
    {
        meshList.push_back(pillars_lowest);
    }
    if (loaded11)
    {
        meshList.push_back(pillars_cross);
    }
    if (loaded12)
    {
        meshList.push_back(basehome_lowest);
    }
    if (loaded13)
    {
        meshList.push_back(basehome_wooden);
    }
    if (loaded14)
    {
        meshList.push_back(pillars);
    }
    if (loaded15)
    {
        meshList.push_back(pillars_upper);
    }
    if (loaded16)
    {
        meshList.push_back(home);
    }
    if (loaded17)
    {
        meshList.push_back(roof);
    }
    if (loaded18)
    {
        meshList.push_back(roof_front);
    }
    if (loaded19)
    {
        meshList.push_back(signhome);
    }
    if (loaded20)
    {
        meshList.push_back(window_circle);
    }
    if (loaded21)
    {
        meshList.push_back(window_regular);
    }
    if (loaded22)
    {
        meshList.push_back(door);
    }
    if (loaded23)
    {
        meshList.push_back(door_knob);
    }
    // Object about decorations-----------------------------------------------------------------
    if (loaded24)
    {
        meshList.push_back(swimring);
    }
    if (loaded25)
    {
        meshList.push_back(swimring_side);
    }
    if (loaded26)
    {
        meshList.push_back(crate_L);
    }
    if (loaded27)
    {
        meshList.push_back(crate_R);
    }
    if (loaded28)
    {
        meshList.push_back(stair);
    }
    if (loaded29)
    {
        meshList.push_back(stair_wood);
    }
    if (loaded30)
    {
        meshList.push_back(rod);
    }
    if (loaded31)
    {
        meshList.push_back(woodcase);
    }
    else
    {
        std::cout << "Failed to load model" << std::endl;
    }
}

void CreateShaders()
{
    Shader *shader1 = new Shader();
    shader1->CreateFromFiles(vShader, fShader);
    shaderList.push_back(*shader1);
}
// // Follow Mouse
// void mouse_callback(GLFWwindow *window, double xPos, double yPos)
// {
//     static float lastX = mainWindow.getBufferWidth() / 2.0f;
//     static float lastY = mainWindow.getBufferHeight() / 2.0f;

//     float xOffset = xPos - lastX;
//     float yOffset = lastY - yPos;

//     lastX = xPos;
//     lastY = yPos;

//     float sensitivity = 0.1f;
//     xOffset *= sensitivity;
//     yOffset *= sensitivity;

//     yaw += xOffset;
//     pitch += yOffset;

//     if (pitch > 89.0f)
//         pitch = 89.0f;
//     if (pitch < -89.0f)
//         pitch = -89.0f;
// }

int main()
{
    mainWindow = Window(WIDTH, HEIGHT, 3, 3);
    mainWindow.initialise();

    // CreateTriangle();
    CreateShaders();
    CreateOBJ();

    GLuint uniformModel = 0, uniformProjection = 0, uniformView = 0;

    glm::mat4 projection = glm::perspective(45.0f, (GLfloat)mainWindow.getBufferWidth() / (GLfloat)mainWindow.getBufferHeight(), 0.1f, 100.0f);
    // All Objects's scale equal
    // glm::mat4 projection = glm::ortho(-4.0f, 4.0f, -3.0f, 3.0f, 0.1f, 100.0f);

    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

    glm::vec3 cameraDirection = glm::normalize(cameraTarget - cameraPos);

    glm::vec3 cameraRight = glm::normalize(glm::cross(cameraDirection, up));
    glm::vec3 cameraUp = glm::normalize(glm::cross(cameraDirection, -cameraRight));

    // texture
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, nrChannels;
    unsigned char *data = stbi_load("Textures/uvmap.png", &width, &height, &nrChannels, 0);
    if (data)
    {
        // bind image with texture
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    // MousePOS
    // glfwSetCursorPosCallback(mainWindow.getWindow(), mouse_callback);

    // Loop until window closed
    while (!mainWindow.getShouldClose())
    {
        // Get + Handle user input events
        glfwPollEvents();

        // glm::vec3 direction;
        //  direction.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
        //  direction.y = sin(glm::radians(pitch));
        //  direction.z = cos(glm::radians(pitch)) * sin(glm::radians(yaw));
        // cameraDirection = glm::normalize(direction);

        cameraRight = glm::normalize(glm::cross(cameraDirection, up));
        cameraUp = glm::normalize(glm::cross(cameraDirection, -cameraRight));

        if (glfwGetKey(mainWindow.getWindow(), GLFW_KEY_W) == GLFW_PRESS)
            cameraPos += cameraDirection * 0.01f;
        if (glfwGetKey(mainWindow.getWindow(), GLFW_KEY_S) == GLFW_PRESS)
            cameraPos -= cameraDirection * 0.01f;
        if (glfwGetKey(mainWindow.getWindow(), GLFW_KEY_A) == GLFW_PRESS)
            cameraPos -= cameraRight * 0.01f;
        if (glfwGetKey(mainWindow.getWindow(), GLFW_KEY_D) == GLFW_PRESS)
            cameraPos += cameraRight * 0.01f;

        // Clear window
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // draw here
        shaderList[0].UseShader();
        uniformModel = shaderList[0].GetUniformLocation("model");
        uniformView = shaderList[0].GetUniformLocation("view");
        uniformProjection = shaderList[0].GetUniformLocation("projection");

        glm::vec3 pyramidPositions[] =
            {
                glm::vec3(0.0f, -5.0f, -10.5f),
            };

        glm::mat4 view(1.0f);

        glm::mat4 cameraPosMat(1.0f);
        cameraPosMat[0][3] = cameraPos.x;
        cameraPosMat[1][3] = cameraPos.y;
        cameraPosMat[2][3] = cameraPos.z;

        glm::mat4 cameraRotateMat(1.0f);
        cameraRotateMat[0] = glm::vec4(cameraRight.x, cameraUp.x, cameraDirection.x, 0.0f);
        cameraRotateMat[1] = glm::vec4(cameraRight.y, cameraUp.y, cameraDirection.y, 0.0f);
        cameraRotateMat[2] = glm::vec4(-cameraRight.z, -cameraUp.z, -cameraDirection.z, 0.0f);

        view = glm::lookAt(cameraPos, cameraPos + cameraDirection, up);

        // Object 1
        {

            for (int i = 0; i < 31; i++)
            {
                glm::mat4 model(1.0f);
                model = glm::translate(model, glm::vec3(0.0f, -5.0f, -10.5f));
                // model = glm::rotate(model, glm::radians(2.0f * i), glm::vec3(1.0f, 0.3f, 0.5f));
                model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));

                glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
                glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(view));
                glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));

                // light
                glUniform3fv(shaderList[0].GetUniformLocation("lightColour"), 1, (GLfloat *)&lightColour);

                glActiveTexture(GL_TEXTURE0);
                glBindTexture(GL_TEXTURE_2D, texture);

                meshList[i]->RenderMesh();
            }
        }

        glUseProgram(0);
        // end draw

        mainWindow.swapBuffers();
    }

    return 0;
}
