var username;					//Variable Declaration(Dynamic Data Type)
var email;
var address;

email	 = "giverbro13@gmail.com";
address	 = "Kathmandu";
username = "Giver Khadka"; 		//Variable Definition

console.log(username);			//Display in console

console.warn("Ahhh! Something is unexpected");	//Print Warning in console

console.error("OOPS! Page content failed to load!")		//Print error in console

/* This is a multiline comment.
	We can write comment in different lines.*/

const USER = "Giver";		//Constant definition(We cannot change its value)
// const USER = "Khadka";		//Same redefinition not allowed
console.log(USER);

// Let
let firstName = "Vision";
let lastName  = "Khadka";
console.log(firstName + " " + lastName);		//Here '+' works as concatination operator to join strings

/*Data Type:
number
boolean
undefined
string
NUll
symbol */

var num1 = 10;				//Automatically stored as number data type
var num2 = 20;

console.log(num1 + num2);		//Here, '+' acts as addition operator for numbers

console.log(num1 + firstName);	//Here, 'num1' is converted into string & concatinated with 'firstName'

var isAProgrammer = true;		// 'true' is a boolean data type
var learningHTML  = false;

console.log(isAProgrammer);
console.log(learningHTML);

var variable = null;		// 'null' is a NULL data type

console.log(typeof variable);	//Here, the type should be NULL, but console shows 'object' which is bug of Js

const userDetails = 			//userDetails is an object
{
	firstName : "Giver",		//Separate object members with a comma
	lastName  : "Khadka",
	age 	  : "19",
	tel		  : "111-111-1111"
};

const countryPrimeMinister = 
{
	nepal     : "Sher Bahadur Deuba",
	pakistan  : "Pakistan PM"
};

const mobile = {
    name    : 'Iphone',
    price  : 110000,
    madeIn : 'China'
};
 
const glass = {
    name: 'Ray ban',
    price: '1100',
    color: 'red',
    soldBy: 'Ram '
};

console.log(typeof userDetails);

console.log(countryPrimeMinister.nepal);

console.log(mobile.name);

console.log(mobile.price);

console.log(glass.name);