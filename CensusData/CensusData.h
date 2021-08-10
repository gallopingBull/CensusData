/**
 * @file CensusData.h   Declaration of the CensusData class.
 *
 * @author Judy Challinger && Joshua Salcido <3
 * @date 2/22/13
 */

#ifndef CSCI_311_CENSUSDATA_H
#define CSCI_311_CENSUSDATA_H

#include <vector>
using std::ifstream;
using std::string;
using std::vector;

class CensusData {
public:
   static const int POPULATION = 0;       // type of sort
   static const int NAME = 1;
   ~CensusData();
   void initialize(ifstream&);            // reads in data
   int getSize(){return data.size();}
   void print();                          // prints out data
   void insertionSort(int);               // sorts data using insertionSort
   void mergeSort(int);                   // sorts data using mergeSort
   void quickSort(int);                   // sorts data using quickSort
private:
   class Record {                         // declaration of a Record
   public:
      string* city;
      string* state;
      int population;
      Record(string&, string&, int);
      ~Record();
   };
   vector<Record*> data;                  // data storage
//
// You may add your private helper functions here!
//
//
   void Merge(int p, int q, int r, int type); // sorts data 
   void MergeSort(int p, int  r, int type); // calls Merge() to sort
   int partition(int p, int r, int type); //sorts data  
   int randomizedPartition(int p, int r, int type); //generates random number and call partition() 
   void QuickSort(int p, int r, int type); //calls randomizedPartition() 

};

#endif // CSCI_311_CENSUSDATA_H
