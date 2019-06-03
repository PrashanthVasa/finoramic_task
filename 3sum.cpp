int Solution::threeSumClosest(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    int N = A.size();
    int left,right,least_diff = INT_MAX,diff;
    long long result,sum3;
    for(int index = 0;index<=N-3;index++){
        left = index+1;
        right = N-1;
        while(left<right){
            sum3 = A[index]+A[left]+A[right];
            if(sum3 == B){
                return B;
            }
            diff = abs(B-sum3);
            if(diff<least_diff){
                least_diff = diff;
                result = sum3;
            }
            if(sum3>B){
                right--;
            }
            else{
                left++;
            }
        }
        
    }
    return result;
}

