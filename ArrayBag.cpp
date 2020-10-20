//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2016 __Pearson Education__. All rights reserved.
//Modified by TAA to remove Template and Inheritance

/** @file ArrayBag.cpp */

#include "ArrayBag.h"
#include <iostream>
using namespace std;

ArrayBag::ArrayBag() : itemCount(0), maxItems(DEFAULT_BAG_SIZE)
{
}  // end default constructor


int ArrayBag::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize


bool ArrayBag::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty


bool ArrayBag::add(const ItemType& newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;
	}  // end if
	return hasRoomToAdd;
}  // end add


bool ArrayBag::remove(const ItemType& anEntry)
{
	int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}  // end if

	return canRemoveItem;
}  // end remove


void ArrayBag::clear()
{
	itemCount = 0;
}  // end clear


int ArrayBag::getFrequencyOf(const ItemType& anEntry) const
{
	int frequency = 0;
	int searchIndex = 0;
	while (searchIndex < itemCount)
	{
		if (items[searchIndex] == anEntry)
		{
			frequency++;
		}  // end if

		searchIndex++;
	}  // end while

	return frequency;
}  // end getFrequencyOf


bool ArrayBag::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) > -1;
}  // end contains


std::vector<ItemType> ArrayBag::toVector() const
{
	std::vector<ItemType> ArrayBagContents;
	for (int i = 0; i < itemCount; i++)
	{
		ArrayBagContents.push_back(items[i]);
	}
	return ArrayBagContents;
}  // end toVector

ArrayBag ArrayBag :: operator + (const ArrayBag &b)
{
	ArrayBag temp;

	//Adding both arrays to the temp array
	for (int i = 0; i < itemCount; i++)
	{
		temp.add(items[i]);
	}
	
	int size = b.getCurrentSize();

	for (int index = 0; index < size; index++)
	{
		temp.add(b.items[index]);
	}

	//Removing duplicates
	int tempSize = temp.getCurrentSize();
	int frequency = 1;
	int secondFrequency = 1;
	for (int newIndex = 0; newIndex < tempSize; newIndex++)
	{
		frequency = temp.getFrequencyOf(temp.items[newIndex]);
		if (frequency > 1)
		{
			temp.remove(items[newIndex]);

			secondFrequency = temp.getFrequencyOf(temp.items[newIndex]);

			if (secondFrequency > 1)
			{
				temp.remove(items[newIndex]);
			}
		}
	}

	return temp;
}

ArrayBag ArrayBag:: operator - (const ArrayBag &b)
{
	ArrayBag temp;

	//removing any items in array bag1 that also appear in array bag b
	for (int i = 0; i < itemCount; i++)
	{
		if (b.contains(items[i]))
		{
			remove(items[i]);
		}
	}

	//placing the updated arrays into temp
	for (int newI = 0; newI < itemCount; newI++)
	{
		temp.add(items[newI]);
	}

	int size = b.getCurrentSize();

	for (int index = 0; index < size; index++)
	{
		temp.add(b.items[index]);
	}

	return temp;

}

   // private

int ArrayBag::getIndexOf(const ItemType& target) const
{
	bool found = false;
	int result = -1;
	int searchIndex = 0;
	// if the ArrayBag is empty, itemCount is zero, so loop is skipped
	while (!found && (searchIndex < itemCount))
	{
		if (items[searchIndex] == target)
		{
			found = true;
			result = searchIndex;
		}
		else
		{
			searchIndex++;
		}  // end if
	}  // end while

	return result;
}  // end getIndexOf
