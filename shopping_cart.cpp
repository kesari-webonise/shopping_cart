//Shopping cart application
using namespace std;

#include<iostream>
#include<cstdlib>
#include<cstring>

class Product
{
	char productName[20];
	int productStock;
	int productPrice;
	char offer;

	public:
	

	void addProduct(const char productName[],int productStock,int productPrice,char offer)
	{
		strcpy(this->productName,productName);
		this->productStock=productStock;
		this->productPrice=productPrice;
		this->offer=offer;
	}
	void productDetails()
	{
		cout<<"Product Name : "<<productName<<std::endl;
		std::cout<<"Product Stock:"<<productStock<<std::endl;
		std::cout<<"Product price:"<<productPrice<<" Rs."<<std::endl;
		std::cout<<"Offer :"<<offer<<std::endl;
	}
	int availableStock()
	{
		return productStock;
	}
	void reduceStock(int count)
	{
		productStock-=count;
	}
	void increaseStock(int count)
	{
		productStock+=count;
	}
	int getPrice()
	{
		return productPrice;
	}
	char hasOffer()
	{
		return offer;
	}
	char* getProductName()
	{
		return productName;
	}
};

class Cart
{
	char nameOfItemBuyed[2][20];
	int noOfItemBuyed[2];
	int cstatus;
	int total; 

	public:
		Cart()
		{
			strcpy(nameOfItemBuyed[0],"");
			strcpy(nameOfItemBuyed[1],"");
			noOfItemBuyed[0]=0;
			noOfItemBuyed[1]=0;
			cstatus=0;
			total=0;
		}
		void addToCart(Product *product,int noItems)
		{
			if(strcmp(product->getProductName(),"Colgate")==0)
			{
				strcpy(nameOfItemBuyed[0],"Colgate");
				noOfItemBuyed[0]+=noItems;
			} else {
				strcpy(nameOfItemBuyed[1],"Closeup");
				noOfItemBuyed[1]+=noItems;
			}
			cstatus=1;
			product->reduceStock(noItems);
		}
		void removeFromCart(Product *colgate,Product *closeup)
		{
			char choice;
			int noItem;

			if(noOfItemBuyed[0]!=0)
			{
				cout<<"Would you like to remove colgate (Y/N):";
				cin>>choice;
				if(choice=='Y')
				{
					cout<<"Enter no of items you want to remove :";
					cin>>noItem;
					if(noItem>noOfItemBuyed[0])
						cout<<"ERROR: Not these many items actually present. Try again"<<endl;
					else{
						noOfItemBuyed[0]-=noItem;
						colgate->increaseStock(noItem);	
						cout<<"Items removed successfully"<<endl;			
					}
					
				}
			}
			if(noOfItemBuyed[1]!=0)
			{
				cout<<"Would you like to remove closeup (Y/N):";
				cin>>choice;
				if(choice=='Y')
				{
					cout<<"Enter no of items you want to remove :";
					cin>>noItem;
					if(noItem>noOfItemBuyed[1])
						cout<<"ERROR: Not these many items actually present. Try again"<<endl;
					else{
						noOfItemBuyed[1]-=noItem;
						closeup->increaseStock(noItem);	
						cout<<"Items removed successfully"<<endl;				
					}
					
				}
			}	
			if(noOfItemBuyed[0]==0)	
				strcpy(nameOfItemBuyed[0],"");
			if(noOfItemBuyed[1]==0)	
				strcpy(nameOfItemBuyed[1],"");
			if(noOfItemBuyed[0]==0 && noOfItemBuyed[1]==0)
				cstatus=0;	
		}
		int cartStatus()
		{
			return cstatus;
		}
		void cartSummary()
		{
			if(strcmp(nameOfItemBuyed[0],"")!=0)
			{
				cout<<"Item name : "<<nameOfItemBuyed[0]<<endl;
				cout<<"No of items : "<<noOfItemBuyed[0]<<endl;
			}
			if(strcmp(nameOfItemBuyed[1],"")!=0)
			{
				cout<<"Item name : "<<nameOfItemBuyed[1]<<endl;
				cout<<"No of items : "<<noOfItemBuyed[1]<<endl;
			}
		}
		void bill(Product *colgate,Product *closeup)
		{
			cout<<"Item name\t Item quantity\t Total"<<endl;
			cout<<"--------------------------------------"<<endl;

			if(strcmp(nameOfItemBuyed[0],"")!=0)
			{
				if(colgate->hasOffer()=='y' &&noOfItemBuyed[0]!=1)
				{
					total+=colgate->getPrice()*(noOfItemBuyed[0]/2)*2;
					cout<<nameOfItemBuyed[0]<<" \t"<<(noOfItemBuyed[0]/2)*3<<" \t"<<colgate->getPrice()*(noOfItemBuyed[0]/2)*2<<endl;
				} else {
					total+=colgate->getPrice()*noOfItemBuyed[0];
					cout<<nameOfItemBuyed[0]<<" \t"<<noOfItemBuyed[0]<<" \t"<<colgate->getPrice()*noOfItemBuyed[0]<<endl;
				}
			}
			if(strcmp(nameOfItemBuyed[1],"")!=0)
			{
				if(closeup->hasOffer()=='y' &&noOfItemBuyed[1]!=1)
				{
					total+=closeup->getPrice()*(noOfItemBuyed[1]/2)*2;
					cout<<nameOfItemBuyed[1]<<" \t"<<(noOfItemBuyed[1]/2)*3<<" \t"<<closeup->getPrice()*(noOfItemBuyed[1]/2)*2<<endl;
				} else {
					total+=closeup->getPrice()*noOfItemBuyed[1];
					cout<<nameOfItemBuyed[1]<<" \t";
					cout<<noOfItemBuyed[1]<<" \t";
					cout<<closeup->getPrice()*noOfItemBuyed[1]<<endl;
				}
			}
			cout<<"Total : "<<total<<endl;
			cout<<"Thanks for visiting.Visit again"<<endl;
		}
};

