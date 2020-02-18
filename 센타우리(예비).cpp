#include <iostream>

using namespace std;

int main()
{
	int arr_size;
	int x, y;
	int dst;
	int low_tmp, high_tmp;
	int count, bpcount = 0;
	int j;

	cin >> arr_size;

	int *answer = new int[arr_size];
	int *input = new int[arr_size];

	// 입력 후 처리, 결과값 배열 저장
	/*for (int i = 0; i < arr_size; i++)
	{
		count = 2;
		cin >> x >> y;
		//예외처리
		if (x >= y)
			return 0;
		else if (y >= 2147483648)
			return 0;

		dst = y - x;
		low_tmp = 1;
		high_tmp = 1;
		j = 1;
		
		if (dst == 1)
			answer[i] = 1;
		else if (dst == 2)
			answer[i] = 2;
		else
		{
			while (1)
			{
				low_tmp = high_tmp;
				high_tmp += j + j + 1;
				count++;
				if (dst <= high_tmp && dst > low_tmp)
				{
					answer[i] = count;
					break;
				}
				j++;
			}
		}
	}*/

	//입력
	for (int i = 0; i < arr_size; i++)
	{
		cin >> x >> y;
		if (x >= y)
			return 0;
		else if (y >= 2147483648)
			return 0;
		dst = y - x;
		input[i] = dst;
	}
	
	//계산
	do
	{
		count = 2;
		low_tmp = 1;
		high_tmp = 1;
		j = 1;
		low_tmp = high_tmp;
		high_tmp += j + j + 1;
		count++;
		for (int i = 0; i < arr_size; i++)
		{
			if (input[i] == 1)
			{
				answer[i] = 1;
				bpcount++;
			}
			else if(input[i] == 2)
			{
				answer[i] = 2;
				bpcount++;
			}
			else if (input[i] <= high_tmp && input[i] > low_tmp)
			{
				answer[i] = count;
				bpcount++;
			}
		}
		j++;
	} while (bpcount <= arr_size);
	
	
	
	


	//결과값 출력
	for (int i = 0; i < arr_size; i++)
	{
		cout << answer[i] << "\n";
	}
	
	delete[] answer;
	answer = NULL;
	delete[] input;
	answer = NULL;

	return 0; 
}