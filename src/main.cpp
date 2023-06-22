#include "QuadTree.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

string formatd(string d) {
    for(int i = 0; i < d.size(); i++) {
        if(d[i] == ',') {
            d[i] = '.'; 
            return d;
        }
    }
    return d;
}

void input(double x, double y, string country, string city, int population, QuadTree *qt, int n) {
    cout << "input 18" << endl;
    fstream fin;
  
    cout << "fin.open 22" << endl;
    fin.open("../../worldcitiespop_fixed.csv");

    string line, word;
    getline(fin, line);

    cout << "while fin temp 31" << endl;
    for(int i = 0; i < n; ++i) {
        getline(fin, line);
        stringstream s(line);
  
        getline(s,word,';');
        country = word;
        cout << "country: " << country << endl;
        
        getline(s,word,';');
        city = word;
        cout << "city: " << city << endl;
        
        getline(s,word,';'); // accentcity
        getline(s,word,';'); // region
        getline(s,word,';');
        population = stoi(word);
        cout << "population: " << population << endl;
        
        getline(s,word,';');
        x = stod(formatd(word));
        cout << "x: " << x << endl;
        
        getline(s,word,';');
        y = stod(formatd(word));
        cout << "y: " << y << endl;
        
        getline(s,word,';'); // geopint

        Point *p = new Point(x, y, country, city, population);
        qt->insert(p);
        cout << "points: " << qt->totalPoints() << endl;
        cout << "nodes: " << qt->totalNodes() << endl << endl;
    }
}

int main() {
    /* TODO:
    - list is working, cometi un error tonto y termine rehaciendo la funcion con vectores, pero funciona
    */
    int xb, yb, n; // xbound, ybound
    cin >> xb >> yb >> n;
    
    QuadTree *qt = new QuadTree(xb,yb);

    // quad tree parameters
    double x, y;
    string country, city;
    int population;
    vector<Point*> list;

    input(x,y,country,city,population, qt, n);

    list = qt->list();
    for(int i = 0; i < qt->totalPoints(); ++i) {
        cout << list[i]->country() << " - " << list[i]->city() << endl;
    }
    cout << endl;

    return 0;
}