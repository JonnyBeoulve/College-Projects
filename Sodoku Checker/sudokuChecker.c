// Author: Jonathan Leack
// Title: Sudoku Checker
 
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct 
{
  int row;
  int column;
  int (* board)[9];
} parameters;

// check each row to see if it has all numbers 1->9
void * checkRows(void * params) {
  parameters * number = (parameters *) params;
  int startRow = number->row;
  int startcolumn = number->column;
  for (int i = startRow; i < 9; ++i) {
    int row[10] = {0};
    for (int j = startcolumn; j < 9; ++j) {
      int num = number->board[i][j];
      if (row[num] != 0) {
	return (void *) 0;
      }
      else{
	row[num] = 1;
      }
    }
  }
  return (void *) 1;
}
// check each column to see if it has the right numbers 1->9
void * checkcolumns(void * params) {
  parameters * number = (parameters *) params;
  int startRow = number->row;
  int startcolumn = number->column;
  for (int i = startcolumn; i < 9; ++i) {
    int column[10] = {0};
    for (int j = startRow; j < 9; ++j) {
      int num = number->board[j][i];
      if (column[num] != 0) {
	return (void *) 0;
      }
      else{
	column[num] = 1;
      }
    }
  }
  return (void *) 1;
}
// check each square to see if it has all the right numbers 1->9
void * checkSquare(void * params) {
  parameters * number = (parameters *) params;
  int startRow = number->row;
  int startcolumn = number->column;
  int saved[10] = {0};
  for (int i = startRow; i < startRow + 3; ++i) {
    for (int j = startcolumn; j < startcolumn + 3; ++j) {
      int num = number->board[i][j];
      if (saved[num] != 0) {
	return (void *) 0;
      }
      else{
	saved[num] = 1;
      }
    }
  }
  return (void *) 1;
}

int main(void) 
{
  // build board
  int board[9][9] = {
    {6, 2, 4, 5, 3, 9, 1, 8, 7},
    {5, 1, 9, 7, 2, 8, 6, 3, 4},
    {8, 3, 7, 6, 1, 4, 2, 9, 5},
    {1, 4, 3, 8, 6, 5, 7, 2, 9},
    {9, 5, 8, 2, 4, 7, 3, 6, 1},
    {7, 6, 2, 3, 9, 1, 4, 5, 8},
    {3, 7, 1, 9, 5, 6, 8, 4, 2},
    {4, 9, 6, 1, 8, 2, 5, 7, 3},
    {2, 8, 5, 4, 7, 3, 9, 1, 6}
  };
    
  // parameters for the columns and rows
  parameters * rowcolumnParam = (parameters *) malloc(sizeof(parameters));
  rowcolumnParam->row = 0;
  rowcolumnParam->column = 0;
  rowcolumnParam->board = board;
    
  // create the parameters for each box
  parameters * box1Param = (parameters *) malloc(sizeof(parameters));
  box1Param->row = 0;
  box1Param->column = 0;
  box1Param->board = board;
  parameters * box2Param = (parameters *) malloc(sizeof(parameters));
  box2Param->row = 0;
  box2Param->column = 3;
  box2Param->board = board;
  parameters * box3Param = (parameters *) malloc(sizeof(parameters));
  box3Param->row = 0;
  box3Param->column = 6;
  box3Param->board = board;
  parameters * box4Param = (parameters *) malloc(sizeof(parameters));
  box4Param->row = 3;
  box4Param->column = 0;
  box4Param->board = board;
  parameters * box5Param = (parameters *) malloc(sizeof(parameters));
  box5Param->row = 3;
  box5Param->column = 3;
  box5Param->board = board;
  parameters * box6Param = (parameters *) malloc(sizeof(parameters));
  box6Param->row = 3;
  box6Param->column = 6;
  box6Param->board = board;
  parameters * box7Param = (parameters *) malloc(sizeof(parameters));
  box7Param->row = 6;
  box7Param->column = 0;
  box7Param->board = board;
  parameters * box8Param = (parameters *) malloc(sizeof(parameters));
  box8Param->row = 6;
  box8Param->column = 3;
  box8Param->board = board;
  parameters * box9Param = (parameters *) malloc(sizeof(parameters));
  box9Param->row = 6;
  box9Param->column = 6;
  box9Param->board = board;
    
  // threads
  pthread_t threadRows, threadcolumns, box1, box2, box3, box4, box5, box6, box7, box8, box9;
    
  void * waitRows;
  void * waitcolumns;
  void * waitSquare1;
  void * waitSquare2;
  void * waitSquare3;
  void * waitSquare4;
  void * waitSquare5;
  void * waitSquare6;
  void * waitSquare7;
  void * waitSquare8;
  void * waitSquare9;
    
  // initialize threads
  pthread_create(&threadRows, NULL, checkRows, (void *) rowcolumnParam);
  pthread_create(&threadcolumns, NULL, checkcolumns, (void *) rowcolumnParam);
  pthread_create(&box1, NULL, checkSquare, (void *) box1Param);
  pthread_create(&box2, NULL, checkSquare, (void *) box2Param);
  pthread_create(&box3, NULL, checkSquare, (void *) box3Param);
  pthread_create(&box4, NULL, checkSquare, (void *) box4Param);
  pthread_create(&box5, NULL, checkSquare, (void *) box5Param);
  pthread_create(&box6, NULL, checkSquare, (void *) box6Param);
  pthread_create(&box7, NULL, checkSquare, (void *) box7Param);
  pthread_create(&box8, NULL, checkSquare, (void *) box8Param);
  pthread_create(&box9, NULL, checkSquare, (void *) box9Param);

  // wait for each thread to complete their job
  pthread_join(threadRows, &waitRows);
  pthread_join(threadcolumns, &waitcolumns);
  pthread_join(box1, &waitSquare1);
  pthread_join(box2, &waitSquare2);
  pthread_join(box3, &waitSquare3);
  pthread_join(box4, &waitSquare4);
  pthread_join(box5, &waitSquare5);
  pthread_join(box6, &waitSquare6);
  pthread_join(box7, &waitSquare7);
  pthread_join(box8, &waitSquare8);
  pthread_join(box9, &waitSquare9);

  // display sudoku board
  printf("\n\t====== SUDOKU BOARD ======\n\t");
  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      printf("%d, ", board[j][i]);
    }
    printf("\n\t");
  }
    
  //check every row, column, and square to see if puzzle is solved
  if ((int) waitRows != 1){
    printf("\nNot all rows are solved!\n");
  }
  else if((int) waitcolumns != 1){
    printf("\nNot all columns are solved!\n");
  }
  else if((int) waitSquare1 != 1){
    printf("\nSquare 1 isn't solved!\n");
  }
  else if((int) waitSquare2 != 1){
    printf("\nSquare 2 isn't solved!\n");
  }
  else if((int) waitSquare3 != 1){
    printf("\nSquare 3 isn't solved!\n");
  }
  else if((int) waitSquare4 != 1){
    printf("\nSquare 4 isn't solved!\n");
  }
  else if((int) waitSquare5 != 1){
    printf("\nSquare 5 isn't solved!\n");
  }
  else if((int) waitSquare6 != 1){
    printf("\nSquare 6 isn't solved!\n");
  }
  else if((int) waitSquare7 != 1){
    printf("\nSquare 7 isn't solved!\n");
  }
  else if((int) waitSquare8 != 1){
    printf("\nSquare 8 isn't solved!\n");
  }
  else if((int) waitSquare9 != 1){
    printf("\nSquare 9 isn't solved!\n");
  }
  else{
    printf("\nThe Sudoku Puzzle is solved!\n");
  }
    
  return 0;
}
