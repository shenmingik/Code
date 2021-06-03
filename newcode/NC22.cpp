//合并两个有序的数组

/*
给出两个有序的整数数组A和B，请将数组B合并到数组 A，变成一个有序的数组
注意：
可以假设A数组有足够的空间存放B数组的元素，A和B中初始的元素数目分别为m和n
*/

class Solution {
    public:
        void merge(int A[], int m, int B[], int n) {
            int ptr_A = m-1;
            int ptr_B = n-1;
            int total_end = m+n-1;
            while(total_end >= 0 && ptr_A >=0 && ptr_B>=0)
            {
                if(A[ptr_A] <= B[ptr_B])
                {
                    A[total_end--] = B[ptr_B--];
                }
                else
                {
                    A[total_end--] = A[ptr_A--];
                }
            }
            
            while(ptr_A>=0&& total_end >= 0 )
            {
                A[total_end--] = A[ptr_A--];
            }
            while(ptr_B >=0&& total_end >= 0 )
            {
                A[total_end--] = B[ptr_B--];
            }
        }
    };