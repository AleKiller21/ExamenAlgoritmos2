#include "Test.h"
#include <iostream>
#include <map>
using namespace std;

int longestPalindromicSubsequence(string sequence, int begin, int end)
{
   if (begin == end)
     return 1;

   if (sequence[begin] == sequence[end] && begin + 1 == end)
     return 2;

   if (sequence[begin] == sequence[end])
      return longestPalindromicSubsequence(sequence, begin+1, end-1) + 2;

   return max( longestPalindromicSubsequence(sequence, begin, end-1),
           longestPalindromicSubsequence(sequence, begin+1, end) );
}

int longestPalindromicSubsequence(string sequence)
{
  return longestPalindromicSubsequence(sequence, 0, sequence.size()-1);
}

vector<int> getPath(int **DAG, int size, int source, int destination)
{
  vector<int> answer;
  int least_weight = 1000;
  int next_vertex = 1000;

  while(source != destination)
  {
    for(int dest = 0; dest < size; dest++)
    {
      if(DAG[source][dest] == -1) continue;
      if(DAG[source][dest] < least_weight)
      {
        least_weight = DAG[source][dest];
        next_vertex = dest;
      }
    }

    answer.push_back(next_vertex);
    source = next_vertex;
    least_weight = 1000;
  }

  return answer;
}


int main ()
{
    test();
    return 0;
}
