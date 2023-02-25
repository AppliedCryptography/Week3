#include <iostream>

using namespace std;

string keyGenerate(size_t size)
{
    string rs = "";
    const int TOCHAR = 97;
    for (int i = 0; i < size; i++)
        rs += char(rand() % 26 + TOCHAR);
    return rs;
}

// string vernamEncrypt(string ciphertext, string key)
// {
//     string rs = "";
//     for (size_t i = 0; i < ciphertext.length(); i++)
//         rs += char(((ciphertext[i] - 97) ^ (key[i] - 97)) + 97);
//     return rs;
// }

string vernamEncrypt(string plaintext, string key)
{
    string message = "";
    for (int i = 0; i < plaintext.length(); i++)
    {
        message += (char)((((int)plaintext[i] - 97) ^ ((int)(key[i] - 97))) + 97);
    }
    return message;
}

string vernamDecrypt(string ciphertext, string key)
{
    string rs = "";
    for (size_t i = 0; i < ciphertext.length(); i++)
        rs += char(((ciphertext[i] - 97) ^ (key[i] - 97)) + 97);
    return rs;
}

int main()
{
    srand(time(NULL));
    string p = "helloworld", c = "", k = "";

    for (int i = 0; i < 20; i++)
    {
        k = keyGenerate(p.length());
        cout << "Key : " << k << endl;
        c = vernamEncrypt(p, k);
        cout << "Ciphertext : " << c << endl;
        cout << "plaintext : " << vernamDecrypt(c, k) << endl
             << endl;
    }
}