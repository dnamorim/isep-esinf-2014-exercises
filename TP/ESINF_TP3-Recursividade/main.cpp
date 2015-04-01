/* 
 * File:   main.cpp
 * Author: dnamorim
 *
 * Created on 20 de Outubro de 2014, 15:50
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>

using namespace std;

int soma_int(int a,int b)
{
	// Final
	if (b==0) return a;

	// Chamada Recursiva
	return soma_int(a+1,b-1);
}

int muda_base(int n,int b)
{
	// Final
	if (n < b) return n;

	// Chamada Recursiva
	int digito = n % b;
	return muda_base(n/b, b)*10+digito;
}

bool e_primo(int n,int d)
{
	// Final
	if (d > sqrt((double)n)) return true;
	if (n % d == 0) return false;

	// Chamada Recursiva
	return e_primo(n,d+1);
}

bool e_primo(int n)
{
	return e_primo(n,2);
}

bool palindroma(string s)
{
	int l = s.length();

	if (l < 2) return true;
	if (s[0] != s[l-1]) return false;

	return palindroma(s.substr(1,l-2));
}

bool capicua(int n)
{
	char tmp[100];
	
	itoa(n,tmp,10);
	return palindroma(tmp);
}

bool capicua2(int n)
{
	if (n < 10) return true;

	int d1 = n % 10;

	int ndigitos = (int)log10((double)n);
	int pot_ndig = (int)pow(10, (double)ndigitos);

	int d2 = n / pot_ndig;
	if (d1 != d2) return false;

	int rd2 = n - d2 * pot_ndig;
	int resto = rd2/10;

	return capicua2(resto);
}

int main(int argc, char** argv)
{	
	cout << "2+3 = " << soma_int(2,3) << endl;
	
	cout << "13 em binario é: " << muda_base(13,2) << endl;
	
	cout .setf(ios::boolalpha);
	cout <<  "77 é primo? " << e_primo(77) << endl;
	cout <<  "919 é primo? " <<e_primo(919) << endl;

	
	cout << "SOPAPOS é palindroma? " << palindroma("SOPPOS") << endl;
	cout << "POSSAP é palindroma? " << palindroma("POSSAP") << endl;
	
	cout << "1234 é capicua? " << capicua(1234) << endl;
	cout << "1221 é capicua? " << capicua2(1221) << endl;

    
	return 0;        
}
