#include <iostream>
#include <stack>
#include <cstdio>
#include <string.h>

using namespace std;

typedef long long ll;

int main() {
    stack<ll> myStack;
    ll Aux, V, Min;
    int N;
    scanf("%d", &N);
    while(N--)
    {
        char Str[15];
        scanf("%s", &Str);
        if (strcmp(Str, "PUSH") == 0)
        {
            scanf("%lld",&V);
            if  (myStack.empty())
            {
            	Min = V;
            	myStack.push(V);
            }
            else
            {
            	if (V < Min)
            	{
            		myStack.push(2*V - Min);
            		Min = V;
            	}
            	else
            	{
            		myStack.push(V);
            	}
            }   
        }
        else
            if(strcmp(Str, "POP") == 0)
            {
                if (myStack.empty())
                    printf("EMPTY\n");
                else
                {
                    Aux = myStack.top();
                    if  (Aux < Min)
                         Min = Min * 2 - Aux;
                    myStack.pop();
                }
            }
            else
            {
                if (myStack.empty())
                    printf("EMPTY\n");
                else
                    printf("%lld\n", Min);
            }
    }

    return 0;
}