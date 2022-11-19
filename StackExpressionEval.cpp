#include<iostream>
#include<cctype>
#include<cstring>
#include<cstdlib>
using namespace std;

template<typename T>
class stack{
public:
  stack();
  stack(const stack&);
  ~stack();
  stack<T>& operator=(const stack&);
  void push(T);
  void pop();
  T top();
  bool empty();
  unsigned int size(); // unsigned int makes it impossible to be negative
  T peek(int);
private:
  T* cat;
  unsigned int _size;
  unsigned int capacity;
  void doubleCap();
  void clear();
  void dup_Arr(T*&, T*, unsigned int);
};

template<typename T>
stack<T>::stack(){
  cat = new T[5];
  _size = 0;
  capacity = 5;
}

template<typename T>
stack<T>::~stack(){
  clear();
}

template<typename T>
bool stack<T>::empty(){
  return _size == 0;
}

template<typename T>
T stack<T>::top(){
  return cat[_size - 1];
}

template<typename T>
void stack<T>::clear(){
  if(cat){
  delete[] cat; // can only use delete on an address
}
}

template<typename T>
void stack<T>::pop(){_size--;}

template<typename T>
void stack<T>::push(T x){
  if(_size == capacity){
    doubleCap();
  }
  cat[_size] = x; // can also do cat[_size++] = x
  _size++;
}
template<typename T>
void stack<T>::dup_Arr(T*& to, T* from, unsigned int N){
to = new T[N];
for(int i = 0; i < N; i++){
  to[i] = from[i];
}
}

template<typename T>
stack<T>::stack(const stack<T>& other){
  dup_Arr(cat,other.cat,other.capacity);
  capacity = other.capacity;
  _size = other._size;
}

template<typename T>
stack<T>& stack<T>::operator=(const stack<T>& other){
  if(this == &other){
    return *this;
  }
  clear();
  dup_Arr(cat,other.cat,other.capacity);
  _size = other._size;
  capacity = other.capacity;
  return *this;
}
template<typename T>
void stack<T>::doubleCap(){
  T* tmp = new T[2*capacity];
  for(int i = 0; i < capacity;i++){
    tmp[i] = cat[i];
  }
  delete[] cat;
  cat = tmp;
  capacity *= 2;
}

template<typename T>
T stack<T>::peek(int j){
  assert(j >= 0 && j <= _size - 1); // valid ranges of J
  return cat[_size - 1 -j];
}

template<typename T>
unsigned int stack<T>:: size(){
  return _size;
}



void evaluate(stack<int>& numbers, stack<string>& symbols, stack<bool>& expressions){
  int num1, num2;
  num1 = numbers.top();
  numbers.pop();
  num2 = numbers.top();
  numbers.pop();
  if(symbols.top() == "<"){
    if(symbols.size() != 1){
      expressions.push(num2 > num1);
    }
    else
    expressions.push(num2 < num1);
  }
  else if(symbols.top() == ">"){
    if(symbols.size() != 1)
    expressions.push(num2 < num1);
    else
    expressions.push(num2 > num1);
  }
  else if(symbols.top() == ">="){
    if(symbols.size() != 1)
    expressions.push(!(num2 >= num1));
    else
    expressions.push(num2 >= num1);
  }
  else if(symbols.top() == "<="){
    if(symbols.size() != 1)
    expressions.push(!(num2 <= num1));
    else
    expressions.push(num2 <= num1);
  }
  else if(symbols.top() == "=="){
    if(symbols.size() != 1)
    expressions.push(!(num2 == num1));
    else
    expressions.push(num2 == num1);
  }
  else if(symbols.top() == "!="){
    if(symbols.size() != 1)
    expressions.push(!(num2 != num1));
    else
    expressions.push(num2 != num1);
  }
  symbols.pop();
  if(!symbols.empty())
  symbols.pop();
}



bool read_and_evaluate(istream& ins,bool yes){
  if(strchr("done",ins.peek()) != NULL){
    yes = false;
    exit(1);
  }
  const char decimal = '.';
  const char right_Parenthesis = ')';
  bool And;
  stack<int> numbers;
  stack<string> symbols;
  stack<bool> expressions;
  int number;
  string symbol;
  while(ins && ins.peek() != '\n'){
    if(isdigit(ins.peek()) || (ins.peek() == decimal)){
      ins >> number;
      // cout<<number<<endl;
      numbers.push(number);
    }
    else if(strchr("<><=>===!=",ins.peek()) != NULL){
      ins >> symbol;
      if(symbol[0] == '!' && symbol.length() > 2){
        // cout<<symbol<<endl;
        symbols.push("!");
        string a = symbol.substr(3,symbol.length() - 1);
        cout<<a<<endl;
        numbers.push(stoi(a));
      }
      else{
      // cout<<symbol<<endl;
      symbols.push(symbol);
    }
    }
    else if(ins.peek() == right_Parenthesis){
      ins.ignore();
      evaluate(numbers,symbols,expressions);
    }
    else if(strchr("&&",ins.peek()) != NULL){
      ins.ignore();
      And = true;
    }
    else if(strchr("||",ins.peek()) != NULL){
      ins.ignore();
      And = false;
    }
    else{
      ins.ignore();
    }
  }
  if(And){
    for(int i = 0; i < expressions.size(); i++){
      if(expressions.peek(i) == false) return false;
    }
    return true;
  }
  else if(!And){
    for(int i = 0; i < expressions.size(); i++){
      if(expressions.peek(i) == true) return true;
    }
    return false;
  }
  else{
    return expressions.top();
  }
}


int main(){
  bool yes = true;
  while(yes){
  cout<<"enter a fully parenthesized arithmetic expression: (done when done)"<<endl;
  bool answer = read_and_evaluate(cin,yes);
  if(answer){
      cout<< "that evaluates to true"<<endl;
  }
  else{
    cout<< "that evaluates to false"<<endl;
  }
  cin.ignore();
}
}
