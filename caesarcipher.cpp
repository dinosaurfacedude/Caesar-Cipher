//Program purpose: Encrypts and decrypts a text file using arithmetic
//Operating System: Windows 10
//Integrated Developement Environment: Code::Blocks
//Compiler Mingw

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

void encrypting(int, int, char**);
void decrypting (int, int, char**);

using namespace std;

int main(int argc, char **argv)
{   char ende;
    int key;
    bool encrypt=true;
    if(argc < 3)
   {
      cerr << "Usage: " << argv[0] << " -e|-d <key> <inputfile.txt>" << endl;
      return 1;
   }
if (argv[1][0] == '-')
   {
    switch (argv[1][1])
    {
   case 'e':
       encrypt=true;
        cout << "argv[1][1] = e" << endl;
       break;
   case 'd':
        encrypt = false;
        cout << "argv[1][1] = d" << endl;
        break;
    default: cerr << "invalid parameter " << argv[1] << endl;
    return 1;
    break;
    }
   }


key = atoi(argv[2]);
   if ((key < 0) || (key > 120))
    {
      cerr << "invalid key " << argv[2] << endl;
      return 1;
    }

   switch (encrypt){
    case true:
    encrypting(key, argc, argv);
    break;

    case false:
    decrypting(key, argc, argv);
    break;
   }

   return 0;
}


void encrypting(int key, int argc, char **argv)
{
    int slen;
    string aline;
    string message[1000];


    ifstream plaintext;
    ofstream encrypted;

plaintext.open (argv[3]);
encrypted.open ("encrypted.txt");


if(!plaintext)
   {
      cerr << "Unable to open file " << argv[3] << " aborting." << endl;
   }
 cout << "encrypting...";

   while(!plaintext.eof())
   {

        for (int i = 0; i < slen; i++)
        {
        getline(plaintext, aline);
        slen = aline.length();

        message [i] = aline[i] += key;
    encrypted << message[i];
        }
     }


plaintext.close();
encrypted.close();

}

void decrypting (int key, int argc, char **argv)
{
    string aline;
    string message[1000];
    int slen;
    ifstream encrypted;
    ofstream decrypted;

encrypted.open (argv[3]);
decrypted.open ("decrypted.txt");


if(!encrypted)
   {
      cerr << "Unable to open file " << argv[3] << " aborting." << endl;

   }
 cout << "decrypting...";

   while(!encrypted.eof())
   {

        for (int i = 0; i < slen; i++)
        {
        getline(encrypted, aline);
        slen = aline.length();

        message [i] = aline[i] -= key;
    decrypted << message[i];
        }
    }



encrypted.close();
decrypted.close();
}
