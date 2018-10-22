#pragma once
#include "../Presenter.h"

struct FIBITMAP;
class BMPPresenter : public Presenter {
public:
	static BMPPresenter& GetInstance();
public:
	~BMPPresenter();
	bool Setup(int width, int height);
	void SetColor(int u, int v, float r, float g, float b);
	void Present();
private:
	BMPPresenter();
private:
	FIBITMAP * m_map;
	int m_width, m_height;
	bool m_hasSetup;
};