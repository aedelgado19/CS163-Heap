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

//function prototypes
Node** openFile(Node* array[]);
Node** getManualNums(Node* array[]);

struct Node {
  int value;
  Node *previous;
  Node *next;
};


int main(){
  int input = 0;
  Node** array = new Node*[SIZE];
  bool validInput = false;
  cout << "*************************" << endl;
  cout << "Welcome to Heap!" << endl;
  while(validInput == false){
    cout << "Would you like to input numbers through: " << endl;
    cout << "(1) a file" << endl;
    cout << "(2) the console" << endl;
    cout << "> " << endl;
    cin >> input;
    cin.get();
    if(input == 1){ //numbers are in a file
      array = openFile(array);
    }
    else if(input == 2){ //manually input numbers
      array = getManualNums(array);
    }
    else { //neither 
      cout << "That was not a valid input." << endl;
      validInput = false;
    }
  }
  return 0;
}

Node** openFile(Node *array[]){
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
  return array;
}

Node** getManualNums(Node *array[]){
  char input[1000];
  cout << "Enter in up to 100 numbers with values between 1 and 1000." << endl;
  cout << "Separate the numbers by spaces. " << endl;
  cin.get(input, 1000);
  cin.get();

  //parsing method from stack overflow
  char *token = strtok(input, " ");
  while(token != NULL){
    cout << atoi(token) << endl;
    token = strtok(NULL, " ");
  }
  return array;
}
