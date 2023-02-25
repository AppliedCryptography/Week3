#include <iostream>

using namespace std;

string keyGenerate(size_t size)
{
    srand(time(NULL));
    string rs = "";
    const int TOCHAR = 97;
    for (int i = 0; i < size; i++)
        rs += char(rand() % 26 + TOCHAR);
    return rs;
}

// string vernamEncryptvme(string ciphertext, string key)
// {
//     string rs = "";
//     for (size_t i = 0; i < ciphertext.length(); i++)
//     {
//         rs += char(((ciphertext[i] - 97) ^ (key[i] - 97)) % 26 + 97);
//         cout << ((ciphertext[i] - 97) ^ (key[i] - 97)) % 26 + 97 << ' ';
//     }
//     return rs;
// }

string vernamEncrypt(string plaintext, string key)
{
    string message = "";
    for (int i = 0; i < plaintext.length(); i++)
    {
        message += (char)((((int)plaintext[i] - 97) ^ ((int)(key[i] - 97))) % 26 + 97);
    }
    return message;
}

string vernamDecrypt(string ciphertext, string key)
{
    string rs = "";
    for (size_t i = 0; i < ciphertext.length(); i++)
    {
        rs += char(((ciphertext[i] - 97) ^ (key[i] - 97)) % 26 + 97);
        // cout << ((ciphertext[i] - 97) ^ (key[i] - 97)) % 26 + 97 << ' ';
    }
    return rs;
}

int main()
{
    string p = "helloworld", c = "", k = "";
    k = keyGenerate(p.length());
    cout << "key: " << k << endl;
    c = vernamEncrypt(p, k);
    cout << "c: " << c << endl;
    string new_p = vernamDecrypt(c, k);
    cout << "new p: " << new_p << endl;
    return 0;
}