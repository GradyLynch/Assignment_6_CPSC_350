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

  double QuickSortStartTime = (clock() / (double) CLOCKS_PER_SEC) * 1000;
  QuickSort(a, 0, size);
  double QuickSortEndTime = (clock() / (double) CLOCKS_PER_SEC) * 1000;

  double InsertionSortStartTime = (clock() / (double) CLOCKS_PER_SEC) * 1000;
  InsertionSort(b, size);
  double InsertionSortEndTime = (clock() / (double) CLOCKS_PER_SEC) * 1000;

  double BubbleSortStartTime = (clock() / (double) CLOCKS_PER_SEC) * 1000;
  BubbleSort(c, size);
  double BubbleSortEndTime = (clock() / (double) CLOCKS_PER_SEC) * 1000;

  double SelectionSortStartTime = (clock() / (double) CLOCKS_PER_SEC) * 1000;
  SelectionSort(d, size);
  double SelectionSortEndTime = (clock() / (double) CLOCKS_PER_SEC) * 1000;

  cout << endl;
  cout << "  Quick Sort" << endl;
  cout << "     Start Time: " << QuickSortStartTime << " milliseconds" << endl;
  cout << "     End Time: " << QuickSortEndTime << " milliseconds" << endl;
  cout << "     Elapsed Time: " << QuickSortEndTime - QuickSortStartTime << " milliseconds" << endl;
  cout << endl;
  cout << "  Insertion Sort" << endl;
  cout << "     Start Time: " << InsertionSortStartTime << " milliseconds" << endl;
  cout << "     End Time: " << InsertionSortEndTime << " milliseconds" << endl;
  cout << "     Elapsed Time: " << InsertionSortEndTime - InsertionSortStartTime << " milliseconds" << endl;
  cout << endl;
  cout << "  Bubble Sort" << endl;
  cout << "     Start Time: " << BubbleSortStartTime << " milliseconds" << endl;
  cout << "     End Time: " << BubbleSortEndTime << " milliseconds" << endl;
  cout << "     Elapsed Time: " << BubbleSortEndTime - BubbleSortStartTime << " milliseconds" << endl;
  cout << endl;
  cout << "  Selection Sort" << endl;
  cout << "     Start Time: " << SelectionSortStartTime << " milliseconds" << endl;
  cout << "     End Time: " << SelectionSortEndTime << " milliseconds" << endl;
  cout << "     Elapsed Time: " << SelectionSortEndTime - SelectionSortStartTime << " milliseconds" << endl;
  cout << endl;
}
