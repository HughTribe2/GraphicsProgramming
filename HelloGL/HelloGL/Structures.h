#pragma once
#include <Windows.h>
#include <gl/GL.h>

struct Vector3
{
    float x, y, z;
};

struct Vector4
{
    float x, y, z, w;
};

struct Camera
{
    Vector3 eye, center, up;
};

struct Color
{
    GLfloat r, g, b;
};

struct Vertex
{
    GLfloat x, y, z;
};


struct TexCoord
{
    GLfloat u, v;
};

struct Mesh 
{
    Vertex* Vertices;
    Vector3* Normals;
    GLushort* Indices;
    TexCoord* TexCoords;

    int VertexCount, NormalCount, IndexCount, TexCoordCount;
};

struct Lighting
{
    Vector4 Ambient, Diffuse, Specular;
};

struct Material
{
    Vector4 Ambient, Diffuse, Specular;
    GLfloat Shininess;
};

class Structures
{
public:


private:

};