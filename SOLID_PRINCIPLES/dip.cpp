#include <iostream>
using namespace std;


class Database
{
    public:
        virtual void save(string data)=0;
};

class saveToSql : public Database
{
    public:
        void save(string data)
        {
            cout << "saving to sql database : " << data << endl;
        }

};

class saveToMongo : public Database
{
    public:
        void save(string data)
        {
            cout << "saving to mongo Db : " << data << endl;
        }
};

class UserService
{
    private :
        Database* db;
    public:
        UserService( Database* database)
        {
            db=database;
        }

        void storeUser(string data)
        {
            db->save(data);
        }
    
};

int main()
{
    Database* sqlDB=new saveToSql();
    Database* mongoDB=new saveToMongo();

    UserService* service1=new UserService(sqlDB);
    service1->storeUser("Hello, i am sql DB");

    UserService* service2=new UserService(mongoDB);
    service2->storeUser("Hello, i am mongo DB");
}