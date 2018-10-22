#include <iostream>
#include "BMPPresenter/BMPPresenter.h"

Presenter& pre = BMPPresenter::GetInstance();

void main() {
	pre.Setup(100, 100);
	pre.Present();
	system("pause");
}