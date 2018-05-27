/***********************************************************************************************************************************************
Courese      :   Data Structures and Algorithms
Year         :   2018
Name         :   HERATH HMMISB
Date         :   02-05-2018



**********************************************************************************************************************************************************/

//Header Files
#include <iostream>
#include <math.h>
#include<fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <ctime>

//Declare namespace
using namespace std;


class MySort{

private:

public:

	//Sorting Functions

	void SelectSort(vector<int>& vec, int n);
	void InnsertionSort(vector<int>& Vec, int length);
	void BubbleSort(vector<int>& Vec, int length);

	vector<int> Merge_Sort(vector<int>& vec);
	vector<int> Merge(const vector<int>& left, const vector<int>& right);

	void QuickSort(vector<int>& Vec, int LowIndex, int HighIndex);



};
//Declaring Functions


//Supportive Functions for Sort

void FileWrite(const vector<int>& VecN,string fileWrite);
void ReadFile(vector<int>& vec1,string fileRead);
void DisplayFile(const vector<int>& Vec,string St);
vector<int> SortDecending(const vector<int> Vec);


//Main funtion

int main() {

	std::vector<int> VecSec;
	std::vector<int> VecInsrt;
	std::vector<int> VecBuble;
	std::vector<int> VecMerge;
	std::vector<int> VecQuick;

  string RandomSet="Set5.txt"; // input Txt file

  ReadFile(VecSec,RandomSet);     // streaming Random Numbers to Vector ;
  ReadFile(VecInsrt,RandomSet);
	ReadFile(VecBuble,RandomSet);
	ReadFile(VecMerge,RandomSet);
	ReadFile(VecQuick,RandomSet);


	//Creating MySort Object to call Sort Functions
	MySort SortFunction;
  std::cout << "\n----------Time taken for : " <<RandomSet<<" ---------"<< '\n';
  int start_s;
	int stop_s;

	start_s=clock(); // Getting Start time ;

     SortFunction.SelectSort(VecSec,(VecSec.size()));


  stop_s=clock();
  cout << "  SelectSort :  " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << " ms "<<endl;

  start_s=clock();

	    SortFunction.InnsertionSort(VecInsrt,(VecInsrt.size()));

  stop_s=clock();
	cout << "  Innsertion Sort :  " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << " ms "<< endl;

	start_s=clock();

	    SortFunction.BubbleSort(VecBuble,(VecBuble.size()));

	 stop_s=clock();
	 cout << "  Bubble Sort :  " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << " ms "<< endl;

	 start_s=clock();

      VecMerge=SortFunction.Merge_Sort(VecMerge);

	 stop_s=clock();
	 cout << "  Merge Sort :  " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000<< " ms " << endl;

	 start_s=clock();

       SortFunction.QuickSort(VecQuick,0,(VecQuick.size()-1));

	 stop_s=clock();
	 cout << "  Quick  Sort :  " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << " ms "<< endl;


  // FileWrite(VecSec,"SetB.txt");
	// FileWrite(SortDecending(VecSec),"SetC.txt");

	return 0;

}


///////////////  Sorting Algorithms /////////////////////


void MySort::QuickSort(vector<int>& Vec, int LowIndex, int HighIndex){

            int i = LowIndex;
            int j = HighIndex;

            int Pivot = Vec[(i + j) / 2];
            int Temp;

       while (i <= j){

			         while (Vec[i] < Pivot){

                   i++;
				       }

              while (Vec[j] > Pivot){

                 j--;
              }


            if (i <= j){

                Temp = Vec[i];
                Vec[i] = Vec[j];
                Vec[j] = Temp;

                i++;
                j--;
            }
    }


    if (j > LowIndex){

			        QuickSort(Vec, LowIndex, j);
		}



    if (i < HighIndex){

          QuickSort(Vec, i, HighIndex);
		}


}






vector<int> MySort::Merge_Sort(vector<int>& vec){


		if(vec.size() == 1)
		{
				return vec;  // base condition // if only one element remain return ;
		}

		// getting the location of the middle element in the vector
		std::vector<int>::iterator middle = vec.begin() + (vec.size() / 2);

		vector<int> left(vec.begin(), middle);
		vector<int> right(middle, vec.end());

		// executing the  merge sort on the two smaller vectors
		left = Merge_Sort(left);
		right = Merge_Sort(right);

		return Merge(left, right); //returning sorted vectors
}


