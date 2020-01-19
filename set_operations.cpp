#include "associative_containers.hpp"

void set_operations()
{
	/*
	 * Template class implementing a container of unique objects of type Key, sorted using a comparison function.
	 * O(log(n)) is the complexity of insertion, deletion and search.
	 * Implemented as red-black trees.
	 */ 
	 
	std::set<int> iset;
	std::pair<std::set<int>::iterator, bool> result;
	result = iset.insert(1);
	std::cout<<"deref insert's result iterator: "<<*result.first<<" result bool value(if the insertion was successful) "<<result.second<<std::endl;
	result = iset.insert(1);
	std::cout<<"2nd attempt deref insert's result iterator: "<<*result.first<<" result bool value(if the insertion was successful) "<<result.second<<std::endl;
	
	//insert using initilizer list
	iset.insert({2,3});
	//avoid calling copy or move c-tor, as object is constructed in place
	iset.emplace(4);
	//give wrong hint
	iset.emplace_hint(++iset.begin(), 5);
	//give better hint
	iset.emplace_hint(--iset.end(), 6);
	
	std::cout<<"insert, insert initilizer list, emplace, emplace_hint: "<<std::endl;
	for(std::set<int>::iterator it = iset.begin(), end = iset.end(); it!=end; ++it)
		std::cout<<*it<<" ";
	std::cout<<"\n";
	
	//counts # of elements that have the given key. Since no duplicates are allowed it returns 0 or 1.
	std::set<int>::size_type count = iset.count(5);
	std::cout<<"count: "<<count<<std::endl;
	
	//find address for a given key in the set
	std::set<int>::iterator find = iset.find(3);
	std::cout<<"find: "<<*find<<std::endl;
	
	//use ietartors to find lower bound (the address of the key euqal to or less than) and upper bound (address of the next key) for the given key
	std::set<int>::iterator lb = iset.lower_bound(3), ub = iset.upper_bound(3);
	std::cout<<"lower bound "<<*lb<<" upper bound "<<*ub<<std::endl;
	//use equal range to take lower and upper bounds
	std::pair<std::set<int>::iterator, std::set<int>::iterator> range = iset.equal_range(3);
	std::cout<<"lower and upper bounds using equal_range: "<<*(range.first)<<" "<<*(std::get<1>(range))<<std::endl; 
}
