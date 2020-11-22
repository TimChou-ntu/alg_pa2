#ifndef _PLANAR_H
#define _PLANAR_H

#include<vector>
#include <algorithm>
#include<iostream>
using namespace std;

class mps {
    public:
        mps(){}; // constructor
        mps(int* all_chord, int n):All_chord(all_chord), N(n) {
            cout<<"right construction"<<endl;
            case_list = new int*[2*n];
            mps_record = new int*[2*n];
            for(int j = 0; j < 2*n; j++){
                mps_record[j] = new int[2*n];
                case_list[j] = new int[2*n];
            }
        }

        void calculate_mps();
        int get_ans();

        void get_mps_chords(vector<vector<int>>&);

    private:
        void get_chord(int&, int, int, vector<vector<int>>&);

        int                         N; // heap size used in heap sort
        int                         Ans;
        int*                        All_chord;
        int**                       case_list;
        int**                       mps_record;
};

#endif
