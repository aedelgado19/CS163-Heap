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


int main(){
  int input = 0;
  int inputArray[SIZE];
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
    }
    else if(input == 2){ //manually input numbers
      validInput = true;
      getManualNums(inputArray);
    }
    else { //neither 
      cout << "That was not a valid input." << endl;
      validInput = false;
    }
  }
  return 0;
}

void openFile(int inputArray[SIZE]){
  ifstream inFile;
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
  //havent done yet: read in all numbers and put into array
}

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

  //parsing method from stack overflow
  char *token = strtok(input, " ");
  while(token != NULL){
    num = atoi(token);
    cout << "num: " << num << endl;
    token = strtok(NULL, " ");    

    inputArray[counter] = num;
    amountOfNums++;
    cout << "added" << endl;
    counter++;
  }
  cout << "print array: " << endl;
  for(int j = 0; j < amountOfNums; j++){
    cout << inputArray[j] << endl;
  }
}
