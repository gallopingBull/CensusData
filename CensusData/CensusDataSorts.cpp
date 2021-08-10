/**
 * @file CensusDataSorts.cpp   Sort functions for census population data.
 * 
 * @brief
 *    Implements several different types of sorts. Data can be sorted
 * by population or by name of town. This file contains all of the sorting
 * functions and their helpers.
 *
 * @author Joshua Salcido
 * @date 2/23/16
 */
#include <ctime> 
#include <iostream>
#include <sstream>
#include <string>
#include <random>
#include <vector>
#include "CensusData.h"

/*
 * Implementation of a sorting algorithm that sorts, 
 * either strings or ints, by one element at a  
 * time --  from smallest to biggest, or alphabetically.  
 *
 * @param 'type' dictates the data type that will be sorted. 
*/ 
void CensusData::insertionSort(int type) {
  
    int j;
    Record* tmp;

    if (type == 1){
     
        for(int i = 1;i < getSize(); i++){
            tmp = data[i]; 
            j=i - 1;            
            while(j>=0 && (*data[j]->city) > (*tmp->city)){
                
                data[j + 1] = data[j]; 
                j = j-1;
            }
            data[j + 1] = tmp; 
        }  
    }

    else{
      
        for(int i = 1;i < getSize(); i++){
            tmp = data[i]; 
            j=i - 1;            
            while(j>=0 && data[j]->population > tmp->population){
                
                data[j + 1] = data[j]; 
                j = j-1;
            }
            data[j + 1] = tmp; 
        }  
    } 
}

/*
 * Private helper method that calls MergeSort()
 * Also initializes 'p'(indice to first element in the vector)
 * and 'r' (indice to last element). 
 *
 * @param 'type' dictates the data type that will be sorted. 
*/ 
void CensusData::mergeSort(int type) {
    
    int p, r;

    p = 0;
    r = getSize() - 1;
        
    MergeSort(p, r, type);  

}

/*
 * Implementation of a recursive algorithm 
 * that sorts either strings or  ints from smallest 
 * to largest,or alphabetically.
 *
 * @param 'type' dictates the data type that will be sorted. 
 * @param 'p' is an indice to first element in the vecotr.
 * @param 'r' is an indice to the last element in th vecotr.  
*/ 
void CensusData::MergeSort(int p, int r, int type){
        
    if (p < r){
        
        int q; 
        q = (p+r)/2;
        
        MergeSort(p, q, type);
        MergeSort(q+1, r, type); 
        Merge(p, q, r, type);
        
    } 
}

/*
 * Implementation of a recusive algorithm 
 * that sorts either strings or ints from smallest 
 * to largest,or alphabetically.
 *
 * @param 'type' dictates the data type that will be sorted. 
 * @param 'p' is an indice to first element in the vecotr.
 * @param 'q' is an indice to the middle element in the vector. 
 * @param 'r' is an indice to the last element in the vector.  
*/ 
void CensusData::Merge(int p, int q, int r, int type){
    
    int n1 = q - p + 1; 
    int n2 = r - q;
   
    std::vector<Record*> left;
    std::vector<Record*> right;
    
    string infiniCity = "kskfhslkjfhdslkjfhdsflkjshdkjfhdskfhdskjfhsdkjlfhdskfskjfh";
    string infiniState = "jlkjlsjljfkljsfkljsfkljsdlfjdsklfjdslfjdslfjdsklfjsdljdsl";
    int infiniPop = 199999999; 
    Record* infini;
    
    infini = new Record(infiniCity, infiniState, infiniPop); 
     

    for (int index = 0; index < n1; index++){
            left.push_back(data[p + index]);
        }           
             
    for (int index = 0; index < n2; index++){
            right.push_back(data[q + index + 1]); 
        }
     
    left.push_back(infini); 
    right.push_back(infini); 
   
    int i = 0; 
    int j = 0; 

    if (type == 1){
        for (int k = p; k <= r; k++){

            if (((n1 != i) && (n2 == j)) || (*left[i]->city <= *right[j]->city)){
                data[k] = left[i];
                i++; 
            }
    
            else{
                data[k] = right[j]; 
                j++; 
            }
        }
    }
    
    else{           
        for (int k = p; k <= r; k++){

            if (((n1 != i) && (n2 == j)) || left[i]->population <= right[j]->population){
                data[k] = left[i];
                i = i+1; 
            }
           
            else{
                data[k] = right[j]; 
                j = j+1; 
            }
        } 
    } 
}

/*
 *  Helper mehod initializes 'p' and 'r' 
 *  then calls QuickSort()
 *
 * @param 'type' dictates the data type that will be sorted. 
*/ 
void CensusData::quickSort(int type) {
    int p, r;

    p = 0;
    r = getSize() - 1;
    
    QuickSort(p, r, type);
   
}

/*
 * Implementation of a recursive algorithm 
 * that sorts either strings or  ints from smallest 
 * to largest,or alphabetically. This a randomized 
 * version of quicksort so the pivot is randomly
 * selected using randomizedPartition().
 *
 * @param 'type' dictates the data type that will be sorted. 
 * @param 'p' is an indice to first element in the vecotr.
 * @param 'r' is an indice to the last element.  
*/ 
void CensusData::QuickSort(int p, int r, int type){
   
    if (p < r){ 
        int q = randomizedPartition(p,r, type);
        QuickSort(p, q-1, type);
        QuickSort(q+1, r, type); 
    } 
}

/*
 * Generates a random number for a pivot point
 * and sends it to partition().
 *
 * @param 'type' dictates the data type that will be sorted. 
 * @param 'p' is an indice to first element in the vecotr.
 * @param 'r' is an indice to the last element in the vector. 
 *
 *@return an indice to an element after partition() is
 *finished sorting. 
*/ 
int CensusData::randomizedPartition(int p, int r, int type){
  
    std::default_random_engine generator(time(0));
    std::uniform_int_distribution<int> randNum(p, r);
    int rn = randNum(generator);
  
    std::swap(data[r], data[rn]);

    return partition(p, r, type); 

}

/*
 * Implementation of a recursive algorithm 
 * that sorts either strings or  ints from smallest 
 * to largest,or alphabetically. 
 *
 * @param 'type' dictates the data type that will be sorted. 
 * @param 'p' is an indice to first element in the vecotr.
 * @param 'r' is an indice to the last element in the vector.
 *
 * @return am indice to the next element in the vector. 
*/ 

int CensusData::partition(int p, int r, int type){
    
    Record* x = data[r];

    int j = p - 1; 
     
    if (type == 1){
        for (int i =p; i < r; i++){
            if((*data[i]->city) <= (*x->city)){ 
                j = j+1; 
                std::swap(data[j], data[i]);
            }
        }
    }
 
    else{
        for (int i = p; i < r; i++){
            if(data[i]->population <= x->population){ 
                j = j+1; 
                std::swap(data[j], data[i]);
            }
        }
    }
    
    std::swap(data[j+ 1], data[r]);

    return j + 1; 
}
