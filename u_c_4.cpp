//Usecase 4: Special offer for Colgate toothpaste: Buy 2 get 1

#include <iostream>

class ShoppingCartTest
{
	int colgateStock;
	public:
		ShoppingCartTest(int colgateStock)
		{
			this->colgateStock=colgateStock;
		}
		void errMessage(const char errMsg[])
		{
			std::cout<<errMsg<<std::endl;
		}
		void bill(int actualQuantity,int totQuantity,int price)
		{
			std::cout<<" Total Quantity = "<<totQuantity<<" Price = "<<price<<" Total = "<<actualQuantity*price<<std::endl;
		}
		void buyColgateInSpecialOffer(int quantity)
		{
			if(quantity==1 && colgateStock>=quantity)
			{
				colgateStock-=1;
				bill(1,1,10);
			}
			else if(colgateStock<(quantity/2+2))
				errMessage("Insufficient colgate toothpaste stock available.");
			else
			{
				colgateStock-=(quantity/2+2);
				bill((quantity/2)*2,(quantity/2*3),10);
			}
		}
		
};

int main()
{
	ShoppingCartTest test1(50);
	test1.buyColgateInSpecialOffer(3);
	return 0;	
}
