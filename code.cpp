#include<iostream>
#include<string>

using namespace std;



// Function to Convert
// Hexadecimal Number to Octal Number
string hexaToOcta(string str)
{
    // array to store binary data
    char binary[300];
    int size = 0;
    int p = 0;
    // getting and mapping each value into binary
    for (int i = 0; i < str.length(); i++)
    {
        switch (str[i])
        {
        case '0':
            binary[p] = '0';
            binary[p + 1] = '0';
            binary[p + 2] = '0';
            binary[p + 3] = '0';
            break;
        case '1':
            binary[p] = '0';
            binary[p + 1] = '0';
            binary[p + 2] = '0';
            binary[p + 3] = '1';
            break;
        case '2':
            binary[p] = '0';
            binary[p + 1] = '0';
            binary[p + 2] = '1';
            binary[p + 3] = '0';
            break;
        case '3':
            binary[p] = '0';
            binary[p + 1] = '0';
            binary[p + 2] = '1';
            binary[p + 3] = '1';
            break;
        case '4':
            binary[p] = '0';
            binary[p + 1] = '1';
            binary[p + 2] = '0';
            binary[p + 3] = '0';
            break;
        case '5':
            binary[p] = '0';
            binary[p + 1] = '1';
            binary[p + 2] = '0';
            binary[p + 3] = '1';
            break;
        case '6':
            binary[p] = '0';
            binary[p + 1] = '1';
            binary[p + 2] = '1';
            binary[p + 3] = '0';
            break;
        case '7':
            binary[p] = '0';
            binary[p + 1] = '1';
            binary[p + 2] = '1';
            binary[p + 3] = '1';
            break;
        case '8':
            binary[p] = '1';
            binary[p + 1] = '0';
            binary[p + 2] = '0';
            binary[p + 3] = '0';
            break;
        case '9':
            binary[p] = '1';
            binary[p + 1] = '0';
            binary[p + 2] = '0';
            binary[p + 3] = '1';
            break;
        case 'A':
            binary[p] = '1';
            binary[p + 1] = '0';
            binary[p + 2] = '1';
            binary[p + 3] = '0';
            break;
        case 'B':
            binary[p] = '1';
            binary[p + 1] = '0';
            binary[p + 2] = '1';
            binary[p + 3] = '1';
            break;
        case 'C':
            binary[p] = '1';
            binary[p + 1] = '1';
            binary[p + 2] = '0';
            binary[p + 3] = '0';
            break;
        case 'D':
            binary[p] = '1';
            binary[p + 1] = '1';
            binary[p + 2] = '0';
            binary[p + 3] = '1';
            break;
        case 'E':
            binary[p] = '1';
            binary[p + 1] = '1';
            binary[p + 2] = '1';
            binary[p + 3] = '0';
            break;
        case 'F':
            binary[p] = '1';
            binary[p + 1] = '1';
            binary[p + 2] = '1';
            binary[p + 3] = '1';
            break;
        }

        p += 4;
    }

    string binry(binary, p);

    while(binry.length() % 3 != 0)
    {
        binry.insert(0, "0");
    }

    int len = (str.length() * 4);

    //array to store octa numbers
    char octa[200];
    int s2 = 0;

    int q = 0;
    // getting and maping each data to octa one
    for (int i = 0; i < len - 2; i += 3)
    {
        q = (4 * (binry[i] - 48)) + (2 * (int(binry[i + 1]) - 48)) + (1 * (int(binry[i + 2]) - 48));
        octa[s2] = (q + 48);
        s2++;
    }

    string str4(octa, s2);

    while (str4[0] == '0')
    {
        str4.erase(0, 1);
    }

    return str4;
}



//function to check weither the given base is in list or not
bool isIN_R(int num)
{
    // list
    int R[] = {2,3,4,5,6,7,8,9,10,16};

    for (int i = 0; i < 10; i++)
    {
        if(num == R[i])
        {
            return true;
        }
    }
    return false;
    
}


//function to convert char to int value
int to_Int(char chart)
{
    if (chart >= 48 && chart <= 57) // check for hexadecimal value input
    {
        return ((int)chart - 48); //converting char to int then setting correct value
    }
    else
    {
        return ((int)chart - 65 + 10); 
    }
}

//function to convert Given any based value to the decimal value
int toDecimal(string str, int base)
{
    int size = str.length();
    int pow = 1; 
    int num = 0;
    int i;
 
    // using method 1*2^2 + 0*2^1 + 1*2^0
    for (i = size - 1; i >= 0; i--)
    {
        num = num + (to_Int(str[i]) * pow);
        pow = pow * base;
    }
    
    // a decimal number
    return num;
}

// function to convet given number to char
char tochar(int num)
{
    if (num >= 0 && num <= 9)
    {
        return (char)(num + 48);
    }
    else
    {
        return (char)(num - 75);
    }
}

// function to convert given decimal number to base number
string toBaseNumber(int dec, int base)
{
    // arrays to store numbers
    char str1[200], str2[200];
    int s1 = 0;
    int s2 = 0;
    // using :=> 40%2 -> 20%2 -> 10%2 -> 5%2 -> 2%2 
    while(dec > 0)
    {
        str1[s1] = tochar(dec % base);
        dec = dec / base;
        s1++;
    }
    // reversing the getted number characters
    for(int i = s1-1; i >= 0; i--)
    {
        str2[s2] = str1[i];
        s2++;
    }
    return string(str2, s2);
}

//function to check validation of input string
bool isValid(string str, int base)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (to_Int(str[i]) >= base)
        {
            return false;
        }
    }
    return true;
}


