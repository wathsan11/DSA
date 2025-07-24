#include <iostream>
#include <vector>

int orientation(const std::vector<int> &p,const std::vector<int>& q,const std::vector<int> &r)
{
    int val = ((q[1]-p[1])*(r[0]-q[0]))-((q[0]-p[0])*(r[1]-q[1]));

    if (val == 0) return 0;
    return(val>0)?1:2;
}

bool onSegment(const std::vector<int> &p,const std::vector<int>& q,const std::vector<int> &r)
{
    //check whether point q lies on segment pr, assuming p,q,r are collinear
    return(
        q[0]<=std::max(p[0],r[0]) &&
        q[0]>=std::min(p[0],r[0]) &&
        q[1]<=std::max(p[1],r[1]) &&
        q[1]>=std::min(p[1],r[1])
        );
}

bool doIntersect(const std::vector<std::vector<std::vector<int>>> &p)
{
    int o1 = orientation(p[0][0],p[0][1],p[1][0]);
    int o2 = orientation(p[0][0],p[0][1],p[1][1]);
    int o3 = orientation(p[1][0],p[1][1],p[0][0]);
    int o4 = orientation(p[1][0],p[1][1],p[0][1]);

    if (o1 != o2 && o3 != o4) return true;  //general case

    //special cases
    if(o1==0 && onSegment(p[0][0],p[1][0],p[0][1])) return true;
    if(o2==0 && onSegment(p[0][0],p[1][1],p[0][1])) return true;
    if(o3==0 && onSegment(p[1][0],p[0][0],p[1][1])) return true;
    if(o4==0 && onSegment(p[1][0],p[0][1],p[1][1])) return true;

    return false;

}

int main()
{
    std::vector<std::vector<std::vector<int>>> p = 
    {{{1, 1}, {10, 1}}, {{1, 2}, {10, 2}}};

    if(doIntersect(p))
    {
        std::cout<<"yes"<<std::endl;
    }
    else std::cout<<"no"<<std::endl;

    return 0;
}
