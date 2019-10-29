/*
 *A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).
 *Each LED represents a zero or one, with the least significant bit on the right.
 *Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.
 *Example:
 *Input: n = 1
 *Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"] 
 */

unsigned int countOneBits(unsigned int n) 
{ 
    unsigned int count = 0; 
    while (n) 
    { 
        count += n & 1; 
        n >>= 1; 
    } 
    return count; 
} 

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** readBinaryWatch(int num, int* returnSize){
    char **result = malloc(720 * sizeof(char*));
    int hour, min,hourCount,minCount;
    *returnSize=0;
    char tempResult[6];
    for(int i=0;i<720;i++) {
        hour=i/60;
        min=i%60;
        hourCount=countOneBits(hour);
        minCount=countOneBits(min);
        if((hourCount+minCount) == num){
           result[*returnSize] = (char*)malloc(sizeof(char)*6);
            sprintf(result[*returnSize],"%d:%02d",hour,min);
            *returnSize=*returnSize+1;
            //printf("%d:%02d\n",hour,min);
            //result[returnSize] = 
        }
    }
    for(int i=0;i<*returnSize;i++){
        printf("\n %s",result[i]);
    }
    return result;
}
