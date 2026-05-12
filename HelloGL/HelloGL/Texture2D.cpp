#include "Texture2D.h"
#include <iostream>
#include <fstream>

using namespace std;

Texture2D::Texture2D()
{
	
}

Texture2D::~Texture2D()
{
	glDeleteTextures(1, &m_ID);
}

bool Texture2D::Load(char* path, int width, int height)
{
	char* tempTextureData; int fileSize; ifstream inFile;
	m_width = width; m_height = height;
	inFile.open(path, ios::binary);

	if (!inFile.good())
	{
		std::cerr << "can't open Texture file " << path << std::endl;
		return false;
	}

	inFile.seekg(0, ios::end); // seek to end of file
	fileSize = (int)inFile.tellg(); // get current position in file - the end, this gives us total file size
	tempTextureData = new char[fileSize]; // create a new array to store data
	inFile.seekg(0, ios::beg); // seek back to begining of file
	inFile.read(tempTextureData, fileSize); // read in all data in one go
	inFile.close(); // close the file

	std::cout << path << " loaded" << std::endl;

	glGenTextures(1, &m_ID); // get new texture ID
	glBindTexture(GL_TEXTURE_2D, m_ID); // bind texture to ID
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, tempTextureData); // specify details of texture image
	

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // filter
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // filter

	delete [] tempTextureData; // clear up data (not needed now)
	return true;
}
