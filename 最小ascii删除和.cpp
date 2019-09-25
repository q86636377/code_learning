#include<iostream>
#include<string>
using namespace std;

class Solution{
public:
    int minimumDeleteSum(string s1, string s2)
    {
        int cnt = 0;
        int len1 = s1.size();
        int len2 = s2.size();
        //cout << len1 << " " << len2;
        if (len1 == 0)
        {
            cnt = 0;
            for (int i=0;i<len2;i++)
                cnt += s2[i];
            return cnt;
        }
        if (len2 == 0)
        {
            cnt = 0;
            for (int i=0;i<len1;i++)
                cnt += s1[i];
            return cnt;
        }
        int dp[len1+1][len2+1];
        cnt = 0;
        for (int i=0;i<=len1;i++)
        {
            dp[i][0]=cnt;
            if(i!=len1)
                cnt+=s1[i];
        }
        cnt = 0;
        for (int i=0;i<=len2;i++)
        {
            dp[0][i]=cnt;
            if(i!=len2)
                cnt+=s2[i];
        }
        for(int i=1;i<=len1;i++)
        {
            for(int j=1;j<=len2;j++)
            {
                if (s1[i-1]==s2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                {
                    int temp1 = dp[i-1][j-1]+s1[i-1]+s2[j-1];
                    int temp2 = dp[i-1][j]+s1[i-1];
                    int temp3 = dp[i][j-1]+s2[j-1];
                    dp[i][j] = min(min(temp1, temp2),temp3);
                }
            }
        }
        for (int i=0;i<=len1;i++)
        {
            for (int j=0;j<=len2;j++)
                cout << dp[i][j] << " ";
            cout << endl;
        }
        return dp[len1][len2];
    }
};

int main()
{
    Solution test;
    string s1 = "test";
    string s2 = "sea";
    int result = test.minimumDeleteSum(s1,s2);
    cout << result << endl;
}
