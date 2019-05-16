#include <iostream>
#include "SortingAlgorithms.h"

using namespace std;

void QuickSort(double myArray[], int start,int end)
{
  int pivot;
  if(start < end)
  {
    pivot = getPivot(myArray, start, end);
    QuickSort(myArray, start, pivot);
    QuickSort(myArray, pivot + 1, end);
  }
}


int getPivot(double myArray[], int start,int end)
{
  int i = start + 1;
  int x = myArray[start];
  int y = start;
  double myArrayY;
  double myArrayI;
  double myArrayStart;

  for(i = start + 1; i < end; i++)
  {
      if(myArray[i]<=x)
      {
          y++;

          myArrayY = myArray[y];
          myArrayI = myArray[i];

          myArray[y] = myArrayI;
          myArray[i] = myArrayY;
      }
  }

  myArrayStart = myArray[start];
  myArrayY = myArray[y];

  myArray[y] = myArrayStart;
  myArray[start] = myArrayY;

  return y;
}

void InsertionSort(double myArray[], int size)
{
  int i = 1;
  int j = 0;
  double x = 0.0;

  for(i = 1; i < size; i++)
  {
    j = i - 1;
    x = myArray[i];

    while(j >= 0 && myArray[j] > x)
    {
      myArray[j+1] = myArray[j];
      j--;
    }

    myArray[j+1] = x;
  }
}

void BubbleSort(double myArray[], int size)
{
  int i = 0;
  int j = 0;
  double temp;

  for(i = 0; i < size - 1; i++)
  {
    for(j = 0; j < size - 1 - i; j++)
    {
      if(myArray[j+1] < myArray[j])
      {
        // switch them
        temp = myArray[j+1];
        myArray[j+1] = myArray[j];
        myArray[j] = temp;
      }
    }
  }
}

void SelectionSort(double myArray[], int size)
{
  int minIndex;
  int i;
  int j;
  double temp;

  for(i = 0; i < size - 1; i++)
  {
    //find minimum
    minIndex = i;

    for(j = i + 1; j < size; j++)
    {
      if(myArray[j] < myArray[minIndex])
        minIndex = j;
    }

    // move minimum to front
    temp = myArray[minIndex];
    myArray[minIndex] = myArray[i];
    myArray[i] = temp;
  }
}
