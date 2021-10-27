#include <iostream>

using namespace std;

int main() {
	int N, P, Q, mult, soma;
	char C;
	cin >> N >> P >> C >> Q;
	if (C == '*') {
		mult = P * Q;
		if (mult <= N) {
			cout << "OK" << "\n";
		}
		else if (mult > N) {
			cout << "OVERFLOW" << "\n";
		}
	}
	else if (C == '+') {
		soma = P + Q;
		if (soma <= N) {
			cout << "OK" << "\n";
		}
		else if (soma > N) {
			cout << "OVERFLOW" << "\n";
		}
	}
}