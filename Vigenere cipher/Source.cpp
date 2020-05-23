#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//Bound checker, if value exceeds the high limit when excrypting - 26, if value exceeds the low limit for decryption + 26, otherwise return the value
int boundCheck(int low, int high, int value, bool crypt) {
    if (crypt == true) {
        if (high < value)
            return value - 26;
        else
            return value;
    }
    else {
        if (low > value)
            return value + 26;
        else
            return value;
    }
   
 }

//Converter, if the input value is uppercase then bound check with uppercase limits 
char convert(char input, int shift, bool crypt) {
    if (isupper(input) == 1)
        return boundCheck(65, 90, (input + shift), crypt);
    else
        return boundCheck(97, 122, (input + shift), crypt);
}

/*cryption, runs through each character in the input, skipping symbols and numbers. Resetting the key iterator, ensuring key 
values are repeated. Obtaining the shift, getting the lower value and subtracting the low limit. Converting the character 
based on a boolean; encrypt or decrypt. Finally, adding the char to a string, incrementing the iterator and returning the output*/
string crypt(string input, string key, bool crypt) {
    string output;
    int iter = 0;
    int shift;
    for (int i = 0; i < input.length(); i++) {
        if (isalpha(input[i]) == 0) {
            output += input[i];
            continue;
        }

        if (iter > key.length() - 1)
            iter = 0;

        shift = (tolower(key[iter]) - 97);

        if (crypt == true)
            output += convert(input[i], shift, crypt);
        else
            output += convert(input[i], (shift * -1), crypt);
        
        iter++;
    }

    return output;
}

//Main function, asks for inputs and passed inputs into the cipher. 
int main() {
    string input;
    string output;
    string key;
    char value;
 
    cout << "Input a message" << endl;
    getline(cin, input);
    cout << "Input a key" << endl;
    cin >> key;
    cout << "Input a value to encrypt (Y) or decrypt (N)" << endl;
    cin >> value;
    
    if (value == 'Y')
        output = crypt(input, key, true);
    else if (value == 'N')
        output = crypt(input, key, false);

    cout << output;
}

