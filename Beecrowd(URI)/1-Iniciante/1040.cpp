#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double N1, N2, N3, N4, Media, Soma, NE, MediaFinal;
    cin >> N1 >> N2 >> N3 >> N4;
    cout << fixed << setprecision(1);
    Media =  (N1 * 2 + N2 * 3 + N3 * 4 + N4 * 1) / 10 ;
    cout << "Media: " << Media << "\n";
    if (Media >= 7.0) {
        cout << "Aluno aprovado." << "\n";
    }
    else if (Media >= 5.0 && Media <=6.9) {
        cout << "Aluno em exame." << "\n";
        cin  >> NE;
        MediaFinal = (Media + NE)/2;
        cout << "Nota do exame: " << NE <<"\n";
        if (MediaFinal >= 5.0) {
            cout << "Aluno aprovado." << "\n";
        }
        else if (MediaFinal <=4.9) {
            cout << "Aluno reprovado." <<"\n";
        }
        cout << "Media final: " << MediaFinal <<'\n';
    }
    else if (Media < 5.0) {
        cout << "Aluno reprovado." << "\n";
    }
}