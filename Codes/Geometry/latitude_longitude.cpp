// Raio da Terra: Polar = 6357km, Equatorial = 6378km, Média = 6371km
#include<bits/stdc++.h>

inline double sq(double x) { return x * x; }

/** Converte latitude-longitude em coordenadas polares **/
struct latlon { double r, lat, lon; };  // lat e lon em radianos!
struct point { double x, y, z; };          // ponto cartesiano

latlon convert(point p) {
  double r = sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
  return latlon{ r,
                 asin(p.z / r),
                 atan2(p.y, p.x) };
}

point convert(latlon l) {
  return point{ l.r * cos(l.lon)* cos(l.lat),
             l.r * sin(l.lon)* cos(l.lat),
             l.r * sin(l.lat) };
}

/** Encontra distância entre dois pontos na terra **/
// fórmula de Haversine =====> LAT-LON EM RADIANOS!!!
double dist1(double r, double lat1, double lon1, double lat2, double lon2) {
  double dlon = lon1 - lon2;
  return r * acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(dlon));
}

double dist2(double r, double lat1, double lon1, double lat2, double lon2) {
  double dlat = lat1 - lat2;
  double dlon = lon1 - lon2;
  double p1 = sq(sin(dlat / 2.0));
  double p2 = cos(lat1) * cos(lat2) * sq(sin(dlon / 2.0));
  return r * 2 * asin(sqrt(p1 + p2));
}

double dist3(double r, double lat1, double lon1, double lat2, double lon2) {
  double dlon = lon1 - lon2;
  double x = sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(dlon);
  double p1 = sq(cos(lat2) * sin(dlon));
  double p2 = sq(cos(lat1) * sin(lat2) - sin(lat1) * cos(lat2) * cos(dlon));
  return r * atan2(sqrt(p1 + p2), x);
}

double dist4(double r, double lat1, double lon1, double lat2, double lon2) {
  double dlat = lat1 - lat2;
  double dlon = lon1 - lon2;
  double x = sq(sin(dlat / 2.0)) + cos(lat1) * cos(lat2) * sq(sin(dlon / 2.0));
  return r * 2 * atan2(sqrt(x), sqrt(1.0 - x));
}

double dist5(double r, double lat1, double lon1, double lat2, double lon2) {
  double dx = cos(lat2) * cos(lon2) - cos(lat1) * cos(lon1);
  double dy = cos(lat2) * sin(lon2) - cos(lat1) * sin(lon1);
  double dz = sin(lat2) - sin(lat1);
  double c = sqrt(dx * dx + dy * dy + dz * dz);
  return r * 2 * asin(c / 2.0);
}
