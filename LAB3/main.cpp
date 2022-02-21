#include <iostream> 
#include <vector>
#include <stdexcept> 
using namespace std;

template <typename T>
T getElement(vector <T> vals, int index)
{
  // return the corresponding value at 'index' from vals
 
return vals.at(index);         
} 
template <typename T>
unsigned int min_index(const vector<T> &vals, unsigned int index)
{
  //start a for loop starting from index+1
  //return the minimum index (if vals[pos] < vals[index]) which is less than vals[index]
  unsigned int min = index;
   for (unsigned int i = index + 1; i < vals.size(); i++)
   {
     if (getElement (vals,i) < getElement (vals,min))
     {
      min = i;
     }
   }
  return min;
}
template <typename T>
void selection_sort(vector<T> &vals)
{
 try 
 {

 
  //O(n^2)
  // start the for loop
  for (unsigned int i = 0; i < vals.size() - 1; i++)
  {
    unsigned int min = min_index(vals, i);
    
    
    
      T temp = getElement(vals,min);
      vals [min] = getElement (vals,i);
      vals[i] = temp;
    
    
  }
 }
 catch (out_of_range& ex)
         {
           cout<<"out of range exception occured";
         }
  // find minimum index at the right using function #in_index()
  //swap minimum index witht the current index
}
// creates a vector with random distinct characters in it 
vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}

int main() 
{
  //Part B
  // cals = ['a', 'b'b, 'c', 'd',]
  //take an input from the user 
  //return the cahracter or that index from the vector
  // wrap the following code in a try-catch block
     srand(time(0));
     vector<char> vals = createVector();
     char curChar;
     int index;
     int numOfRuns = 10;
     while(--numOfRuns >= 0){
         cout << "Enter a number: " << endl;
         cin >> index; //index = 6
           try {
        curChar = getElement(vals,index);
         } catch (out_of_range& ex)
         {
           cout<<"exception";
         }
  
           //write what you want to catch std:: out_of_range&){//write the output using cout}
         cout << "Element located at " << index << ": is " << curChar << endl;
    }
    return 0;
}
