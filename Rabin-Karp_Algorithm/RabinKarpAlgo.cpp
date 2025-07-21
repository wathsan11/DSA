#include <iostream>
#include <string>
#include <vector>

std::vector<int> RabinKarpSearch(const std::string& patt,const std::string &text)
{
    int d = 256; // base
    int q = 101; // Prime Number
    int M = patt.length();
    int N = text.length();
    int p = 0;   // hash value for pattern
    int t = 0;   // hash value for current window of text
    int h = 1;   

    std::vector<int> ans;

    for (int i=0;i<M-1;i++)
    {
        h = (h*d)%q;
    }

    for(int i=0;i<M;i++)
    {
        p = (p*d + patt[i])%q;
        t = (t*d + text[i])%q;
    }

    for (int i=0; i<=N-M;i++)
    {
        if(p==t)
        {
            bool match = true;
            for (int j=0;j<M;j++)
            {
                if(text[i+j] != patt[j])
                {
                    match = false;
                    break;
                }
            }

            if (match)
            {
                ans.push_back(i+1);  //1-base index
            }
        }

        if (i<N-M)
        {
            t = (d*(t - text[i]*h) + text[i+M])%q;

            if(t<0)
            {
                t+=q;
            }
        }
    }
    return ans;
}

int main(){

    std::string txt = "abndsaskjjejaskiwjdaskss";
    std::string pat = "ask";

    std::vector<int> result = RabinKarpSearch(pat,txt);

    for (unsigned int i =0; i<result.size(); ++i)
    {
        std::cout<<result[i]<<std::endl;
    }

    return 0;
}