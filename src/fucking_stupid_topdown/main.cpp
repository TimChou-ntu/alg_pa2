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
        cout<<chord_h<<endl;
        cout<<chord_e<<endl;
    }
    cout<<"======="<<endl;

    mps myMPS(p,n);
    int ans = -100;
    ans = (myMPS.calculate_mps(0,2*n-1));
    cout<<endl<<ans<<endl;

    int** chords = new int*[ans];
    for(int i = 0; i < ans; i++){
        chords[i] = new int[2];
    } 

    myMPS.get_chord(0,2*n-1,chords);
    fout<<ans<<endl;
    for(int i = 0; i < ans; i++){
        fout<<chords[i][0]<<" "<<chords[i][1]<<endl;
    }

    delete [] p;
    fout.close();
    return 0;
}