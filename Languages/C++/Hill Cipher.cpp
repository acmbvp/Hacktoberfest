// C++ code to implement Hill Cipher
#include <bits/stdc++.h>
using namespace std;    
string input;

void init_code()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}
void Key(string letterkey, int Keymatrix[][3])
{
    int k = 0;
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            Keymatrix[i][j] = (letterkey[k]) % 65;
            k++;
        }
    }
}
  

void encryption(int cipherMatrix[][1],
             int Keymatrix[][3], 
             int inputVector[][1])
{
    
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 1; j++)
        {
            cipherMatrix[i][j] = 0;
           
            for (int x = 0; x < 3; x++)
            {
                cipherMatrix[i][j] += 
                     Keymatrix[i][x] * inputVector[x][j];
            }
          
            cipherMatrix[i][j] = cipherMatrix[i][j] % 26;
        }
    }
}

void decryption(int outputMatrix[][1],
             int inverseKeymatrix[][3], 
             int cipherMatrix[][1])
{
    
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 1; j++)
        {
            outputMatrix[i][j] = 0;
           
            for (int x = 0; x < 3; x++)
            {
                outputMatrix[i][j] += 
                     inverseKeymatrix[i][x] * cipherMatrix[x][j];
            }
          
            outputMatrix[i][j] = outputMatrix[i][j] % 26;
        }
    }
}
  

void HillCipher(string message, string letterkey)
{
    int Keymatrix[3][3];
    Key(letterkey, Keymatrix);
  
    int inputVector[3][1];
  
    for (int i = 0; i < 3; i++)
        inputVector[i][0] = (message[i]) % 65;
  
    int cipherMatrix[3][1];
    int outputMatrix[3][1];
    encryption(cipherMatrix, Keymatrix, inputVector);
  
    string CipherText;
  
   
    for (int i = 0; i < 3; i++)
        CipherText += cipherMatrix[i][0] + 65;
  

    cout << "Ciphertext:" << CipherText;
    int inverseKeymatrix[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cin >> inverseKeymatrix[i][j];
    }
    string outputText = "";
    decryption(outputMatrix,
             inverseKeymatrix, 
             cipherMatrix);

    for (int i = 0; i < 3; i++)
        outputText += outputMatrix[i][0] + 65;
  
    if (outputText == input)
    {
        cout << "\n" << "-----KEY MATCHED!-----" << "\n";
        cout << "Output:" << outputText;
    }
    else
        cout << "\n" << "SORRY! WRONG KEY";
}
  

int main()
{
    init_code();
    cin >> input;
  
    string letterkey = "GYBNQKURP";
  
    HillCipher(input, letterkey);

  
    return 0;
}