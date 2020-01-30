#ifndef SPIELER_H
#define SPIELER_H

#include<iostream>
#include<unordered_map>
#include<stdexcept>
#include<algorithm>
#include<numeric>
#include<iterator>
#include<set>
#include<vector>

using namespace std;

enum class Positionen{Point_Guard,Shooting_Guard,Small_Forward,Power_Forward,Center};
const vector<string> pnamen{"PG","SG","SF","PF","C"};

class Spieler{
  string name;
  string team;
  Positionen position;
  int groesse;
  vector<double> faehigkeiten;  // PPG,RPG,APG

  public:
    Spieler(string="Blake Griffin",string="Detroit_Pistons",Positionen=Positionen::Power_Forward,int =208,vector<double> = {19.8,6.6,6.2});
    virtual ~Spieler();
    string get_name() const;
    string get_team() const;
    Positionen get_position() const;
    int get_groesse() const;
    const vector<double>& get_faehigkeiten() const;
    friend ostream& operator<<(ostream& o,const Spieler& h);
    double summe_faehigkeiten() const;
    void wachsen();
    bool operator<(const Spieler& s) const;
    bool operator>(const Spieler& s) const;
    bool operator==(const Spieler& s) const;
    ostream& write(ostream&) const;
    istream& read(istream&);
};

#endif

