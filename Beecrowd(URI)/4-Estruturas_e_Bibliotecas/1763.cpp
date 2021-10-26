#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	int Ans;
	string Pais;
	map< string, string > myMap;
	myMap["brasil"] = "Feliz Natal!";
	myMap["portugal"] = "Feliz Natal!";
	myMap["alemanha"] = "Frohliche Weihnachten!";
	myMap["austria"] = "Frohe Weihnacht!";
	myMap["coreia"] = "Chuk Sung Tan!";
	myMap["espanha"] = "Feliz Navidad!";
	myMap["argentina"] = "Feliz Navidad!";
	myMap["chile"] = "Feliz Navidad!";
	myMap["mexico"] = "Feliz Navidad!";
	myMap["grecia"] = "Kala Christougena!";
	myMap["estados-unidos"] = "Merry Christmas!";
	myMap["inglaterra"] = "Merry Christmas!";
	myMap["australia"] = "Merry Christmas!";
	myMap["antardida"] = "Merry Christmas!";
	myMap["canada"] = "Merry Christmas!";
	myMap["suecia"] = "God Jul!";
	myMap["turquia"] = "Mutlu Noeller";
	myMap["irlanda"] = "Nollaig Shona Dhuit!";
	myMap["belgica"] = "Zalig Kerstfeest!";
	myMap["italia"] = "Buon Natale!";
	myMap["libia"] = "Buon Natale!";
	myMap["siria"] = "Milad Mubarak!";
	myMap["marrocos"] = "Milad Mubarak!";
	myMap["japao"] = "Merii Kurisumasu!";

	while(cin >> Pais)
	{
		if	(!myMap.count(Pais))
			cout << "--- NOT FOUND ---" << '\n';
		else
			cout << myMap[Pais] << '\n';
	}
}