#include <iostream>

void orientation(int x1, int y1, int x2, int y2, int x3, int y3)
{
    int val = ((y2-y1)*(x3-x2))-((x2-x1)*(y3-y2));

    if(val == 0)
    {
        std::cout<<"collinear"<<std::endl;
    }
    else if(val >0)
    {
        std::cout<<"clockwise"<<std::endl;
    }
    else
    {
        std::cout<<"counterclockwise"<<std::endl;
    }
}

int main(){
    int x1 = 3, y1 = 6, x2 = 2; 
    int y2 = 8, x3 = 1, y3 = 1;

    orientation(x1,y1,x2,y2,x3,y3);

    return 0;
}