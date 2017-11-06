//Usecase 1: Colgate toothpaste: Quantity-1 Price-10 Total-10

#include <iostream>

class ShoppingCartTest
{
	int colgateStock;
	public:
		ShoppingCartTest()
		{
			colgateStock=0;
		}
		ShoppingCartTest(int colgateStock)
		{
			this->colgateStock=colgateStock;
		}
		void errMessage(const char errMsg[])
		{
			std::cout<<errMsg<<std::endl;
		}
		void bill(int quantity,int price)
		{
			std::cout<<"Colgate : "<<"Quantity = "<<quantity<<" Price = "<<price<<" Total = "<<quantity*price<<std::endl;
		}
		void buyColgate(int quantity)
		{
			if(colgateStock<quantity)
				errMessage("Insufficient colgate toothpaste stock available.");
			else
			{
				colgateStock-=quantity;
				bill(quantity,10);
			}
		}
		
};

int main()
{
	ShoppingCartTest test1(5);
	test1.buyColgate(1);
	return 0;	
}
