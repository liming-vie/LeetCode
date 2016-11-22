class Solution {
public:
void find(vector<int> &candidates, int vi,int target, vector<int> tmp, int cursum, vector<vector<int> >&res){
  if (cursum>target)   return;

  int n = candidates.size();
  for (int i = vi; i<n; ++i){
    cursum += candidates[i];
    if (cursum>target) return;

    tmp.push_back(candidates[i]);

    if (cursum == target){
      res.push_back(tmp);
      return;
    }
    find(candidates, i, target, tmp, cursum, res);
    cursum -= candidates[i];
    tmp.pop_back();
  }
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
  vector<vector<int> > res;
  if (target<0)    return res;

  sort(candidates.begin(), candidates.end());

  if (candidates[0]>target)    return res;
  vector<int> tmp;
  find(candidates, 0,target, tmp, 0, res);
  return res;
}
};