/*
    filename: incomeTax.cpp
    summary: calculate income tax
    author: Abdurrahman Alyajouri
    date: 1/28/2023
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int wage,
        taxInterest,
        unemployment,
        status,
        taxesWithheld,
        agi,
        deduction,
        taxIncome,
        finalTax;
       
    double taxAmount;
    
    cin >> wage
        >> taxInterest
        >> unemployment
        >> status
        >> taxesWithheld;
        
    agi = wage + taxInterest + unemployment;    
    
    if(status == 2) {
        deduction = 24000;
    } else {
        status = 1;
        deduction = 12000;
    }
    
    taxIncome = agi - deduction;
    if(taxIncome < 0) {
        taxIncome = 0;
    }
    
    if(status == 1) {
        if(taxIncome >= 0 && taxIncome <= 10000) {
            taxAmount = taxIncome * 0.1;
        } else if(taxIncome >= 10001 && taxIncome <= 40000) {
            taxAmount = 1000 + (taxIncome - 10000) * 0.12; 
        } else if(taxIncome >= 40001 && taxIncome <= 85000) {
	        taxAmount = 4600 + (taxIncome - 40000) * 0.22;
	    } else if(taxIncome > 85000) {
	        taxAmount = 14500 + (taxIncome - 85000) * 0.24;
	    }  
    } else if(status == 2) {
	    if(taxIncome >= 0 && taxIncome <= 20000) {
            taxAmount = taxIncome * 0.1;
        } else if(taxIncome >= 20001 && taxIncome <= 80000) {
            taxAmount = 2000 + (taxIncome - 20000) * 0.12; 
        } else if(taxIncome > 80000) {
	        taxAmount = 9200 + (taxIncome - 80000) * 0.22;
	    }
    } 
    
    taxAmount = round(taxAmount);
    finalTax = taxesWithheld - taxAmount;
    
    if(agi < 120000) {
        cout << "AGI: $" << agi << endl
             << "Deduction: $" << deduction << endl
             << "Taxable income: $" << taxIncome << endl
	          << "Federal tax: $" << taxAmount << endl;
	     if(finalTax < 0) {
	         cout << "Taxes Owed: $" << abs(finalTax) << endl; 
	     } else {
	         cout << "Tax refund: $" << abs(finalTax) << endl;    
	     }   
    } else {
        cout << "AGI: $" << agi << endl;
        cout << "Error: Income too high to use this form\n";
    }

   return 0;
}

