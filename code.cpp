#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

using namespace std;

bool isIN_R(int base)
{
    return (base >= 2 && base <= 10) || base == 16;
}

int to_Int(char digit)
{
    if (digit >= '0' && digit <= '9') return digit - '0';
    if (digit >= 'A' && digit <= 'F') return digit - 'A' + 10;
    if (digit >= 'a' && digit <= 'f') return digit - 'a' + 10;
    return -1;
}

bool isValid(string number, int base)
{
    if (!isIN_R(base) || number.empty()) return false;
    for (unsigned char digit : number)
    {
        if (!std::isxdigit(digit) || to_Int(digit) >= base) return false;
    }
    return true;
}

// Preserve the hexadecimal -> binary -> octal conversion path.
string hexaToOcta(string number)
{
    if (!isValid(number, 16)) throw invalid_argument("Invalid hexadecimal number");
    string binary;
    for (char digit : number)
    {
        int value = to_Int(digit);
        for (int bit = 3; bit >= 0; --bit)
            binary += ((value >> bit) & 1) ? '1' : '0';
    }
    binary.insert(0, (3 - binary.size() % 3) % 3, '0');
    string octal;
    for (size_t i = 0; i < binary.size(); i += 3)
    {
        int value = 4 * (binary[i] - '0') + 2 * (binary[i + 1] - '0') +
                    (binary[i + 2] - '0');
        octal += static_cast<char>('0' + value);
    }
    size_t first = octal.find_first_not_of('0');
    return first == string::npos ? "0" : octal.substr(first);
}

int toDecimal(string number, int base)
{
    if (!isValid(number, base)) throw invalid_argument("Invalid number or base");
    int value = 0;
    for (char digit : number)
    {
        int next = to_Int(digit);
        if (value > (numeric_limits<int>::max() - next) / base)
            throw overflow_error("Number exceeds the supported integer range");
        value = value * base + next;
    }
    return value;
}

char tochar(int digit)
{
    if (digit < 0 || digit > 15) throw invalid_argument("Invalid digit");
    return "0123456789ABCDEF"[digit];
}

string toBaseNumber(int decimal, int base)
{
    if (!isIN_R(base) || decimal < 0) throw invalid_argument("Invalid number or base");
    if (decimal == 0) return "0";
    string result;
    while (decimal > 0)
    {
        result += tochar(decimal % base);
        decimal /= base;
    }
    reverse(result.begin(), result.end());
    return result;
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
        if (!(cin >> base)) return 0;
        // check input validation and quiting option
        if(!isIN_R(base))
        {
            cout << "=====================================\n";
            cout << "Confirm Close =============================\n";
            cout << "=====================================\n";
            cout << "ARE YOU SURE YOU WANT TO QUIT THE PRO-\n";
            cout << "GRAM?(Y/N)\n";
            if (!(cin >> ch)) return 0;
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
            if (!(cin >> base2)) return 0;
            // check input validation and quiting option
            if (!isIN_R(base2))
            {
                cout << "=====================================\n";
                cout << "Confirm Close =============================\n";
                cout << "=====================================\n";
                cout << "ARE YOU SURE YOU WANT TO QUIT THE PRO-\n";
                cout << "GRAM?(Y/N)\n";
                if (!(cin >> ch)) return 0;
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
            if (!(cin >> input)) return 0;
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
                if (!(cin >> input)) return 0;
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
                    try
                    {
                        decimal = toDecimal(input, base);
                        cout << ": " << toBaseNumber(decimal, base2) << endl;
                    }
                    catch (const overflow_error& error)
                    {
                        cout << ": " << error.what() << endl;
                    }
                    cout << "YOU WILL BE RETURNED TO THE MAIN MENU.\n";
                }
            }
        }

    }

    return 0;
}
