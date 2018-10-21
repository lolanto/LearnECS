#pragma once


class Presenter {
public:
	virtual ~Presenter() = default;
	virtual bool Setup(int width, int height) = 0;
	virtual void SetColor(int u, int v, float r, float g, float b) = 0;
	virtual void Present() = 0;
};