#include <iostream>
#include <string>
#include <vector>

void constructLps(std::string& pat, std::vector<int> &lps)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while (i<pat.length())
    {
        if (pat[i]==pat[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len != 0)
            {
                len = lps[len-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
}

std::vector<int> KMPSearch(std::string &text, std::string &patt)
{
    int n = text.length();
    int m = patt.length();

    std::vector<int> lps(m);
    std::vector<int> results;

    constructLps(patt,lps);

    int i = 0;
    int j = 0;

    while (i < n)
    {
        if(text[i]==patt[j])
        {
            i++;
            j++;

            if(j==m)
            {
                results.push_back(i-j);
                j = lps[j-1];
            }
        }
        else
        {
            if(j != 0)
            {
                j = lps[j-1];
            }
            else
            {
                i++;
            }
        }
    }
    return results;
}

int main(){

    std::string txt = "aaaebaabbaacaadaabaabadf";
    std::string pattern1 = "baa";

    std::vector<int> results = KMPSearch(txt,pattern1);
    
    for(int& p : results)
    {
        std::cout<<p<<std::endl;
    }

    return 0;
}