#include <stdio.h>


int searchInsert1(int *nums, int numsSize, int target) {
    int index = 0;
    for (int i=0; i < numsSize; i++) {
        if (target == nums[i]) {
            return i;
        }else if(target < nums[i]){
            return index;
        }else if (target > nums[i]){
            index = i + 1;
        }else{
            return target - 1;
        }
    }
    return index;
}

int searchInsert2(int *nums, int numsSize, int target){
    int left = 0, right = numsSize - 1, index = numsSize;
    int mid = 0;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        // 如果 left > 当前元素， left前进
        if(target <= nums[mid]){ // 要查找的数据在左半边
            right = mid - 1;
            index = mid;
        }else{  // 要查找的数据在右半边
            left = mid + 1;
        }
        
    }
    return index;
}

int searchInsert(int *nums, int numsSize, int target){
    for(int i = 0; i< numsSize; i++){
        if(nums[i] >= target){
            return i;
        }
    }
    return numsSize;
}


int main(){
    int a[5] = {1,3,5,7};
    int index = searchInsert(a, 5, 2);
    printf("索引位置:%d", index);
    return 0;
}