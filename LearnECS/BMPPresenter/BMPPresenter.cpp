#include "BMPPresenter.h"

const char* FILE_NAME = "result.bmp";

BMPPresenter::BMPPresenter() : m_buffer(nullptr), m_hasSetup(false) {}

bool BMPPresenter::Setup(int width, int height) {
	m_hasSetup = false;
	if (width <= 0 || height <= 0) return false;
	if (m_file.is_open()) m_file.close();
	void* temp = nullptr;
	if (m_buffer) {
		temp = realloc(reinterpret_cast<void*>(m_buffer), sizeof(Pixel) * width * height);
	}
	else {
		temp = malloc(sizeof(Pixel) * width * height);
	}
	if (!temp) return false;
	m_buffer = reinterpret_cast<Pixel*>(temp);
	m_file.open(FILE_NAME, std::ios::out | std::ios::trunc);
	if (!m_file.is_open()) return false;
	m_hasSetup = true;
	return true;
}

void BMPPresenter::SetColor(int u, int v, float r, float g, float b) {
	if (!m_hasSetup) return;
	if (u < 0 || u >= m_width) return;
	if (v < 0 || v >= m_height) return;

	Pixel p = { r * 255, g * 255, b * 255 };
	memcpy_s((m_buffer + u + v * m_width), sizeof(Pixel), &p, sizeof(Pixel));
}

void BMPPresenter::Present() {
	if (!m_hasSetup) return;

	const int byteSize = sizeof(Pixel);
	int pixelSize = byteSize * m_width * m_height;
	int fileSize = 54 + pixelSize;
	const unsigned char bmpfileheader[14] = { 'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0 };

}

BMPPresenter::~BMPPresenter() {
	if (m_file.is_open()) m_file.close();
	if (m_buffer) free(reinterpret_cast<void*>(m_buffer));
}