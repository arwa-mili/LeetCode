//by mahdi
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        vector<int> cnt(n+1,0);
        vector<pair<int,int> > v;
        vector<int> divs[n+1];
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j+=i){
                divs[j].push_back(i);
            }
        }
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        int l=0;
        for(int i=0;i<n;){
            int j = i;
            while(j<n && v[j].first==v[i].first){
                j++;
            }
            j--;
            for(int o=i;o<=j;o++){
                if(v[o].second==0){
                    ans+=j-i;
                    continue;
                }
                int d = __gcd(v[o].second, k);
                d = k/d;
                if(d<n)ans+=cnt[d];
                for(auto &di:divs[v[o].second]){
                    cnt[di]++;
                }
            }
            for(int o=i;o<=j;o++){
                if(v[o].second==0)continue;
                for(auto &di:divs[v[o].second]){
                    cnt[di]--;
                }
            }
            i=j+1;
        }
        return ans;
    }
};
