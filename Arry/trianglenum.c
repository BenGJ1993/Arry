//611. Valid Triangle Number
//my code
//
int triangleNumber(int *nums, int numsSize)
{
	int i, j, k;
	int count = 0;

	for (i = 0; i < numsSize; i++)
		for (j = i+1; j < numsSize; j++)
			for (k = j+1; k < numsSize; k++)
				if (nums[i] + nums[j] > nums[k] &&
						nums[i] + nums[k] > nums[j] &&
						nums[j] + nums[k] >nums[i])
					++count;

	return count;
}



//The good solution from leetcode disccussion
public static int triangleNumber(int[] A)
{
	Arrays.sort(A);

	int count = 0, n = A.length;
	for (int i=n-1; i>=2; i--)
	{
		int l = 0, r = i - 1;
		while (l < r)
		{
			if (A[l] + A[r] > A[i])
			{
				count += r-l;
				r--;
			}
			else
				l++;
		}
	}
	return count;
}
