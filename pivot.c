int pivotIndex(int* nums, int numsSize){
    if(numsSize==0) {
        return -1;
    }
    int i=0, j=numsSize-1;
    int leftSum=0,rightSum=0;
    int pivot=i;
    
    while(i!=j){
        pivot=-1;
        if(leftSum==rightSum){
            rightSum=rightSum+nums[j];
            j--;
        }
        else if(leftSum>rightSum){
            rightSum=rightSum+nums[j];
            j--;
        }
        else if(leftSum<rightSum){
            leftSum=leftSum+nums[i];
            i++;
        }
    }
    if(leftSum == rightSum){
        pivot=j--;
    }
    else{
        pivot=-1;
    }
    return pivot;
}