// CSCN 215 - LAB 4 - Test.cpp
#include <iostream>
#include "SOListCount.h"
#include "SOListMTF.h"
#include "SOListTranspose.h"
#include <fstream>

int main() {
	SOListCount<char> countList;
	SOListMTF<char> mtfList;
	SOListTranspose<char> transposeList;
	// Test 1 data
	char testData[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
	for(int i = 0; i < 8; i++) {
		countList.addIt(testData[i]);
		mtfList.addIt(testData[i]);
		transposeList.addIt(testData[i]);
	}
	// Search for elements in the lists using count heuristic
	countList.search('F');
	countList.search('D');
	countList.search('F');
	countList.search('G');
	countList.search('E');
	countList.search('G');
	countList.search('F');
	countList.search('A');
	countList.search('D');
	countList.search('F');
	countList.search('G');
	countList.search('E');
	countList.search('H');
	countList.search('I');
	// Search for elements in the lists using move-to-front
	mtfList.search('F');
	mtfList.search('D');
	mtfList.search('F');
	mtfList.search('G');
	mtfList.search('E');
	mtfList.search('G');
	mtfList.search('F');
	mtfList.search('A');
	mtfList.search('D');
	mtfList.search('F');
	mtfList.search('G');
	mtfList.search('E');
	mtfList.search('H');
	mtfList.search('I');
	// Search for elements in the lists using transpose
	transposeList.search('F');
	transposeList.search('D');
	transposeList.search('F');
	transposeList.search('G');
	transposeList.search('E');
	transposeList.search('G');
	transposeList.search('F');
	transposeList.search('A');
	transposeList.search('D');
	transposeList.search('F');
	transposeList.search('G');
	transposeList.search('E');
	transposeList.search('H');
	transposeList.search('I');
	// Print the results
	countList.printlist();
	mtfList.printlist();
	transposeList.printlist();

	// Test 2 data
	SOListCount<string> countList2;
	SOListMTF<string> mtfList2;
	SOListTranspose<string> transposeList2;
	// Open test.txt file word by word and read data into the lists
	std::ifstream inputFile("test.txt");
	if (inputFile.is_open()) {
		std::string word;
		while (inputFile >> word) {
				countList2.search(word);
				mtfList2.search(word);
				transposeList2.search(word);
		}
		inputFile.close();
	} else {
		std::cerr << "Unable to open file test.txt" << std::endl;
	}
	// Print the results for test 2
	countList2.printlist(10); // Print first 10 nodes
	mtfList2.printlist(10);   // Print first 10 nodes
	transposeList2.printlist(10); // Print first 10 nodes

	return 0;
}