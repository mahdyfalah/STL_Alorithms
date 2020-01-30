#include<iostream>
#include<unordered_map>
#include<stdexcept>
#include<algorithm>
#include<numeric>
#include<iterator>
#include<set>
#include<vector>
#include"spieler.h"

using namespace std;

//Aufgabe1
struct CustomCompare1{
  bool operator()(Spieler lhs, Spieler rhs){
    if(lhs.get_team() > rhs.get_team())
      return true;  
    if(lhs.get_team() == rhs.get_team()){
      if(lhs.get_position() > rhs.get_position())
        return true;
      if(lhs.get_position() == rhs.get_position()){
        return lhs.get_faehigkeiten()[0] > rhs.get_faehigkeiten()[0];
      }
      return false;
    }
    return false;
  }
};

using sorted_set = set<Spieler, CustomCompare1>;

sorted_set make_set(const vector<Spieler>& v){
  return sorted_set(v.begin(), v.end());
}

tuple<Spieler, Spieler, Spieler, Spieler> find_extremes(const sorted_set& s){
  
  set<Spieler>::iterator elem50 = s.begin();
  set<Spieler>::iterator elem100 = s.begin();
  advance(elem50, 50);
  advance(elem100, 100);

  auto min_elem = min_element(s.begin(), s.end(), [](const Spieler& s1, const Spieler& s2){
    return s1.get_groesse() < s2.get_groesse();
  });

  auto max_elem = max_element(s.begin(), s.end(), [](const Spieler& s1, const Spieler& s2){
    return s1.get_groesse() < s2.get_groesse();
  });

  return tuple(*min_elem, *max_elem, *elem50, *elem100);
}
//Aufgabe2
double get_mean(const vector<Spieler>& v, Positionen p){
  double d = accumulate(v.begin(), v.end(), 0., [p](double sum, Spieler s){
    if(s.get_position() == p)
      return sum + s.get_groesse();
    return sum;
  });

  d /= count_if(v.begin(), v.end(), [p](Spieler s){
    return s.get_position() == p;
  });

  return d;
}
//?????????
vector<Spieler> load(const vector<Spieler>& v){
  vector<Spieler> temp;
  
  copy(v.begin(), v.end(), temp.begin());

  transform(temp.begin(), temp.end(), temp.begin(), [](Spieler& s){
    s.wachsen();
    return s;
  });
  
  return temp;
}

//Aufgabe3
unordered_map<int,set<string>> make_map(const vector<Spieler>& v){
  unordered_map<int, set<string>> map;

  for_each(v.begin(), v.end(), [&](const Spieler& s){
   int key = s.get_groesse();
    unordered_map<int,set<string>>::iterator it = map.find(key);
    set<string> value;
    if(it == map.end()){
      set<string> value;
      value.insert(s.get_name());
      map.insert(make_pair(key, value));
    }else{
      (it->second).insert(s.get_name());
    }
  });  

  return map;
}


int analyze(const unordered_map<int,set<string>>& map){
  
  auto i = min_element(map.begin(), map.end(), [](pair<int, set<string>> p1, pair<int, set<string>> p2){
    return p1.second.size() < p2.second.size();
  });
  
  return (i->second).size();
}  

