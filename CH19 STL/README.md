## Vector
Similar to array.  

## Iterator
Similar to pointer.  
*Noticed*: Every container has different iterator class. Not the same.

## Deque
Same as Vector. But insertion, deletion are faster.(tradeoff with random access);  

## List
Using double-linked list.  
Insertion, deletion are much more faster.(tradeoff with slower random access);

## stack
```=c++
include<stack>
stack<char, /*vector<char>*/ > s;
s.push();
s.pop();
s.top();
s.empty();
```

## set
```=c++
include<set>
set<T, /*Ordering*/> s; // default < relation
s.insert();
s.find() // 如果有找到Iterator指向找到的東東, 沒找到指到s.end()
```

## map
```=c++
include<map>
map<string, int> m;
map<string, int>:: iterator it;
m[a] = 1;
m[b] = 0;
m.find(); // 如果有找到Iterator指向找到的東東, 沒找到指到s.end()
for(it=m.begin(); it!=m.end(); it++)
{
  //first is like "key", second is like "value"
  cout << it->first << " " << it->second;
}
```

## Algorithm
### find
```=c++
vector<int> v;
vector<int> ::iterator it;
it = find(v.begin(), v.end(), 3); it會指到出現3的位置
```

### sort
```=c++
vecotr<int> v;
vector<int>:: iterator it;
bool comp(int x, int y){return x<y}
it = sort(v.begin(), v.end(), comp);
```
