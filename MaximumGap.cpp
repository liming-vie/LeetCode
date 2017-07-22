/* bucket sorting */
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN(a,b) (a)<(b)?(a):(b)
#define MAXN ~(1<<31)
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        if (n < 2)    return 0;
        int max=0,min=MAXN;
        for(int n:nums) {
            max=MAX(n,max);
            min=MIN(n,min);
        }
        int bucket_size = (max-min)/(n-1) + 1;
        int bucket_count=(max-min)/bucket_size+2;
        vector<pair<int,int>> buckets(bucket_count, make_pair(-1, MAXN));
        int idx;
        for(int n:nums) {
            idx=n/bucket_size;
            buckets[idx].first = MAX(buckets[idx].first, n);
            buckets[idx].second = MIN(buckets[idx].second, n);
        }
        int last=MAXN, res=0, tmp;
        for(int i=0; i<bucket_count; ++i) {
            if (buckets[i].first == -1) continue;
            tmp=buckets[i].second - last;
            res=MAX(tmp,res);
            last=buckets[i].first;
        }
        return res;
    }
}; 