int main()
{
	int usrChoice,itemChoice,noItems;
	Product colgate;
	Product closeup;
	Cart c;

	colgate.addProduct("Colgate",10,10,'y');
	closeup.addProduct("Closeup",10,15,'n');

	while(1)
	{
	cout<<"*****************************Welcome***************************************"<<endl;
	cout<<endl;
	cout<<"*****************************Offers***************************************"<<endl;
	cout<<"Colgate By 2 get 1 offer"<<endl;
	cout<<endl;
	cout<<"***************************************Products Details***************************************"<<endl;
	colgate.productDetails();
	closeup.productDetails();
	cout<<endl;

	if(colgate.availableStock()>0 || closeup.availableStock()>0)
	{

		std::cout<<"***************************************Start buying***************************************"<<std::endl;
		std::cout<<"1. Add item to cart"<<std::endl;
		std::cout<<"2. Delete item from cart"<<std::endl;
		std::cout<<"3. Checkout"<<std::endl;
		std::cout<<"What you want to do - "<<std::endl;
		std::cin>>usrChoice;
	
		switch(usrChoice)
		{
			case 1: 
			{	
				cout<<"1. Colgate toothpaste"<<endl;
				cout<<"2. Closeup toothpaste"<<endl;
				cout<"What you would like to buy - ";
				cin>>itemChoice;
				if(itemChoice>3 && itemChoice<1)
					cout<<"ERROR::You didn't select product"<<endl;
				else
				{
					cout<<"Enter no of items you want :";
					cin>>noItems;
					if(noItems<1)
						cout<<"ERROR::Invalide no of items";
					else if(itemChoice==1 && colgate.availableStock()<noItems) 	
						cout<<"ERROR::Insufficient number of colgate items. Please check stock";	
					else if(closeup.availableStock()<noItems) 
						cout<<"ERROR::Insufficient number of closeup items. Please check stock";
					else
					{
						if(itemChoice==1)
							c.addToCart(&colgate,noItems);
						else
							c.addToCart(&closeup,noItems);
						cout<<"Item added to cart successfully!!!"<<endl;				
					}
				}
			}
			break;
			
			case 2: 
			{
				if(c.cartStatus()==0)
					cout<<"ERROR: Nothing there in cart"<<endl;
				else
				{
					cout<<"Your cart status"<<endl;
					c.cartSummary();
					c.removeFromCart(&colgate,&closeup);
				}
			}
				break;
			case 3: 
			{
				cout<<"***************************************Your Cart***************************************"<<endl;
				c.cartSummary();
				c.bill(&colgate,&closeup);
				exit(0);	
			}				
			default: cout<<"You may have entered wrong choice!"<<endl;
		}
	}
	else
	{
		cout<<"***************ERROR::No products available. Sorry****************"<<endl;
		break;
	}
	}	
	return 0;
}


