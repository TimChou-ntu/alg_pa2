#ifndef _PLANAR_H
#define _PLANAR_H

#include<vector>
#include<iostream>
using namespace std;

class mps {
    public:
        mps(){}; // constructor
        mps(int* all_chord, int n):All_chord(all_chord), N(n) {
            printf("right construction");
            case_list = new int[2*n];
            mps_record.resize(2*n);
            for(int j = 0; j < 2*n; j++){
                mps_record[j] = vector<int>(j,-1);
            }
        }

        int calculate_mps(int, int);
        void get_chord(int, int, int**);
        int* get_case_list();
        vector<vector<int>> get_mps_record();

    private:
        int                         N; // heap size used in heap sort
        int*                        All_chord;
        int*                        case_list;
        vector<vector<int>>         mps_record;
};

#endif
    //     void        InsertionSort(vector<int>&); // sort data using insertion sort
    //     void        MergeSort(vector<int>&); // sort data using merge sort
    //     void        QuickSort(vector<int>&); // sort data using quick sort
    //     void        HeapSort(vector<int>&); // sort data using heap sort
    // private:
    //     void        QuickSortSubVector(vector<int>&, int, int); // quick sort subvector
    //     int         Partition(vector<int>&, int, int); // partition the subvector
    //     void        MergeSortSubVector(vector<int>&, int, int); // merge sort subvector
    //     void        Merge(vector<int>&, int, int, int, int); // merge two sorted subvector
    //     void        MaxHeapify(vector<int>&, int); // make tree with given root be a max-heap 
    //                                                 //if both right and left sub-tree are max-heap
    //     void        BuildMaxHeap(vector<int>&); // make data become a max-heap