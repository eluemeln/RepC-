/******************************************************
file name: Employee.h

file purpose: used define the prototypes of the functions declared in indexList.h
 ****************************************************/

#include "IndexList.h"

//declaring the function as a prototype
template<class T, int maxSize>
indexList<T, maxSize>::indexList()
{
  size=0;  //initializing the size to Zero
}

//declaring the function as a prototype
template<class T, int maxSize>
void indexList<T, maxSize>::selSort()  // a function with two parameters
{
  //local datas
  int search_index, search_max;
   T temp;

   for (int current_index = 0; current_index < size; current_index++) //a for-loop to access the list
   {
      search_max = current_index;

      // Find index of largest element in unsorted section of elements
      for(search_index = current_index + 1; search_index < size; search_index++)
	 if(elements[search_max] > elements[search_index])
	    search_max = search_index;

      // Exchange items at position search_max and current_index
      if (search_max > current_index)
      {
	 temp = elements[search_max];
	 elements[search_max] = elements[current_index];
	 elements[current_index] = temp;
      }
   }
}

//declaring the function as a prototype
template<class T, int maxSize>
bool indexList<T, maxSize>::append(const T& items)
{
  bool result;
  //add item to the end of the list if list is not full
  if(size<maxSize)
    {//assertion:the array is not filled up
      elements[size]=items;
      size++;
      result=true;
    }
else
  {  //assertion:the array is filled up
    cerr<<"Array is filled _ can't append!"<<endl;
    result=false;
  }
 return result;
}

//declaring the function as a prototype
 template<class T,int maxSize>
   void indexList<T,maxSize>::display(ostream& outs)const
 {
   for(int i=0;i<size;i++)  //a for-loop to access the list
     outs<<elements[i]<<endl;
 }
 
