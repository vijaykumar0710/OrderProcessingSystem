#include<bits/stdc++.h>
using namespace std;

class Order{
    public:
    int OrderId;
    string customer_name;
    string OrderDetails;
    
    Order(int id,const string& name,const string& details):OrderId(id),customer_name(name),OrderDetails(details){}
};

class OrderProcessingSystem{
    private:
    queue<Order> OrderQueue;
    int OrderCounter;

public:
OrderProcessingSystem():OrderCounter(1){}

void placeOrder(const string& customer_name,const string& OrderDetails);
void processOrder();
void displayPendingOrder();
};

void OrderProcessingSystem::placeOrder(const string& customer_name,const string& OrderDetails){
Order newOrder(OrderCounter++,customer_name,OrderDetails);
OrderQueue.push(newOrder);
cout<<"Order Placed: "<<newOrder.OrderId<<" by "<<newOrder.customer_name<<endl;
}

void OrderProcessingSystem::processOrder(){
    if(!OrderQueue.empty()){
    Order currentOrder=OrderQueue.front();
    OrderQueue.pop();
    cout<<"Processing Order: "<<currentOrder.OrderId<<" by "<<currentOrder.customer_name<<endl;   
    } else{
        cout<<"No Order to Process."<<endl;
    }
}

void OrderProcessingSystem::displayPendingOrder(){
if(OrderQueue.empty()){
    cout<<"No pending Orders."<<endl;
} else{
    queue<Order> tempQueue=OrderQueue;
    cout<<"Pending Orders: "<<endl;
    while(!tempQueue.empty()){
        Order currentOrder=tempQueue.front();
        tempQueue.pop();
        cout<<"OrderId: "<<currentOrder.OrderId<<", customer: "<<currentOrder.customer_name<<", Details: "<<currentOrder.OrderDetails<<endl;
    }
  }
}

int main(){
OrderProcessingSystem ops;

ops.placeOrder("Vikram", "murga chawal");
ops.placeOrder("Vijay","daal bhaat bhujia");
ops.placeOrder("SM", "saag bhaat");

ops.displayPendingOrder();

ops.processOrder();
ops.displayPendingOrder();

ops.processOrder();
ops.processOrder();
ops.processOrder();
ops.displayPendingOrder();

return 0;
}