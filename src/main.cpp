#include "QuadTree.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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

void input(double x, double y, string country, string city, int population, QuadTree *qt, Point *list) {
    cout << "input 18" << endl;
    fstream fin;
  
    cout << "fin.open 22" << endl;
    fin.open("../../worldcitiespop_fixed.csv");//, ios::in);

    string line, word;
    getline(fin, line);

    cout << "while fin temp 31" << endl;
    while (getline(fin, line)) {
  
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
    > fixed manage edge cases (?)
    > fixed negative cases
    > fixed adding point when is indeed added
    */
    int xb, yb; // xbound, ybound
    cin >> xb >> yb;
    
    QuadTree *qt = new QuadTree(xb,yb);

    // quad tree parameters
    double x, y;
    string country, city;
    int population;
    Point* list;

    cout << "input 82" << endl;
    input(x,y,country,city,population, qt, list);

    for(int i = 0; i < qt->totalPoints(); i++) {
        cout << list[i].city() << " ";
    }
    cout << endl;

    /* file input
    ifstream file;
    file.open("../../worldcitiespop_fixed.csv");
    string line;

    while(getline(file,line)) { // insert points data
        // create point
        Point *p = new Point(x, y, country, city, population);
        // insert
        qt->insert(p);
        
        // print list
        list = qt->list();
        for(int i = 0; i < qt->totalPoints(); i++) {
            cout << list[i].city() << " ";
        }
    }
    cout << endl;
    */

    return 0;
}