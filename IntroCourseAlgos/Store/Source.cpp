#include <iostream>
#include <vector>
#include <string>
#include <limits>

using std::string;

class My_cart
{
private:
	string productName;
	double productPrice;
	unsigned long long int productCode;
	int amount;
public:
	void setProductName(string name)
	{
		productName = name;
	}

	void setProductCode(unsigned long long int code)
	{
		if (code > 0)
			productCode = code;
		else
			std::cout << "Code must be possitive value! \n";
	}

	void setProductPrice(double price)
	{
		if (price > 0)
			productPrice = price;
		else
			std::cout << "Price must be possitive value! \n";
	}

	void setAmount(int howmany)
	{
		if (howmany > 0)
			amount = howmany;
		else
			std::cout << "Amount must be possitive value! \n";
	}

	string getProductName()
	{
		return productName;
	}

	unsigned long long int getProductCode()
	{
		return productCode;
	}

	double getProductPrice()
	{
		return productPrice;
	}

	int getAmount()
	{
		return amount;
	}

	double cashier(My_cart& product)
	{
		double result = amount*(product.getProductPrice());
		return result;
	}

	My_cart() {}
	My_cart(string productname, double productprice, unsigned long long int code, int amounts)
		:productName(productname), productPrice(productprice), productCode(code), amount(amounts)
	{
		if (productPrice < 0 || amount < 0)
			std::cout << "Invalid data! \n";
		productPrice = 0.0;
		amount = 0;
	}
	~My_cart()
	{
		
	};
	

};

void fillCart(std::vector<My_cart>&carts)
{
	string pName;
	double pPrice;
	unsigned long long int pCode;
	int amounts;

	std::cout << "Enter productname, productprice, productcode and amount: ";
	std::cin >> pName;
	
	while (!(std::cin >> pPrice))
	{
		std::cout << "Price must be a number.Enter new Price. \n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	while (!(std::cin >> pCode))
	{
		std::cout << "Code must be a number.Enter new Code. \n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	while (!(std::cin >> amounts))
	{
		std::cout << "Amount must be a number.Enter new Amount. \n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
		
		if (pPrice == 0.0 || amounts == 0)
		{
			std::cout << "Bezsmislena pokupka ! \n";
		}
		else
		{
			My_cart cart;
			cart.setProductName(pName);
			cart.setProductPrice(pPrice);
			cart.setProductCode(pCode);
			cart.setAmount(amounts);
			carts.push_back(cart);
		}

}

void printCart(std::vector<My_cart>&cart)
{
	int size = cart.size();
	double TOTAL = 0;
	if (size > 0)
	{
		std::cout << "\n		---V-------Kolichkata------ima-----\n";
		std::cout << "		-----------------------------------\n";
		for (int i = 0; i < size; i++)
		{
			std::cout <<"		"<< cart[i].getProductName() << " x " << cart[i].getAmount() << "	cost/s: " << cart[i].cashier(cart[i]) << " $\n";
			TOTAL += cart[i].cashier(cart[i]);
		}

		std::cout << "		-----------------------------------" << "\n" << "		Duljite obshto: " << TOTAL << " para \n\n";
	}
	else
	{
		std::cout << "Kolichkata vi e prazna!Kupete neshto .\n\n\n";
	}
}

int main()
{
	std::vector <My_cart> cart;

	char command;
	bool done = false;
	
	do {
		std::cout << "Press [Q]uit [B]uy [S]how list   ==> ";
		std::cin >> command;
		switch (command) {
		
		case 'S':
		case 's':
			printCart(cart);
			break;
		case 'B':
		case 'b':
			fillCart(cart);
			break;
		case 'Q':
		case 'q':
			std::cout << "Blagodarim vi che izbrahte nas !\n\n\n";
			done = true;
			break;
		}
	} while (!done);

	return 0;
}