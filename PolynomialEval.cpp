#include<iostream>
using namespace std;

   class node{
   private:
     int coefficient;
     int power;
     node* next;
   public:
     node(){coefficient = 0; power = 0; next = nullptr;}
     node(int c){coefficient = c; power = 0; next = nullptr;}
     node(int c, int p, node* n = nullptr):coefficient(c),power(p),next(n){}
     node(const node& a){coefficient = a.coefficient; power = a.power; next = a.next;}
     void setNext(node* next){this -> next  = next;}
     node* get_next(){return next;}
     int get_coefficient(){return coefficient;}
     int get_power(){return power;}
     void set_coefficient(int data){coefficient = data;}
     void set_power(int data){power = data;}
     void print(){
       cout<<coefficient<<"x^"<<power;
       if(this -> get_next() != nullptr){
         if(this -> get_next() -> get_coefficient() > 0){
          cout<< "+";
     }
   }
   else
   cout<<endl;
   }
     node operator+(const node& other){
       if(other.power == power)
         coefficient = coefficient + other.coefficient;
         return *this;
     }
     node operator-(const node& other){
       if(other.power == power)
         coefficient = coefficient - other.coefficient;
         return *this;
     }
     node operator*(const node& other){coefficient = coefficient *  other.coefficient;
       if(power == 0){power = 1;}
       power = power * other.power;
       return *this;}

   };
   node* add(node* head, node* head2){
     node* new_head = nullptr;
     node* new_pcurr;
     node* pcurr = head;
     node* pcurr2 = head2;
     int C;
     while(pcurr != nullptr){
       pcurr2 = head2;
       while(pcurr2 != nullptr){
         if(pcurr -> get_power() == pcurr2 -> get_power()){
           C = pcurr -> get_coefficient() + pcurr2 -> get_coefficient();
           if(new_head == nullptr){
             new_head = new node(C,pcurr2 -> get_power());
             new_pcurr = new_head;
           }
           else{
             new_pcurr -> setNext(new node(C,pcurr2 -> get_power()));
             new_pcurr = new_pcurr -> get_next();
           }
         }
         pcurr2 = pcurr2 -> get_next();
       }
       pcurr = pcurr -> get_next();
     }
     pcurr = head;
     pcurr2 = head2;
     bool add = false;
     while(pcurr != nullptr){
      pcurr2 = head2;
      add = true;
       while(pcurr2 != nullptr){
         if(pcurr -> get_power() == pcurr2 -> get_power()){
           add = false;
         }
          pcurr2 = pcurr2 -> get_next();
       }
       if(add){
         if(new_head == nullptr){
           new_head = new node(pcurr -> get_coefficient(),pcurr -> get_power());
           new_pcurr = new_head;
         }
         else{
           new_pcurr -> setNext(new node(pcurr -> get_coefficient(),pcurr -> get_power()));
           new_pcurr = new_pcurr -> get_next();
         }
       }
       pcurr = pcurr -> get_next();
     }
     pcurr = head;
     pcurr2 = head2;
     while(pcurr2 != nullptr){
      pcurr = head;
      add = true;
       while(pcurr != nullptr){
         if(pcurr -> get_power() == pcurr2 -> get_power()){
           add = false;
         }
          pcurr = pcurr -> get_next();
       }
       if(add){
         if(new_head == nullptr){
           new_head = new node(pcurr -> get_coefficient(),pcurr -> get_power());
           new_pcurr = new_head;
         }
         else{ new_pcurr -> setNext(new node(pcurr2 -> get_coefficient(),pcurr2 -> get_power()));
          new_pcurr = new_pcurr -> get_next();
        }
       }
       pcurr2 = pcurr2 -> get_next();
     }
     return new_head;
   }

   node* subtract(node* head, node* head2){
     node* new_head = nullptr;
     node* new_pcurr;
     node* pcurr = head;
     node* pcurr2 = head2;
     int C;
     while(pcurr != nullptr){
       pcurr2 = head2;
       while(pcurr2 != nullptr){
         if(pcurr -> get_power() == pcurr2 -> get_power()){
           C = pcurr -> get_coefficient() - pcurr2 -> get_coefficient();
           if(new_head == nullptr){
             new_head = new node(C,pcurr2 -> get_power());
             new_pcurr = new_head;
           }
           else{
             new_pcurr -> setNext(new node(C,pcurr2 -> get_power()));
             new_pcurr = new_pcurr -> get_next();
           }
         }
         pcurr2 = pcurr2 -> get_next();
       }
       pcurr = pcurr -> get_next();
     }
     pcurr = head;
     pcurr2 = head2;
     bool add = false;
     while(pcurr != nullptr){
      pcurr2 = head2;
      add = true;
       while(pcurr2 != nullptr){
         if(pcurr -> get_power() == pcurr2 -> get_power()){
           add = false;
         }
          pcurr2 = pcurr2 -> get_next();
       }
       if(add){
         if(new_head == nullptr){
           new_head = new node(pcurr -> get_coefficient(),pcurr -> get_power());
           new_pcurr = new_head;
         }
         else{
           new_pcurr -> setNext(new node(pcurr -> get_coefficient(),pcurr -> get_power()));
           new_pcurr = new_pcurr -> get_next();
         }
       }
       pcurr = pcurr -> get_next();
     }
     pcurr = head;
     pcurr2 = head2;
     while(pcurr2 != nullptr){
      pcurr = head;
      add = true;
       while(pcurr != nullptr){
         if(pcurr -> get_power() == pcurr2 -> get_power()){
           add = false;
         }
          pcurr = pcurr -> get_next();
       }
       if(add){
         if(new_head == nullptr){
           new_head = new node(pcurr -> get_coefficient() * -1,pcurr -> get_power());
           new_pcurr = new_head;
         }
         else{
           new_pcurr -> setNext(new node(pcurr2 -> get_coefficient() * -1,pcurr2 -> get_power()));
           new_pcurr = new_pcurr -> get_next();
         }
       }
       pcurr2 = pcurr2 -> get_next();
     }
     return new_head;
   }

   node* multiply(node* head, node* head2){
     node* new_head = nullptr;
     node* new_pcurr;
     node* pcurr = head;
     node* pcurr2 = head2;
     int C;
     int P;
     while(pcurr != nullptr){
       pcurr2 = head2;
       while(pcurr2 != nullptr){
         C = pcurr -> get_coefficient();
         P = pcurr -> get_power();
           C *= pcurr2 -> get_coefficient();
           P += pcurr2 -> get_power();
           if(new_head == nullptr){
             new_head = new node(C,P);
             new_pcurr = new_head;
           }
           else{
             new_pcurr -> setNext(new node(C,P));
             new_pcurr = new_pcurr -> get_next();
           }
           pcurr2 = pcurr2 -> get_next();
         }
       pcurr = pcurr -> get_next();
     }
     return new_head;
   }

   void erase(node* head){
   if(head){
   node* tmp = head;
   head = head -> get_next();
   delete tmp;
   erase(head);
   }
   }


