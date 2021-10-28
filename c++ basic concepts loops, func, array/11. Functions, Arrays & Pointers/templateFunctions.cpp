#include <iostream>

using namespace std;

template <typename T>
T sum( T x, T y)
{
    return x + y;
}

int main()
{
	cout << "Sum : " << sum<float>(3.5, 5) << endl;
	cout << "Sum : " << sum<int>(3.0, 5.2) << endl;
	cout << "Sum : " << sum(3.24234, 5.24144) << endl;
	return 0;
}