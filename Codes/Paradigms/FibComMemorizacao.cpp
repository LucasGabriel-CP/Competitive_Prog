unsigned ll pd[10000];

unsigned ll f(int at)
{
	if (at == 0 || at == 1)
		return 1;

	if (pd[at] != -1)
		return pd[at];

	return pd[at] = f(at - 1) + f(at - 2);
}

int main()
{
	unsigned ll n;

	memset(pd, -1, sizeof(pd));

	while (cin >> n && n != -1) {
		cout << f(n) << '\n';
	}
}
