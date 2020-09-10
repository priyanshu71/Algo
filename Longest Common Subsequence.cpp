/************
    Given two sequences, find the length of longest subsequence present in both of them. (LCS)

    Examples:
    LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
    LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.

************/


#include<bits/stdc++.h>
using namespace std;

void lcs(string s1 , string s2)
{
    int x = s1.length();
    int y = s2.length();

    int dp[x+1][y+1] = {0};
    int i,j;

// **** building DP Table in bottom up Manner **** //

    for( i=0 ; i<=x ; i++)
        dp[i][0] = 0;

    for( j=0 ; j<=y ; j++)
        dp[0][j] = 0;

    for( i=1 ; i<=x ; i++)
    {
        for( j=1 ; j<=y ; j++)
        {
            if( s1[i-1] == s2[j-1] )
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
        }
    }

//     cout<<"Length of Longest Common Subsequence is "<<dp[x][y]<<endl;


/****  Uncomment Below Code to see how DP table works ****

    cout<<"  ' ";
    for(auto x:s2)
        cout<<x<<" ";
    cout<<endl;

    cout<<"' ";
    for(int i=0 ; i < x+1 ; i++)
    {
        for(int j=0 ; j < y+1 ; j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;

        cout<<s1[i]<<" ";
    }

********/

// **** Code for printing the longest common Subsequence **** //
   string res;

    i=x;
    j=y;

   while(i>0 && j>0)
    {
       if(s1[i-1] == s2[j-1])
       {
         res += s1[i-1];
         i--;
         j--;
       }

       else
       {
           if(dp[i-1][j] > dp[i][j-1])
            i--;
           else
            j--;
       }

    }

    reverse(res.begin() , res.end());

     cout<<"Longest Common Subsequence is '"<<res<<"'"<<endl;


}
//end of function


int main()
{
    string s1,s2;

    cin>>s1>>s2;

    lcs(s1 , s2);

    return 0;
}
