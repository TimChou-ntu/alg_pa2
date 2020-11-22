#include <cstring>
#include <iostream>
#include <fstream>

#include "planar.h"

using namespace std;

int main(int argc, char* argv[]){
    if(argc != 3){
        printf("need input file name and output file name");
        return 0;
    }
    fstream fin(argv[1]);
    fstream fout;
    fout.open(argv[2], ios::out);
    
    int n;
    fin >> n;
    n/=2;

    int chord_h, chord_e;
    int* p = new int[2*n];
    while(fin>>chord_h>>chord_e){
        p[chord_h] = chord_e;
        p[chord_e] = chord_h;
    }

    mps MyMPS(p,n);
    MyMPS.calculate_mps();
    int ans = MyMPS.get_ans();
    cout<<"ans is "<<ans<<endl;

    vector<vector<int>> mps_chords;
    mps_chords.resize(ans);
    for(int j = 0; j < ans; j++){
        mps_chords[j] = vector<int>(2,-1);
    }
    MyMPS.get_mps_chords(mps_chords);
    
    fout<<ans<<endl;
    for(int i = 0; i < ans; i++){
        fout<<mps_chords[i][0]<<" "<<mps_chords[i][1]<<endl;
    }

    delete [] p;
    fout.close();
    return 0;
}