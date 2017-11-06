//Usecase 3: Colgate toothpaste: Quantity-10 Price-5 Colgate Total-50
//	     Closeup toothpaste: Quantity-15 Price-2 Closeup Total-30
//						       Final Total-80
#include <iostream>

class ShoppingCartTest
{
	int colgateStock;
	int closeupStock;

	public:
		ShoppingCartTest(int colgateStock,int closeupStock)
		{
			this->colgateStock=colgateStock;
			this->closeupStock=closeupStock;
		}
		void errMessage(const char errMsg[])
		{
			std::cout<<errMsg<<std::endl;
		}
		void bill(int colgateQnt,int colgatePrice,int closeupQnt, int closeupPrice)
		{
			std::cout<<"Colgate : "<<" Quantity = "<<colgateQnt<<" Price = "<<colgatePrice<<" Colgate Total = "<<colgateQnt*colgatePrice<<std::endl;
			std::cout<<"Closeup : "<<" Quantity = "<<closeupQnt<<" Price = "<<closeupPrice<<" Closeup Total = "<<closeupQnt*closeupPrice<<std::endl;
			std::cout<<"Total bill : "<<colgateQnt*colgatePrice+closeupQnt*closeupPrice<<std::endl;
		}
		void buyColgateCloseup(int colgateQuantity,int closeupQuantity)
		{
			if(colgateStock<colgateQuantity)
				errMessage("Insufficient colgate toothpaste stock available.");
			else if(closeupStock<closeupQuantity)
				errMessage("Insufficient closeup toothpaste stock available.");
			else
			{
				colgateStock-=colgateQuantity;
				closeupStock-=closeupQuantity;
				bill(colgateQuantity,5,closeupQuantity,2);
			}
		}		
};

int main()
{
	ShoppingCartTest test1(50,20);
	test1.buyColgateCloseup(10,15);
	return 0;	
}
