#pragma once
#include <cstdint>

struct Vertex 
{
	Vertex(float x, float y, float z)
	{
		Pos[0] = x;
		Pos[1] = y;
		Pos[2] = z;
	}

	float Pos[3] = { 0.0f, 0.0f, 0.0f };
};

struct DrawDetails
{
	DrawDetails(uint32_t v, uint32_t e)
	{
		vao = v; // vertex array object
		numElements = e;
	}

	uint32_t vao;
	uint32_t numElements;
};