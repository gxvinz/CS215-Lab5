//--------------------------------------------------------
//                  CS215-402 Lab 5
//---------------------------------------------------------
// Author: Gavin Crain
// Date: 2/27/2020
// Description: Code to display election results  
//---------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

// structure to hold precincts and the votes from each 
struct precinct {
	int precinctNum;
	int numVotes1, numVotes2, numVotes3;
};

const int maxPrecinct = 20; // max amount of precincts
int main() {
	// partial array of precincts 
	precinct p[maxPrecinct];
	int numPrecinct;

	// total vote integers 
	int total1{}, total2{}, total3{};

	// opening input and checking for error 
	ifstream fin;
	fin.open("precincts.txt");
	if (fin.fail()) {
		cout << "Unable to open file grades.txt" << endl;
	}
	else {
		// reading the input
		string name1, name2, name3;
		getline(fin, name1);
		getline(fin, name2);
		getline(fin, name3);

		fin >> numPrecinct;

		for (int i = 0; i < numPrecinct; i++) {
			fin >> p[i].precinctNum;
			fin >> p[i].numVotes1;
			fin >> p[i].numVotes2;
			fin >> p[i].numVotes3;
		}
		// closing after reading 
		fin.close();

		// summing the totals 

		for (int i = 0; i < numPrecinct; i++) {
			total1 += p[i].numVotes1;
		}

		for (int i = 0; i < numPrecinct; i++) {
			total2 += p[i].numVotes2;
		}

		for (int i = 0; i < numPrecinct; i++) {
			total3 += p[i].numVotes3;
		}

		// arranging based on precinct num low to high 
		for (int i = 0; i < numPrecinct - 1; i++) {
			for (int j = i + 1; j < numPrecinct; j++) {
				if (p[i].precinctNum > p[j].precinctNum) {
					precinct t;
					t = p[i];
					p[i] = p[j];
					p[j] = t;
				}
			}
		}
		// making output and checking for failure 

		ofstream fout;
		fout.open("results.txt");
		if (fout.fail()) {
			cout << "Unable to open file results.txt\n";
		}
		else {
			// printing out the election results 
			
			fout << "--------------------------------------------------------" << endl;
			fout << setw(36) << "ELECTION RESULTS" << endl;
			fout << "--------------------------------------------------------" << endl;
			fout << "PRECINCT " << left << setw(15) << name1;
			fout << " " << left << setw(15) << name2;
			fout << " " << left << setw(15) << name3 << endl;
			fout << "-------- --------------- --------------- ---------------" << endl;
			for (int i = 0; i < numPrecinct; i++) {
				fout << left << setw(8) << p[i].precinctNum;
				fout << " " << right << setw(15) << p[i].numVotes1;
				fout << " " << right << setw(15) << p[i].numVotes2;
				fout << " " << right << setw(15) << p[i].numVotes3 << endl;
			}
			fout << setw(8) << left << "TOTALS";
			fout << " " << right << setw(15) << total1;
			fout << " " << right << setw(15) << total2;
			fout << " " << right << setw(15) << total3 << endl;
			cout << "Election data processed." << endl;
			fout.close();
		}
	}




	system("pause");
	return 0;
}