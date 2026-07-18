/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int found = 0;
    int* indexs = malloc(2*sizeof(int));
    if( indexs == NULL){
        return NULL;
    }
    for(int i=0;i<numsSize;i++){
        for(int j=0;j<numsSize;j++){
            if(i != j){
            if(nums[i] + nums[j] == target){
                indexs[0] = i;
                indexs[1] = j;
                found = 1;
            }
            }
            if(found){
                break;
            }
        }
         if(found){
                break;
            }
    }
    return indexs;
}
