#include <iostream>
#include <queue>
#include <stack>
#include <set>

using namespace std;

bool valid(bool St, bool Pq, bool Qe)
{
	if	(St && Qe)
		return true;
	if	(St && Pq)
		return true;
	if	(Pq && Qe)
		return true;
	return false;
}

int main()
{
	int N, Num, Op;
	bool St, Qe, Pq;
	while(cin >> N)
	{
		stack< int > mySt;
		queue< int > myQe;
		priority_queue< int > myPq;
		set< int > myset;
		Qe = St = Pq = true;
		for	(int i = 0; i < N; i++)
		{
			cin >> Op >> Num;
			if	(Qe || St || Pq)
			{
				if	(Op == 1)
				{
					mySt.push(Num);
					myQe.push(Num);
					myPq.push(Num);

					myset.insert(Num);
				}
				else
				{
					if	(!myset.count(Num))
						Qe = St = Pq = false;
					else
					{
						if	(St && Num != mySt.top())
							St = false;						
						if	(Qe && Num != myQe.front())
							Qe = false;
						if	(Pq && Num != myPq.top())
							Pq = false;
						mySt.pop();
						myQe.pop();
						myPq.pop();
					}
				}
			}
		}
		if	(!St && !Pq && !Qe)
			cout << "impossible\n";
		else
			if	(valid(St, Pq, Qe))
				cout << "not sure\n";
			else
				if	(St)
					cout << "stack\n";
				else
					if	(Pq)
						cout << "priority queue\n";
					else
						cout << "queue\n";
	}
}