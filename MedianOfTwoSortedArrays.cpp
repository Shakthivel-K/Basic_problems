#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> num_compiled={};
        int i=0,j=0;
        int ns1=nums1.size();
        int ns2=nums2.size();
        while ((i<ns1)&&(j<ns2))
        {
            if (nums1[i]<nums2[j])
            {
                num_compiled.push_back(nums1[i++]);
                
            }
            else
            {
                num_compiled.push_back(nums2[j++]);
                
            }
        }
        while (i<ns1)
        {
            
            num_compiled.push_back(nums1[i++]);
           
        }
        while (j<ns2)
        {
            num_compiled.push_back(nums2[j++]);
            
        }
        int total_len=num_compiled.size();
        float sum=0;
        if (total_len%2==0)
        {
            sum=static_cast <float> (num_compiled.at((total_len/2)-1)+num_compiled.at(total_len/2))/2;
        }
        else
        {
            
            sum=static_cast <float> (num_compiled.at(total_len/2));
        }
        return sum;
    }
};
int main()
{
Solution s;
vector<int> a={1,3,5};
vector<int> b={2,4,6};
cout <<"median"<<s.findMedianSortedArrays(a,b);


}