// CSCN 215 - LAB 4 - Test.cpp
#include <iostream>
#include "SOListCount.h"
#include "SOListMTF.h"
#include "SOListTranspose.h"

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
	return 0;
}