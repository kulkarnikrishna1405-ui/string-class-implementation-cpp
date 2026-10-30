#include<iostream>
#include<fstream>
using namespace std;

class String
{
    char *s;

public:

    // Default constructor
    String()
    {
        s = new char[1];
        s[0] = '\0';
    }

    // Copy constructor
    String(const String &obj)
    {
        int len = 0, i = 0;

        for(len = 0; obj.s[len]; len++);

        s = new char[len + 1];

        for(i = 0; obj.s[i]; i++)
            s[i] = obj.s[i];

        s[i] = '\0';
    }

    // Parameterized constructor
    String(const char *p)
    {
        int len = 0, i = 0;

        for(len = 0; p[len]; len++);

        s = new char[len + 1];

        for(i = 0; p[i]; i++)
            s[i] = p[i];

        s[i] = '\0';
    }

    // Size-based constructor
    String(int si)
    {
        if(si < 1)
            si = 1;

        s = new char[si];
        s[0] = '\0';
    }

    // Extraction operator - Read file
    friend istream& operator >>(istream& in, String &obj)
    {
        int count = 0;
        char ch;

        // Count total characters in file
        while(in.get(ch))
            count++;

        // Return to beginning of file
        in.clear();
        in.seekg(0, ios::beg);

        if(!in)
            return in;

        // Allocate exact memory
        char *temp = new char[count + 1];

        int i = 0;

        // Read complete file
        while(i < count && in.get(temp[i]))
            i++;

        if(i != count)
        {
            delete []temp;
            in.setstate(ios::failbit);
            return in;
        }

        temp[i] = '\0';

        // Replace old memory
        delete []obj.s;
        obj.s = temp;

        return in;
    }

    // Insertion operator
    friend ostream& operator <<(ostream& out, const String &obj)
    {
        out << obj.s;
        return out;
    }

    // [] operator
    char& operator[](int i)
    {
        return s[i];
    }

    // + operator
    String operator +(const String &obj)
    {
        int len1 = 0, len2 = 0;

        for(len1 = 0; s[len1]; len1++);
        for(len2 = 0; obj.s[len2]; len2++);

        String temp(len1 + len2 + 2);

        int i = 0;

        for(; s[i]; i++)
            temp.s[i] = s[i];

        temp.s[i] = ' ';
        i++;

        int j = 0;

        while(obj.s[j] != '\0')
            temp.s[i++] = obj.s[j++];

        temp.s[i] = '\0';

        return temp;
    }

    // Assignment operator
    String& operator =(const String &obj)
    {
        if(this != &obj)
        {
            int len = 0, i = 0;

            for(len = 0; obj.s[len]; len++);

            char *temp = new char[len + 1];

            for(i = 0; obj.s[i]; i++)
                temp[i] = obj.s[i];

            temp[i] = '\0';

            delete []s;
            s = temp;
        }

        return *this;
    }

    // < operator
    bool operator <(const String &obj)
    {
        int i = 0;

        for(i = 0; s[i] && obj.s[i]; i++)
        {
            if(s[i] < obj.s[i])
                return true;

            if(s[i] > obj.s[i])
                return false;
        }

        return s[i] < obj.s[i];
    }

    // > operator
    bool operator >(const String &obj)
    {
        int i = 0;

        for(i = 0; s[i] && obj.s[i]; i++)
        {
            if(s[i] > obj.s[i])
                return true;

            if(s[i] < obj.s[i])
                return false;
        }

        return s[i] > obj.s[i];
    }

    // <= operator
    bool operator <=(const String &obj)
    {
        int i = 0;

        for(i = 0; s[i] && obj.s[i]; i++)
        {
            if(s[i] < obj.s[i])
                return true;

            if(s[i] > obj.s[i])
                return false;
        }

        return s[i] <= obj.s[i];
    }

    // >= operator
    bool operator >=(const String &obj)
    {
        int i = 0;

        for(i = 0; s[i] && obj.s[i]; i++)
        {
            if(s[i] > obj.s[i])
                return true;

            if(s[i] < obj.s[i])
                return false;
        }

        return s[i] >= obj.s[i];
    }

    // == operator
    bool operator ==(const String &obj)
    {
        int i = 0;

        for(i = 0; s[i] && obj.s[i]; i++)
        {
            if(s[i] != obj.s[i])
                return false;
        }

        return s[i] == obj.s[i];
    }

    // != operator
    bool operator !=(const String &obj)
    {
        int i = 0;

        for(i = 0; s[i] && obj.s[i]; i++)
        {
            if(s[i] != obj.s[i])
                return true;
        }

        return s[i] != obj.s[i];
    }

    // Destructor
    ~String()
    {
        delete []s;
    }

    // Friend function declarations

    friend int strlen(String &s1);

    friend char *strcpy(String &s1, const String &s2);

    friend char *strcat(String &s1, const String &s2);

    friend int strcmp(const String &s1, const String &s2);

    friend char *strchr(const String &s1, char ch);

    friend char *strncpy(String &s1, const String &s2, int n);

