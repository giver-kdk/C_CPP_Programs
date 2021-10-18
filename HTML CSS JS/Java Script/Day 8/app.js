// Input/Output(prompt, confirm, console.log(), alert(), etc.)
var msg = prompt("Please enter a message");		//'prompt' is used for input string message from webpage
console.log(msg);

var msg = confirm("Are you sure to delete?");	//'confirm' is used for confirmation(True or False)
console.log(msg);

alert("Login Successful");						//'alert' just shows alert message on webpage

console.log("Giver", 12, "Khadka");				//Multiple data can be printed once

//Conditionals

var num = prompt("Enter a number:");
if(num == 0)
{
	console.log("The Number is Zero");
}
else if(num % 2 == 0)
{
	console.log("The Number is EVEN");
}
else
{
	console.log("The Number is ODD");
}
//String Compare

var name = "Giver";

if(name == "Giver")
{
	console.log("Correct Username");
}
else
{
	console.log("Incorrect Username");
}

var main_balance = parseInt(prompt("Enter a Number:"));		//'parseInt' function takes integer input from prompt
var interest = 0;

if(main_balance >= 5000)
{
	interest = 100;
}
else
{
	interest = 50;
}
alert("You earned Rs" + interest + "as an interest");

//Switch Case

var color = "red";

switch(color)
{
	case "yellow":
		console.log("Yellow is good. But not correct");
		break;
	case "green":
		console.log("Green is good. But not correct");
		break;
	case "blue":
		console.log("Blue is good. But not correct");
		break;
	case "red":
		console.log("Red is correct");
		break;
	default:
		console.log("Nothing Matched");		
}



