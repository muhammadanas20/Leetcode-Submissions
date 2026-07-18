

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    *returnSize = 2*n; 
    int *returnArray = (int*)malloc((*returnSize) * sizeof(int));
    if (returnArray == NULL) {
        return NULL; 
    }
        for(int i=0;i<n;i++){
                returnArray[2*i] = nums[i];
                returnArray[2*i+1] = nums[i+n];
        }  
     
    return returnArray;

}