#include<iostream>
#include<fstream>
#include<vector>
#include<set>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<numeric>
#include"spieler.h"
#include"task.h"

using namespace std;

int main() {
  vector<Spieler> v;

  //hier wird der Vektor v mit Daten gefuellt
  ifstream input{"spieler.txt"};
  Spieler f;
  while (f.read(input)) {
    v.push_back(f);
  }
  

  // Aufgabe 1
  sorted_set s{make_set(v)};
  tuple<Spieler, Spieler, Spieler, Spieler> t (find_extremes(s));
  
  cout << "Set: " << s.size() << " items, " << endl;
  cout << "min: " << get<0>(t) << "max: " << get<1>(t) << "elem50: " << get<2>(t) << "elem100: " << get<3>(t) << endl;


  // Aufgabe 2
  cout << "d: " << get_mean(v, Positionen::Small_Forward) << endl ;



  // Aufgabe 3
  unordered_map<int, set<string>> map {make_map(v)};
  


  

  cout << "Min: " << analyze(map) << endl;

  return 0;
}

