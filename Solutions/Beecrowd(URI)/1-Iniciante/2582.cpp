#include <iostream>

using namespace std;

int main()
{
	int NMusic, Bot1, Bot2;
	cin >> NMusic;
	for (int i = 0; i < NMusic; i++)
    {
        int Soma = 0;
        cin >> Bot1 >> Bot2;
        Soma = Bot1 + Bot2;
        switch (Soma) 
        {
            case 0: cout  << "PROXYCITY"     << '\n'; break;
            case 1: cout  << "P.Y.N.G."      << '\n'; break;
            case 2: cout  << "DNSUEY!"       << '\n'; break;
            case 3: cout  << "SERVERS"       << '\n'; break;
            case 4: cout  << "HOST!"         << '\n'; break;
            case 5: cout  << "CRIPTONIZE"    << '\n'; break;
            case 6: cout  << "OFFLINE DAY"   << '\n'; break;
            case 7: cout  << "SALT"          << '\n'; break;
            case 8: cout  << "ANSWER!"       << '\n'; break;
            case 9: cout  << "RAR?"          << '\n'; break;
            case 10: cout << "WIFI ANTENNAS" << '\n';
        }
    }
}