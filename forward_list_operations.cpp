#include "sequence_containers.hpp"

void fwd_list_operations()
{
	/*
	 * Template class that implements a singly-linked list which allows for fast insertion and removal from anywhere in the list.
	 * Does not have an overhead when compared to C implementation.
	 */
	 
	 //uniform initializationm
	 std::forward_list<int> ifwd_list{0,1,2,3,4,5};
	 
	 //use iterator to print
	 std::cout<<"use iterator to print "<<std::endl;
	 for(std::forward_list<int>::iterator it = ifwd_list.begin(), end = ifwd_list.end(); it!=end; ++it)
		std::cout<<*it<<" ";
	std::cout<<"\n";
	
	std::cout<<"front: "<<ifwd_list.front()<<" empty "<<ifwd_list.empty()<<std::endl;
	ifwd_list.clear();
	std::cout<<"after clear() empty "<<ifwd_list.empty()<<std::endl;
	
	
	 ifwd_list.emplace_front(0);
	 ifwd_list.push_front(1);
	 ifwd_list.insert_after(ifwd_list.begin(), 22);
	 
	 //pointer arithmetic with iterators supports only ++, as it performs incrementally ->next dereferencing
	 std::forward_list<int>::iterator bg = ++ifwd_list.begin(); 
	 ifwd_list.insert_after(++bg, 2, 134); //2 copies
	 ifwd_list.emplace_after(++(++ifwd_list.begin()), 78);
	 std::cout<<" emplace_front, push front, insert after, insert after(count), emplace_after"<<std::endl;
	 for(std::forward_list<int>::iterator it = ifwd_list.begin(), end = ifwd_list.end(); it!=end; ++it)
		std::cout<<*it<<" ";
	std::cout<<"\n";
	
	std::cout<<"sort elements"<<std::endl;
	ifwd_list.sort();
	std::copy(ifwd_list.begin(), ifwd_list.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout<<"\n";
	
	std::cout<<"reverse elements"<<std::endl;
	ifwd_list.reverse();
	std::copy(ifwd_list.begin(), ifwd_list.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout<<"\n";
	
	std::cout<<"remove consecutive duplicate elements"<<std::endl;
	ifwd_list.unique();
	std::copy(ifwd_list.begin(), ifwd_list.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout<<"\n";
	
	ifwd_list.insert_after(++(++ifwd_list.begin()), {123,3356, 22, -9});
	std::cout<<"insert_after an initilizer list"<<std::endl;
	std::copy(ifwd_list.begin(), ifwd_list.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout<<"\n";
	
	ifwd_list.remove(22);
	std::cout<<"remove all values=22"<<std::endl;
	std::copy(ifwd_list.begin(), ifwd_list.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout<<"\n";
	
	ifwd_list.remove_if([](int elem){return elem>99; });
	std::cout<<"remove all >99"<<std::endl;
	std::copy(ifwd_list.begin(), ifwd_list.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout<<"\n";
	
	ifwd_list.pop_front();
	std::cout<<"pop front"<<std::endl;
	std::copy(ifwd_list.begin(), ifwd_list.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout<<"\n";
	
	ifwd_list.resize(7);
	std::cout<<"resize to 7 elements (more than it currently has)"<<std::endl;
	std::copy(ifwd_list.begin(), ifwd_list.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout<<"\n";
	 
	std::forward_list<int> ifwd_list2{0,1,2,3,4,5};
	ifwd_list.splice_after(++ifwd_list.begin(), ifwd_list2, ++ifwd_list2.begin(), ifwd_list2.end());
	std::cout<<"splice after the 2nd element"<<std::endl;
	std::copy(ifwd_list.begin(), ifwd_list.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout<<"\n";
	
	std::cout<<"2nd list"<<std::endl;
	std::copy(ifwd_list2.begin(), ifwd_list2.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout<<"\n";
	
	
}
