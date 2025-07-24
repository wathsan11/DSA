#include <iostream>
#include <string>
#include <vector>

void getZarr (std::string str, std::vector<int> &z)
{
    int n = str.length();
    int L = 0, R = 0; //If you don’t assign values like L = 0; R = 0;
                      //their contents are undefined, and using them in comparisons
                      //like if (i > R) leads to undefined behavior.


    int k;
    
    for (int i=1; i<n;++i)
    {
        if(i>R)
        {
            L=R=i;
            while (R<n && str[R-L]==str[R])
            {
                R++;
            }
            z[i]=R-L;
            R--;
        }

        else
        {
            k=i-L;

            if(z[k]<R-i+1)
            {
                z[i]=z[k];
            }
            else
            {
                L=i;
                while(R<n && str[R-L]==str[R])
                {
                    R++;
                }
                z[i]= R-L;
                R--;
            }
        }
    }
}

void ZSearch(std::string &text,std::string &pattern)
{
    std ::string concat = pattern+"$"+text;
    int l = concat.length();
    
    std::vector<int> z(l,0);
    getZarr(concat,z);

    std::cout << "Z array: ";
    for(unsigned int i=0; i<l; i++)
    {
        std::cout << z[i] << " ";   
    }
    std::cout << "\n";
    
    for (int i=0;i<l;++i)
    {
        if(z[i]== (int)pattern.length())
        {
            std::cout<<"Pattern found at index "<<i-(int)pattern.length()-1<<std::endl;
        }
    }
}

int main(){
    std::string text = "aacbabbbabbberabbaaakc";
    std::string pat = "abb";

    ZSearch(text,pat);

    return 0;
}