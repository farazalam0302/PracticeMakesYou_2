class DBInterface {
	string dbName;
	string  dbId;
	string  password;
public:
	DBInterface(string database, string id , string pass){
		dbName = database;
		dbId=id;
		password =pass;

	}

	virtual   authenticate(string database, string id , string pass) =0 ;

	virtual bool openConnection() = 0 ;

	void insert(string database, string id , string pass)

};

