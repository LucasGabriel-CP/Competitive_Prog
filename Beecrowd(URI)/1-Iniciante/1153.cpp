#include <iostream>

using namespace std;

unsigned int Fat(unsigned int Num)
{
    if(Num == 0)
        return 1;
    return Fat(Num - 1) * Num;
}

int main()
{
    unsigned int Num;
    cin >> Num;
    cout << Fat(Num) << '\n';
}