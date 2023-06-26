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

void input(double x, double y, string country, string city, int population, QuadTree *qt, int n) { // process input, reads from csv file, set up points and insert those points into the quadtree
    fin.open("../../worldcitiespop_fixed.csv"); // open file

    string line, word;
    getline(fin, line); // gets first line (description)
    //Point *q;
    for(int i = 0; i < n; i+=interval) {
        long double duration_time = 0;
        for(int j = i; j < i+interval; ++j) {
        
            getline(fin, line); // gets one line from the file
            stringstream s(line); // splits the line into words

            // get data
            getline(s,word,';'); // Country 
            country = word;

            getline(s,word,';'); // City
            city = word;

            getline(s,word,';'); // Accentcity (ignore)
            getline(s,word,';'); // Region (ignore)

            getline(s,word,';'); // Population
            population = stoi(word);
            
            getline(s,word,';'); // Latitude
            y = stod(formatd(word));
            
            getline(s,word,';'); // Longitude
            x = stod(formatd(word));
            
            getline(s,word,';'); // Geopint (ignore)

            // build point
            Point *p = new Point(x, y, country, city, population);
            // insert and tomar tiempo de insercion        
            auto start_time = chrono::high_resolution_clock::now();
            qt->insert(p,false);
            auto end_time = chrono::high_resolution_clock::now();
            duration_time += (long double)chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();
            //this_thread::sleep_for(nanoseconds(10));
            // q = p;
        }
        //for(int k = 0; k < tests; ++k) {
            
            //qt->insert(q, true);
            
            // display
            /*
            cout << "country: " << country << endl;
            cout << "city: " << city << endl;
            cout << "population: " << population << endl;
            cout << "x: " << x << endl;
            cout << "y: " << y << endl;
            cout << "points: " << qt->totalPoints() << endl;
            cout << "nodes: " << qt->totalNodes() << endl << endl;
            */
        //}
        

        cout << "For n=" << i << ", it takes " << fixed << setprecision(18) << duration_time/interval << " microseconds to insert a Node" << endl;
        file << fixed << setprecision(18) << duration_time / (interval*tests) << endl;
    }
    cout << qt->totalPoints() << endl;
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
    - manage duplicated points !!!
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
    vector<Point*> list;
    input(x,y,country,city,population, qt, n);
    
    /*list = qt->list();
    for(int i = 0; i < qt->totalPoints(); ++i) {
        cout << list[i]->country() << " - " << list[i]->city() << endl;
    }
    cout << endl;
*/
    return 0;
}