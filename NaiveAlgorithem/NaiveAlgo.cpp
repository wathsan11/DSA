#include <iostream>
#include <string>

void NaiveSearch(std::string& text, std::string& pattern )
{
    int M = text.size();
    int N = pattern.size();

    for (int i=0;i<M-N;i++)
    {
        int j; // 'j' is declared outside the loop so we can use it after the loop ends
               // to check whether the entire pattern was matched (i.e., j == M)
        
        for (j=0;i<M;j++)
        {
            if(text[i+j] != pattern[j])
            {
                break;
            }
        }
        //j < M is the loop condition
        //If the loop runs fully (no break),
        //j becomes M after the loop ends.

        if (j == N)
        {
            std::cout<<"Pattern found at index "<<i<<std::endl;
        }
    }

}

int main(){
    std::string text = "AABCDAABAABRKSTAABAL";
    std::string pattern1 ="AABA";

    NaiveSearch(text,pattern1);

    return 0;
}

