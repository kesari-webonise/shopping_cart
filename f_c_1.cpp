//No Toothpastes are available

#include <iostream>

class ShoppingCartTest
{
	int toothpasteStock;
	public:
		ShoppingCartTest()
		{
			toothpasteStock=0;
		}
		ShoppingCartTest(int toothpasteStock)
		{
			this->toothpasteStock=toothpasteStock;
		}
		void errMessage(const char errMsg[])
		{
			std::cout<<errMsg<<std::endl;
		}
		void toothpastesOutOfStock()
		{
			if(toothpasteStock<1)
				errMessage("Toothpastes are out of stock");
		}
		
};

int main()
{
	ShoppingCartTest test1;
	test1.toothpastesOutOfStock();
	ShoppingCartTest test2(2);
	test2.toothpastesOutOfStock();
	return 0;	
}
