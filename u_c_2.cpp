//Usecase 2: Colgate toothpaste: Quantity-10 Price-10 Total-100

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
		void bill(int quantity,int price)
		{
			std::cout<<"Quantity = "<<quantity<<" Price = "<<price<<" Total = "<<quantity*price<<std::endl;
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
	ShoppingCartTest test1(50);
	test1.buyColgate(10);
	return 0;	
}
