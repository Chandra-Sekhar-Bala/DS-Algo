#include <iostream>
using namespace std;

int Egcd(int a, int b)
{
    // {
    // 	if(!b)
    // 	return a;
    //    return Egcd(b,a%b);

    return ((b % a == 0) ? a : Egcd(b, a % b));
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << Egcd(a, b);
    return 0;
}