#ifndef STRING_STRING_H
#define STRING_STRING_H
class String {
private:
    char *data;
    unsigned size;

    void copy(const String& other);
    void destroy();
public:
    //constructors
    String();
    String(const String &other);
    String(const String &other, unsigned pos, unsigned n);
    String(const char *other);
    ~String();

    //operator =
    String& operator=(const String& other);
    String& operator=(const char*& other);
    String& operator=(const char other);

    //capacity
    const unsigned getSize() const;

    //modifiers
    String& append (const char* s);
    String& operator+=(const char* s);
    String& insert (unsigned pos, const char* s);
    String& erase (unsigned pos, unsigned len);
    String& push_back(const char* s);
    String& pop_back();
};


#endif










