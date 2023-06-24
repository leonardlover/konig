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
    fstream fin;
  
    fin.open("../../worldcitiespop_fixed.csv");

    string line, word;
    getline(fin, line);

    for(int i = 0; i < n; ++i) {
        getline(fin, line);
        stringstream s(line);
  
        getline(s,word,';');
        country = word;

        getline(s,word,';');
        city = word;
        
        getline(s,word,';'); // accentcity
        getline(s,word,';'); // region

        getline(s,word,';');
        population = stoi(word);
        
        getline(s,word,';');
        x = stod(formatd(word));
        
        getline(s,word,';');
        y = stod(formatd(word));
        
        getline(s,word,';'); // geopint

        Point *p = new Point(x, y, country, city, population);
        qt->insert(p);

        cout << "country: " << country << endl;
        cout << "city: " << city << endl;
        cout << "population: " << population << endl;
        cout << "x: " << x << endl;
        cout << "y: " << y << endl;
        cout << "points: " << qt->totalPoints() << endl;
        cout << "nodes: " << qt->totalNodes() << endl << endl;
    }
}

int main() {
    /* TODO:
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
/*
    list = qt->list();
    for(int i = 0; i < qt->totalPoints(); ++i) {
        cout << list[i]->country() << " - " << list[i]->city() << endl;
    }
    cout << endl;
*/
    return 0;
}