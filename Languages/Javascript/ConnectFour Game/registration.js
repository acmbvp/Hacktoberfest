
        
//--------------------------- Does some basic checking of user data then stores user data in localStorage -------------------- 
           
        
		function registerUser()
		{
            //Extract the name and password that the user has entered
			
            var nameInput = document.getElementById("name").value;
            var pwdInput = document.getElementById("password").value; 
            
            
			
			//Check that the name and password are not empty
			
            if(nameInput !== "" && pwdInput !== ""){
                //Create a JavaScript object to hold the user data.
                var usrObj = {};
                
                //Add user entered data to object
                usrObj.username = nameInput;
                usrObj.password = pwdInput;
                
                //Add a score field to object to support rankings table
                usrObj.topscore = 0;
                
                //Store a string version of the object in local storage.
                localStorage[nameInput] = JSON.stringify(usrObj);
            }
        }
        
        
		
		
        /* Checks that the username and password match the user name and password of a 
            registered user and provides feedback to user. */
       

	   function checkLogin()
	   {
            //Get a reference to the div where we will display the login result
            var loginResult = document.getElementById("LoginResult");

            //Extract the name and password that the user has entered
            var nameInput = document.getElementById("loginName").value;
            var pwdInput = document.getElementById("loginPassword").value; 

			
			
            //Output for debugging
            console.log("Login name: " + nameInput+ "; Login password" + pwdInput);

            //Check to see if we have data stored for this user
            if(localStorage[nameInput] === undefined)
			{
                //No user found - provide feedback to user.
                loginResult.innerHTML = "User name incorrect";
                return;
            }

			
			
            //Check password
            //Get object that is stored for the user name.
            var usrObj = JSON.parse(localStorage[nameInput]);

			
			
            //Compare the entered password with the stored password
            if(pwdInput !== usrObj.password)
			{
                //Incorrect password - provide feedback to user
                loginResult.innerHTML = "Password incorrect";
                return;
            }

	
            //Record the user that has logged in using local storage.
            localStorage.loggedInUser = nameInput;

            //Provide feedback to user - you could also provide a logout button - see the example in my slides.
            loginResult.innerHTML = "User logged in.";
        }
    
        
        /* This function is called when a logged in user 
            plays the game and gets a score */
        function updateScore(newScore)
		{
            //Get the JavaScript object that holds the data for the logged in user
            var usrObj = JSON.parse(localStorage[localStorage.loggedInUser]);
        
            //Update the user object with the new top score
            
            usrObj.topscore = newScore;
            
            //Put the user data back into local storage.
            localStorage[localStorage.loggedInUser] = JSON.stringify(usrObj);
        }
    
        
        /* Loads the rankings table.  */
        function showRankingsTable(){
            //Get a reference to the div that will hold the rankings table.
            var rankingDiv = document.getElementById("RankingsTable");
            
            //Create a variable that will hold the HTML for the rankings table
            var htmlStr = "";
            
            //Add a heading 
            htmlStr += "<h1>Rankings Table</h1>";
            
            //Add the table tag
            htmlStr += "<table>";
            
            //Work through all of the keys in local storage
            for(var key in localStorage) {
                //All of the keys should point to user data except loggedInUser
                if(key !== "loggedInUser"){
                    //Extract object containing user data

                    //Extract user name and top score
                    htmlStr += "David";
                    //Add a table row to the HTML string.
                }
            }
           
            //Finish off the table
            htmlStr += "</table>";
           
            //Add the table to the page.

        }
    