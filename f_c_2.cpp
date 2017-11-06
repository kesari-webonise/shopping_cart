//No Colgate toothpaste available

#include <iostream>

class ShoppingCartTest
{
	int colgateStock;
	public:
		/*ShoppingCartTest()
		{
			colgateStock=0;
		}*/
		ShoppingCartTest(int colgateStock)
		{
			this->colgateStock=colgateStock;
		}
		void errMessage(const char errMsg[])
		{
			std::cout<<errMsg<<std::endl;
		}
		void colgateToothpasteOutOfStock()
		{
			if(colgateStock<1)
				errMessage("Colgate toothpastes are out of stock");
		}
		
};

int main()
{
	//ShoppingCartTest tst1;
	//tst1.colgateToothpasteOutOfStock();
	ShoppingCartTest test2(0);
	test2.colgateToothpasteOutOfStock();
	return 0;	
}
