/*
Name: Mariam Ashraf Amin          ID:20200520
Name: Reem Ayman Abd El-fattah    ID:20200186
*/
//It is c++ program for online system shopping

#include <iostream>
#include <string>

using namespace std;

//Item Class
class Item
        {
        private:
            int ID;
            string name;
            int quantity;
            int price;
            static int id;
        public:
            //Default Constructor
            //it takes no parameter
            Item ()
            {
                ID=++id;
                name="UnKnown";
                quantity=0;
                price=0;
            }

            //Parameterized Constructor
            //it takes: string(item's name),int(item's quantity) and int(item's price) as parameter
            Item (string n,int q, int p)
            {
                ID=++id;
                name=n;
                quantity=q;
                price=p;
            }

            //Copy Constructor
            //it takes: rafarence constant Item(object from class Item) as parameter
            Item (const Item & item_obj)
            {
                ID=item_obj.ID;
                name=item_obj.name;
                quantity=item_obj.quantity;
                price=item_obj.price;
            }

            //ID getter Function to return Item's ID
            //it takes no parameter
            int get_ID ()
            {
                return ID;
            }

            //name setter Function to set Items' name
            //it takes string(name) as parameter
            void set_name (string n)
            {
                name=n;
            }
            //name getter Function to return Item's name
            //it takes no parameter
            string get_name ()
            {
                return name;
            }

            //quantity setter Function to set Items' quantity
            //it takes int(quantity) as parameter
            void set_quantity (int q)
            {
                quantity=q;
            }
            //quantity getter Function to return Item's quantity
            //it takes no parameter
            int get_quantity ()
            {
                return quantity;
            }

            //price setter Function to set Items' price
            //it takes int(price) as parameter
            void set_price (int p)
            {
                price=p;
            }
            //price getter Function to return Item's quantity
            //it takes no parameter
            int get_price ()
            {
                return price;
            }

            //Operator overloading for the == operators, to know if the item is exist or not
            //it takes reference constant Item as parameter
            bool operator == (const Item & item_obj)
            {
                bool status;
                if (name == item_obj.name)
                    status = true;
                else
                    status = false;

                return status;
            }

            //Operator overloading for the += operators, to increase item's quantity
            //it takes reference constant Item as parameter
            int operator += (const Item & item_obj)
            {
                quantity+=item_obj.quantity;

                return quantity;
            }

            //Operator overloading for the -= operators, to decrease item's quantity
            //it takes constant int(quantity) as parameter
            int operator -= (const int q)
            {
                quantity-=q;

                return quantity;
            }

            //Operator overloading for the >> operators for Item Class
            //it takes: reference istream and reference Item as parameter
            friend istream & operator >> (istream & is, Item & item_obj);

            //Operator overloading for the << operators for Item Class
            //it takes: reference ostream and reference Item as parameter
            friend ostream & operator << (ostream & os, const Item & item_obj);


        };

//Seller Class
class Seller
        {
        private:
            string name;
            string email;
            Item * items;
            int maxItems;
            int counter =0;
        public:
            //Parameterized Constructor
            //it takes: string(name) ,string(email) ,pointer to Item(array of items) as parameters
            Seller (string n, string e, int max_i)
            {
                name=n;
                email=e;
                maxItems=max_i;
                items = new Item[maxItems];
            }

            //Default Constructor
            //it takes no parameter
            Seller ()
            {
                name=" ";
                email=" ";
                maxItems=0;
                items = new Item[maxItems];
            }


            //Operator overloading for the >> operators for Seller Class
            //it takes: reference istream and reference Seller as parameter
            friend istream & operator >> (istream & is, Seller & seller_obj);

            //Operator overloading for the << operators for Seller Class
            //it takes: reference ostream and reference Seller as parameter
            friend ostream & operator << (ostream & os, const Seller & seller_obj);

            //Add An Item Function, it adds item if it isn't found
            //it takes reference Item as a parameter
            bool Add (Item & item_obj)
            {
                bool status= false;
                for (int i = 0; i < counter; i++)
                {
                    if (items[i]==item_obj)
                    {
                        items[i]+=item_obj;
                        status = true;
                        break;
                    }
                }
                if (status == false)
                {
                    if (counter<maxItems)
                    {
                        items[counter]=item_obj;
                        counter++;
                        status = true;
                    }
                    else
                        status= false;
                }

                return status;
            }

            //Sell An Item Function, it reduces the items' quantity
            //it takes: string(item's name) and int(quantity reduced)as parameters
            bool Sell (string n,int q)
            {
                bool status = false;
                for (int i = 0; i < counter; i++)
                {
                    if (items[i].get_name()==n)
                    {
                        status = true;
                        if (items[i].get_quantity()>=q)
                        {
                            items[i]-=q;
                        }
                        else
                        {
                            cout<<"There is only "<<items[i].get_quantity()<<" left for this item\n";
                        }
                        break;
                    }
                }
                return status;
            }

            //Print Items Function
            //it takes no parameters
            void Print ()
            {
                for (int i = 0; i < counter; i++)
                {
                    cout<<items[i];
                }
            }

            //Find an Item by ID Function
            //it takes: int(item's ID)
            Item Find_ID (int id)
            {
                for (int i = 0; i < counter; ++i)
                {
                    if (items[i].get_ID()==id)
                    {
                        return items[i];
                    }
                }
            }


            //Destructor, to delete dynamic array
            ~ Seller ()
            {
                delete [] items;
            }


        };

