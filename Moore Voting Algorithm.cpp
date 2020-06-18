   //////////////////////
  // Author: k_ma2111 //
 // Date: 18-06-2020 //
//////////////////////

#include <bits/stdc++.h>        // only for g++ compiler
using namespace std;

int main ()
{
  ios::sync_with_stdio (false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin>>n;

  int a[n];

  for(int i=0 ;i<n ; i++)
  cin>>a[i];

/*Let's initialize index of majority element
        to be index of 1st element */

  int maj_element_index = 0;
  int count_element = 1;

  // loop for identifying candidate for majority

  for(int i=1 ; i<n ; i++)
  {
      if(a[maj_element_index] == a[i])
        count_element++;
      else
        count_element--;

      if(count_element == 0)
      {
          maj_element_index = i;
          count_element = 1;
      }
  }

  //Now again a traversal for comparing if maj_element is > n/2
  int count_ = 0;

 for(int i=0 ; i<n ; i++)
  {
      if(a[i] == a[maj_element_index])
        count_++;
  }

  if(count_ > n/2)
    cout<<1<<endl;
  else
    cout<<0<<endl;


  return 0;
}
