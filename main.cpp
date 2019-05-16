#include <iostream>
#include "SortingAlgorithms.h"
#include <fstream>
#include <ctime>

using namespace std;

int main()
{
  // take input and initalize arrays

  string fileName;

  cout << endl;
  cout << "Please enter the name of the text file that contains the array to be sorted." << endl;
  getline(cin, fileName);
  cout << endl;

  double * a;
  double * b;
  double * c;
  double * d;
  int size;
  string delimiter = ", ";
  int counter = 0;
  size_t pos = 0;
  string token;
  int lineNumber = 0;
	string line;
	ifstream myfile (fileName);


// reads one double per line
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      lineNumber ++;

      if(lineNumber == 1)
      {
        size = stoi(line);

        a = new double[size];
        b = new double[size];
        c = new double[size];
        d = new double[size];
      }
      else
      {
        a[lineNumber-2] = stod(line);
        b[lineNumber-2] = stod(line);
        c[lineNumber-2] = stod(line);
        d[lineNumber-2] = stod(line);
      }
		}
		myfile.close();
	}

// reads one line of doubles separated by ", "
/*
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      lineNumber ++;

      if(lineNumber == 1)
      {
        size = stoi(line);
      }
      else
      {
        a = new double[size];
        b = new double[size];
        c = new double[size];
        d = new double[size];

        while((pos = line.find(delimiter)) != std::string::npos)
        {
          if(counter >= size)
            break;

          token = line.substr(0, pos);

          a[counter] = stod(token);
          b[counter] = stod(token);
          c[counter] = stod(token);
          d[counter] = stod(token);

          line.erase(0, pos + delimiter.length());
          counter++;
        }

        a[counter] = stod(line);
        b[counter] = stod(line);
        c[counter] = stod(line);
        d[counter] = stod(line);

        break;
      }
		}
		myfile.close();
	}
  */

  // sort arrays and track times

  double QuickSortStartTime = clock() / (double) CLOCKS_PER_SEC;
  QuickSort(a, 0, size);
  double QuickSortEndTime = clock() / (double) CLOCKS_PER_SEC;

  double InsertionSortStartTime = clock() / (double) CLOCKS_PER_SEC;
  InsertionSort(b, size);
  double InsertionSortEndTime = clock() / (double) CLOCKS_PER_SEC;

  double BubbleSortStartTime = clock() / (double) CLOCKS_PER_SEC;
  BubbleSort(c, size);
  double BubbleSortEndTime = clock() / (double) CLOCKS_PER_SEC;

  double SelectionSortStartTime = clock() / (double) CLOCKS_PER_SEC;
  SelectionSort(d, size);
  double SelectionSortEndTime = clock() / (double) CLOCKS_PER_SEC;

/*
  for(int i = 0; i < size; i++)
  {
    cout << a[i] << ", ";
  }
  cout << "  TIME: " << QuickSortEndTime - QuickSortStartTime << endl;

  for(int i = 0; i < size; i++)
  {
    cout << b[i] << ", ";
  }
  cout << "  TIME: " << InsertionSortEndTime - InsertionSortStartTime << endl;

  for(int i = 0; i < size; i++)
  {
    cout << c[i] << ", ";
  }
  cout << "  TIME: " << BubbleSortEndTime - BubbleSortStartTime << endl;

  for(int i = 0; i < size; i++)
  {
    cout << d[i] << ", ";
  }
  cout << "  TIME: " << SelectionSortEndTime - SelectionSortStartTime << endl;
  */

  cout << endl;
  cout << "  Quick Sort" << endl;
  cout << "     Start Time: " << QuickSortStartTime << " seconds" << endl;
  cout << "     End Time: " << QuickSortEndTime << " seconds" << endl;
  cout << "     Elapsed Time: " << QuickSortEndTime - QuickSortStartTime << " seconds" << endl;
  cout << endl;
  cout << "  Insertion Sort" << endl;
  cout << "     Start Time: " << InsertionSortStartTime << " seconds" << endl;
  cout << "     End Time: " << InsertionSortEndTime << " seconds" << endl;
  cout << "     Elapsed Time: " << InsertionSortEndTime - InsertionSortStartTime << " seconds" << endl;
  cout << endl;
  cout << "  Bubble Sort" << endl;
  cout << "     Start Time: " << BubbleSortStartTime << " seconds" << endl;
  cout << "     End Time: " << BubbleSortEndTime << " seconds" << endl;
  cout << "     Elapsed Time: " << BubbleSortEndTime - BubbleSortStartTime << " seconds" << endl;
  cout << endl;
  cout << "  Selection Sort" << endl;
  cout << "     Start Time: " << SelectionSortStartTime << " seconds" << endl;
  cout << "     End Time: " << SelectionSortEndTime << " seconds" << endl;
  cout << "     Elapsed Time: " << SelectionSortEndTime - SelectionSortStartTime << " seconds" << endl;
  cout << endl;
}
