#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mergedVector;

        int i = 0, j = 0;

        while (1) {
            if (i == nums1.size() && j == nums2.size()) break;
            else if (i == nums1.size() && j != nums2.size()) {
                mergedVector.push_back(nums2[j]);
                j++;
            }
            else if (i != nums1.size() && j == nums2.size()) {
                mergedVector.push_back(nums1[i]);
                i++;
            }
            else {
                if (nums1[i] > nums2[j]) {
                    mergedVector.push_back(nums2[j]);
                    j++;
                }
                else {
                    mergedVector.push_back(nums1[i]);
                    i++;
                }
            }
        }

        if (mergedVector.size() % 2 == 0) {
            double i = mergedVector[mergedVector.size() / 2];
            double j = mergedVector[mergedVector.size() / 2 - 1];
            return (i + j) / 2;
        }
        else {
            return (double)mergedVector[mergedVector.size() / 2];
        }
    }
};