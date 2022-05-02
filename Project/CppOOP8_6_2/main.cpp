#include <iostream>
#include <forward_list>
#include <list>
#include <vector>
#include <fstream>
#include <set>


using std::cout;
using std::endl;

void istreamIter(std::istream& is)
{
	std::istream_iterator<int> iter(is);
	auto value = *iter;
	std::cout << value << std::endl;
}


void ostreamIter(std::ostream& os)
{
	std::ostream_iterator<int> iter(os, " ");
	*iter = 1;
	*iter = 2;
	*iter = 3;
	*iter = 4;
}

void setInsert()
{
	std::set<int> s;
	auto iter = std::inserter(s, s.begin());
	//std::insert_iterator iter(s, s.begin());
	*iter = 10;
	*iter = 20;
	*iter = 30;
	*iter = 40;

	for (auto num : s)
	{
		cout << num << endl;
	}
}


int main()
{
	//std::forward_list<int> fl;
	//auto iter = fl.begin();

	//iter++;
	//++iter;

	//std::list<int> fl1;
	//auto iters = fl1.begin();

	//iters++;
	//++iters;
	//iters--;
	//--iters;

	//std::vector<int> v{1,2,3};
	//auto iters1 = v.begin();
	//std::cout << *(iters1 + 2) << endl;
	//std::cout << *(std::addressof(*iters1) + 2) << endl;

	//std::ofstream ofs("output.txt");
	//ostreamIter(ofs);

	//setInsert();

	istreamIter(std::cin);
}
// output iterator
// *iter = value
// cout

// input iterator
// value = *iter
// cin

//forward iterator
//- forward_list, unordered xxx
//++ 전진 밖에 안 됨

// bidirectional iterator (양방향 반복자)
// - list, set, map, multiset, multimap
// ++, --

// random access iterator
// - array, vector, deque
// ++, --, +, -


// continguous access iterator (C++20)
// - array, vector
// ++, --, +, -, physical memory contiguous (물리적 메모리 연속적)
