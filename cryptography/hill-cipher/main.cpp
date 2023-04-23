#include <iostream>
using namespace std;

int k=0;
string result ;

void decrypt(int cipherMatrix[][1], int messageVector[][1])
{
    int x, i, j;
    int keyMatrix[2][2]={{5,1},{2,7}};
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 1; j++)
        {
            cipherMatrix[i][j] = 0;

            for (x = 0; x < 2; x++)
            {
                cipherMatrix[i][j] += keyMatrix[i][x] * messageVector[x][j];
            }

            cipherMatrix[i][j] = cipherMatrix[i][j] % 26;
        }
    }
}

void HillCipher(string message)
{
    int messageVector[2][1];
    for (int i = 0; i < 2; i++,k++)
    {
        messageVector[i][0] = (message[k]) % 65;
    }

    int cipherMatrix[2][1];

    decrypt(cipherMatrix, messageVector);

    string CipherText;

    for (int i = 0; i < 2; i++)
        CipherText += cipherMatrix[i][0] + 65;

    result += CipherText;
}

int main()
{
    string message = "YITJPGWJOWFAQTQXCSMAETSQUSQAPUSQGKCPQTYJ";
    for(int i = 0; i < message.length() / 2; i++)
    {
        HillCipher(message);
    }
    for(int i = 0; i < result.length(); i++)
    {
        if(i > 0 && i % 5 == 0)
        {
            cout << " " << result[i];
        }
        else
        {
            cout << result[i];
        }
    }
    return 0;
}
