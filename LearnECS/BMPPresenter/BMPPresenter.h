#pragma once
#include "../Presenter.h"
#include <fstream>

class BMPPresenter : public Presenter {
	struct Pixel {
		unsigned char r;
		unsigned char g;
		unsigned char b;
	};
public:
	~BMPPresenter();
	bool Setup(int width, int height);
	void SetColor(int u, int v, float r, float g, float b);
	void Present();
private:
	BMPPresenter();
private:
	int m_width, m_height;
	bool m_hasSetup;
	std::ofstream m_file;
	Pixel* m_buffer;
};