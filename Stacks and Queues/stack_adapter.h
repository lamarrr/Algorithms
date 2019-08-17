#include <cinttypes>
#include <cassert>

#include <vector>

template<typename ValueType,
typename ContainerType = std::vector<ValueType>>
class Stack {
using value_type = ValueType;
using container_type =  ContainerType;
container_type container_;

public:

Stack(){}
Stack(const container_type& v) : 
container_{v}{}
Stack(const Stack &) = default;
Stack(Stack &&) = default;
Stack& operator=(const Stack&) = default;
Stack& operator=(Stack&&) = default;
value_type Pop(){
assert(!container_.empty());
value_type tmp = std::move(container_.back());
container_.erase(container_.end()-1);
return std::move(tmp);
}
void Push(const value_type & v){
container_.push_back(v);
}
value_type size(){
return container_.size();
}


};
