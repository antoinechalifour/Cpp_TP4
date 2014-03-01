class Chaine{
    private:
    char* string;
    int size;

    public:
    Chaine();
    Chaine(char* str);
    Chaine(const Chaine& obj);
    ~Chaine();
    unsigned int getSize();
    char* getString() const;
    void addString(char* str);
    void replaceString(char* str);
	Chaine& operator=(const Chaine& c);
};