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


//visually prints a horizontal tree recursively
void visualPrint(int outputArray[], int index, int depth){
  if(outputArray[index] <= 0 || index > 101){
    return;
  }
  //top child
  visualPrint(outputArray, index*2+1, depth+1);

  //spacing
  for(int i = 0; i < depth; i++){
    cout << "   ";
  }
  cout << outputArray[index] << endl;

  //bottom child
  visualPrint(outputArray, index*2, depth+1);

}

// removing numbers from heap, cout as array output
void remove(int outputArray[], int arraysize){  
  cout << "Array form of heap: " << endl;
  for(int i = 1; i < arraysize+1; i++){
    if(outputArray[i] != 0){
      cout << outputArray[i] << " ";
    }
    outputArray[i] = 0;
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
    searchnum = outputArray[childIndex];
    parentIndex = findParent(outputArray, childIndex);
    parentNum = outputArray[parentIndex];
  }
}

int findParent(int outputArray[], int childIndex){
  int parentIndex = 0;
  parentIndex = childIndex/2;
  if(parentIndex == 0){
    parentIndex = 1; //special case
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
  while(token != NULL){
    num = atoi(token);
    token = strtok(NULL, " ");    
    inputArray[counter] = num;
    amountOfNums++;
    counter++; //iterate in order to add into array
  }
  return amountOfNums;
}

int main(){
  int arraysize = 0;
  int input = 0;
  int inputArray[SIZE];
  int outputArray[101] = { };
  bool validInput = false;
  cout << "*************************" << endl;
  cout << "Welcome to Heap!" << endl;
  while(validInput == false){
    cout << "Please use the following numbers to indicate your response. " << endl;
    cout << "Would you like to input numbers through: " << endl;
    cout << "(1) a file" << endl;
    cout << "(2) the console" << endl;
    cout << "> ";
    cin >> input;
    cin.get();
    if(input == 1){ //numbers are in a file
      validInput = true;
      arraysize = openFile(inputArray);
      insert(inputArray, arraysize, outputArray);
      visualPrint(inputArray, 1, 0);
      remove(outputArray, arraysize);
      
    }
    else if(input == 2){ //manually input numbers
      validInput = true;
      arraysize = getManualNums(inputArray);
      insert(inputArray, arraysize, outputArray);
      visualPrint(inputArray, 1, 0);
      remove(outputArray, arraysize);
    }
    else { //neither 
      cout << "That was not a valid input." << endl;
      validInput = false;
    }
  }
  return 0;
}
