#pragma once
#include "SelfOrderedListADT.h"
#include "llist.h"

// Self-ordered list implementation
template <class E>
class SOListMTF : public SelfOrderedListADT<E> {
private:
	LList<E> list;  // List to hold the elements
	int compares;    // Number of compares for search

public:
	SOListMTF() : compares(0) {}  // Constructor
	// Look for 'it'. If found return true and execute the self-ordering
	// heuristic used for ordering the list: count, move-to-front, or transpose.
	// Increments the compare instance variable every time it compares 'it' to
	// other members of the list. Returns true if 'it' is found.
	bool search(const E& it)
	{
		compares = 0; // Reset compares for this search
		for (int i = 0; i < list.length(); i++) {
			compares++; // Increment compares for each comparison
			if (list.getValueAt(i) == it) {
				list.moveToPos(i); // Move to the position of the found element
				return true; // 'it' is found
			}
		}
		return false; // 'it' is not found
	}
	// Called by find if 'it' is not in the list. Adds the new 'it' to the list
	// Can also be called independently when initially loading the list with
	// unique values and when you want to load the list in the order 'it' is 
	// read without your re-order method being called (or the number of compares
	// being incremented.
	void addIt(const E& it) override;  // Add new 'it' to the list
	int getCompares() const override { return compares; }   // Returns the number of accumulated compares
	int size() const override { return list.length(); }     // Returns the size of the list
	// Print the list
	void printlist() const override { list.print(); }       // Print entire list
	void printlist(int n) const override;                   // Print first n nodes
	void reorder(const E& it)
	{
		it.incrementCount(); //reorder the list by moving the element to the front
		int index = list.currPos();
		while (index > 0) {
			list.swap(index, index - 1);
			index--;
		}
	}

};