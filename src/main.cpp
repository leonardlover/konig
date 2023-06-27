#include "QuadTree.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <chrono>
#include <ctime>
//#include <thread>

using namespace std;

// testing consts
const int tests = 1e2;
const int testsFactor = 1e2;
const int interval = 1000;

ofstream file;
fstream fin;

string formatd(string d) { // format double, replaces ',' into '.'
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

    fin.open("../../worldcitiespop_fixed.csv");//, ios::in);

    string line, word;
    getline(fin, line);

    while (n--) {
        getline(fin, line);
        stringstream s(line);

        getline(s,word,';');
        country = word;
        //cout << "country: " << country << endl;

        getline(s,word,';');
        city = word;
        //cout << "city: " << city << endl;

        getline(s,word,';'); // accencity
        getline(s,word,';'); // region
        getline(s,word,';');
        population = stoi(word);
        //cout << "population: " << population << endl;

        getline(s,word,';');
        x = stod(formatd(word));
        //cout << "x: " << x << endl;

        getline(s,word,';');
        y = stod(formatd(word));
        //cout << "y: " << y << endl;

        getline(s,word,';'); // geopint

        Point *p = new Point(x, y, country, city, population);
        qt->insert(*p);
        //cout << "inserted " << endl;
    }
    cout << "total nodes: " << qt->totalNodes() << endl;
    cout << "total points: " << qt->totalPoints() << endl << endl;
}

/* not actually a function, just to understand the format
double test(QuadTree *qt, int n, int interval, int tests) {
    for(int i = 0; i<n; i+=interval) {
        auto start_time = chrono::high_resolution_clock::now();
        for(int j = i; j < i+interval; ++j) {
            // funcion
            for(int k = 1; k < tests; ++k) {
                // funcion (not assigning)
            }
            auto end_time = chrono::high_resolution_clock::now();
            auto duration_time = (long double)chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

		    cout << "For n=" << i << ", it takes " << fixed << setprecision(18) << duration_time/interval << " microseconds to insert a Node" << endl;
		    file << fixed << setprecision(18) << duration_time / (interval*tests) << endl;
        }
    }
}
*/
int main(int argc, char *argv[]) {
    /* TODO:
    - usar todos los datos
    - testing
    - informe
    */

    file.open ("data.txt");

    int xb, yb, n; // xbound, ybound, number of cities
    cin >> xb >> yb >> n;

    QuadTree *qt = new QuadTree(xb,yb);

    // quad tree parameters
    double x, y;
    string country, city;
    int population;
    vector<Point> list;
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