#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    vector<string> VetYes;
    vector<string> VetNo;
    int i;
    string Cand, Maior;
    string Opcao;
    Cand = Opcao = string(1,'a');
    Maior = "";
    cin >> Cand;
    while(Cand != "FIM")
    {
        cin >> Opcao;
        if  (Opcao == "NO")
            VetNo.push_back(Cand);
        else
        {
            for (i = 0; i < VetYes.size() && Cand != VetYes[i]; i++);
            if	(i == VetYes.size())
            {
                VetYes.push_back(Cand);
                if	(Cand.size() > Maior.size())
                {
                    Maior = "";
                    Maior = Cand;
                }
            }
        }
        cin >> Cand;
    }

    sort(VetNo.begin(),VetNo.end());
    sort(VetYes.begin(),VetYes.end());

    for (i = 0; i < VetYes.size(); i++)
            cout << VetYes[i] << '\n';

    for (i = 0; i < VetNo.size(); i++)
        cout << VetNo[i] << '\n';

    cout << "\nAmigo do Habay:" << '\n'
            << Maior << '\n';
}