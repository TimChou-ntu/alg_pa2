#include "planar.h"
#include<iostream>
using namespace std;

int mps::calculate_mps(int i, int j){
    int mps_now = -10;
    if(j<=i){
        return 0;}
    else if(this->mps_record[j][i] != -1){
        return this->mps_record[j][i];}
    else{
        int k = this->All_chord[j];
        //case 1
        if((k < i) || (k > j)){
            mps_now = this->calculate_mps(i,j-1);
            this->mps_record[j][i] = mps_now;
            return mps_now;
        }
        //case 2
        else if((k > i) && (k < j)){
            //case 2-1
            if(this->calculate_mps(i, j-1) >= (this->calculate_mps(i, k-1) + this->calculate_mps(k+1, j-1) +1)){
                mps_now = this->calculate_mps(i, j-1);
                this->mps_record[j][i] = mps_now;
                return mps_now;
            }
            //case 2-2
            else{
                mps_now = (this->calculate_mps(i, k-1) + this->calculate_mps(k+1, j-1) +1);
                this->mps_record[j][i] = mps_now;
                this->case_list[k] = 2;
                this->case_list[j] = 2;
                return mps_now;
            }
        }
        //case 3
        else if(k == i){
            if((j-i) == 1){
                mps_now = 1;
                this->mps_record[j][i] = mps_now;
                this->case_list[k] = 3;
                this->case_list[j] = 3;
                return mps_now;
            }
            else{
                mps_now = (this->calculate_mps(i+1,j-1) + 1);
                this->mps_record[j][i] = mps_now;
                this->case_list[k] = 3;
                this->case_list[j] = 3;
                return mps_now;
            }
        }
    }
    return mps_now;
}
static int   x = 0;

void mps::get_chord(int i, int j, int** chords){
    while((j-i)>1){
        //if(x == 52){return;}
        int k = this->All_chord[j];
        if(this->case_list[j] == 2 && k < j){
            // int k = this->All_chord[j];
            chords[x][0] = k;
            chords[x][1] = j;
            this->case_list[k] = 0;
            x++;
            this->get_chord(k,j-1,chords);
            j = k-1;
        }
        else if(this->case_list[j] == 3 && k < j){
            // int k = this->All_chord[j];
            chords[x][0] = k;
            chords[x][1] = j;
            this->case_list[k] = 0;
            x++;
            this->get_chord(i+1,j-1,chords);
            //j = i - 1;
            return;
        }
        else{
            j--;
        }
    }
}
vector<vector<int>> mps::get_mps_record(){return this->mps_record;}

int* mps::get_case_list(){return this->case_list;}