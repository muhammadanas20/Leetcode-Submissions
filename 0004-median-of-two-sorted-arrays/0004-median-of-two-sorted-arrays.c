 double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int merged_size = nums1Size + nums2Size;
    double median;
   int merged_array[merged_size];
   int i=0,j=0,k=0;
   while (i < nums1Size && j < nums2Size){
    if(nums1[i]<nums2[j]){
        merged_array[k++] = nums1[i++];
    }
    else{
        merged_array[k++] = nums2[j++];
    }
   }
    while (i < nums1Size) {
        merged_array[k++] = nums1[i++];
    }
    while (j < nums2Size) {
        merged_array[k++] = nums2[j++];
    }
    if(merged_size % 2 == 0 ){
      median =(double)(merged_array[(merged_size/2)] + merged_array[(merged_size/2)-1]);
      median /= 2.0;
    }else{
        median = (double)merged_array[(merged_size/2)];
    }
    return median;
}