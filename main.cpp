/* Author: Allison Delgado
 * Last Updated: November 28, 2020
 * This program creates a heap to store up to 100 numbers
 * and displays them visually
 */
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;
#define SIZE 100

struct Node {
  int value; //num
  Node *left; //left child
  Node *right; //right child
};

//function prototypes
void openFile(int inputArray[SIZE]);
void getManualNums(int inputArray[SIZE]);
Node* insert(int inputArray[SIZE]);
void printTree(); //prints visual tree
void printOutput(); //prints greatest to smallest
void heapify(); //recursively swaps nodes to order in heap 
void removeNode(); //removes from tree, adds to output

//creates nodes for each slot of input array
Node* insert(int inputArray[SIZE]){


}

//gets numbers from a file
void openFile(int inputArray[SIZE]){
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
}

//gets manually entered numbers from user
void getManualNums(int inputArray[SIZE]){
  char input[1000];
  Node* numPtr = new Node;
  int num = 0;
  int amountOfNums = 0;
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
    amountOfNums++; //used for debug print
    counter++; //iterate in order to add into array
  }
  /* debug:
  cout << "print array: " << endl;
  for(int j = 0; j < amountOfNums; j++){
    cout << inputArray[j] << endl;
  }
  */
}

int main(){
  int input = 0;
  int inputArray[SIZE];
  Node* tree;
  bool validInput = false;
  cout << "*************************" << endl;
  cout << "Welcome to Heap!" << endl;
  while(validInput == false){
    cout << "Would you like to input numbers through: " << endl;
    cout << "(1) a file" << endl;
    cout << "(2) the console" << endl;
    cout << "> ";
    cin >> input;
    cin.get();
    if(input == 1){ //numbers are in a file
      validInput = true;
      openFile(inputArray);
      tree = insert(inputArray);
    }
    else if(input == 2){ //manually input numbers
      validInput = true;
      getManualNums(inputArray);
      tree = insert(inputArray);
    }
    else { //neither 
      cout << "That was not a valid input." << endl;
      validInput = false;
    }
  }
  return 0;
}
