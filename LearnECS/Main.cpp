#include <iostream>
#include "Math/Vector3.h"
#include "Math/Matrix4x4.h"
using namespace std;
void main() {
	Vector3 v(2, 3, 4);
	v = Vector3::Normalize(v);
	cout << v[0];
	system("pause");
}