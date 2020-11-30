/* Author: Allison Delgado
 * Last Updated: November 29, 2020
 * This program creates a heap to store up to 100 numbers
 * and displays them visually
 */
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;
#define SIZE 100

//function prototypes
int openFile(int inputArray[SIZE]);
int getManualNums(int inputArray[SIZE]);
void insert(int inputArray[SIZE], int arraysize, int outputArray[]);
void heapify(int outputArray[], int searchnum, int childIndex); 
int findParent(int outputArray[], int childIndex);
void remove(int outputArray[], int arraysize); //removes from array, adds to output and visually prints
void visualPrint(int outputArray[], int index, int depth);
bool checkRange(int num);


//visually prints a horizontal tree recursively
/*
algorithm inspired by 
https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
but changed to fit this case (does not use nodes and 
instead works with array). this prints the tree horizontally, 
with the top child first,then adding spacing, then the bottom child.
top = right and bottom = left.
*/
void visualPrint(int outputArray[], int index, int depth){
  if(outputArray[index] <= 0 || index > 101){
    return;
  }

  //top child (right)
  visualPrint(outputArray, index*2+1, depth+1);

  //spacing
  for(int i = 0; i < depth; i++){
    cout << "   ";
  }
  cout << outputArray[index] << endl;

  //bottom child (left)
  visualPrint(outputArray, index*2, depth+1);

}

// removing numbers from heap, cout as array output
void remove(int outputArray[], int arraysize){  
  cout << "Array form of heap: " << endl;
  for(int i = 1; i < arraysize+1; i++){
    if(outputArray[i] != 0){
      cout << outputArray[i] << " ";
    }
    outputArray[i] = 0; //remove
  }
}

//creates nodes for each slot of input array
void insert(int inputArray[SIZE], int arraysize, int outputArray[]){
  int j = 0; //keeps track of input array
  for(int i = 1; i < arraysize+1; i++){ //start at i = 1
    outputArray[i] = inputArray[j];
    j++;
    heapify(outputArray, outputArray[i], i);
  }
}

//sorts out the array into a max heap by swapping nums until child < parent
void heapify(int outputArray[], int searchnum, int childIndex){
  int parentIndex = 0;
  int parentNum = 0;
  int temp = 0;
  parentIndex = findParent(outputArray, childIndex);
  parentNum = outputArray[parentIndex];
  while(searchnum > parentNum){
    //swap numbers
    temp = parentNum;
    parentNum = searchnum;
    searchnum = temp;
    
    //swap indexes
    temp = childIndex;
    childIndex = parentIndex;
    parentIndex = temp;

    //update array
    outputArray[parentIndex] = searchnum;
    outputArray[childIndex] = parentNum;

    //recall functions to prepare for next loop iteration
    childIndex = findParent(outputArray, parentIndex); //make what used to be parent, child

    //update parameters
    searchnum = outputArray[childIndex];
    parentIndex = findParent(outputArray, childIndex);
    parentNum = outputArray[parentIndex];
  }
}

//finds the parent of a child index by dividing index by 2
int findParent(int outputArray[], int childIndex){
  int parentIndex = 0;
  parentIndex = childIndex/2;
  if(parentIndex == 0){
    parentIndex = 1; //special case, return 1
  }
  return parentIndex;
}

//gets numbers from a file
int openFile(int inputArray[SIZE]){
  ifstream inFile;
  int num = 0;
  int count = 0;
  char fileName[30];
  cout << "Enter the file name: " << endl;
  cout << "Remember: numbers must be separated by spaces. " << endl;
  cin.get(fileName, 30);
  cin.get();
  inFile.open(fileName);
  
  if(!inFile){ //error out if cannot open
    cout << "Unable to open file. " << endl;
    cout << "Terminating program. Please re run and try again. " << endl; 
    exit(1);
  }
  while(inFile >> num){
    inputArray[count] = num; //add into input array
    count++;
  }
  return count;
}

//gets manually entered numbers from user
int getManualNums(int inputArray[SIZE]){
  char input[1000];
  int num = 0;
  int amountOfNums = 0;
  bool isInRange = true;
  int counter = 0;
  cout << "Enter in up to 100 numbers with values between 1 and 1000." << endl;
  cout << "Separate the numbers by spaces. " << endl;
  cin.get(input, 1000);
  cin.get();
  char *token = strtok(input, " ");

  //while in range, turn input into numbers
  while(token != NULL){
    num = atoi(token);
    isInRange = checkRange(num);
    if(isInRange == true){
      token = strtok(NULL, " ");    
      inputArray[counter] = num;
      amountOfNums++;
      counter++; //iterate in order to add into array

    } else { //not valid
      cout << "That was not a number within the range of 1 - 1000" << endl;
      cout << "Terminating program. Please re run and try again. " << endl; 
      exit(0);
    }
  }
  return amountOfNums;
}

//checks that inputted numbers are between 1 and 1000
bool checkRange(int num){
  if(num >= 1 && num <= 1000){
    return true;
  } else {
    return false;
  }
}

int main(){
  int arraysize = 0;
  int input = 0;
  int inputArray[SIZE];
  int outputArray[101] = {0};
  bool validInput = false;

  //welcome messages
  cout << "*************************" << endl;
  cout << "Welcome to Heap!" << endl;
  while(validInput == false){
    cout << "Please use the following numbers to indicate your response. " << endl;
    cout << "Would you like to input numbers through: " << endl;
    cout << "(1) a file" << endl;
    cout << "(2) the console" << endl;
    cout << "> ";
    cin >> input;
    cin.clear();
    cin.ignore(1000, '\n');

    if(input == 1){ //numbers are in a file
      validInput = true;
      arraysize = openFile(inputArray);
      insert(inputArray, arraysize, outputArray);
      cout << endl;
      visualPrint(outputArray, 1, 0);
      remove(outputArray, arraysize);
      
    }
    else if(input == 2){ //manually input numbers
      validInput = true;
      arraysize = getManualNums(inputArray);
      insert(inputArray, arraysize, outputArray);
      cout << endl;
      visualPrint(outputArray, 1, 0);
      remove(outputArray, arraysize);
    }
    else { //neither 
      cout << "That was not a valid input." << endl;
      cout << endl;
      cout << "*************************" << endl;
      validInput = false;
    }
  }
  return 0;
}