vector<int> MySort::Merge(const vector<int>& left, const vector<int>& right){

	     	// Fill the resultant vector with sorted results from both vectors

		    vector<int> result;
		    unsigned leftIdx = 0, rightIdx = 0;

		while(leftIdx < left.size() && rightIdx < right.size()){

				    // If the left value is smaller than the right it goes next
				    // into the resultant vector
				if(left[leftIdx] < right[rightIdx]){

						 result.push_back(left[leftIdx]);
						 leftIdx++;

				}else{

						result.push_back(right[rightIdx]);
						rightIdx++;

				}
		}

		// Push the remaining data from both vectors onto the resultant
		while(leftIdx < left.size()){

				result.push_back(left[leftIdx]);
				leftIdx++;

		}

		while(rightIdx < right.size()){

				result.push_back(right[rightIdx]);
				rightIdx++;

		}

		return result;
}



void MySort::BubbleSort(vector<int>& Vec, int length){

    int i, j, Temp;

    for(i = 0; i < length; i++){               // loop for sorting set sub-cases

          for(j = 0; j <length-i-1; j++){      // Swaping element within semis sorted set

                if( Vec[j] > Vec[j+1]){


                     Temp = Vec[j];
                     Vec[j] = Vec[j+1];   // Swaping elements if Vec[1]<Vec[0]
                     Vec[j+1] = 	Temp;
                 }
           }
     }


}

void MySort::InnsertionSort(vector<int>& Vec, int length){

	       int i, j, ElemtVal;

	      for (i = 1; i < length; i++){

	          	 j = i;

						  // Sorting sub_List

 		          while (j > 0 && Vec[j - 1] > Vec[j]){

 		          	ElemtVal = Vec[j];    // assigng  relatively (1)th value to elemnt var
 			          Vec[j] = Vec[j - 1];  // when val[0]>val[1]
 		          	Vec[j - 1] = ElemtVal; // val[0]= element (1)th value

 		           	j--;  // going << to check sublist

 		         }
	       }

}



void MySort::SelectSort(vector<int>& vec, int n){


	 int PosMinVal, Temp;

	 for (int i = 0; i < n - 1; i++){

		PosMinVal = i;          //Set PosMinVal to the current index of array

		for (int j = i + 1; j < n; j++){

		  	if (vec[j] < vec[PosMinVal]){
				  PosMinVal = j;
			   }

				 // locating the Position of minmum value in the set

	 	}

	      // Swapping Minimum valus with capmaring minmum value at (i)th positiong

		      if (PosMinVal != i){

		        	Temp = vec[i];
		         	vec[i] = vec[PosMinVal];
			        vec[PosMinVal] = Temp;

		      }
	   }

}


//Supportive Functions

void ReadFile(vector<int>& vec1,string fileRead) {

        int idx=0 ; //indexing int for vector
        vector<int> Temp;

	      ifstream infile(fileRead.c_str());

	   if(!infile){

			  cerr << "Error, file does not exist. " << endl;


		 }else{

				        while(!infile.eof()){

										 int getInt;
                     infile>>getInt;
                     Temp.push_back(getInt);   // here last iterration return null value so
                                               //  vector size is (Size+1)
                       idx++;
				        }

					infile.close();
		}

     for (int id = 0; id < (Temp.size()-1); id++) {
     	      vec1.push_back(Temp[id]);          // getting pure random number set
     }

    //  DisplayFile(vec1,"Steamed Random Numbers are ");
}


void FileWrite(const vector<int>& VecN,string fileWrite){


              ofstream outfile;  // creating output stream object
	            outfile.open(fileWrite.c_str()); // creating output file



	           for (int i = 0; i < (VecN.size()); i++) {

		         outfile << VecN[i]<< endl;

					   }

						 outfile.close();  // closing output stream

            // Displying values were commeted

          //   DisplayFile(VecN,"Sorted Random Numbers");

          //   std::cout << "Sorted Random numbers are saved to ‘"<<fileWrite.c_str()<<"’ file \n"  ;
          //   std::cout << "------------------------------------------------------------------\n"  ;

}



void DisplayFile(const vector<int>& Vec,string St){

	std::cout << "------------------------------\n"  ;
	std::cout << " "<<St.c_str()<<" : "<<'\n'  ;
	std::cout << "------------------------------\n"  ;

     for (int i = 0; i < (Vec.size()) ; i++) {

			  std::cout << Vec[i] << '\n';
     }

  std::cout << "------------------------------\n"  ;

}

// This function used to sort accendingly sorted list decendingly
vector<int> SortDecending(const vector<int> Vec){
    std::vector<int> Temp; // Temp vector for return vector

		for (int Idx = (Vec.size()-1); Idx >= 0 ; Idx--) {

			 Temp.push_back(Vec[Idx]);  // asging values in Decending order
		}

	  return Temp;
}