    friend int strncmp(const String &s1, const String &s2, int n);

    friend char *strncat(String &s1, const String &s2, int n);

    friend char *strrev(String &s1);

    friend char *strupr(String &s1);

    friend char *strlwr(String &s1);

    friend char *strrchr(const String &s1, char ch);

    friend char *strstr(const String &s1, const char *sub);
};


// strlen()
int strlen(String &s1)
{
    int len = 0;

    for(; s1.s[len]; len++);

    return len;
}


// strcpy()
char *strcpy(String &s1, const String &s2)
{
    int len = 0, i = 0;

    for(; s2.s[len]; len++);

    char *temp = new char[len + 1];

    for(; s2.s[i]; i++)
        temp[i] = s2.s[i];

    temp[i] = '\0';

    delete []s1.s;
    s1.s = temp;

    return s1.s;
}


// strcat()
char *strcat(String &s1, const String &s2)
{
    int len1 = 0, len2 = 0;

    for(; s1.s[len1]; len1++);
    for(; s2.s[len2]; len2++);

    char *temp = new char[len1 + len2 + 1];

    int i = 0;

    for(; s1.s[i]; i++)
        temp[i] = s1.s[i];

    int j = 0;

    while(s2.s[j] != '\0')
        temp[i++] = s2.s[j++];

    temp[i] = '\0';

    delete []s1.s;
    s1.s = temp;

    return s1.s;
}


// strcmp()
int strcmp(const String &s1, const String &s2)
{
    int i = 0;

    for(i = 0; s1.s[i] && s2.s[i]; i++)
    {
        if(s1.s[i] < s2.s[i])
            return -1;

        if(s1.s[i] > s2.s[i])
            return 1;
    }

    if(s1.s[i] < s2.s[i])
        return -1;

    if(s1.s[i] > s2.s[i])
        return 1;

    return 0;
}


// strchr()
char *strchr(const String &s1, char ch)
{
    for(int i = 0; ; i++)
    {
        if(s1.s[i] == ch)
            return &s1.s[i];

        if(s1.s[i] == '\0')
            break;
    }

    return NULL;
}


// strncpy()
char *strncpy(String &s1, const String &s2, int n)
{
    if(n < 0)
        n = 0;

    int len = 0;

    for(; s2.s[len]; len++);

    int c = (len > n) ? n : len;

    char *temp = new char[c + 1];

    int i = 0;

    for(i = 0; i < c; i++)
        temp[i] = s2.s[i];

    temp[i] = '\0';

    delete []s1.s;
    s1.s = temp;

    return s1.s;
}


// strncmp()
int strncmp(const String &s1, const String &s2, int n)
{
    if(n <= 0)
        return 0;

    int i = 0;

    for(i = 0; i < n && s1.s[i] && s2.s[i]; i++)
    {
        if(s1.s[i] < s2.s[i])
            return -1;

        if(s1.s[i] > s2.s[i])
            return 1;
    }

    if(i == n)
        return 0;

    if(s1.s[i] < s2.s[i])
        return -1;

    if(s1.s[i] > s2.s[i])
        return 1;

    return 0;
}


// strncat()
char *strncat(String &s1, const String &s2, int n)
{
    if(n < 0)
        n = 0;

    int len1 = 0, len2 = 0;

    for(; s1.s[len1]; len1++);
    for(; s2.s[len2]; len2++);

    int c = (len2 > n) ? n : len2;

    char *temp = new char[len1 + c + 1];

    int i = 0, j = 0;

    for(; s1.s[i]; i++)
        temp[i] = s1.s[i];

    for(j = 0; j < c; j++)
        temp[i++] = s2.s[j];

    temp[i] = '\0';

    delete []s1.s;
    s1.s = temp;

    return s1.s;
}


// strrev()
char *strrev(String &s1)
{
    int i = 0, len = 0;

    for(; s1.s[len]; len++);

    int j = len - 1;

    while(i < j)
    {
        char ch = s1.s[i];

        s1.s[i] = s1.s[j];
        s1.s[j] = ch;

        i++;
        j--;
    }

    return s1.s;
}


// strupr()
char *strupr(String &s1)
{
    for(int i = 0; s1.s[i]; i++)
    {
        if(s1.s[i] >= 'a' && s1.s[i] <= 'z')
            s1.s[i] = s1.s[i] - 'a' + 'A';
    }

    return s1.s;
}


// strlwr()
char *strlwr(String &s1)
{
    for(int i = 0; s1.s[i]; i++)
    {
        if(s1.s[i] >= 'A' && s1.s[i] <= 'Z')
            s1.s[i] = s1.s[i] - 'A' + 'a';
    }

    return s1.s;
}


// strrchr()
char *strrchr(const String &s1, char ch)
{
    char *last = NULL;

    for(int i = 0; ; i++)
    {
        if(s1.s[i] == ch)
            last = &s1.s[i];

        if(s1.s[i] == '\0')
            break;
    }

    return last;
}


