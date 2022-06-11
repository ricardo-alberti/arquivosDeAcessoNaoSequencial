#indef DATABASE
#define DATABASE

template<classT>

class Database {
public:
    Database();
    void run();
private:
    fstream database;
    char FName[20];
    ostream& print(ostream&);
    void add(T&);
    bool find(const T&);
    void modify(const T&);
    friend ostream& operator<<(ostream& out, Database& db) {
        return db.print(out);
    }
};

#endif
