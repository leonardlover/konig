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
    return duration_time;
}



int main(int argc, char *argv[]) {
    int n[7] = {100000,200000,400000,800000,1600000,3000000,3173648};

    long double timeIns[] = {0,0,0,0,0,0,0};
    long double timeCont[] = {0,0,0,0,0,0,0};
    long double timeAggr[] = {0,0,0,0,0,0,0};


    QuadTree *qt = new QuadTree();
    cout << "Midiendo inserciones:" << endl;
    for (int i = 0; i < 7; ++i){
        cout << "\tIteracion n. "<< i+1 << "\n\tN = " << n[i] << endl;
        for (int j = 0; j < 1; ++j){
            delete qt;
            double x, y;
            string country, city;
            int population;
            vector<Point> list;
            qt = new QuadTree();
            timeIns[i] += input(x,y,country,city,population, qt, n[i]);
            //cout << qt->totalPoints() << endl;
            //cout << qt->aggregateRegion(Point(180,180),200) << endl;
        }
        timeIns[i] /= 1.0;
        cout << "\tTiempo: " << timeIns[i]/1e9 << " s.\n" << endl;
    }

    double X[6] = {2,90 ,90,100,150,180};
    double Y[6] = {2,180,60,120,200,180};
    double d[6] = {2,90 ,45,64 ,123,200};

    cout << "Midiendo countRegion & aggregateRegion:" << endl;
    for (int i = 0; i < 6; ++i){
        cout << "\tIteracion n. "<< i+1 << "\n\tPoint = (" << X[i] << ", " << Y[i] << ") - d = " << d[i] << endl;
        for (int j = 0; j < 1; ++j){
            Point p = Point(X[i], Y[i]);
            auto start_time1 = chrono::high_resolution_clock::now();
            qt->countRegion(p,d[i]);
            auto end_time1 = chrono::high_resolution_clock::now();
            timeCont[i] += (long double)chrono::duration_cast<chrono::nanoseconds>(end_time1 - start_time1).count();

            auto start_time2 = chrono::high_resolution_clock::now();
            qt->aggregateRegion(p,d[i]);
            auto end_time2 = chrono::high_resolution_clock::now();
            timeAggr[i] += (long double)chrono::duration_cast<chrono::nanoseconds>(end_time2 - start_time2).count();

        }
        timeCont[i] /= 1.0;
        timeAggr[i] /= 1.0;
        cout << "\tTiempo countRegion: " << timeCont[i]/1e9 << " s." << endl;
        cout << "\tTiempo aggregateRegion: " << timeAggr[i]/1e9 << " s.\n" << endl;
    }

    return 0;
}