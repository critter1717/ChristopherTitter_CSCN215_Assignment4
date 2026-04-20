#pragma once
#include "SelfOrderedListADT.h"
#include "llist.h"

// Self-ordered list implementation
template <class E>
class SOListCount : public SelfOrderedListADT<E> {
private:
	LList<E> list;  // List to hold the elements
	int compares;    // Number of compares for search

public:
	SOListCount() : compares(0) {}  // Constructor
	// Look for 'it'. If found return true and execute the self-ordering
	// heuristic used for ordering the list: count, move-to-front, or transpose.
	// Increments the compare instance variable every time it compares 'it' to
	// other members of the list. Returns true if 'it' is found.
    bool search(const E& it) override
	{
		list.moveToStart(); // Start from the beginning of the list
		for (int i = 0; i < list.length(); i++) {
			compares++; // Increment compares for each comparison
			if (list.getValue() == it) {
				list.moveToPos(i); // Move to the position of the found element
				reorder(i); // Reorder the list using the count heuristic
				return true; // 'it' is found
			}
			list.next(); // Move to the next element in the list
		}
		addIt(it); // If 'it' is not found, add it to the list
		return false; // 'it' is not found
	}
	// Called by find if 'it' is not in the list. Adds the new 'it' to the list
	// Can also be called independently when initially loading the list with
	// unique values and when you want to load the list in the order 'it' is 
	// read without your re-order method being called (or the number of compares
	// being incremented.
	void addIt(const E& it)
	{
		list.append(it); // Add new 'it' to the end of the list
	}
	int getCompares() const override { return compares; }   // Returns the number of accumulated compares
	int size() const override { return list.length(); }     // Returns the size of the list
	// Print the list
	void printlist() const override 
	{ 
		std::cout << "Count Heuristic: " << std::endl;
		std::cout << "Size of list: " << size() << std::endl;
		std::cout << "Number of compares: " << getCompares() << std::endl;
		list.print();
	}       // Print entire list
	void printlist(int n) const override
	{
		std::cout << "Count Heuristic: " << std::endl;
		std::cout << "Size of list: " << size() << std::endl;
		std::cout << "Number of compares: " << getCompares() << std::endl;
		list.print(n);
	}// Print first n nodes
    void reorder(int index)
	{
        // Increment the count for the node at index if available
		if (index >= 0 && index < list.length()) {
			Link<E>* node = list.getLinkAt(index);
			if (node) node->incrementCount();
		}
		// Move the node toward front while its count is greater than predecessor
		while (index > 0) {
			int prevCount = list.getLinkAt(index - 1)->getCount();
			int curCount = list.getLinkAt(index)->getCount();
			if (prevCount < curCount) {
				list.transposeAt(index);
				index--;
			} else break;
		}
	}
};

