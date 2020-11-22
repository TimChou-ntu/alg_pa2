#include "planar.h"
#include<iostream>

using namespace std;

bool sortcol(const vector<int>& v1, const vector<int>& v2 ){ 
    return v1[0] < v2[0]; 
} 

void mps::calculate_mps(){
    int length = 2*this->N;
    int i, j, k;
    for(int dis = 1; dis < length; dis++){
        i = 0;
        j = i + dis;
        while(j != length){
            k = this->All_chord[j];
            if ((k < i) || (k > j)){
                this->mps_record[i][j] = this->mps_record[i][j-1];
            }
            else if((k > i) && ( k < j)){
                if(this->mps_record[i][j-1] >= (this->mps_record[i][k-1]+this->mps_record[k+1][j-1]+1)){
                    this->mps_record[i][j] = this->mps_record[i][j-1];
                }
                else{
                    this->mps_record[i][j] = (this->mps_record[i][k-1]+this->mps_record[k+1][j-1]+1);
                    this->case_list[i][j] = 2;
                }
            }
            else if(k == i){
                if(dis == 1){
                    this->mps_record[i][j] = 1;
                    this->case_list[i][j] = 3;
                }
                else{
                    this->mps_record[i][j] = (this->mps_record[i+1][j-1] + 1);
                    this->case_list[i][j] = 3;
                }
            }
            i++;
            j++;
        }
    }
    //test
    for(int i = 0; i < 2*this->N; i++){
        for(int j = 0; j < 2*this->N; j++){
            cout<<this->case_list[i][j]<<" ";
        }
        cout<<endl;
    }
}

int mps::get_ans(){
    this->Ans = this->mps_record[0][2*this->N-1];
    return this->Ans;
}

void mps::get_chord(int& x, int i, int j, vector<vector<int>>& mps_chords){
    while((j-i) > 1){
        if(this->case_list[i][j] == 2){
            int k = this->All_chord[j];
            mps_chords[x][0] = k;
            mps_chords[x][1] = j;
            x++;
            this->get_chord(x, k, j-1, mps_chords);
            j = k-1;
        }
        else if(this->case_list[i][j] == 3){
            int k = this->All_chord[j];
            mps_chords[x][0] = k;
            mps_chords[x][1] = j;
            x++;
            this->get_chord(x, i+1, j-1, mps_chords);
            j = i-1;
        }
        else{
            j--;
        }
    }
}

void mps::get_mps_chords(vector<vector<int>>& mps_chords){
    int x = 0;
    this->get_chord(x, 0, (2*this->N)-1, mps_chords);
    sort(mps_chords.begin(), mps_chords.end(), sortcol);
}