//
//  main.cpp
//  Combination Sum
//
//  Created by 李佳 on 14/12/6.
//  Copyright (c) 2014年 LiJia. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target)
    {
        std::sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> resultVec;
        if (candidates.size() > 0)
        {
            vector<int> curVec;
            doSearchNum(resultVec, curVec, candidates, 0,target);
        }
        return resultVec;
    }
    
    void doSearchNum(vector<vector<int>> &resultVec, vector<int> &curVec, vector<int> &candidates, int curValue ,int target)
    {
        for (int i = 0; i < candidates.size(); ++i)
        {
            if (candidates[i] < curValue)
                continue;
            if (target == candidates[i])
            {
                curVec.push_back(candidates[i]);
                resultVec.push_back(curVec);
                curVec.pop_back();
                return;
            }
            auto it = std::upper_bound(candidates.begin(), candidates.end(), target);
            vector<int> newInput(candidates.begin(), it);
            if (newInput.size() > 0)
            {
                curVec.push_back(candidates[i]);
                doSearchNum(resultVec, curVec, newInput, candidates[i],target - candidates[i]);
                curVec.pop_back();
            }
        }
    }
    
};

int main(int argc, const char * argv[])
{
    Solution obj;
    vector<int> inputVec({1,2,3,5,7});
    vector<vector<int>> result;
    result = obj.combinationSum(inputVec, 7);
    printf("sfsf");
    return 0;
}
