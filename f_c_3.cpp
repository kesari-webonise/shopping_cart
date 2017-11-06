//No Closeup toothpaste available

#include <iostream>

class ShoppingCartTest
{
	int closeupStock;
	public:
		ShoppingCartTest()
		{
			closeupStock=0;
		}
		ShoppingCartTest(int closeupStock)
		{
			this->closeupStock=closeupStock;
		}
		void errMessage(const char errMsg[])
		{
			std::cout<<errMsg<<std::endl;
		}
		void closeupToothpasteOutOfStock()
		{
			if(closeupStock<1)
				errMessage("Closeup toothpastes are out of stock");
		}
		
};

int main()
{
	ShoppingCartTest test1(0);
	test1.closeupToothpasteOutOfStock();
	return 0;	
}
