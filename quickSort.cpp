/*
The purpose of this assignment is to design a program that QuickSorts. It should dynamically allocate 
an array large enough to hold test score values. These test scores will come from an input file called “input.txt” 
that then should display the values of the data from ascending and descending order. The program will have values that are input f
rom the “input.txt” file. The output of this program is “Display Input Data:  3 5 16 12 1 4 7 9 10 200 100….., 
Ascending Order: 1 3 4 5 7 9 10 12 16 100 200….., Descending Order: 200 100 16 12 10 9 7 5 4 3 1….” For the 
file to process the “input.txt” file, it will need to be in a dynamically allocated array, in which the array will go into the 
partition() functions and then a Quicksort() function, then in a Display() function for the output. 

*/

#include <iostream> 
#include <string> 
#include <fstream>
#include <iomanip> 
using namespace std;

const int NUM = 22; 
int myArray[NUM]; 

void display (); //Displays the ascending and descending order of the values
int partition(int myArray[], int low, int high);
void quickSort(int myArray[], int low, int high); //Sorts the program from left to right
void Read(int *myArray, int NUM); //Stores the inputs from the file into a a dynamically allocated array

int main (){
    Read(myArray, NUM);
    display();
}

//Purpose of this function is to display both the ascending and descending order.
void display() {
    quickSort(myArray, 0, NUM - 1); //Calls to the function quickSort
    cout<<endl;
    cout<<"Ascending Order: ";
    for (int i = 0; i < NUM; i++) { //Loops in ascending order
        cout << myArray[i] << " "; //displays output of the array
    }

		cout<<endl;
		cout << "Descending Order: ";
		for(int i=NUM; i>=0, i--;) {  //Loops in descending order
            cout <<  myArray[i] << " "; //displays output of the array
        }
			
		cout << endl;
}

//Accepts an array, uses an element x as a pivot, and then arranges x correctly within the sorted array.
int partition(int myArray[], int low, int high) {
 
    int pivot = myArray[low]; //Starting element of the array
 
    int count = 0;
    //Loops through from start to finish
    for (int i = low + 1; i <= high; i++) {
        if (myArray[i] <= pivot)
            count++;
    }

     // Swapping the pivot element to its position
    int pivotIndex = low + count;
    swap(myArray[pivotIndex], myArray[low]); //swaps elements

    int i = low, j = high; //loop control variables
 

    //Begin sorting from left to right of the array
    while (i < pivotIndex && j > pivotIndex) {
         //Checks if pivot is greater or equal to
        while (myArray[i] <= pivot) {
            i++;
        }
        //Checks if pivot is less
        while (myArray[j] > pivot) {
            j--;
        }
 
        //Swaps if the pivotIndex is less than the start and greater than the end
        if (i < pivotIndex && j > pivotIndex) {
            swap(myArray[i++], myArray[j--]);
        }
    }
 
    return pivotIndex;
}

//Sorts from the left to the right side .
void quickSort(int myArray[], int low, int high)
{
    if (low >= high)
        return;
 
    //partitioning the array
    int p = partition(myArray, low, high);
 
    //Sorting the left hand side
    quickSort(myArray, low, p - 1);
 
    //Sorting the right hand side
    quickSort(myArray, p + 1, high);
}

//Checks for the file and then displays the number within the text file
void Read(int *myArray, int NUM) {   
   int i = 0;    
   string inFileName = "input.txt"; //input.txt
   ifstream inFile;   
   inFile.open(inFileName.c_str()); //Opens the input.txt file
  
  //If the file opens, it will then iterate through the input file and store the numbers into myArray[]
   if (inFile.is_open()) {     
   		cout << "Display Input Data: ";     
		for (i = 0; i < NUM; i++) {       
			inFile >> myArray[i];      
			cout << myArray[i] << " ";     
			}     
           
		inFile.close(); //Close file
		} 
        //Checks to see if the file didn't open correctly
        else {               
		cerr << "Error, find input file: " << inFileName << endl;  
		} 
	} 