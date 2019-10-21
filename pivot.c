int pivotIndex(int* nums, int numsSize){
    int pivot = -1;
    if(numsSize==0) return pivot;
    int preSum[numsSize];
    int postSum[numsSize];
    preSum[0]=0;
    postSum[numsSize-1]=0;
    for(int i=numsSize-1;i>0;i--){
        postSum[i-1]=postSum[i]+nums[i];
    }
    for(int i=0;i<numsSize-1;i++){
        preSum[i+1]=preSum[i]+nums[i];
    }
    
    for(int i=0;i<numsSize;i++){
        if(preSum[i]==postSum[i]){
            return i;
        }
    }
    return pivot;
}
