#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

class card{
public:
int size = 52;
card(){
  card_ = "NONE";
}
card(string suit, string number){
  this -> suit = suit;
  this -> number = number;
  card_  = suit + ", " + number;
}
string get_card() const{
  return card_;
}
string get_suit() const{
  return suit;
}
string get_num() const{
  return number;
}
card operator=(const card& other){
  if(this == &other){
    return *this;
  }
  else{
    card_ =other.card_;
    suit = other.suit;
    number = other.number;
  }
  return *this;
}
protected:
  string card_;
  string suit;
  string number;
};


class deck:public card{
public:
deck(){
  int count = 0;
  int type_count = 0;
  string arr[4] = {"Diamond","Heart","Club","Spade"};
  string type = arr[type_count];
  for(int i = 0; i < 4; i++){
    for(int j = 2; j <= 10; j++){
      pile.push_back(card(type,to_string(j)));
    }
    pile.push_back(card(type,"Jack"));
    pile.push_back(card(type,"Queen"));
    pile.push_back(card(type,"King"));
    pile.push_back(card(type,"Ace"));
    type_count += 1;
    type = arr[type_count];
  }
}
  void print(){
  for(int i = 0; i < size; i++){
    cout<<pile[i].get_card()<<endl;
  }
}
void shuffle(){
  srand(time(0));
  int random;
  for(int i = 0; i < size; i++){
    random = (rand() % 51) + 1;
    card a = pile[random];
    pile[random] = pile[i];
    pile[i] = a;
  }
}
void add(const card& a){
  size += 1;
  pile.push_back(a);
}
card remove(){
  card a = pile[0];
  pile.erase(pile.begin());
  size -= 1;
  return a;

}
void sort(vector<card> &pile,int size){
  vector<card> v;
  int counter = 0;
for(int i = 0; i < size; i++){
  if(pile[i].get_suit() == "Diamond"){
    v.push_back(pile[i]);
  }
}
for(int i = 0; i < size; i++){
  if(pile[i].get_suit() == "Heart"){
    v.push_back(pile[i]);
  }
}
for(int i = 0; i < size; i++){
  if(pile[i].get_suit() == "Spade"){
    v.push_back(pile[i]);
  }
}
for(int i = 0; i < size; i++){
  if(pile[i].get_suit() == "Club"){
    v.push_back(pile[i]);
  }
}
for(int i = 0; i < size; i++){
  pile[i] = v[i];
}
}
vector<card> pile;
};

class Hand:public deck{
public:
  Hand(){
    for(int i = 0; i < 5; i++){
      hand.push_back(card("none","none"));
      hand2.push_back(card("none","none"));
    }
  }
  Hand(deck& a){
    a.shuffle();
    for(int i = 0; i < 5; i++){
      hand.push_back(a.pile[0]);
      pile.erase(a.pile.begin());
      a.size -= 1;
      hand2.push_back(a.pile[0]);
      pile.erase(a.pile.begin());
      a.size -= 1;
    }
  }
  void print_hand(){
      int size_1_hand = hand.size();
    for(int i = 0; i < size_1_hand; i++){
      cout<<hand[i].get_card()<<endl;
    }
  }
  void print_hand2(){
    int size_1_hand2 = hand2.size();
    for(int i = 0; i < size_1_hand2; i++){
      cout<<hand2[i].get_card()<<endl;
    }
  }
  void shuffle(){
    srand(time(0));
    int random;
    int size_1_hand = hand.size();
    int size_1_hand2 = hand2.size();
    for(int i = 0; i < size_1_hand2; i++){
      random = (rand() % (size_1_hand2-1)) + 1;
      card a = hand2[random];
      hand2[random] = hand2[i];
      hand2[i] = a;
    }
    for(int i = 0; i < size_1_hand; i++){
      random = (rand() % (size_1_hand -1)) + 1;
      card a = hand[random];
      hand[random] = hand[i];
      hand[i] = a;
    }
  }
  void add_hand(const card& a){
    hand.push_back(a);
  }
  void add_hand2(const card& a){
    hand2.push_back(a);
  }
  card remove_hand(){
    card a = hand[0];
    hand.erase(hand.begin());
    return a;

  }
  card remove_hand2(){
    card a = hand2[0];
    hand2.erase(hand2.begin());
    return a;

  }
  void sort(){
    deck::sort(hand,hand.size());
    deck::sort(hand2,hand2.size());
  }
protected:
  vector<card> hand;
  vector<card> hand2;

};



int main(){
  deck a;
  // a.shuffle();
  // a.sort(a.pile,a.size);
  // a.print();
  // a.sort(a.pile,a.size);
  // a.print();
  // a.print();
  // a.shuffle();
  // a.print();
  // card f("Diamond","2");
  // card g("Diamond","5");
  // f = g;
  // cout<<f.get_card()<<endl;
  // a.print();
  Hand z(a);
  z.shuffle();
  cout<<"hand 1"<<endl;
  z.print_hand();
  cout<<"hand 2"<<endl;
  z.print_hand2();
  // cout<<"removing"<<endl;
  // z.remove_hand();
  // z.print_hand();
  // cout<<"sorted hand #1"<<endl;
  // z.sort();
  // z.print_hand();
  // cout<<"sorted hand #2"<<endl;
  // z.sort();
  // z.print_hand2();
}
