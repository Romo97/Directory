# Directory
```
//This program list the documents of a file and read the size of this document, and create a new documen .json with this information
//Input ./Directory direccion of the file.
//For example: ./Directory /home/user/Documents
Output A document: dir.json is creatde with the information in the folder where is the executable
#include <iostream> //Library for inputs and outputs
#include <dirent.h>
#include <fstream>
#include <cstring>
#include <sstream>
#define SSTR( x ) static_cast< std::ostringstream & >( std::ostringstream() << std::dec << x ).str()
using namespace std; //To use cout and cin
string dir,direccion,direccion2,joinstrings,direccion1_2="/";
const char* c;
 

void list_dir(string dir) //Include the ruote of the file
  {
    DIR * directorio; //Create a pointer for this file
    struct dirent* elemento; //struct to access file's elemts and make a pinter
    string elem; // To save the name of elements
    if (directorio = opendir(dir.c_str()))// If the directory above can open
    {
        FILE *pf; //Create a pointer to the new file
        pf=fopen("dir.json","w"); //Create a file .json
        if ((pf=fopen("dir.json","w"))!=NULL)//Do all when the document is open
          {
            fputs("{\"files\":[\n",pf); //Put the first part in the document before write the elements
            while (elemento =readdir(directorio)) //Read elemnts one by one
              {
                elem = elemento -> d_name; //assing the value of each elemnto in elem variable
                if (elem !="."&& elem!="..") //This function generate two elements "." and ".." ,so with this, they are elmimanted
                  {
                    direccion2=elem; //Save elem in another variable for the next step
                    joinstrings=direccion+direccion1_2+direccion2;// as a specific address for each element is needed to read the document size, the union of the address written by the user and the element is created
                    c = joinstrings.c_str(); //Convert joinstring variable in const char
                    ifstream ifs(c);//Create an ifstream for c
                    ifs.seekg(0, ios::end); //position the pointer to the end

                    char elemchar[elem.size() + 1]; //These two lines convert the variable elem to char in order to introduce the name of the element in a new document . json  
                    strcpy(elemchar, elem.c_str());
              
                    int i = ifs.tellg() ;//ifs.tellg position the size in bytes and save in new variable
                    std:: string s2=SSTR( i ); //These three lines convert int to char in order to print the elements's size in the new document .json
                    char s2char[s2.size() + 1];
                    strcpy(s2char, s2.c_str());
                    
                    fputs ("  {\"name\":\"",pf);// The next lines print in the document the information with an specific format
                    fputs(elemchar,pf);
                    fputs (",\"size\":",pf);
                    fputs (s2char,pf);
                    fputs("},\n",pf);
                  }
              }
              fputs("]}",pf); //print the end of the document
              
          }
   
    }
    else cout<<"This document don't exist\n"; //If there not exist file
    closedir(directorio); //Close the file 
  } 

int main (int argc, char *argv [])
{
  
  dir=argv[1]; ////Create a varible for the user type
  direccion=dir; //Create a varible for the variable joinstring
  list_dir(dir); //Initialize the function that make all
  
  return -1;
   
}
```
