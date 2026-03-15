#include<iostream>
#include<vector>
#include<typeinfo>
using namespace std;

class depositOnlyAccount{
    public :
        virtual void deposit(double amount) = 0;
};

class withdrawableAccount : public depositOnlyAccount {
    public :
        virtual void withdraw(double amount) = 0;
};

class savingsAccount : public withdrawableAccount {
    private : 
        double balance;
    public:
        savingsAccount()
        {
            balance = 0;
        }

        void deposit(double amount)
        {
            balance += amount;
            cout << "Savings account has been credited with " << amount << endl;
        }

        void withdraw(double amount)
        {
            if(balance < amount)
            {
                cout << "Savings account has insufficient balance " << endl;
                return;
            }

            balance -= amount;
            cout << "Savings account has been debited with " << amount << endl;
        }
};

class fixedTermAccount : public depositOnlyAccount {
    private : 
        double balance;
    public :
        fixedTermAccount()
        {
            balance = 0;
        }

        void deposit(double amount)
        {
            balance += amount;
            cout << "Fixed term account has been credited with " << amount << endl;
        }
};

class bankCLient {
    private :
        vector<withdrawableAccount*> withdrawableAccounts;
        vector<depositOnlyAccount*> depositOnlyAccounts;
    public:
        bankCLient(vector<withdrawableAccount*> withdrawableAccounts , vector<depositOnlyAccount*> depositOnlyAccounts)
        {
            this->withdrawableAccounts = withdrawableAccounts;
            this->depositOnlyAccounts = depositOnlyAccounts;
        }

        void processTransaction()
        {
            for(auto &it : withdrawableAccounts)
            {
                it->deposit(1000);
                it->withdraw(500);
            }

            for(auto &it : depositOnlyAccounts)
            {
                it->deposit(1000);
            }
        }
};

int main()
{
    vector<withdrawableAccount*> withdrawableAccounts;
    savingsAccount* sav1 = new savingsAccount();
    withdrawableAccounts.push_back(sav1);

    vector<depositOnlyAccount*> depositOnlyAccounts;
    fixedTermAccount* fix1 = new fixedTermAccount();
    depositOnlyAccounts.push_back(fix1);

    bankCLient* client = new bankCLient(withdrawableAccounts , depositOnlyAccounts);
    client -> processTransaction();
}