// strstr()
char *strstr(const String &s1, const char *sub)
{
    if(sub[0] == '\0')
        return s1.s;

    for(int i = 0; s1.s[i]; i++)
    {
        int j = 0;
        int k = i;

        while(s1.s[k] != '\0' && sub[j] != '\0')
        {
            if(s1.s[k] != sub[j])
                break;

            k++;
            j++;
        }

        if(sub[j] == '\0')
            return &s1.s[i];
    }

    return NULL;
}


// Main function
int main()
{
    String obj1;

    // Open file
    ifstream fin("input1.txt", ios::in);

    if(!fin)
    {
        cout << "FILE NOT OPENED" << endl;
        return 0;
    }

    cout << "\nReading data from file:\n";

    // Read file using overloaded extraction operator
    fin >> obj1;

    if(!fin)
    {
        cout << "FILE READING FAILED" << endl;
        return 0;
    }

    fin.close();

    cout << "\nFile contents:\n";
    cout << obj1 << endl;


    // Parameterized constructor
    String obj2("Hello vector");

    cout << "\nParameterized constructor";
    cout << "\nobj2 = " << obj2 << endl;


    // Copy constructor
    String obj3(obj2);

    cout << "\nCopy constructor";
    cout << "\nobj3 = " << obj3 << endl;


    // Assignment operator
    String obj4;

    obj4 = obj1;

    cout << "\nAssignment operator";
    cout << "\nobj4 = " << obj4 << endl;


    // [] operator
    cout << "\n[] operator";
    cout << "\nobj2[1] = " << obj2[1] << endl;


    // + operator
    String obj5 = obj2 + obj1;

    cout << "\n+ operator";
    cout << "\nobj5 = " << obj5 << endl;


    // Comparison operators
    cout << "\nComparison operators";

    cout << "\nobj2 < obj1  = " << (obj2 < obj1);
    cout << "\nobj2 > obj1  = " << (obj2 > obj1);
    cout << "\nobj2 <= obj1 = " << (obj2 <= obj1);
    cout << "\nobj2 >= obj1 = " << (obj2 >= obj1);
    cout << "\nobj2 == obj1 = " << (obj2 == obj1);
    cout << "\nobj2 != obj1 = " << (obj2 != obj1);


    // strlen()
    cout << "\n\nstrlen()";
    cout << "\nLength of obj2 = " << strlen(obj2) << endl;


    // strcpy()
    String s1("ABC");
    String s2("Hello");

    cout << "\nstrcpy()";
    cout << "\nBefore strcpy : " << s1 << endl;

    strcpy(s1, s2);

    cout << "After strcpy  : " << s1 << endl;


    // strncpy()
    String s3("ABCDE");
    String s4("Hello");

    cout << "\nstrncpy()";
    cout << "\nBefore strncpy : " << s3 << endl;

    strncpy(s3, s4, 3);

    cout << "After strncpy  : " << s3 << endl;


    // strcmp()
    String s5("Hello");
    String s6("Hello");

    cout << "\nstrcmp()";
    cout << "\nstrcmp(s5,s6) = " << strcmp(s5, s6) << endl;


    // strncmp()
    String s7("Hello");
    String s8("Help");

    cout << "\nstrncmp()";
    cout << "\nstrncmp(s7,s8,3) = ";
    cout << strncmp(s7, s8, 3) << endl;


    // strcat()
    String s9("Hello");
    String s10("World");

    cout << "\nstrcat()";
    cout << "\nBefore strcat : " << s9 << endl;

    strcat(s9, s10);

    cout << "After strcat  : " << s9 << endl;


    // strncat()
    String s11("Hello");
    String s12("World");

    cout << "\nstrncat()";
    cout << "\nBefore strncat : " << s11 << endl;

    strncat(s11, s12, 3);

    cout << "After strncat  : " << s11 << endl;


    // strrev()
    String s13("Hello");

    cout << "\nstrrev()";
    cout << "\nBefore strrev : " << s13 << endl;

    strrev(s13);

    cout << "After strrev  : " << s13 << endl;


    // strupr()
    String s14("Hello World");

    cout << "\nstrupr()";
    cout << "\nBefore strupr : " << s14 << endl;

    strupr(s14);

    cout << "After strupr  : " << s14 << endl;


    // strlwr()
    String s15("HELLO WORLD");

    cout << "\nstrlwr()";
    cout << "\nBefore strlwr : " << s15 << endl;

    strlwr(s15);

    cout << "After strlwr  : " << s15 << endl;


    // strchr()
    String s16("banana");

    cout << "\nstrchr()";
    cout << "\nFirst occurrence of 'a' : ";
    cout << strchr(s16, 'a') << endl;


    // strrchr()
    cout << "\nstrrchr()";
    cout << "\nLast occurrence of 'a' : ";
    cout << strrchr(s16, 'a') << endl;


    // strstr()
    String s17("Hello World");

    cout << "\nstrstr()";
    cout << "\nSubstring \"World\" : ";
    cout << strstr(s17, "World") << endl;


    cout << "\n\nAll tests completed.\n";

    return 0;
}
