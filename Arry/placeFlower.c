//605. Can Place Flowers
//mycode

bool canPlaceFlowers(int *flowerbed, int flowerbedSize, int n)
{
	int i, j;
	int count = 0;

	if (flowerbedSize == 1 && flowerbed[0] != 1)
	{
		++count;
		return count >= n;
	}else if (flowerbedSize == 1 && flowerbed[0] == 1)
	{
		return count >= n;
	}

	for (i = 0; i < flowerbedSize;)
	{
		if (i == 0 && flowerbed[0] == 0)
		{
			if (flowerbed[1] == 0)
			{
				++count;
				i += 2;
				continue;
			}
		}

		if (i == flowerbedSize-1 && flowerbed[flowerbedSize-1] == 0)
		{
			if (flowerbed[flowerbedSize-2] == 0)
			{
				++count;
				break;
			}
		}

		if (i > 0 && i < flowerbedSize-1 &&
				flowerbed[i] == 0)
		{
			if (flowerbed[i-1] == 0 && flowerbed[i+1] == 0)
			{
				++count;
				i += 2;
				continue;
			}
		}

		++i;
	}

	return count >= n;
}

//the good solution from leetcode disccussion
public class Solution{
	public boolean canPlaceFlowers(int[] flowerbed, int n){
		int count = 0;
		for (int i = 0; i < flowerbed.length && count < n; i++)
		{
			if (flowerbed[i] == 0)
			{
				int next = (i == flowerbed.length -1) ? 0 : flowerbed[i+1];
				int prev = (i == 0)?0 : flowerbed[i-1];
				if (next == 0 && prev == 0)
				{
					flowerbed[i] = 1;
					count++;
				}
			}
		}

		return count == n;
	}
}
