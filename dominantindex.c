int dominantIndex(int* nums, int numsSize) {
    int index=0;
    if(numsSize==0) return -1;
    if(numsSize==1)return 0;
    int max=INT_MIN,secondMax=INT_MIN;
    for(int i=0; i<numsSize; i++) {
        if(max<nums[i]){
            index=i;
            secondMax=max;
            max=nums[i];
        }
        else if(secondMax<nums[i]){
            secondMax=nums[i];
        }
    }
    if(max>=2*secondMax){
        return index;
    }
    return -1;

}
