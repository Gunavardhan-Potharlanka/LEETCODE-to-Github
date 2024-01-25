class Solution {
    int ans=0;
    void Compute(int l, int mid, int h, vector<int>& nums){
        // Compare
        cout<<"HIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII";
        int cnt=0, j1=mid+1;
        for(int m=l;m<mid+1;m++){
            while(j1<h+1 && nums[m]>(2L*nums[j1])) j1++;
            cnt+=(j1-mid-1);
        }
        ans+=cnt;
        // Sort
        int i=0, j=0, k=l;
        vector<int> a(nums.begin()+l, nums.begin()+mid+1), b(nums.begin()+mid+1, nums.begin()+h+1);
        int n1=a.size(), n2=b.size();
        while(i<n1 && j<n2){
            if(a[i]<b[j]) nums[k++]=a[i++];
            else nums[k++]=b[j++];
        }
        while(i<n1) nums[k++]=a[i++];
        while(j<n2) nums[k++]=b[j++];
        return;
    }
    void MergeCompute(int l, int h, vector<int>& nums){
        if(l<h){
            int mid=l+(h-l)/2;
            MergeCompute(l, mid, nums);
            MergeCompute(mid+1, h, nums);
            Compute(l, mid, h, nums);
        }
        return;
    }
public:
    int reversePairs(vector<int>& nums) {
        MergeCompute(0, nums.size()-1, nums);
        return ans;
    }
};