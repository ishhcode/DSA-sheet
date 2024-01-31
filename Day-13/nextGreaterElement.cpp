//next greater element
vector<int> nextGreaterElement(vector<int>& arr, int n)
{
	// Write your code here
	vector<int> ans(n,-1);
	stack<int> st;
	for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top()<=arr[i]){
			st.pop();
		}
		if(st.empty()==false){
			ans[i]=st.top();
		}
		st.push(arr[i]);
	}
	return ans;
}

//next greater element 1
//You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

//For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of 
//nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.
 vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> ans;
        unordered_map<int,int> mp;
        stack<int> st;
        for(int i=n2-1;i>=0;i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            
            int res = st.empty() ? -1: st.top();
            mp.insert({nums2[i],res});
            st.push(nums2[i]);
        }
        for(auto x: nums1){
            ans.push_back(mp[x]);
        }
        return ans;

    }

//next greater element 2
/*Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next 
greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, 
which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.*/
vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
	    stack<int> st;
	    for(int i=2*n-1;i>=0;i--){
        while(!st.empty() && st.top()<= (nums[i%n])){
			st.pop();
		}
        if(i<n){
            if(st.empty()==false){
			ans[i]=st.top();
		}
        }
		
		st.push(nums[i%n]);
	}
	return ans;
        
    }