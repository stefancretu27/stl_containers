#include "sequence_containers.hpp"

void list_operations()
{
	/* 
	 * Template class that implements a conatiner based on a doubly-linked list. It allows for pushing elements at both ends.
	 * Unlike forward list, it provides reverse iterator that allow for reverse traversial.
	 * Like forward list, insertion and deletion of an elemnt are O(1), whilst search and access are O(n)
	 */ 
	 
	std::list<int> ilist{0,1,2,3,4,5};
	std::list<int> ilist2, ilist_bk;
	
	//assign value to container
	ilist2.assign(3,-3);
	
	std::cout<<"reverse iterator to print list in reverse order"<<std::endl;
	//use reverse iterator
	for(std::list<int>::reverse_iterator it = ilist.rbegin(), rend = ilist.rend(); it!=rend; ++it)
		std::cout<<*it<<" ";
	std::cout<<"\n";
	
	//get front and back
	std::cout<<"font: "<<ilist.front()<<" back: "<<ilist.back()<<std::endl;
	
	//clear, size and empty
	ilist2.clear();
	std::cout<<"After clear empty: "<<ilist2.empty()<<" size: "<<ilist2.size()<<std::endl;
	
	ilist2.insert(ilist2.begin(), {33, 44});
	ilist2.insert(++(++ilist2.begin()), 3, 11);
	ilist2.emplace_front(77);
	ilist2.push_front(99);
	ilist2.emplace(++ilist2.begin(), 88);
	ilist2.emplace_back(1909);
	std::cout<<"insert initilizer list of 2 elements on empty list, then insert 3 elements at the end, then emplace_front, push_front,emplace on pos 1 and emplace_back"<<std::endl;
	std::copy(ilist2.begin(), ilist2.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout<<std::endl;
	
	ilist2.pop_front();
	ilist2.pop_back();
	ilist2.erase(++(++ilist2.begin()),  --(--ilist2.end()));
	std::cout<<"pop_front, pop_back, erase everything but first 2 and last 2"<<std::endl;
	std::copy(ilist2.begin(), ilist2.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout<<std::endl;
	
	ilist2.sort();
	std::cout<<"sort"<<std::endl;
	std::copy(ilist2.begin(), ilist2.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout<<std::endl;
	
	ilist_bk = ilist2;
	ilist.merge(ilist2);
	ilist2 = ilist_bk;
	std::cout<<"merge. The merged list becomes empty and the list to merge with becomes larger by the new list"<<std::endl;
	std::copy(ilist.begin(), ilist.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout<<std::endl;
	std::copy(ilist2.begin(), ilist2.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout<<std::endl;
	
	auto it = ilist.end();
	std::advance(it, -2);
	ilist.splice(it, ilist2, ++ilist2.begin(), --ilist2.end());
	std::cout<<"splice = moves elements from one list to another and advance"<<std::endl;
	std::copy(ilist.begin(), ilist.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout<<std::endl;
	std::copy(ilist2.begin(), ilist2.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout<<std::endl;
	
	ilist2.resize(5);
	std::copy(ilist2.begin(), ilist2.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout<<std::endl<<"size after resize:"<<ilist2.size()<<std::endl;
	
	ilist.insert(ilist.end(), {0, 1});
	ilist.unique();
	std::cout<<"unique = remove consecutive unique values"<<std::endl;
	std::copy(ilist.begin(), ilist.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout<<std::endl;
	
	
	
	
}
