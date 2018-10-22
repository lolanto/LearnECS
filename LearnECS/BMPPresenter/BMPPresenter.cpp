#include "BMPPresenter.h"
#include <FreeImage.h>
#include <iostream>

const char* FILE_NAME = "result.bmp";

BMPPresenter& BMPPresenter::GetInstance() {
	static BMPPresenter _ins;
	return _ins;
}

bool BMPPresenter::Setup(int width, int height) {
	m_hasSetup = false;
	if (width <= 0 || height <= 0) return false;
	m_width = width; m_height = height;
	m_map = FreeImage_Allocate(width, height, 24);
	if (!m_map) return false;
	m_hasSetup = true;
	return true;
}

void BMPPresenter::SetColor(int u, int v, float r, float g, float b) {
	if (!m_hasSetup) return;
	if (u < 0 || u >= m_width) return;
	if (v < 0 || v >= m_height) return;
	RGBQUAD color;
	color.rgbBlue = static_cast<BYTE>(b * 255);
	color.rgbGreen = static_cast<BYTE>(g * 255);
	color.rgbRed = static_cast<BYTE>(r * 255);
	FreeImage_SetPixelColor(m_map, u, v, &color);
}

void BMPPresenter::Present() {
	if (!m_hasSetup) return;
	if (FreeImage_Save(FIF_BMP, m_map, FILE_NAME, 0))
		std::cout << FILE_NAME << " present!" << std::endl;
}

BMPPresenter::BMPPresenter() : m_map(nullptr) {
	FreeImage_Initialise();
}

BMPPresenter::~BMPPresenter() {
	FreeImage_DeInitialise();
}