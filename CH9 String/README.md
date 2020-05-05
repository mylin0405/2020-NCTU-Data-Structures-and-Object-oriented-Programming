## Some functions
```=c++
//C-string functions
strcpy(aString, "Hello");  
strncpy(aString, "Hello");  
strcmp(aString, anotherString);  
strlen(aString); //No including NULL
strcat(aString, "Hello");
```

```=c++
//Read one line
char a[80];
cin.getline(a, 80); // Including NULL
//Read one line(Class string v.)
string line;
getline(cin, line);
cout << line << endl;
```

```=c++
//Read one char
char onechar;
cin.get(onechar);
//Output one char
char aString[10] = "Hello";
cout.put(aString[1]);
//Others
cin.putback();
cin.peek();
cin.ignore(1000, '\n'); //skip at most 1000 char until '\n'
```

```=c++
//Char-Manipulating
toupper(char);
tolower(char);
isupper(char);
islower(char);
//.....................
```

```
//Convert between string and Numbers
stoi();
stod();
stof();
string s;
s = to_string(d*2);
``
```
//Command Line arguments
//EX: int main(int argc, char *argv[]);
int main(int argc, char *argv[])
{
  for(int i=0; i <argc; i++)
  {
    cout << "Argument " << i << " " << argv[i] << endl;
  }
  return  ;
}
```
