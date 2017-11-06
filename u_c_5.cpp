//Usecase 5: Special offer for Colgate toothpaste: Buy 2 get 1 and Closeup

#include <iostream>

class ShoppingCartTest
{
	int colgateStock;
	int closeupStock;
	int finalBill;
	public:
		ShoppingCartTest(int colgateStock,int closeupStock)
		{
			finalBill=0;
			this->colgateStock=colgateStock;
			this->closeupStock=closeupStock;
		}
		void errMessage(const char errMsg[])
		{
			std::cout<<errMsg<<std::endl;
		}
		void billColgate(int actualQuantity,int totQuantity,int price)
		{
			std::cout<<"Colgate : "<<" Total Quantity = "<<totQuantity<<" Price = "<<price<<" Total = "<<actualQuantity*price<<std::endl;
			finalBill=actualQuantity*price;
		}
		void billCloseup(int Quantity,int price)
		{
			std::cout<<"Closeup : "<<"Quantity = "<<Quantity<<" Price = "<<price<<" Total = "<<Quantity*price<<std::endl;
			finalBill+=Quantity*price;
		}
		void buyColgateInSpecialOffer(int quantity)
		{
			if(quantity==1 && colgateStock>=quantity)
			{
				colgateStock-=1;
				billColgate(1,1,10);
			}
			else if(colgateStock<(quantity/2+2))
				errMessage("Insufficient colgate toothpaste stock available.");
			else
			{
				colgateStock-=(quantity/2+2);
				billColgate((quantity/2)*2,(quantity/2*3),10);
			}
		}
		void buyCloseup(int quantity)
		{
			if(closeupStock<quantity)
				errMessage("Insufficient closeup toothpaste stock available.");
			else
			{	
				closeupStock-=quantity;
				billCloseup(quantity,15);
			}
		}
		void totalBill()
		{
			std::cout<<"Total bill : "<<finalBill<<std::endl;
		}
};

int main()
{
	ShoppingCartTest test1(50,20);
	test1.buyColgateInSpecialOffer(3);
	test1.buyCloseup(2);
	test1.totalBill();
	return 0;	
}
