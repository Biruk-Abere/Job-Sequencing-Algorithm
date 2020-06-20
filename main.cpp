// ConsoleApplication6.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include<iostream>
using namespace std;
void jobsequence(int n, int jobid[], int profit[], int deadline[] , int large);

int main()
{
	int num;
	cout << "please enter the number of jobs" << endl;
	cin >> num;
	int jobid[num], profit[num], deadline[num];
	cout << "please enter the job id  , profit and its deadline " << endl;
	for (int i = 0; i < num; i++) {
		cout << "Enter Job Id" << i + 1 << " ";
		cin >> jobid[i];
	}
	for (int i = 0; i < num; i++) {
		cout << "Enter Profit " << i + 1 << " ";
		cin >> profit[i];
	}
	for (int i = 0; i < num; i++) {
		cout << "Enter Deadline " << i + 1 << " ";
		cin >> deadline[i];
	}
	  int large = deadline[0];
	  for (int i = 0; i < num; i++) {
		  if (deadline[i] > large) {
			  large = deadline[i];

		  }
	  }

	for (int i = 0; i < num; i++) {
		for (int j = i + 1; i < num; i++) {
			if (profit[i] < profit[j]) {
				//these code will help to put the profit in decreasing order
				int temp = profit[j];
				profit[j] = profit[i];
				profit[i] = temp;

				//these code will help the deadline in order with the profit

				 temp = deadline[j];
				deadline[j] = deadline[i];
				deadline[i] = temp;

				//these code will help the jobid inorder with the profit
				temp = jobid[j];
				jobid[j] = jobid[i];
				jobid[i] = temp;

			}
			jobsequence(num, jobid, profit, deadline,large);
		}
	}
    return 0;
}
void jobsequence(int n, int jobid[], int profit[], int deadline[] , int large) {

	int p = 0;
	int x[large]; // these the ghant chart with the size of the largest deadline
	for (int i = 0; i < n; i++)
		x[i] = 0.0;
	for (int i = 0; i < n; i++){
		if (deadline[i]<x[deadline[i]]) {
			if (x[deadline[i]] == false) {
				x[deadline[i]] = jobid[i];
				p = p + profit[i];
			}

	}

}
cout << "The Maximum Profit Will Be " << p << " ";
}

