/**
 *  Infix to postfix implementation
 * 
 *  Dinesh
 *  
 *  Input: 4+8*6-5/3-2*2+2 ==>  486*+53/-22*-2+    
 * 
 * Algorithm:
 *  - Whenever an integer/character comes from expression we append to postfix String
 *  - Whenever a operator comes in we check the precedence of the incoming operator with the 
 *    operator on the top of the stack if the stack is not null
 *  - If the precedence of the incoming operator is lower than or equal to operator on the top of
 *    the stack - Pop the operator on the stack and check the precedence again until the operator
 *    is greater than that of the operator on the stack (except if operator is '^' which has the highest precedence and 
 *    is right associative)
 *  - Append the popped operator to the postFix string
 *  - If there are no expressions left in the stack pop all the operators and append to the string  
 * 
 */

EX.InfixToPostfix = function(expression){
	var pfixString = "";
	var infixStack = new EX.LinkedStack();
	
	// Helper function to get the precedence of the operator
	var precedence = function(operator){
		switch(operator){
		case "^":
			return 3;
		case "*":
		case "/":
			return 2;
		case "+":
		case "-":
			return 1;
		default:
			return 0;
		}
	}
	
	for(var i=0; i<expression.length; i++){
		var c = expression.charAt(i);
		if(!isNaN(parseInt(c))){
			pfixString += c;
		}else if(c === "+" || c==="-" || c === "*" || c==="/" || c==="^"){
			while(c != "^" && !infixStack.isStackEmpty() && (precedence(c) <= precedence(infixStack.stackTop()))){
				pfixString += infixStack.popFromStack().item;
			}
			infixStack.pushToStack(c);
		}
	}
	while(!infixStack.isStackEmpty()){
		pfixString += infixStack.popFromStack().item;
	}
	
	
	
	this.getPostfix = function(){
		return pfixString;
	}
}



console.log("INFIX to POSTFIX");
var in1 = new EX.InfixToPostfix("2+3*4"); //234*+
console.log("Postfix 2+3*4 ==> "+in1.getPostfix());
var in2 = new EX.InfixToPostfix("2*3-4^2"); //23*42^-
console.log("Postfix 2*3-4^2 ==> "+in2.getPostfix());
var in3 = new EX.InfixToPostfix("3+4*5/6"); //345*6/+
console.log("Postfix 3+4*5/6 ==> "+in3.getPostfix());
var in4 = new EX.InfixToPostfix("4+8*6-5/3-2*2+2"); // 486*+53/-22*-2+    
console.log("Postfix 4+8*6-5/3-2*2+2 ==> " +in4.getPostfix());

/**
 * OUTPUT
 * 
 * INFIX to POSTFIX 
 * Postfix 2+3*4 ==> 234*+ 
 * Postfix 2*3-4^2 ==> 23*42^- 
 * Postfix 3+4*5/6 ==> 345*6/+ 
 * Postfix 4+8*6-5/3-2*2+2 ==> 486*+53/-22*-2+
 * 
 */
