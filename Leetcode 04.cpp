
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  int i = 0, j = 0, k = 0;
        int n1 = nums1Size;
        int n2 = nums2Size;
        int n[10000];
    
        while (i<n1 && j <n2)
        {
            if (nums1[i] < nums2[j])
                n[k++] = nums1[i++];
            else
                n[k++] = nums2[j++];
        }
     
        while (i < n1)
            n[k++] = nums1[i++];
     
        while (j < n2)
            n[k++] = nums2[j++];

        return (k%2==1) ? (float) n[k/2] : (((float)n[k/2-1] + ((float)n[k/2]))/2);
  
}
