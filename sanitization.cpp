/***********************************************************************
 * Program:
 *    Lab 06, Sanitization
 *    Brother Helfrich, CS 470
 *
 * Authors:
 *   Osvaldo Carrillo Lira
 *   Aaron Eiche
 *   Zach Heiner
 *   Collin Steel
 *   John Tanner
 *   Jordon Thompson
 *
 * Summary:
 *    Please include a detailed description of:
 *    1. What this program is designed to do
 *    2. How this program will go about solving the problem
 *    3. What assumptions about input (file or user) is made
 *    4. Citations if the algorithm was borrowed or inspired from any source
 ************************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void promptForSQLQuery(string prompt, string &query);
string queryGeneration(string username, string password);
void testValidCases();
void testVulnerabilities(string results);
void weakTuatology(string attack);
void weakUnion(string attack);
void weakAdditionalStatement(string attack);
void weakComment(string attack);

void strongMitigation(string cmdInjection);

struct userpass {
   string username;
   string password;
};

vector <userpass>validCases {
   {"Jimmy","_P34Gu_234"},
   {"culigan","Password_1234"},
   {"Franky","1234_password"},
   {"Franky_445","12_pass_34_Word"},
   {"Arnold_2003","pass_34_12_worD"},
   {"2005_Kerry","5678_pword_1234"},
   {"3_3_Jake","p_1234567"},
   {"Alf_1980","Hairy_alien_80s"},
   {"Kade_Emily_2005","_Got_Married_2_2"},
   {"username","password"},
   {"My_House","House_My"},
   {"Home_1234","1234_Home"}   
};

vector <userpass>tautologyAttacks {
   {"Jimmy","password' OR '1'='1"},
   {"Jimmy","true OR 'x'='x"}
};

vector <userpass>unionQueryAttacks{
   {"Jimmy", "password' UNION SELECT authenticate FROM passList"},
   {"Jimmy", "password' UNION SELECT name FROM passList"}
};

vector <userpass>additionalStatementAttacks{
   {"Jimmy", "password' INSERT INTO users(name, id) VALUES 'bob', '9"},
   {"Jimmy", "password' INSERT INTO users(userName, password) VALUES 'jimbob', 'Gotcha_right_now"}
};

vector <userpass>commentAttacks{
   {"Jimmy'; --", "password"},
   {"Jimmy", "password'; --"}
};

int main() {

   // Create 2 string variables to hold user input
   string username = "";
   string password = "";

   // Prompt user for SQL Queries
   promptForSQLQuery("Please enter your username: ", username);
   promptForSQLQuery("Please enter your password: ", password);

   // Create variable to hold SQL string
   string sqlString = queryGeneration(username, password);

   cout << "Output from prompted values\n";
   cout << sqlString << "\n\n";

   cout << "Output from for valid test cases: \n";
   testValidCases();

   cout << "Output for Tautology attacks:\n";

   // Test SQL string for vulnerabilities
   testVulnerabilities(sqlString);

   // Run SQL string through weak mitigation test
   weakMitigation(sqlString);

   // Run SQL string through strong mitigation test
   strongMitigation(sqlString);

   return 0;
}

/**********************************************************
 * PROMPT FOR SQL QUERY
 * This function displays a prompt on the screen asking 
 * the user for a username and password. The user provided 
 * input is stored in the "pass-by-reference" string argument.
 * *******************************************************/
void promptForSQLQuery(string prompt, string &query){
   cout << prompt;
   cin >> query;
}

/*****************************************************
 * QUERY GENERATION
 * This function takes the user provided input and
 * transforms it into a single SQL string. This SQL
 * string is then returned to the main function. 
 * **************************************************/
string queryGeneration(string username, string password){
   return "SELECT authenticate FROM passwordList WHERE name='"+username+"' and passwd='"+password+"';";
}

/*****************************************************
 * TEST VALID CASES
 * This function takes the test cases for valid input
 * and generates the SQL queries for each of the inputs;
 * It outputs directly to the screen.
 * **************************************************/
void testValidCases(){
   for(vector<userpass>::iterator it = validCases.begin(); it != validCases.end(); it++){
      cout << queryGeneration((*it).username,(*it).password) << "\n";
   }
}


/*****************************************************
 * TEST VULNERABILIES
 * 
 * **************************************************/
void testVulnerabilities(string sqlString){

   for(vector<userpass>::iterator it = tautologyAttacks.begin(); it != tautologyAttacks.end(); it++){
      cout << queryGeneration((*it).username,(*it).password) << "\n";
   }

}

/*****************************************************
 * WEAK MITIGATION
 * 
 * **************************************************/
void weakMitigation(string tuatology){

}

/*****************************************************
 * STRONG MITIGATION
 * 
 * **************************************************/
void strongMitigation(string cmdInjection){

}
