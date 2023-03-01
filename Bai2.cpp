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

string vernamEncrypt(string plaintext, string key)
{
    string message = "";
    for (int i = 0; i < plaintext.length(); i++)
    {
        message += ((plaintext[i]-'a') ^ (key[i]-'a')) + 'a';
    }
    return message;
}

string vernamDecrypt(string ciphertext, string key)
{
    string rs = "";
    for (size_t i = 0; i < ciphertext.length(); i++)
        rs += ((ciphertext[i]-'a') ^ (key[i]-'a')) + 'a';
    return rs;
}

int main()
{
    srand(time(NULL));
    string p = "duongquangbinh", c = "", k = "";

    for (int i = 0; i < 20; i++)
    {
        k = keyGenerate(p.length());
        cout << "Key : " << k << endl;
        c = vernamEncrypt(p, k);
        cout << "Ciphertext : " << c << endl;
        cout << "plaintext : " << vernamDecrypt(c, k) << endl;
        cout << endl;
    }
    return 0;
}