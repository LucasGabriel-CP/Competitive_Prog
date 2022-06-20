#include <bits/stdc++.h>

using namespace std;

struct Point{
    double x, y;
    Point(){x = y = 0;}
    Point(double _x, double _y) : x(_x), y(_y){}
};

double dist(Point p1, Point p2){ return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)); }

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    string str;
    int c = 1;
    double dia = sqrt(2)/2.0;
    while(cin >> str, str != "END"){
        int t = str.size();
        Point ini;
        for (int i = 0; i < t; i += 2){
            if (str[i] == '.') continue;
            string aux = "";
            while(i < t && str[i] <= '9'){
                aux += str[i++];
            }
            int val = stoi(aux);
            if (str[i] == 'N'){
                if (str[i + 1] == ',' || str[i + 1] == '.') ini.y += val;
                else{
                    ++i;
                    if (str[i] == 'W'){ ini.y += dia * val; ini.x -= dia * val; }
                    else { ini.y += dia * val; ini.x += dia * val; }
                }
            }
            else if (str[i] == 'S'){
                if (str[i + 1] == ',' || str[i + 1] == '.') ini.y -= val;
                else{
                    ++i;
                    if (str[i] == 'W'){ ini.y -= dia * val; ini.x -= dia * val; }
                    else { ini.y -= dia * val; ini.x += dia * val; }
                }
            }
            else if (str[i] == 'W') ini.x -= val;
            else if (str[i] == 'E') ini.x += val;
        }
        cout  << fixed << setprecision(3)
            << "Map #" << c++ << '\n'
            << "The treasure is located at (" << ini.x << ',' << ini.y << ").\n"
            << "The distance to the treasure is " << dist(ini, Point()) << ".\n\n";
    }

	return 0;
}