int main(){
node* head = nullptr;
node* pcurr =nullptr;
string input;
int coefficient;
int power;
string input2;
int coefficient2;
int power2;
node* head2 = nullptr;
node* pcurr2 =nullptr;





cout<<"do you want to enter a polynomial (y/n)"<<endl;
cin>>input;
while(input  != "n"){
cout<<"enter the coefficient"<<endl;
cin>>coefficient;
cout<<"enter the power of x"<<endl;
cin>>power;
if(head == nullptr){
  head = new node(coefficient,power);
  pcurr = head;
}
else{
  pcurr -> setNext(new node(coefficient,power));
  pcurr = pcurr -> get_next();
}
cout<<"do you want to enter a polynomial (y/n)"<<endl;
cin>>input;
}
pcurr = head;
while(pcurr){
  pcurr -> print();
  pcurr = pcurr -> get_next();
}




cout<<"do you want to enter a polynomial (y/n)"<<endl;
cin>>input2;
while(input2  != "n"){
cout<<"enter the coefficient"<<endl;
cin>>coefficient2;
cout<<"enter the power of x"<<endl;
cin>>power2;
if(head2 == nullptr){
  head2 = new node(coefficient2,power2);
  pcurr2 = head2;
}
else{
  pcurr2 -> setNext(new node(coefficient2,power2));
  pcurr2 = pcurr2 -> get_next();
}
cout<<"do you want to enter a polynomial (y/n)"<<endl;
cin>>input2;
}
pcurr2 = head2;
while(pcurr2){
  pcurr2 -> print();
  pcurr2 = pcurr2 -> get_next();
}
node* final_head = add(head,head2);
node* new_pcurr = final_head;
cout<<"polynomials added"<<endl;
while(new_pcurr){
  new_pcurr -> print();
  new_pcurr = new_pcurr -> get_next();
}

node* final2_head = subtract(head,head2);
node* new_pcurr2 = final2_head;
cout<<"polynomials subtracted"<<endl;
while(new_pcurr2){
  new_pcurr2 -> print();
  new_pcurr2 = new_pcurr2 -> get_next();
}

node* final3_head = multiply(head,head2);
node* new_pcurr3 = final3_head;
cout<<"polynomials multiplied"<<endl;
while(new_pcurr3){
  new_pcurr3 -> print();
  new_pcurr3 = new_pcurr3 -> get_next();
}



erase(head);
erase(head2);
if(final_head){
  erase(final_head);
}
if(final2_head){
  erase(final2_head);
}
if(final3_head){
  erase(final3_head);
}
}

/*
If you enter 1x^5+2x^3 && 4x^5-3x^4 you get
polynomials added
5x^5+2x^3-3x^4
polynomials subtracted
-3x^5+2x^3+3x^4
polynomials subtracted
4x^10-3x^9+8x^8-6x^7

*/
