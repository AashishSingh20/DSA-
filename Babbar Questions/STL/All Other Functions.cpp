#include<iostream>
using namespace std;

int main(){
	vector<int> v;  // Vector Declaration with datatype name v
	
	v.push_back(1); // Inserts 1 into vector v
	v.emplace_back(3); // Dynamically increases the size of v and pushes back 3 into the vector(Faster than push_back)
	
	vector<pair<int,int>> vec;  // Creates a pair funtion using vector.
	
	v.push_back({2,5});  // This is used to insert pair of 2 & 5 into vector v.
	v.emplace_back(2,5); // Automatically Assumes it is a pair and puts it into v.
	
	vector<int> v1(5,10); // Here an array of size 5 will all elements as 10 is created.
	
	vector<int> v2(5);  // Here an Array of size 5 is created. 
	
	vector<int> v3(v2); // v2 is copied in v2. 
	
	
	
	
	// Iterators   // Used to access the elenents in the array
	
	vector<int>::iterator it v.begin();  // Iterator is created with name 'it'(cn be changed) & it stores address of 1st element in the array
	it++;      // Iterator is incremented(It moves from 1st element to 2nd)
	cout<< *it <<" ";  // It prints the element at iterator is currently at.
	
	it = it+2;  // Iterator shifts 2 position from the current position
	cout<< *it <<" "; 
	
	vector<int>::iterator it = v.end(); // It stores the address of the element next to the last element in the array.
	
	for(auto it = v.begin();it != v.end();it++){  // 'auto' assigns data type to 'it'
		cout<<*it<<endl;
	}
	
	for(auto it: v){   // For each loop to perform the same operation as above.
		cout<<it<<endl;
	}
	
	v.erase(v.begin()+1); // Will erase the element next to the first element
	
	v.erase(v.begin()+2, v.begin()+ 4); // Will erase elements from 3rd element to 4th element.
	
	
	
	// Insert Functions
	
	vector<int>v(2,100); // {100,100}
	v.insert(v.begin(), 300); // 300 will be inserted at the front of the array.  {300,100,100}
	v.insert(v.begin()+ 1,2,10);  // Here '1' is the first index place where '10' element will be inserted for '2' times.  {300,10,10,100,100}
	
	vector<int> copy(2,50); // {50,50};
	v.insert(v.begin(), copy.begin(), copy.end()); // {50,50,300,10,10,100,100}
	
	
	
	//List Functions
	
	list<int> ls; // A list ls is created
	
	ls.push_back(2); // 2 is inserted into list {2}
	ls.emplace_back(4); // {2,4}
	
	ls.push_front(5);  // {5,2,4}
	ls.emplace_front(); 
	
	//Deque Functions
	
	deque<int>dq;  // Queue is created;
	dq.push_back(1); // {1};
	dq.emplace_back(2); // {1,2};
	dq.push_front(4); // {4,1,2}
	
	dq.pop_back();  // {1,2}  // Pops the first element
	
	
	
	// Stack Functions
	
	stack<int> st;
	st.push(1); // {1}
	st.push(2); // {2,1}
	st.push(3); // {3,2,1}
	st.push(3); // {3,3,2,1}
	st.emplace(5); // {5,3,3,2,1}
	
	cout<< st.top();  // Prints 5 "** st[2] is invalid **"
	st.pop(); // {3,3,2,1}
	
	cout<< st.top();  // 3
	cout<< st.size();  // 4
	cout<< st.empty(); 
	
	stack<int>st1, st2;
	st1.swap(st2);
	
	
	// Queue Functions
	
	queue<int> q;
	q.push(1); 	// {1}
	q.push(2); // {1,2}
	q.emplace(3);  // {1,2,3}
	
	q.back() +=	5;   // Add 5 into the last added no, Here 3+5 = 8
	cout<<q.back();  // Prints 8
	
	// q = {1,2,8}
	cout<<q.front(); // Prints 1
	
	q.pop();  // {2,9}
	cout<<q.front(); // Prints 2
	
	
	// Priority Queue
	
	priority_queue<int>pq;  // Stores the greatest element on the top
	
	pq.push(5);  // {5}
	pq.push(2);  // {5,2}
	pq.push(8);  // {8,5,2}
	pq.emplace(10);  // {10,8,5,2}
	
	cout<<pq.top();  // prints 10
	
	pq.pop(); // pops 10  // {8,5,2}
	cout<<pq.top();  // prints 8
	
	priority queue<int, vector<int>, greater<int>> pq; //Stores the minimum element at the top
	
	pq.push(5);  // {5}
	pq.push(2);  // {2,5}
	pq.push(8);  // {2,5,8}
	pq.emplace(10);  // {2,5,8,10}
	
	cout<<pq.top();  // prints 2
	
	
	// Set Functions
	
	set<int> st;  // Stores in a sorted order
	st.insert(1);  // {1} 
	st.emplace(2);  // {1,2}
	st.insert(2);   // {1,2}  // Does not store repeated value
	st.insert(3);  // {1,2,3}
	st.insert(4);  //{1,2,3,4}
	
	auto it = st.find(3);  // Returns an iterator that points to the element 3

	// {1,2,3,4,5}
	auto it = st.find(6) // If the Element is not in the set it will point to the st.end() [the element after last element(Garbage)]
	
	st.erase(5);  // Erases 5  // Takes O(log n) time
	
	int cnt = st.count(1);  // If 1 is there in the set it will give '1' or '0'
	
	auto it = st.find(3);
	st.erase(it);  // It takes O(1) time
	
	// {1,2,3,4,5}
	auto it1 = st.find(2);
	auto it2 = st.find(4); 
	st.erase(it1, it2);    // {1,3,5}
	
	
	// MultiSet Functions
	
	multiset<int> ms;
	ms.insert(1);  // {1}
	ms.insert(1);  // {1,1}
	ms.insert(1);  // {1,1,1}
	
	ms.erase(1);  // all 1's erased
	
	int cnt = ms.count(1);
	ms.erase(ms.find(1));  // Only a single '1' erased
	
	ms.erase(ms.find(1), ms.find(1)+(2));  	
	
	// Unordered Set  // Stores in random order
	unordered set<int> st;  // Inserts unique elements
	// All other operations are same.
	// Lower Bound and Upper Bound Functions sho not work
	
	
	// Map    // Stores unique keys in the sorted order 
	
	map<int, int> mpp;      // Stores in {Key,Value} format  // Here there is a key and a value
	map<int, pair<int ,int>> mpp;  //Here there is a single key and 2 values
	map<pair<int, int>, int> mpp;  // Here there are 2 keys and 1 value
	
	mp[1] = 2;     // Here 1 is the key and 2 is the value {1,2}
	mpp.emplace({3,1});  // Here 3 is the key and 1 is the value
	mpp.insert({2,4});	// Here 2 is the key and 4 is the value
	
	mpp({2,3}) = 10;
	{
		{1,2};
		{2,4};
		{3,1};     // [{1,2}, {3,4}, {3,1}]
	}
	
	for (auto it: mpp){
		cout<< it.first()<<" "<<it.second()<<endl;
	}
	
	cout<<mpp[1];  // Gives value at 1st position which is 2
	cout<<mpp[5];  // Gives 0 or NULL as there are only 3 values
	
	auto it = mpp.find(3);
	cout<<*it.second;
	
	auto it = mpp.find(5);	
	
	auto it = mpp.lower_bound(2);
	auto it = mpp.upper_bound(3);
	
	
	//Multi Map
	// Same as map but can stores multiple values.
	
	
	//Unordered Map   // Same as Set and Unordered_Set but values will be stored in randomized manner.
	
	 
}