//id initialization
int Item::id=0;

//Operator overloading for the >> operators for Item Class(stand alone function)
istream & operator >> (istream & is, Item & item_obj)
{
    cout<<"Enter ItemInfo\n";
    cout<<"Enter Name: ";
    is>>item_obj.name;
    cout<<"Enter Quantity: ";
    is>>item_obj.quantity;
    cout<<"Enter Price: ";
    is>>item_obj.price;
    return is;
}

//Operator overloading for the << operators for Item Class(stand alone function)
ostream & operator << (ostream & os, const Item & item_obj)
{
    os<<"ItemInfo:\n";
    os<<"ID: "<<item_obj.ID<<endl;
    os<<"Name: "<<item_obj.name<<endl;
    os<<"Quantity: "<<item_obj.quantity<<endl;
    os<<"Price: "<<item_obj.price<<endl;

    return os;
}

//Operator overloading for the >> operators for Seller Class(stand alone function)
istream & operator >> (istream & is, Seller & seller_obj)
{
    cout<<"Please Enter Name: ";
    is>>seller_obj.name;
    cout<<"Please Enter Email: ";
    is>>seller_obj.email;
    cout<<"Please Enter Your Store Capacity: ";
    is>>seller_obj.maxItems;
    return is;
}

//Operator overloading for the << operators for Seller Class(stand alone function)
ostream & operator << (ostream & os, const Seller & seller_obj)
{
    os<<"SellerInfo\n";
    os<<"Name: "<<seller_obj.name<<endl;
    os<<"Email: "<<seller_obj.email<<endl;
    os<<"Max Number Of Items: "<<seller_obj.maxItems<<endl;

    return os;
}

int main()
{
    Seller s1;
    cin>>s1;
    int num;
    cout<<"The Menu\n";
    cout<<"1. Print My Info."<<endl<<"2. Add An Item."<<endl<<"3. Sell An Item."<<endl<<"4. Print Items."<<endl
    <<"5. Find an Item by ID"<<endl<<"6. Exit"<<endl;
    cout<<"Choose what you want from the menu: ";
    cin>>num;

    while (num!=6)
    {
        if (num==1)
        {
            cout<<s1;
        }
        else if (num==2)
        {
            Item i1;
            cin>>i1;
            if (s1.Add(i1)== true)
            {
                cout<<"Successful Addition \n";
            }
            else
            {
                cout<<"Failed Addition \n";
            }
        }
        else if (num==3)
        {
            string obj_name;
            int obj_quantity;
            cout<<"Please Enter The Item Name: ";
            cin>>obj_name;
            cout<<"Please Enter The Item Quantity: ";
            cin>>obj_quantity;
            if (s1.Sell(obj_name,obj_quantity)== true)
            {
                cout<<"Item was found. \n";
            }
            else
            {
                cout<<"Item wasn't found. \n";
            }
        }
        else if (num==4)
        {
            s1.Print();
        }
        else if (num==5)
        {
            int id;
            cout<<"Enter the ID of item you want to find: ";
            cin>>id;
            Item find_i = s1.Find_ID(id);
            cout<<find_i;
        }

        cout<<"Choose what you want from the menu: ";
        cin>>num;
    }

    cout<<"EXIT\n";

    return 0;
}


