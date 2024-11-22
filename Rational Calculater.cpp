#include<bits/stdc++.h>

using namespace std;

// Function to clear input buffer
void clear_Input() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main(){

    int  var , count;                                              
    char  operation ;                                           
                                                                 
    char comp ;                                                 
    string  numerator1  ,numerator2 , ope , demon1 ,  demon2 ;  
    bool f = false ;                                          

    // Main loop for calculator functionality
    cout << "========================== Welcome to Rational Number Calculator =========================="<<endl;
    while (true){     
        cout << "Please, enter a rational number operations but you must enter a space between number and operation:  "<<endl;
        getline(cin,ope);
        
        count = 0;

        while (true)
        {
         for (int i = 0 ; i < ope.length() ; i++){

            if(isdigit(ope[i])){
                count++ ;
            }

            if (!isspace(ope[i]) && !isdigit(ope[i]) && ope[i] != '+'  && ope[i] != '-'  && ope[i] != '/'  && ope[i] != '*' ){                
                cout << "Invalid operand. Try again." <<endl;
                ope = ' ';
                getline(cin,ope);
                continue;       // Handling invalid input
            }

            if(count == 0 && i >= 1){
                cout << "Invalid operand. Try again." <<endl;
                ope = ' ';
                getline(cin,ope);
                break; 
            }
            else{
                continue;
            }
         }
         break;
        
        }   

        // Reset variables for each iteration
       numerator1 = " "  ;
       demon1 = " ";
       numerator2 = " ";
       demon2 = " ";
       operation = ' ';


        // Parsing the input string
        for (int i = 0 ; i < ope.length() ; i++){

            // Parsing numerator and denominator of the first fraction
            if((isdigit(ope[i]) || ope[i] == '-') && !f ){
                numerator1 += ope[i];
            }

            if(ope[i] == '/' && !f   ){
                f = true;
                continue;
            }

            if (isspace(ope[i])){
                var = i + 1 ;
                f = false ;
                break;
            }

            if ((ope[i] == '+'&& isspace(ope[i-1]) ) ||(isspace(ope[i-1]) && ope[i] == '/' )|| (ope[i] == '*' && isspace(ope[i-1])) ||(   ope[i] == '-' &&  isspace(ope[i-1])) ){

                var = i + 1 ;
                operation = ope[i];
                f = false ;
                break;
            }

            // Parsing numerator and denominator of the first fraction
            if ((isdigit(ope[i]) || (ope[i] == '-' && ope[i-1] == '/')) && f){
                demon1 += ope[i];
            }

        }

        // Parsing the second fraction and operation
        while (var < ope.length() )
        {    
            if((ope[var] =='+' && isspace(ope[var-1]) && operation == ' ' ) || ( ope[var] == '/' && isspace(ope[var-1])  && operation == ' ' ) || (ope[var] == '*' && isspace(ope[var-1])  && operation == ' ')  || (ope[var] == '-' &&  isspace(ope[var-1])&&
                                                                                                                                                  operation == ' '))  {
                operation = ope[var];
                var += 1 ;
                continue;
            }
            
            if(isspace(ope[var])){
                var += 1;
                continue;
            }
            if((isdigit(ope[var]) || ope[var] == '-' ) && !f ){
                numerator2 += ope[var];
            }

            if(ope[var] == '/' && operation != ' '  &&  (isspace(ope[var-1]) || isspace(ope[var+1])) || ( (ope[var] == '+'&& isspace(ope[var-1]) && operation != ' ' ) ||(isspace(ope[var-1]) && ope[var] == '/' && operation != ' ')|| (ope[var] == '*' && operation != ' ' ) || (isspace(ope[var-1]) && ope[var] == '-' && operation != ' ' && isspace(ope[var+1]))) ){
 
                 numerator1 = " "  ;
                 demon1 = " ";
                 numerator2 = " ";
                 demon2 = " ";
                 operation = ' ';         
                 break;                    
            }

            if(ope[var] == '/' && !f   ){
                f = true;
                var += 1;
                continue;                     
            }

           
          

            if ((isdigit(ope[var]) || (ope[var] == '-' && ope[var-1] == '/')) && f ){
                demon2 += ope[var];
            }

            var += 1;
        } 

         if(numerator1 == " " || numerator2 == " " || numerator2 == " -" || numerator1 == " -"){
            cout << "Invalid operand , Try again." << endl;
            continue; 
        }

        f = false ;
 
        // Handling case when denominator is omitted
        if(demon1 == " "){
            demon1 = "1" ;
        }
        if(demon2 == " "){
            demon2 = "1" ;
        }

        // Converting strings to floats for calculation
        float num1 = atof(numerator1.c_str());
        float den1 = atof(demon1.c_str());
        float num2 = atof(numerator2.c_str());
        float den2 = atof(demon2.c_str());

        // Handling division by zero error
        if(den1 == 0 || den2 == 0 ){
            cout << "Invalid, Division by zero error" << endl;
            continue; 
        }

        // Performing arithmetic operations based on the operator
        switch(operation){
            case '+':
                if(den1 == den2){
                    cout<<"The result is " << num1 << '/' << den1 << " + "  << num2 << '/' << den2 << " = " << (num1 + num2) << '/' << den1 <<endl;
                }
                else
                    cout<<"The result is "<< num1 << '/' << den1 << " + "  << num2 << '/' << den2 << " = " << (num1 * den2 + num2 * den1) <<'/'<< (den1 * den2) <<endl;
                break;

            case '-':
                if(den1 == den2) {
                    cout << "The result is " << num1 << '/' << den1 << " - "  << num2 << '/' << den2 << " = " << (num1 - num2) << '/' << den1 <<endl;
                }
                else
                    cout<<"The result is " << num1 << '/' << den1 << " - "  << num2 << '/' << den2 << " = " << (num1 * den2 - num2 * den1) <<'/'<< (den1 * den2) <<endl;
                break;

            case '*':
                cout<<"The result is " << num1 << '/' << den1 << " * "  << num2 << '/'<< den2 << " = " << (num1 * num2)<<'/'<< (den1 * den2)<<endl;
                break;

            case '/'  :
                if ((den1 * num2) == 0){
                    cout << "Division by zero error" << endl;
                    break;
                }
                cout<<" The result is " << num1 << '/' << den1 << " / "  << num2 << '/' << den2 << " = " << (num1 *den2) <<'/'<< (den1 * num2)<<endl;
                break;

            default:
                cout << "Invalid operation, Try again." << endl;
                continue;
        }

        // Asking user if they want to continue or not
        while(true){
            cout << "Do you want to continue (Y/N): ";
            cin >> comp;
            if (comp == 'N' || comp == 'n') {
                cout << "Thank you for using this rational number calculator" ;
                exit(EEXIST);
            }
            if (comp == 'Y' || comp == 'y') {
                break;
            }
            else {
                clear_Input();

            }
        }
        clear_Input();
    }

    return 0;
}
