// 把一个含有N个元素的数组循环右移k位
// 简单的例子：每次右移一次，循环k次。abcd1234->4abcd123->...->1234abcd
//

////the normal code
//
Rightshift(int *arr, int N, int K)
{
	while (k--)
	{
		int t = arr[N-1];
		for (int i = N - 1; i > 0; i--)
			arr[i] = arr[i-1];
		arr[0] = t;
	}
}


///the better code 
//需要全面考虑问题，k有可能大于N，而当每次移N次时会从新开始
RightShift(int *arr, int N, int K)
{
	K %= N;

	while (K--)
	{
		int t = arr[N-1];

		for (int i = N-1; i > 0; i--)
			arr[i] = arr[i-1];
		arr[0] = t;
	}
}

///the good code 
//通过逆序过程完成
//1、abcd1234 -> dcba1234
//2、dcba1234 -> dcba4321
//3、dcba4321 -> 1234abcd
//
Reverse(int *arr, int b, int e)
{
	for (; b < e; b++, e--)
	{
		int temp = arr[e];
		arr[e] = arr[b];
		arr[b] = temp;
	}
}

RightShift(int *arr, int N, int K)
{
	K %= N;
	Reverse(arr, 0, N-K-1);
	Reverse(arr, N-K, N-1);
	Reverse(arr, 0, N-1);
}
