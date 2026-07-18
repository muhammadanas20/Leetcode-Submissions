/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* transformArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* transformArray = (int*) malloc((*returnSize) * sizeof(int));
    if(transformArray == NULL){
        return NULL;
    }
    for(int i=0;i<(*returnSize);i++){
        if(nums[i] % 2 == 0){
            transformArray[i] = 0;
        }else{
            transformArray[i] = 1;
        }
    }
    int swap,temp;
    for(int i=0;i<(*returnSize);i++){
        swap =0;
        for(int j=0;j<(*returnSize)-i-1;j++){
            if(transformArray[j]>transformArray[j+1]){
            temp = transformArray[j];
            transformArray[j] = transformArray[j+1];
             transformArray[j+1] = temp;
             swap =1;
            }
        }
         if(!swap){
                break;
            }
    }
    return transformArray;
}