//========================================================
//          main
//========================================================
int main()
{
    int base = 0; // store source base
    int base2 = 0; // store target base
    char ch = ' '; // to get check input
    string input; // inpput string
    int decimal = 0; // to store intermediate decimal numbers
    while(true)
    {
        //===================================================
        //                      Menu
        //===================================================
        cout << "\n\n=====================================\n";
        cout << "Number System Conversion=============\n";
        cout << "=====================================\n";
        cout << "CHOOSE YOUR SOURCE NUMBER SYSTEM: \n";
        cout << "(2) BINARY\n";
        cout << "(3) TERNARY\n";
        cout << "(4) QUATERNARY\n";
        cout << "(5) QUINARY\n";
        cout << "(6) SENARY\n";
        cout << "(7) SEPTENARY\n";
        cout << "(8) OCTAL\n";
        cout << "(9) NONARY\n";
        cout << "(10) DECIMAL\n";
        cout << "(16) HEXADECIMAL\n";
        cout << "INPUT ANY OTHER VALUE TO EXIT THE PROGRAM.\n";
        cout << "=====================================\n";
        cin >> base;
        // check input validation and quiting option
        if(!isIN_R(base))
        {
            cout << "=====================================\n";
            cout << "Confirm Close =============================\n";
            cout << "=====================================\n";
            cout << "ARE YOU SURE YOU WANT TO QUIT THE PRO-\n";
            cout << "GRAM?(Y/N)\n";
            cin >> ch;
            if(ch == 'Y')
            {
                cout << "BYE! \n";
                cout << "=====================================\n";
                exit(0);
            }
            else
            {
                cout << "YOU WILL BE RETURNED TO THE MAIN MENU.\n";
                continue;
            }
        }
        else
        {
            cout << "==========================================\n";
            cout << "Source Number System : " << base << "  =================\n";
            cout << "==========================================\n";
            cout << "CHOOSE YOUR TARGET NUMBER SYSTEM: ";
            cin >> base2;
            // check input validation and quiting option
            if (!isIN_R(base2))
            {
                cout << "=====================================\n";
                cout << "Confirm Close =============================\n";
                cout << "=====================================\n";
                cout << "ARE YOU SURE YOU WANT TO QUIT THE PRO-\n";
                cout << "GRAM?(Y/N)\n";
                cin >> ch;
                if (ch == 'Y')
                {
                    cout << "BYE! \n";
                    cout << "=====================================\n";
                    exit(0);
                }
                else
                {
                    cout << "YOU WILL BE RETURNED TO THE MAIN MENU.\n";
                    continue;
                }
            }



            //displaying source and arget base
            cout << "=====================================\n";
            cout << "Source Number System : " << base << ", Target Number System: " << base2 << " ======\n";
            cout << "=====================================\n";
            cout << "INPUT YOUR NUMBER IN SOURCE NUMBER SYSTEM:\n";

            string str1;
            string str2;

            //Implement the main menu branches with switch, NOT if - else
            switch (base)
            {
            case 2:
                str1 = "BINARY";
                break;
            case 3:
                str1 = "TERNARY";
                break;
            case 4:
                str1 = "QUATERNARY";
                break;
            case 5:
                str1 = "QUINARY";
                break;
            case 6:
                str1 = "SENARY";
                break;
            case 7:
                str1 = "SEPTENARY";
                break;
            case 8:
                str1 = "OCTAL";
                break;
            case 9:
                str1 = "NONARY";
                break;
            case 10:
                str1 = "DECIMAL";
                break;
            case 16:
                str1 = "HEXADECIMAL";
                break;
            default:
                cout << "Invalid Input \n";
            }

            switch (base2)
            {
            case 2:
                str2 = "BINARY";
                break;
            case 3:
                str2 = "TERNARY";
                break;
            case 4:
                str2 = "QUATERNARY";
                break;
            case 5:
                str2 = "QUINARY";
                break;
            case 6:
                str2 = "SENARY";
                break;
            case 7:
                str2 = "SEPTENARY";
                break;
            case 8:
                str2 = "OCTAL";
                break;
            case 9:
                str2 = "NONARY";
                break;
            case 10:
                str2 = "DECIMAL";
                break;
            case 16:
                str2 = "HEXADECIMAL";
                break;
            default:
                cout << "Invalid Input \n";
            }

            cout << str1 << ": ";
            cin >> input;
            int i = 1;
            bool check = true;
            /*
                For input validation loop, check the cctype library functionsand choose
                the most relevant one.You won't get any point for writing an if-statement
                with logical or of 16 conditions.
             */
            while (!isValid(input, base))
            {
                cout << "NOT A VALID NUMBER!TRY AGAIN :\n";
                cout << str1 << ": ";
                cin >> input;
                i++;
                if (i == 5)
                {
                    cout << "YOU WILL BE RETURNED TO THE MAIN MENU.\n";
                    check = false;
                    break;
                }
            }
            if (check)
            {
                //The hexadecimal to octal conversion should be through base 2 as
                //    explained in this video.You won't get any point for converting to 10
                //    and then 8. If you use any reference for this part of the problem, do not
                //    forget to cite them.As I mentioned before, you should NOT search for
                //    the code but you can search for the algorithm to see how this conversion is
                //    supposed to be done.Your reference should match your implementation.
                if (base == 16 && base2 == 8)
                {
                    cout << str2;
                    cout << ": " << hexaToOcta(input) << endl;
                    cout << "YOU WILL BE RETURNED TO THE MAIN MENU.\n";

                }
                else
                {
                    cout << str2;
                    decimal = toDecimal(input, base);
                    cout << ": " << toBaseNumber(decimal, base2) << endl;
                    cout << "YOU WILL BE RETURNED TO THE MAIN MENU.\n";
                }
            }
        }

    }

    return 0;
}