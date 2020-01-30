#include<iostream>
#include<unordered_map>
#include<stdexcept>
#include<algorithm>
#include<numeric>
#include<iterator>
#include<set>
#include<vector>
#include"spieler.h"

Spieler::Spieler(string name,string team,Positionen position,int groesse,vector<double> faehigkeiten):name{name},team{team},position{position},groesse{groesse},faehigkeiten{faehigkeiten} {}

Spieler::~Spieler() {}

string Spieler::get_name() const{ return name;}

string Spieler::get_team() const{return team;}

int Spieler::get_groesse() const { return groesse;}

const vector<double>& Spieler::get_faehigkeiten() const{ return faehigkeiten;}

Positionen Spieler::get_position() const{ return position;}

double Spieler::summe_faehigkeiten() const{
  return accumulate(faehigkeiten.begin(),faehigkeiten.end(),0.0, [] (const double& sum,const double& x){return sum+x;});
}

ostream& operator<<(ostream& o,const Spieler& h){
  o << "[" << h.name << ", " << h.team << ", " << pnamen[static_cast<size_t>(h.position)] << ", " << h.groesse << ", {";
  bool first{true};
  for(const auto& x : h.faehigkeiten){
    if(first)
      first=false;
    else
      o<< ", ";
    o << x;
  }

  return o << "}]";

}

bool Spieler::operator<(const Spieler& s) const{
  return name<s.name;
}

bool Spieler::operator>(const Spieler& s) const{
  return name>s.name;
}

bool Spieler::operator==(const Spieler& s) const{
  return name==s.name;
}

ostream& Spieler::write(ostream& o) const{
  o << name << " " << team << " " << static_cast<size_t>(position) << " " << groesse;
  for(const auto& x:faehigkeiten)
    o << " " << x;
  return o;
}

istream& Spieler::read(istream& i){
  string s;
  if(!(i >> s))
    return i;
  string t;
  i >> t;
  name = s + " " + t;
  i >> team;
  int j;
  i >> j;
  position = static_cast<Positionen>(j);
  i >> groesse;
  faehigkeiten.clear();
  double d;
  i >> d;
  faehigkeiten.push_back(d);
  i >> d;
  faehigkeiten.push_back(d);
  i >> d;
  faehigkeiten.push_back(d);
  return i;
}

void Spieler::wachsen(){
  groesse+=10;
}

