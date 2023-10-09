/*  
    Author: JP Ognibene
    Date: 8/26/23
    Purpose: This program will demonstrate the extended euclidean algorithm as well as the consecutive integer algorithm
*/
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
int EuclidsExtended(int, int, int, int);
int consecutive(int, int);
int middleSchool(int, int);

int main()
{
    int m;
    int n;

    //a and b are used only in the EuclidsExtended function
    int a;
    int b;

    cout << "Please enter your first integer value: ";
    cin >> m;
    cout << "Please enter your second integer value: ";
    cin >> n;
    
    //determines if the output is considered "undefined" using the consecutive integer algorithm
    if(consecutive(m, n) == -1)
    {
        cout << "The GCD(" << m << ", " << n << ") = UNDEFINED using the consecutive integer algorithm" << endl;
    }else
    {
        cout << "The GCD(" << m << ", " << n << ") = " << consecutive(m, n) << " using the consecutive integer algorithm."<< endl;
    }//end if-else

    //determines if the output is considered "undefined" using Euclid's Extended algorithm
    if(EuclidsExtended(m, n, a, b) == -1)
    {
        cout << "The GCD(" << m << ", " << n << ") = UNDEFINED using Euclid's Extended algorithm" << endl;
    }else
    {
        cout << "The GCD(" << m << ", " << n << ") = " << EuclidsExtended(m, n, a, b) << " using Euclids Extended algorithm."<< endl;
    }//end if else
    
    //determines if the output is considered "undefined" using Middle School algorithm
    if(middleSchool(m, n) == -1)
    {
        cout << "The GCD(" << m << ", " << n << ") = UNDEFINED using the Middle School algorithm" << endl;
    }else
    {
        cout << "The GCD(" << m << ", " << n << ") = " << middleSchool(m, n) << " using the Middle School algorithm."<< endl;
    }//end if-else
}//end main

/*
    Name: EuclidsExtended
    Purpose: This function is an implementation of the extended euclidean algorithm
    Inputs(Args): User provided integers and holding variables for the recursive calls
    Outputs(Return): The GCD or -1 if undefined
*/
int EuclidsExtended(int m, int n, int a, int b)
{
    int gcd;
    int hold;

    //if both user inputs are 0, no GCD exits, therefore it is undefined and returns -1
    if(m == 0 && n == 0)
    {
        return -1;
    }//end if

    //checks to see if the either user input is 0 or a negative number
    //if one input is 0 and the other is not, the non-zero integer is returned
    //also serve as the base case for the recursive calls
    if(m == 0 && n != 0)
    {
        if(n < 0)
        {
            n = n * -1;
        }
        return n;
    }else if(n == 0 && m != 0)
    {
        if(m < 0)
        {
            m = m * -1;
        }
        return m;
    }//end if-else-if

    gcd = EuclidsExtended(n%m, m, a, b); //recursive function call

    //updates variable values
    hold = b - (n/m) * a; 
    b = a;
    a = hold;

    return gcd;
}//end EuclidsExtended

/*
    Name: consecutive
    Purpose: This is an implementation of the consecutive integer algorithm for finding GCD
    Inputs(args): User provided integers
    Outputs(Return): The gcd or -1 if undefined
*/
int consecutive(int z, int y)
{
    int hold;
    int min;

    //determines if one of the values is 0 and if the other value is not, 
    //that value is made sure not to be negative and returned
    if(z == 0 && y != 0)
    {
        if(y < 0)
        {
            y = y * -1;
        }//end nested if
        return y;
    }else if(y == 0 && z != 0)
    {
        if(z < 0)
        {
            z = z * -1;
        }//end nested if
        return z;
    }//end if-else-if

    //if z is a negative number, it is reassigned with its absolute value
    if(z < 0)
    {
        z = z * -1;
    }

    //if y is a negative number, it is reassigned with its absolute value
    if(y < 0)
    {
        y = y * -1;
    }

    //determines the smallest user provided integer
    if(z < y)
    {
        min = z;
    }else
    {
        min = y;
    }//end if-else

    //subtracts one from the smallest integer until the GCD is found
    while(min != 0)
    {
        if(z % min == 0 && y % min == 0)
        {
            return min;
        }else
        {
            min = min - 1;
        }//end if-else
    }//end while-loop

    return -1; //-1 is returned if no GCD exists
}//end consecutiveInteger

/*
    Name: middleSchool
    Purpose: find the GCD of a two numbers using prime factorization
    Inputs(args): user defined integers
    Outputs(Return): GCD of two integers or -1
*/
int middleSchool(int m, int n)
{
    //vectors to hold the prime factorization for each user input
    vector<int> fac1;
    vector<int> fac2;

    //common will hold all of the common factors
    vector<int> common;

    //adds 1 so the start of both vectors
    fac1.push_back(1);
    fac2.push_back(1);

    //value that will be updated and returned
    int hold = 1;
    
    //makes sure neither variable remains negative
    if(m < 0)
    {
        m = m * -1;
    }

    if(n < 0)
    {
        n = n * -1;
    }

    //returns the non-zero integer if one of the two user-inputs is 0
    if(m == 0 && n != 0)
    {
        return n;
    }else if(n == 0 && m != 0)
    {
        return m;
    }else if(m == 0 && n == 0) //returns -1 if the no GCD exists
    {
        return -1;
    }

    //This loop determines how many 2's can be factored out
    //of the first user-defined integer
    while (m % 2 == 0) 
    { 
        fac1.push_back(2); //adds the element 2 to the first vector
        m = m / 2; 
    }//end while-loop

    //This loop determines how many 2's can be factored out
    //of the second user-defined integer
    while(n % 2 == 0)
    {
        fac2.push_back(2); //adds the element 2 to the second vector
        n = n / 2;
    }//end while-loop

    for(int i = 3; i <= m; i = i + 2) //all prime factors greater than 2 will be odd
    {
        while(m % i == 0) //while loop finds all factors of the first user-defined integer
        {
            fac1.push_back(i);
            m = m / i;
        }//end while-loop
    }//end for-loop

    for(int j = 3; j <= n; j = j + 2) //all prime factors greater than 2 will be odd
    {
        while(n % j == 0) //while loop finds all factors of the first user-defined integer
        {
            fac2.push_back(j);
            n = n / j;
        }//end while-loop
    }//end for-loop

    for(int i = 0; i < fac1.size(); i++) //traverses the first vector
    {
        for(int j = 0; j < fac2.size(); j++) //traverses the second vector
        {
            if(fac1[i] == fac2[j] && fac1[i] != 0) //determines if the two elements match
            {
                common.push_back(fac1[i]); //adds common element to a new vector
                fac1[i] = 0; //replaces common element with a 0
            }//end if
        }//end inner for-loop
    }//end outer for-loop

    //computes the GCD by traversing "common" vector
    for(int x = 0; x < common.size(); x++)
    {
        hold = hold * common[x];
    }//end for-loop

    //calculated GCD is returned
    return hold;
}//end middleSchool

