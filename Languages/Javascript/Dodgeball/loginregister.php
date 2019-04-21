<?php
    /*Include the PHP functions to be used on the page*/
    include('common.php'); 
	
    //Output header and navigation 
    outputHeader("Welcome to DoGGBall - Login/Register");
    outputBannerNavigation("LOGIN/REGISTER");
?>

<!-- Login and registration form -->
         <div id="loginregister">
            <form>
               <br>
                USERNAME:
                <!-- textbox input -->
                <input type="text" name="username"> 
                <br><br>
                PASSWORD:
                <!-- textbox input -->
                <input type="text" name="password"> 
                <br><br>
                <!-- login button -->
                <input type="submit" value="LOGIN"><br><br> 
                E-MAIL:
                <!-- textbox input -->
                <input type="text" name="email"> 
                <br><br>
                USERNAME:
                <!-- textbox input -->
                <input type="text" name="username"> 
                <br><br>
                PASSWORD:
                <!-- textbox input -->
                <input type="text" name="password"> 
                <br><br>
                <!-- registration button -->
                <input type="submit" value="REGISTER">
            </form>
        </div>

<?php
    //Output the footer
    outputFooter();
?>