#include <iostream>
#include <vector>
#include <algorithm>

int  binary_search(std::vector<int> &v, int num, int idx_min, int idx_max)
{
	int mid;

	if (idx_min == idx_max)
	{
		if (num < v[idx_min])
			return (idx_min);
		else
			return (idx_min + 1);
	}
	if (idx_min > idx_max)
		return idx_min;
	
	mid = (idx_min + idx_max) / 2;
	if (num > v[mid])
		return binary_search(v, num, mid + 1, idx_max);
	else if (num < v[mid])
		return binary_search(v, num, idx_min, mid - 1);
	else
		return mid;
}

int main(int argc, char* argv[]) {
	std::vector<int> v{118, 120, 176, 189, 300, 392, 395, 400, 472, 474, 482, 485, 500, 541, 577, 658, 755, 777, 788, 900, 931};
					//	0	 1	  2	   3	4	 5	  6	   7	8	 9	  10   11	12	 13	  14   15   16   17   18   19   20
	int num = atoi(argv[1]);
	int idx_i = atoi(argv[2]);
	int idx_f = atoi(argv[3]);
	int idx_inserted;
	std::vector<int>::iterator it = v.begin();
	std::cout << "---->>>> " << v.back() << std::endl;
	std::cout << "---->>>>" << std::endl;
	
	idx_inserted = binary_search(v, num, idx_i, idx_f);
	v.insert(it + idx_inserted, num);
	std::cout << "Insertado en: " << idx_inserted << std::endl;
	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;
	
	(void)idx_inserted;
	return 0;
}

/* 
118, 119, 176, 189, 300, 392, 395, 400, 472, 474, 482, 485, 500, 541, 577, 658, 755, 777, 789, 900, 931

 */