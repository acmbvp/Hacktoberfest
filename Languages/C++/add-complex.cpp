#include <iostream>
using namespace std;

typedef struct complex
{
    float real;
    float imag;
} complexNumber;

complexNumber addComplexNumbers(complex, complex);

int main()
{
    complexNumber n1, n2, temporaryNumber;
    char signOfImag;


    cout<< "1st commit";
    cout << "For 1st complex number," << endl;
    cout << "Enter real and imaginary parts respectively:" << endl;
    cin >> n1.real >> n1.imag;

    cout << endl << "For 2nd complex number," << endl;
    cout << "Enter real and imaginary parts respectively:" << endl;
    cin >> n2.real >> n2.imag;

    signOfImag = (temporaryNumber.imag > 0) ? '+' : '-';
    temporaryNumber.imag = (temporaryNumber.imag > 0) ? temporaryNumber.imag : -temporaryNumber.imag; 

    temporaryNumber = addComplexNumbers(n1, n2);    
    cout << "Sum = "  << temporaryNumber.real << temporaryNumber.imag << "i";
    return 0;
}

complexNumber addComplexNumbers(complex n1,complex n2)
{
      complex temp;
      temp.real = n1.real+n2.real;
      temp.imag = n1.imag+n2.imag;
      return(temp);
}