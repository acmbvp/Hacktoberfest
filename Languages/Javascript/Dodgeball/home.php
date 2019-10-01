<?php
    /*Include the PHP functions to be used on the page*/
    include('common.php'); 
	
    //Output header and navigation 
    outputHeader("Welcome to DoGGBall - Home");
    outputBannerNavigation("HOME");
?>

    <!-- Contents of the page -->
    <!-- game picture -->
    <img id="gamepicture" src="images/game.png" alt="game">

<?php
    /*Output the footer*/
    outputFooter();
?>