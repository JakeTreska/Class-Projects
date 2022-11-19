#include<iostream>
using namespace std;


class binaryTree{
struct node{
  string data;
  node* left;
  node* right;
  node(string d = "", node* l = nullptr, node* r = nullptr):data(d),left(l),right(r){}
};
void clear(node*& p){
  if(p == nullptr){
    return;
  }
  clear(p -> left);
  clear(p -> right);
  delete p;
}
node* root;
void DF(node* p){
  if (p == nullptr) return;
  cout<<p -> data<<endl;
  DF(p -> left);
  DF(p -> right);
}
int string_to_int(string s){
  int answer = 0;
  int count = 1;
  for(int i = s.length() - 1; i >= 0; i--){
    answer += (s[i] - '0') * count;
    count *= 10;
  }
  return answer;
}
public:
  binaryTree(){
    root = new node();
  }
  ~binaryTree(){
    clear(root);
  }
  void print(){
    DF(root);
  }
  void set_data(string info){
    root -> data  = info;
  }

  void create(){
    root -> data = "*";
    // root -> left = new node("22");
    // root -> right = new node("10");
    root -> left = new node("+",new node("3"),new node("7"));
    root -> right = new node("14");
  }

  int evaluate(node* p,int& total){
    if(p == nullptr){
      cout<<"found null"<<endl;
      return 1;
    }
    if(p -> data != "*" && p -> data != "+"){
      return string_to_int(p -> data);
    }
    else{
      if(p -> data == "+"){
        int num1 = evaluate( p -> left,total);
        int num2 = evaluate( p -> right,total);
         total = num1 + num2;
         return total;
       }
      if (p -> data == "*"){
        int num1 = evaluate( p -> left,total);
        int num2 = evaluate( p -> right,total);
        total = num1 * num2;
        return total;
      }
    }
  }
  int combine(){
    int total = 0;
    evaluate(root,total);
    cout<<total<<endl;
  }
};


int main(){
  binaryTree A;
  A.create();
  A.print();
  A.combine();
}
