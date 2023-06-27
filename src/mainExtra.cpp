#include "QuadTree.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <chrono>
#include <ctime>
#include <string>

using namespace std;

string formatd(string d) { // format double, replaces ',' into '.'
    for(int i = 0; i < d.size(); i++) {
        if(d[i] == ',') {
            d[i] = '.'; 
            return d;
        }
    }
    return d;
}


long double input(double x, double y, string country, string city, int population, QuadTree *qt, int n) { // process input, reads from csv file, set up points and insert those points into the quadtree
    fstream fin;
    fin.open("../../worldcitiespop_fixed.csv"); // open file

    string line, word;
    getline(fin, line); // gets first line (description)
    //Point *q;
    long double duration_time = 0;
    for(int j = 0; j < n; ++j) {
    
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
        Point p = Point(x, y, country, city, population);
        // insert and tomar tiempo de insercion        
        auto start_time = chrono::high_resolution_clock::now();
        qt->insert(p);
        auto end_time = chrono::high_resolution_clock::now();
        duration_time += (long double)chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();
        //this_thread::sleep_for(nanoseconds(10));
        // q = p;
    }
        

    
    //cout << "total nodes: " << qt->totalNodes() << endl;
    //cout << "total points: " << qt->totalPoints() << endl << endl;
    //file << fixed << setprecision(18) << duration_time / (interval*tests) << endl;
    
    return duration_time;
}



int main(int argc, char *argv[]) {
    int xb, yb;
    int n[6] = {100000,200000,400000,800000,1600000,3000000};
    //cin >> xb >> yb;

    long double time[] = {0,0,0,0,0,0};

    for (int i = 0; i < 6; ++i){
        cout << "Iteracion n. "<< i+1 << "\nN = " << n[i] << endl;
        for (int j = 0; j < 1; ++j){
            //cout << j+1 << " ";
            // quad tree parameters
            double x, y;
            string country, city;
            int population;
            vector<Point> list;
            QuadTree *qt = new QuadTree();
            time[i] += input(x,y,country,city,population, qt, n[i]);
        }
        time[i] /= 1.0;
        cout << "\nTiempo: " << time[i]/1e9 << " s." << endl;
    }

    return 0;
}